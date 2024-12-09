#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int N, M, K;

bool try_radius(vector<vector<int>> &sums, vector<vector<int>> &seats, int r) {
  // Probar sentar a Pedro en todas las posiciones
  for (int y = 1; y <= N; ++y) {
    for (int x = 1; x <= M; ++x) {
      // Asiento ocupado
      if (seats[y][x]) {
        continue;
      }

      // Contar la cantidad de ceros en la submatriz de radio `r` centrada en
      // `(x, y)` asegurandose que esté totalmente contenida.
      int y1 = max(y - r, 1), y2 = min(y + r, N);
      int x1 = max(x - r, 1), x2 = min(x + r, M);
      int c = sums[y2][x2] - sums[y1 - 1][x2] - sums[y2][x1 - 1] +
              sums[y1 - 1][x1 - 1];

      // Si caben todos respondemos `true`
      if (c >= K + 1) {
        return true;
      }
    }
  }
  return false;
}

using namespace std;

int main() {
  cin >> N >> M >> K;

  // Los asientos
  vector<vector<int>> seats(N + 1, vector<int>(M + 1));
  // Suma de prefijos para calcular la cantidad de ceros en una submatriz
  vector<vector<int>> sums(N + 1, vector<int>(M + 1, 0));
  for (int y = 1; y <= N; ++y) {
    for (int x = 1; x <= M; ++x) {
      cin >> seats[y][x];
      sums[y][x] =
          !seats[y][x] + sums[y - 1][x] + sums[y][x - 1] - sums[y - 1][x - 1];
    }
  }

  // Busqueda binaria en el "radio", es decir, busqueda binaria en las posibles
  // distancias grupales. `max(N, M)` es una cota superior olgada. Podría
  // optimizarse y solo buscar hasta la mitad.
  int left = 1;
  int right = max(N, M);
  while (left < right) {
    int mid = left + (right - left) / 2;
    if (try_radius(sums, seats, mid)) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  cout << left << endl;

  return 0;
}
