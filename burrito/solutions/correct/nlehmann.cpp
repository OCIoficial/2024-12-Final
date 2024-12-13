#include <iostream>
#include <vector>
using namespace std;

bool horizontal(const vector<string> &grid, int i, int j, const string &s) {
  auto n = grid.size();
  for (int k = 0; k < s.length(); ++k) {
    if (grid[i][(j + k) % n] != s[k]) {
      return false;
    }
  }
  return true;
}

bool vertical(const vector<string> grid, int i, int j, const string &s) {
  auto n = grid.size();
  for (int k = 0; k < s.length(); ++k) {
    if (i + k >= n) {
      return false;
    }
    if (grid[i + k][j] != s[k]) {
      return false;
    }
  }
  return true;
}

bool search(const vector<string> &grid, const string &s) {
  auto n = grid.size();
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (horizontal(grid, i, j, s) || vertical(grid, i, j, s)) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  int n, m;

  cin >> n;

  vector<string> grid;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    grid.push_back(s);
  }

  cin >> m;

  for (int i = 0; i < m; ++i) {
    string s;
    cin >> s;
    cout << (search(grid, s) ? "PRESENTE" : "AUSENTE") << endl;
  }

  return 0;
}
