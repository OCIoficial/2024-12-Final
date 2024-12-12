#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

int main() {
    int n, h;
    cin >> n >> h;

    // Elevators (b_i, a_i) ordered by b_i, then a_i ascending
    vector<pair<int, int>> elevators;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        elevators.push_back(make_pair(b, a));
    }
    sort(elevators.begin(), elevators.end());

    auto iter = elevators.begin();

    vector<int> min_stairs(h + 1);
    min_stairs[1] = 0;

    for (int i = 2; i <= h; i++) {
        min_stairs[i] = min_stairs[i - 1] + 1;
        while(iter != elevators.end() && (*iter).first == i) {
            min_stairs[i] = min(min_stairs[i], min_stairs[(*iter).second]);
            iter++;
        }
    }

    cout << min_stairs[h] << endl;
    return 0;
}
