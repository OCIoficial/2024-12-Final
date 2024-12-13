#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

struct Node {
  vector <int> terminal;
  map <char, Node*> children;
  Node() = default;

  Node* add(char c){
    if(!children.count(c)){
      children[c] = new Node();
    }
    return children[c];
  }
};

struct Trie {

  Node* root;

  Trie(){
    root = new Node();
  }

  void add_string(string &s, int idx){
    Node *cur = root;
    for(char c : s){
      cur = cur->add(c);
    }
    cur->terminal.push_back(idx);
  }
};


int main(){
  // O(n^2(n+m)) solution
  int n;
  cin >> n;
  vector <string> grid(n);
  for(int i=0; i<n; i++){
    cin >> grid[i];
  }
  int m;
  cin >> m;

  vector <bool> ans(m, false);
  Trie trie;

  for(int i=0; i<m; i++){
    string s;
    cin >> s;
    trie.add_string(s, i);
  }

  for(int x=0; x<n; x++){
    for(int y=0; y<n; y++){
      // starting pos (x,y)

      // move horizontally, search trie
      Node* cur = trie.root;
      for(int i=0; i<n; i++){
        char c = grid[x][(y+i)%n];

        if(!cur->children.count(c)){
          break;
        }

        cur = cur->children[c];

        for(int idx : cur->terminal){
          ans[idx] = true;
        }
      }

      // move vertically
      cur = trie.root;
      for(int i=0; i<n and x+i<n; i++){
        char c = grid[x+i][y];

        if(!cur->children.count(c)){
          break;
        }

        cur = cur->children[c];

        for(int idx : cur->terminal){
          ans[idx] = true;
        }
      }
    }
  }

  for(int i=0; i<m; i++){
    if(ans[i]) cout << "PRESENTE\n";
    else cout << "AUSENTE\n";
  }
}
