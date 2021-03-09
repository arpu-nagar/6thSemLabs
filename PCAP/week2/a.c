#include <mpi.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#define MAX 100
int main(int argc, char* argv[]) {
    int rank, size, result, x=3;
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    

    if(rank == 0) {
        char word[MAX];
        printf("Enter a word: ");
        scanf("%s", word);
        MPI_Send(&word, strlen(word), MPI_CHAR, 1, 0, MPI_COMM_WORLD);
        printf("RANK 0: Sending Word to Rank 1\n");
        MPI_Recv(&word, MAX, MPI_CHAR, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("RANK 0: Recieved Toggled Word from Rank 1\n");
        printf("%s\n", word);
    } else if (rank == 1) {
        char word[MAX];
        MPI_Recv(&word, MAX, MPI_CHAR, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("RANK 1: Recieved Word from Rank 0\n");
        for(int i = 0; i < strlen(word); i++) {
            if(word[i] >= 65 && word[i] <= 90) {
                word[i] += 32;
            }
            else if(word[i] >= 97 && word[i] <= 122) {
                word[i] -=32;
            }
        }
        printf("RANK 1: Sending Toggled Word to Rank 0\n");
        MPI_Send(&word, strlen(word), MPI_CHAR, 0, 0, MPI_COMM_WORLD);

    }
    MPI_Finalize();
    return 0;
}