#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, h;
	cin >> n >> h;

	vector<vector<int>> adj(h+1);
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
	}
	vector<int> ans(h+1,1000000);
	ans[1] = 0;
	for (int i = 1; i < h; ++i) {
		for (auto x : adj[i]) {
			ans[x] = min(ans[x], ans[i]);
		}
		ans[i+1] = min(ans[i+1], ans[i]+1);
	}
	cout << ans[h] << endl;
	return 0;
}
