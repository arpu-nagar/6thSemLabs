#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int main(int argc, char* argv[]) {
    int rank, size;
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    
    if(rank == 0) {
        int num;
        printf("Enter a number\n");
        scanf("%d", &num);

        int recv_num;
    	MPI_Send(&num, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        MPI_Recv(&recv_num, 1, MPI_INT, size - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        printf("RANK 0: Recieved %d from Rank %d \n", recv_num, size - 1);
    }
    else if(rank >= 1 && rank <= size - 2) {
        int recv_num;
        MPI_Recv(&recv_num, 1, MPI_INT, rank - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("RANK %d: Recieved %d from Rank %d \n", rank, recv_num, rank - 1);
        recv_num++;
        MPI_Ssend(&recv_num, 1, MPI_INT, rank + 1, 0, MPI_COMM_WORLD);
    }
    else if(rank == size - 1) {
        int recv_num;
        MPI_Recv(&recv_num, 1, MPI_INT, size - 2, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("RANK %d: Recieved %d from Rank %d \n", size - 1, recv_num, size - 2);
        recv_num++;
        MPI_Send(&recv_num, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    MPI_Finalize();
    return 0;
}