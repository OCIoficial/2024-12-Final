#include <bits/stdc++.h>
using namespace std;

template <typename T> using vec = vector<T>;
using mat = vec<vec<int>>;

int n, m;
mat C;
// calculate the sum of (a,b),(x,y) rectangle inclusive
//          n      m      n      m
int sum(int a, int b, int x, int y) {
    a = max(0, a);
    b = max(0, b);
    x = min(n-1, x);
    y = min(m-1, y);

    int S = C[x][y];
    if (a > 0) {
        S -= C[a-1][y];
    }
    if (b > 0) {
        S -= C[x][b-1];
    }
    if (a > 0 && b > 0) {
        S += C[a-1][b-1];
    }
    return S;
}

int main() {
    int k;
    cin >> n >> m >> k;

    mat O(n, vec<int>(m));
    C = mat(n, vec<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> O[i][j];
            C[i][j] = 1 - O[i][j];
            if (i > 0) {
                C[i][j] += C[i-1][j];
            }
            if (j > 0) {
                C[i][j] += C[i][j-1];
            }
            if (i > 0 && j > 0) {
                C[i][j] -= C[i-1][j-1];
            }
        }
    }

    int ans = 1e9;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (O[i][j] == 1) {
                continue;
            }
            int l = 1;
            int r = max(n, m);
            while (l < r) {
                int mid = (l+r)/2;
                if (sum(i-mid, j-mid, i+mid, j+mid) >= k+1) {
                    r = mid;
                } else {
                    l = mid+1;
                }
            }
            ans = min(ans, l);
        }
    }
    cout << ans << "\n";
    return 0;
}
