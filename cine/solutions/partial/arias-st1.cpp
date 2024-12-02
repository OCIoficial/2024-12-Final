// @ocimatic should-fail=[st2, st3, st4]
#include <bits/stdc++.h>
using namespace std;

template <typename T> using vec = vector<T>;
using mat = vec<vec<int>>;

int n, m;
mat C;

int main() {
    int k;
    cin >> n >> m >> k;

    C = mat(n, vec<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> C[i][j];
        }
    }

    int ans = 1e9;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (C[i][j] == 1) {
                continue;
            }
            int S = 0;
            for (int R = 1; R < max(n, m); R++) {
                S = 0;
                for (int l = max(i-R, 0); l <= min(i+R, n-1); l++) {
                    for (int r = max(j-R, 0); r <= min(j+R, m-1); r++) {
                        S += 1 - C[l][r];
                    }
                }
                if (S >= k+1) {
                    ans = min(ans, R);
                    break;
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
