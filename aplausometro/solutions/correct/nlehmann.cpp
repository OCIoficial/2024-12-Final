#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int findRounds(vector<int>& arr) {
  int n = arr.size();
  stack<pair<int, int>> stk;  // Stack to track (value, round)
  int maxRounds = 0;

  for (int i = 0; i < n; ++i) {
    int currentRound = 0;

    // Propagate rounds for elements smaller than the current
    while (!stk.empty() && stk.top().first <= arr[i]) {
      currentRound = max(currentRound, stk.top().second);
      stk.pop();
    }

    // Calculate the round for the current element
    if (!stk.empty()) {
      currentRound++;
    }

    // Push the current element and its round
    stk.push({arr[i], currentRound});

    // Track the maximum round
    maxRounds = max(maxRounds, currentRound);
  }

  // Otherwise, add an extra round for stabilization
  return maxRounds + 1;
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  cout << findRounds(arr) << endl;
  return 0;
}
