#include <mpi.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
int main(int argc, char* argv[]) {
    int rank, size, result, x=3;
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    
    if(rank == 0) {
        int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        for(int i = 1; i <= 10; i++)
           MPI_Send(&nums[i - 1], 1, MPI_INT, i, 0, MPI_COMM_WORLD);
    } else if(rank >= 1 && rank <= 10) {
        int num; 
        
        MPI_Recv(&num, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        printf("Recieved %d in Rank %d\n", num, rank);
    }
    MPI_Finalize();
    return 0;
}