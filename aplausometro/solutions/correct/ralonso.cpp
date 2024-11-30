#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// Represents a participant not eliminated in any round.
const int FINALIST = 0;

int main() {
  int n;

  cin >> n;

  // We store participants' aplos along with the round in which they were eliminated.
  stack<pair<int, int>> s;
  int max_rounds = 0;

  for(int i = 0; i < n; i++) {
    int aplos;
    int round = 1;
    cin >> aplos;

    while(true) {
      if (s.empty()) {
        s.push({aplos, FINALIST});
        break;
      }
      if (s.top().first > aplos) {
        s.push({aplos, round});
        break;
      }
      round = s.top().second + 1;
      s.pop();
      max_rounds = max(max_rounds, round);
    }
  }

  cout << max_rounds + 1 << endl;

  return 0;
}
