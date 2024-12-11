#include "testlib.h"

static std::tuple<int, int, int> readHeader() {
  int n = inf.readInt(1, 1e6, "n");
  inf.readSpace();
  int m = inf.readInt(1, 1e6, "m");
  inf.readSpace();
  int k = inf.readInt();
  inf.readEoln();
  return {n, m, k};
}

static int readMatrix(int n, int m) {
  int C[n][m];
  int zeros = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      C[i][j] = inf.readInt(0, 1, "C_ij");
      if (j != m - 1) {
        inf.readSpace();
      }
      if (C[i][j] == 0) {
        zeros++;
      }
    }
    inf.readEoln();
  }
  return zeros;
}

int main(int argc, char *argv[]) {
  registerValidation();
  auto [n, m, k] = readHeader();
  int zeros = readMatrix(n, m);
  inf.readEof();

  ensuref(zeros >= k + 1, "Not enough empty spaces in matrix.");
  if (argv[1] == "st1") {
    ensuref(n <= 20, "n is too big for this subtask.");
    ensuref(m <= 20, "m is too big for this subtask.");
  } else if (argv[1] == "st2") {
    ensuref(n * m <= 5000, "Matrix is too big for this subtask.");
    ensuref(zeros >= k + 1, "Not enough empty spaces in matrix.");
  } else if (argv[1] == "st3") {
    ensuref(n == 1, "N must be 1 for this subtask.");
    ensuref(m <= 1'000'000, "Matrix is too big for this subtask.");
  } else if (argv[1] == "st4") {
    ensuref(n * m <= 1'000'000, "Matrix is too big for this subtask.");
  }
}
