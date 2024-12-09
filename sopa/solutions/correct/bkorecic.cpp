#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
  int n;
  cin >> n;
  vector <string> grid(n);
  for(int i=0; i<n; i++){
    cin >> grid[i];
  }
  int m;
  cin >> m;

  while(m--){
    string s;
    cin >> s;

    bool match = false;
    for(int x=0; x<n; x++){
      for(int y=0; y<n; y++){
        // attempt vertical
        bool vertical = true;
        for(int i=0; i<s.size(); i++){
          if(x+i >= n){
            vertical = false;
            break;
          }
          if(s[i] != grid[x+i][y]) vertical = false;
        }
        
        // attempt horizontal
        bool horizontal = true;
        for(int i=0; i<s.size(); i++){
          if(s[i] != grid[x][(y+i)%n]) horizontal = false;
        }

        if(horizontal or vertical) match = true;
      }
    }
    cout << (match ? "PRESENTE" : "AUSENTE") << '\n';
  }
}
