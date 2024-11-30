#include <iostream>
#include "testlib.h"

int main() {
  registerValidation();
  int n = inf.readInt(1, 1e6, "n");
  inf.readEoln();
  for (int i = 1; i <= n; i++) {
    inf.readInt(0, 1e9, "a_" + std::to_string(i));
    if (i != n) {
      inf.readSpace();
    }
  }
  inf.readEoln();
  inf.readEof();
}
