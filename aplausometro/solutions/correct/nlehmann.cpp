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
    while (!stk.empty() && stk.top().first < arr[i]) {
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
  //   vector<int> arr = {5, 1, 2, 3, 4, 2, 1};
  //   vector<int> arr = {4, 5, 2, 1, 3, 4};
  //   vector<int> arr = {5, 2, 1, 3, 2};
  cout << findRounds(arr) << endl;
  return 0;
}

// 5 1 2 3 4 2 1
// 5 2 3 4
// 5 3 4
// 5 4
// 5

// 5 2 1 3 2
// 5 3
// 5

// 4 5 2 1 3 4
// 4 5 3 4
// 4 5 4
// 4 5
