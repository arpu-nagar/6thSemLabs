#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
	int rank,size;
	int x=20,y=4;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	if(rank==0)
		printf("Rank %d, SUM %d + %d = %d\n",rank,x,y,x+y);
	if(rank==1)
		printf("Rank %d, DIFF %d - %d = %d\n",rank,x,y,x-y);
	if(rank==2)
		printf("Rank %d, PROD %d * %d = %d\n",rank,x,y,x*y);
	if(rank==3)
		printf("Rank %d, DIV %d / %d = %f\n",rank,x,y,(double)(x/y));
	MPI_Finalize();
	return 0;
}
