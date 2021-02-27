#include <stdio.h>
#include <mpi.h>
#include <math.h>

int main(int argc, char *argv[])
{
	int rank,size;
	int x=3,result;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	result=pow(x,rank);
	printf("Result in process %d is = %d\n",rank,result);
	MPI_Finalize();
	return 0;
}