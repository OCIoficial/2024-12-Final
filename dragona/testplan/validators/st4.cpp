#include "testlib.h"

int main() {
  registerValidation();
  int n = inf.readInt(1, 100000, "n");
  inf.readSpace();
  int h = inf.readInt(1, 1000000, "h");
  inf.readEoln();
  for (int i = 0; i < n; ++i) {
    int a = inf.readInt(1, h, "a");
    inf.readSpace();
    int b = inf.readInt(1, h, "b");
    inf.ensuref(a < b, "`a` tiene que ser menor que `b`");
    inf.readEoln();
  }
  inf.readEof();
}
