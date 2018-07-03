#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
    int my_id, omp_rank;
    int provided, required = MPI_THREAD_MULTIPLE;

    /* Initialize MPI with thread support. */
    MPI_Init_thread(&argc, &argv, required, &provided);

    /* Find out the MPI rank and thread ID of each thread and print
     * out the results. */
    MPI_Comm_rank(MPI_COMM_WORLD, &my_id);
    #pragma omp parallel private(omp_rank)
    {
        omp_rank = omp_get_thread_num();
        printf("Thread: %d, process: %d\n", omp_rank, my_id);
    }

    /* Investigate the provided thread support level. */
    if(my_id == 0) {
        if (provided == MPI_THREAD_FUNNELED) {
            printf("FUNNELED supported\n");
        } else if (provided == MPI_THREAD_SINGLE) {
            printf("SINGLE supported\n");
        } else if (provided == MPI_THREAD_SERIALIZED) {
            printf("SERIALIZED supported\n");
        } else if (provided == MPI_THREAD_MULTIPLE){
            printf("MULTIPLE supported\n");
        }
    }

    MPI_Finalize();
    return 0;
}
