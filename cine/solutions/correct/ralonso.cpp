#include<iostream>
#include<vector>

using namespace std;


int available_seats(
    int n,
    int m,
    int i,
    int j,
    vector<vector<int>> &accumulate,
    int p
) {
    int lr = max(0, i - p),
        lc = max(0, j - p),
        ur = min(n - 1, i + p),
        uc = min(m - 1, j + p);

    return (
        accumulate[ur + 1][uc + 1]
        - accumulate[ur + 1][lc]
        - accumulate[lr][uc + 1]
        + accumulate[lr][lc]
    );
}


bool feasible(
    int n,
    int m,
    int k,
    vector<vector<int>> &available,
    vector<vector<int>> &accumulate,
    int p
) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (available[i][j] && available_seats(n, m, i, j, accumulate, p) > k) {
                return true;
            }
        }
    }
    return false;
}


int main() {
    int n, m, k;
    cin >> n >> m >> k;

    // Accumulate sum of available seats
    vector<vector<int>> available(n, vector<int>(m, 0));
    vector<vector<int>> accumulate(n + 1, vector<int>(m + 1, 0));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int taken;
            cin >> taken;
            available[i][j] = 1 - taken;
            accumulate[i + 1][j + 1] = (
                available[i][j]
                + accumulate[i][j + 1]
                + accumulate[i + 1][j]
                - accumulate[i][j]
            );
        }
    }

    // Binsearch over solution space.
    // Our invariant: a is unfeasible and b is feasible
    int a = 0, b = max(n, m) - 1;
    while (a + 1 < b) {
        int p = (a + b) / 2;
        if (feasible(n, m, k, available, accumulate, p)) {
            b = p;
        } else {
            a = p;
        }
    }

    cout << b << endl;

    return 0;
}
