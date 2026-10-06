#include <stdio.h>
#include <mpi.h>
int main(int argc, char *argv[]) {
int rank;
MPI_Init(&argc, &argv);
MPI_Comm_rank(MPI_COMM_WORLD, &rank);
int value;
if (rank == 0) {
// Deadlock example (if both send first)
// MPI_Send(&value, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
// MPI_Recv(&value, 1, MPI_INT, 1, 0, MPI_COMM_WORLD,
MPI_STATUS_IGNORE);
// Avoiding deadlock
MPI_Recv(&value, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
MPI_Send(&value, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
printf("Process 0 completed communication\n");
} else if (rank == 1) {
    MPI_Send(&value, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
MPI_Recv(&value, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
printf("Process 1 completed communication\n");
}
MPI_Finalize();
return 0;
}