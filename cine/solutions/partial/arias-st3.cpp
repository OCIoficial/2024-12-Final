// @ocimatic should-fail=[st1, st2, st4]
#include <bits/stdc++.h>
using namespace std;

template <typename T> using vec = vector<T>;

int n, m;

int main() {
    int k;
    cin >> n >> m >> k;
    if (n != 1) {
        return 0;
    }

    vec<int> C(m), O(m);
    for (int i = 0; i < m; i++) {
        cin >> O[i];
        C[i] = 1 - O[i];
        if (i > 0) {
            C[i] += C[i-1];
        }
    }

    int ans = 1e9;
    for (int i = 0; i < m; i++) {
        if (O[i] == 1) {
            continue;
        }
        int l = 1;
        int r = m;
        while (l < r) {
            int mid = (l+r)/2;
            int S = C[min(i+mid, m-1)];
            if (max(i-mid, 0) > 0) {
                S -= C[max(i-mid, 0)-1];
            }
            if (S >= k+1) {
                r = mid;
            } else {
                l = mid+1;
            }
        }
        ans = min(ans, l);
    }
    cout << ans << "\n";
    return 0;
}
