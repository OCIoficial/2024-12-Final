#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// Represents a participant not eliminated in any round.
const int FINALIST = -2;

int main() {
  int n;

  cin >> n;

  // We store participants' aplos along with how many rounds they passed.
  stack<pair<int, int>> s;
  int elimination_rounds = 0;

  for(int i = 0; i < n; i++) {
    int aplos;
    int round = 0;
    cin >> aplos;

    while(true) {
      if (s.empty()) {
        s.push({aplos, FINALIST});
        break;
      }
      if (s.top().first > aplos) {
        elimination_rounds = max(elimination_rounds, round + 1);
        s.push({aplos, round});
        break;
      }
      round = max(round, s.top().second + 1);
      s.pop();
    }
  }

  cout << elimination_rounds + 1 << endl;

  return 0;
}
