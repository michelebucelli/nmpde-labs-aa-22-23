#include <deal.II/base/convergence_table.h>

#include <fstream>
#include <iostream>
#include <vector>

#include "Poisson2D.hpp"

// Main function.
int
main(int /*argc*/, char * /*argv*/[])
{
  ConvergenceTable table;

  const std::vector<unsigned int> N_values = {4, 9, 19, 39};
  const unsigned int              degree   = 1;

  // Only for Exercise 1:
  // std::ofstream convergence_file("convergence.csv");
  // convergence_file << "h,eL2,eH1" << std::endl;

  for (const unsigned int &N : N_values)
    {
      Poisson2D problem(N, degree);

      problem.setup();
      problem.assemble();
      problem.solve();
      problem.output();

      // Only for Exercise 1:
      // const double h        = 1.0 / N;
      // const double error_L2 = problem.compute_error(VectorTools::L2_norm);
      // const double error_H1 = problem.compute_error(VectorTools::H1_norm);

      // table.add_value("h", h);
      // table.add_value("L2", error_L2);
      // table.add_value("H1", error_H1);

      // convergence_file << h << "," << error_L2 << "," << error_H1 <<
      // std::endl;
    }

  // Only for Exercise 1:
  // table.evaluate_all_convergence_rates(ConvergenceTable::reduction_rate_log2);
  // table.set_scientific("L2", true);
  // table.set_scientific("H1", true);
  // table.write_text(std::cout);

  return 0;
}