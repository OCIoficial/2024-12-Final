#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n;
  cin >> n;

  vector <int> a(n), left(n), right(n);
  vector <bool> deleted(n, false); // to mark deleted indices
  for(int i=0; i<n; i++){
    cin >> a[i];
    left[i] = i-1;
    right[i] = i+1;
  }

  vector <int> to_elim; // indices to eliminate in next round
  for(int i=1; i<n; i++){
    if(a[i] < a[i-1]) to_elim.push_back(i);
  }

  int ans=0;
  while(!to_elim.empty()){
    vector <int> candidates;
    // mark as deleted
    for(int i : to_elim){
      deleted[i] = true;
    }
    // get candidates
    for(int i : to_elim){
      if(right[i] < n && !deleted[right[i]]){
        candidates.push_back(right[i]);
      }
    }
    // maintain left/right
    for(int i : to_elim){
      if(left[i] >= 0){
        right[left[i]] = right[i];
      }
      if(right[i] < n){
        left[right[i]] = left[i];
      }
    }
    // get new eliminations from
    // candidates
    vector <int> new_elim;
    for(int i : candidates){
      if(left[i] >= 0 && a[i] < a[left[i]]){
        new_elim.push_back(i);
      }
    }
    to_elim = new_elim;
    ans++;
  }
  cout << ans+1 << '\n';
}
