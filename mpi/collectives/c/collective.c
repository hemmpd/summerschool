#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define NTASKS 4

void print_buffers(int *printbuffer, int *sendbuffer, int buffersize);
void init_buffers(int *sendbuffer, int *recvbuffer, int buffersize);


int main(int argc, char *argv[])
{
    int ntasks, rank, color;
    int sendbuf[2 * NTASKS], recvbuf[2 * NTASKS];
    int printbuf[2 * NTASKS * NTASKS];

    MPI_Comm sub_comm;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &ntasks);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (ntasks != NTASKS) {
        if (rank == 0) {
            fprintf(stderr, "Run this program with %i tasks.\n", NTASKS);
        }
        MPI_Abort(MPI_COMM_WORLD, -1);
    }

    /* Initialize message buffers */
    init_buffers(sendbuf, recvbuf, 2 * NTASKS);

    /* Print data that will be sent */
    print_buffers(printbuf, sendbuf, 2 * NTASKS);

    /* use a single collective communication call (and maybe prepare
     * some parameters for the call) */
    int i;
    //for (i = 0; i < NTASKS; i++)
    //    MPI_Bcast(sendbuf, 2 * NTASKS, MPI_INT, i, MPI_COMM_WORLD);

    //MPI_Scatter(sendbuf, 2, MPI_INT, recvbuf, 2, MPI_INT,
    //   0, MPI_COMM_WORLD);

    /*int counts[4] = {1, 1, 2, 4};
    int disp[4] = {0, 1, 2, 4};

    MPI_Gatherv(sendbuf, counts[rank], MPI_INT, recvbuf, counts, disp, MPI_INT, 1, MPI_COMM_WORLD);*/

    //MPI_Alltoall(sendbuf, 2, MPI_INT, recvbuf, 2, MPI_INT, MPI_COMM_WORLD);

    if (rank < 2) {
        color = 1;
    } else {
        color = 2;
    }

    MPI_Comm_split(MPI_COMM_WORLD, color, rank, &sub_comm);

    int subid;
    MPI_Comm_rank(sub_comm, &subid);

    MPI_Reduce(sendbuf, recvbuf, 2 *  NTASKS, MPI_INT, MPI_SUM, 0, sub_comm);

    /* Print data that was received */
    print_buffers(printbuf, recvbuf, 2 * NTASKS);

    MPI_Finalize();
    return 0;
}


void init_buffers(int *sendbuffer, int *recvbuffer, int buffersize)
{
    int rank, i;

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    for (i = 0; i < buffersize; i++) {
        recvbuffer[i] = -1;
        sendbuffer[i] = i + buffersize * rank;
    }
}


void print_buffers(int *printbuffer, int *sendbuffer, int buffersize)
{
    int i, j, rank, ntasks;

    MPI_Gather(sendbuffer, buffersize, MPI_INT,
               printbuffer, buffersize, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &ntasks);

    if (rank == 0) {
        for (j = 0; j < ntasks; j++) {
            printf("Task %i:", j);
            for (i = 0; i < buffersize; i++) {
                printf(" %2i", printbuffer[i + buffersize * j]);
            }
            printf("\n");
        }
        printf("\n");
    }
}
