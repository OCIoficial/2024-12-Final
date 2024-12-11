#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n, h;
  cin >> n >> h;
  
  vector <vector <int>> shortcuts(h);

  for(int i=0; i<n; i++){
	int a, b;
	cin >> a >> b;
	a--; b--;
	shortcuts[b].push_back(a);
  }

  vector <int> dp(h);
  dp[0] = 0;
  for(int i=1; i<h; i++){

	dp[i] = dp[i-1]+1;

	for(int a : shortcuts[i]){
	  dp[i] = min(dp[i], dp[a]);
	}
  }

  cout << dp[h-1] << '\n';
}
