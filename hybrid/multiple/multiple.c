#include <stdio.h>
#include <mpi.h>
#include <omp.h>

int main(int argc, char *argv[]) {

    int rank, tid, msg, i, ntasks;
    int provided, required = MPI_THREAD_MULTIPLE;

    MPI_Init_thread(&argc, &argv, required, &provided);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &ntasks);

    #pragma omp parallel private(tid, msg, i)
    {
        tid = omp_get_thread_num();

        if (rank == 0) {
            for (i = 0; i < ntasks; i++)
                MPI_Send(&tid, 1, MPI_INT, i, tid, MPI_COMM_WORLD);
        } else {
            MPI_Recv(&msg, 1, MPI_INT, 0, tid, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            printf("Rank %d, thread %d received %d\n", rank, tid, msg);
        }
    }

    MPI_Finalize();
    return 0;
}
