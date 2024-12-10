#include <climits>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> pii;

int dijkstra(const vector<vector<pii>> &edges, int s, int f) {
  vector<int> dist(edges.size(), INT_MAX);
  priority_queue<pii, vector<pii>, greater<pii>> q;
  q.emplace(0, s);
  while (!q.empty()) {
    auto [d, n] = q.top();
    q.pop();
    if (d >= dist[n]) {
      continue;
    }
    dist[n] = d;

    for (auto [vn, vd] : edges[n]) {
      q.emplace(d + vd, vn);
    }
  }
  return dist[f];
}

int main() {
  int n, h;
  scanf("%d%d", &n, &h);

  // Armamos un grafo con pesos donde cada piso es un nodo
  vector<vector<pii>> edges(h + 1);

  // Agregar una arista entre cada piso y el siguiente de costo 1
  for (int i = 1; i < h; ++i) {
    edges[i].emplace_back(i + 1, 1);
  }

  // Agregar una arista entre el inicio y fin de cada ascensor de costo 0
  for (int i = 0; i < n; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    edges[a].emplace_back(b, 0);
  }

  // Buscar el camino mas corto entre 1 y `h` usando Dijkstra
  printf("%d\n", dijkstra(edges, 1, h));
}
