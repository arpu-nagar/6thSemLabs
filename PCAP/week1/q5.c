#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
    int rank,size;
    int rev=0,rem;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    int a[9]={18,523,301,1234,2,14,108,150,1928};
    int n=a[rank];
    while(n!=0){
        rem=n%10;
        rev=rev*10+rem;
        n/=10;
    }
    printf("Rank %d, Number:%d \n",rank,rev);
    MPI_Finalize();
    return 0;
}