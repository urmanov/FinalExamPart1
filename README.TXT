Big Data in Finance final exam, Part B1, calculating PI using MPI
=================================================================

The MPI program has several bugs. These bugs can be in the C code,
the makefile, or the PBS job file. Your task is to find these bugs,
fix them, compile and run the program, then share your results.

In this file, write any thoughts or comments that might help
improve your grade.

A hint to help you on your way. Remember that make uses tabs to indent
the commands below targets.

And, remember, to use Git you must first load Git:

  module load git
  
These may also be useful commands:

  module list
  
  module avail

Comments:

Used your hint and indented the makefile (replaced double spaces with Tab)
Also, makefile had wrong filename. I replaced mpi.cpp with mpi.c

mpi.pbs file: changed select=4 to 8 to match mpirun command on the bottom which has 8
last line has mpi.exe, removed ".exe" part

mpi.c: x*x*x changed to x*x
if statement error, corrected.

