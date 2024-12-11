//@ocimatic should-fail=[st2]

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int findRounds(vector<int>& arr) {
  int round = 1;
  while (true) {
    vector<int> next;
    for (int i = 0; i < arr.size(); ++i) {
      if (i == 0 || arr[i] >= arr[i - 1]) {
        next.push_back(arr[i]);
      }
    }
    if (arr.size() == next.size()) {
      return round;
    }
    arr = next;
    round += 1;
  }
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
