#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"

int main(int argc, char *argv[]) {

  int myid,nprocs;

  long int npts = 1e10;

  long int i,mynpts;

  double f,sum,mysum;
  double xmin,xmax,x;

  MPI_Init(&argc,&argv);
  MPI_Comm_size(MPI_COMM_WORLD,&nprocs);
  MPI_Comm_rank(MPI_COMM_WORLD,&myid);

  if (myid = 0) {
    mynpts = npts - (nprocs-1)*(npts/nprocs);
  } else {
    mynpts = npts/nprocs;
  }

  mysum = 0.0;
  xmin = 0.0;
  xmax = 1.0;

  srand(myid);

  for (i=0; i<mynpts; i++) {
    x = (double) rand()/RAND_MAX*(xmax-xmin) + xmin;
    mysum += 4.0/(1.0 + x*x*x);
  }

  MPI_Reduce(&mysum,&sum,1,MPI_DOUBLE,MPI_SUM,0,MPI_COMM_WORLD);
  
  if (myid == 0) {
    f = sum/npts;
    printf("PI calculated with %ld points = %f \n",npts,f);
  }

  MPI_Finalize();
}
