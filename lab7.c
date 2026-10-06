#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    int rank, value;

    // Initialize the MPI environment
    MPI_Init(&argc, &argv);

    // Get the rank of the calling process
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    // Process 0 sets the initial value
    if (rank == 0) {
        value = 50;
    }

    // Broadcast 'value' from process 0 to all processes in MPI_COMM_WORLD
    MPI_Bcast(&value, 1, MPI_INT, 0, MPI_COMM_WORLD);

    // Every process prints the received value
    printf("Process %d received value %d\n", rank, value);

    // Finalize the MPI environment
    MPI_Finalize();

    return 0;
}