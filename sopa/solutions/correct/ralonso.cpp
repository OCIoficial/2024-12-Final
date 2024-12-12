#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
    int n, m;
    string s;

    cin >> n;
    vector<vector<char>> burrito(n + 2, vector<char>(2 * n, '-'));

    for (int i = 1; i <= n; i++) {
        cin >> s;
        for (int j = 0; j < n; j++) {
            burrito[i][j] = burrito[i][j + n] = s[j];
        }
    }

    vector<pair<int, int>> directions = {{-1, 1}, {0, 1}, {1, 1}, {1, 0}};

    cin >> m;
    for (int w = 0; w < m; w++) {
        cin >> s;
        bool found = false;
        for (auto d: directions) {
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j < n; j++) {
                    found = true;
                    for (int v = 0; v < s.size(); v++) {
                        if (s[v] != burrito[i + d.first * v][j + d.second * v]) {
                            found = false;
                            break;
                        }
                    }
                    if (found) break;
                }
                if (found) break;
            }
            if (found) break;
        }
        if (found) {
            cout << "PRESENTE" << endl;
            continue;
        }
        for (auto d: directions) {
            for (int i = 1; i <= n; i++) {
                for (int j = n - 1; j < 2 * n; j++) {
                    found = true;
                    for (int v = 0; v < s.size(); v++) {
                        if (s[v] != burrito[i - d.first * v][j - d.second * v]) {
                            found = false;
                            break;
                        }
                    }
                    if (found) break;
                }
                if (found) break;
            }
            if (found) break;
        }
        cout << (found ? "PRESENTE" : "AUSENTE") << endl;
    }

    return 0;
}
