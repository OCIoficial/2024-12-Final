#include "testlib.h"
#include "generic.h"

int main() {
  registerValidation();
  auto [n, m, k] = readHeader();
  ensuref(n <= 20, "n is too big for this subtask.");
  ensuref(m <= 20, "m is too big for this subtask.");
  int zeros = readMatrix(n, m);
  ensuref(zeros >= k+1, "Not enough empty spaces in matrix.");
  inf.readEof();
}
