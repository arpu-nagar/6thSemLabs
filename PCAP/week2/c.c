#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int main(int argc, char* argv[]) {
    int rank, size, result, x=3;
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int n = 10;

    if(rank == 0) {
        int *nums = calloc(n, sizeof(int));
        printf("Enter elements\n");
        for(int i = 0; i < n; i++) {
            scanf("%d", &nums[i]);
        }
        void* buffer = calloc(10 * n, sizeof(int));
        int size = sizeof(int) * 10 * n;
        MPI_Buffer_attach(buffer, size);
        
        for(int i = 1; i <= 10; i++)
           MPI_Bsend(&nums[i - 1], 1, MPI_INT, i, 0, MPI_COMM_WORLD);
        
        MPI_Buffer_detach(&buffer, &size);

    } else if(rank >= 1 && rank <= n) {
        int num;
        MPI_Recv(&num, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        if(rank % 2 == 0)
            printf("Recieved %d in Rank %d and Square is %d\n", num, rank, num * num);
        else 
            printf("Recieved %d in Rank %d and Cube is %d\n", num, rank, num * num * num);
    }
    MPI_Finalize();
    return 0;
}