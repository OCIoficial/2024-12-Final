#include "testlib.h"
#include "generic.h"

int main() {
  registerValidation();
  auto [n, m, k] = readHeader();
  ensuref(n == 1, "N must be 1 for this subtask.");
  ensuref(m <= 1'000'000, "Matrix is too big for this subtask.");
  int zeros = readMatrix(n, m);
  ensuref(zeros >= k+1, "Not enough empty spaces in matrix.");
  inf.readEof();
}
