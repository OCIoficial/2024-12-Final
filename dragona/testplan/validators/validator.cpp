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

std::tuple<int, int> readHeader() {
  int n = inf.readInt(0, 100'000, "n");
  inf.readSpace();
  int h = inf.readInt(1, 1'000'000, "h");
  inf.readEoln();
  return {n, h};
}

std::vector<int> readElevators(int n, int h) {
  vector<int> vec;
  for (int i = 0; i < n; ++i) {
    int a = inf.readInt(1, h, "a");
    inf.readSpace();
    int b = inf.readInt(1, h, "b");
    inf.readEoln();

    ensure(a < b);
    vec.push_back(a);
    vec.push_back(b);
  }
  return vec;
}

int main(int argc, char* argv[]) {
  registerValidation();
  auto [n, h] = readHeader();
  auto vec = readElevators(n, h);
  inf.readEof();

  if (!strcmp(argv[1], "st1")) {
    ensure(n == 1);
  } else if (!strcmp(argv[1], "st2")) {
    ensure(isStrictlyIncreasing(vec));
  } else if (!strcmp(argv[1], "st3")) {
    ensure(n <= 20);
  }
}
