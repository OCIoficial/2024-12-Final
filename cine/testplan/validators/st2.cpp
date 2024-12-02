#include "testlib.h"
#include "generic.h"

int main() {
  registerValidation();
  auto [n, m, k] = readHeader();
  ensuref(n*m <= 5000, "Matrix is too big for this subtask.");
  int zeros = readMatrix(n, m);
  ensuref(zeros >= k+1, "Not enough empty spaces in matrix.");
  inf.readEof();
}
