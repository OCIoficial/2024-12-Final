// This file is a partial solution for the sample task. You can add partial
// solutions just by placing them in this directory. Remove this file before
// you start working on the actual task.
//
// Partial solutions must specify the list of subtasks they should fail with a
// comment as exemplified below. Ocimatic will check the solution fails these
// subtasks and only these subtasks. If no comment is present, ocimatic will
// assume all subtasks should fail.
//
// For the sample task, this solution should fail the subtask 2 because it uses
// `int` instead of `long`. This implies the solution should pass subtask 1.

// @ocimatic should-fail=[st3,st4]
// solución alternativa
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int n, h;
	cin >> n >> h;

	priority_queue<pair<int, pair<int, int>>> pq;
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		pq.push({b-a, {a,b}});
	}
	vector<int> visitados(h+1,0);
	while (!pq.empty()) {
		auto [a, b] = pq.top().second;
		pq.pop();
		bool works = 1;
		for (int i = a; i < b; ++i) {
			if (visitados[i]) {
				works = 0;
				break;
			}
		}
		if (works) {
			for (int i = a; i < b; ++i) {
				visitados[i] = 1;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i < h; ++i) {
		ans += !visitados[i];
	}
	cout << ans << endl;
	return 0;
}
