#include <vector>

#include "testlib.h"

using namespace std;

bool isStrictlyIncreasing(const std::vector<int>& arr) {
  for (size_t i = 1; i < arr.size(); ++i) {
    if (arr[i] <= arr[i - 1]) {
      return false;
    }
  }
  return true;
}

int main() {
  registerValidation();
  int n = inf.readInt(1, 100000, "n");
  inf.readSpace();
  int h = inf.readInt(1, 100000, "h");
  inf.readEoln();
  vector<int> vec;
  for (int i = 0; i < n; ++i) {
    int a = inf.readInt(1, h, "a");
    inf.readSpace();
    int b = inf.readInt(1, h, "b");
    inf.ensuref(a < b, "`a` tiene que ser menor que `b`");
    inf.readEoln();

    vec.push_back(a);
    vec.push_back(b);
  }
  inf.ensuref(isStrictlyIncreasing(vec),
              "los ascensores no se deben intersectar");
  inf.readEof();
}
