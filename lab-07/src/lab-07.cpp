#include "Heat.hpp"

// Main function.
int
main(int argc, char *argv[])
{
  Utilities::MPI::MPI_InitFinalize mpi_init(argc, argv);

  const unsigned int N      = 9;
  const unsigned int degree = 1;

  const double T      = 1.0;
  const double deltat = 0.05;
  const double theta  = 1.0;

  Heat problem(N, degree, T, deltat, theta);

  problem.setup();
  problem.solve();

  return 0;
}