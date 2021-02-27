#include<stdio.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
	int rank,size,c1;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	if(rank==0)
		for(int i=2;i<=50;i++)
		{
			c1=0;
			for(int j=1;j<i;j++)
				if(i%j==0)
					c1++;
			if(c1==1)
				printf("Rank %d, Prime Number:%d\n",rank,i);
		}
	else if(rank==1)
		for(int i=51;i<=100;i++)
		{
			c1=0;
			for(int j=1;j<i;j++)
				if(i%j==0)
					c1++;
			if(c1==1)
				printf("Rank %d, Prime Number:%d\n",rank,i);
		}
	MPI_Finalize();
	return 0;
}