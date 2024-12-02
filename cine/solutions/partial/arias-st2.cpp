// @ocimatic should-fail=[st3, st4]
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
            int S = 1;
            for (int R = 1; R < max(n, m); R++) {
                if (j-R >= 0 || j+R < m) {
                    for (int l = max(i-R, 0); l <= min(i+R, n-1); l++) {
                        if (j-R >= 0) {
                            S += 1 - C[l][j-R];
                        }
                        if (j+R < m) {
                            S += 1 - C[l][j+R];
                        }
                    }
                }
                if (i-R >= 0 || i+R < n) {
                    for (int l = max(j-R+1, 0); l <= min(j+R-1, m-1); l++) {
                        if (i-R >= 0) {
                            S += 1 - C[i-R][l];
                        }
                        if (i+R < n) {
                            S += 1 - C[i+R][l];
                        }
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
