// This script generates random test cases for the sample task. It takes a
// minimum and maximum value and prints two random numbers in that range.
// See the comment in testplan.txt for further details.

#include <cassert>
#include <iostream>
#include <vector>
#include <random>
#include <utility>

std::mt19937 gen;
std::string subtask;
const int VERTICAL = 0;
const int HORIZONTAL = 1;

// char used in subtask1 to fill
// empty spaces in order to
// not accidentally add words
char special_char;

char random_char(){
  const char MIN = 'A';
  const char MAX = 'Z';
  std::uniform_int_distribution<char> dist(MIN, MAX);
  char ans = dist(gen);
  // avoid using special char if st1
  if(subtask == "st1"){
    while(ans == special_char){
      ans = dist(gen);
    }
  }
  return ans;
}

int main(int argc, char *argv[]) {
  // The argument in position 1 is the hidden seed.
  std::hash<std::string> hasher;
  gen = std::mt19937(hasher(argv[1]));
  // The argument in position 1 is either "st1" or "st2",
  // indicating the subtask and therefore if we allow 
  // horizontal strings in the grid.
  subtask = argv[2];
  assert(subtask == "st1" or subtask == "st2");
  if(subtask == "st1"){
    special_char = std::uniform_int_distribution<char>('A','Z')(gen);
  }

  const int n = 50;
  const int m = 25;
  std::vector <std::vector <char>> grid(n, std::vector<char>(n, '\0'));
  std::vector <std::string> words(m);
  
  for(int i=0; i<m; i++){
    // Generate random string with length between [1,n]
    std::uniform_int_distribution<int> len_dist(3, n);
    int len = len_dist(gen);
    words[i] = std::string(len, 'a');
    for(char &c : words[i]){
      c = random_char();
    }
  }

  // tests if a string can go in
  // some position and orientation
  auto test_placement = [&](int x, int y, int orientation, std::string &s){
    if(orientation == VERTICAL){
      for(int i=0; i<s.size(); i++){
        if(x+i >= n) return false;
        if(grid[x+i][y] != '\0') return false;
      }
    }
    else{
      for(int i=0; i<s.size(); i++){
        if(grid[x][(y+i)%n] != '\0') return false;
      }
    }
    return true;
  };

  // places string at some position+orientation in grid
  auto place = [&](int x, int y, int orientation, std::string &s){
    if(orientation == VERTICAL){
      for(int i=0; i<s.size(); i++){
        grid[x+i][y] = s[i];
      }
    }
    else{
      for(int i=0; i<s.size(); i++){
        grid[x][(y+i)%n] = s[i];
      }
    }
  };

  for(std::string &s : words){
    // Decide if it goes in the grid
    std::bernoulli_distribution bool_dist(0.5);
    bool present = bool_dist(gen);
    if(!present) continue;

    // If present,
    // pick orientation
    int orientation = VERTICAL;
    if(subtask == "st2"){
      std::uniform_int_distribution<int> orient_dist(0, 1);
      orientation = orient_dist(gen);
    }

    // list possible locations
    std::vector <std::pair<int,int>> locs;
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        if(test_placement(i, j, orientation, s)){
          locs.push_back({i, j});
        }
      }
    }

    // choose one location at random
    if(!locs.empty()){
      std::uniform_int_distribution<int> loc_dist(0, (int)locs.size()-1);
      int loc_idx = loc_dist(gen);
      auto [i, j] = locs[loc_idx];
      place(i, j, orientation, s);
    }
  }

  // Fill the rest of the grid
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(grid[i][j] == '\0'){
        if(subtask == "st1"){
          grid[i][j] = special_char;
        }
        else{
          grid[i][j] = random_char();
        }
      }
    }
  }
  
  // Print formatted input
  std::cout << n << std::endl;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      std::cout << grid[i][j];
    } 
    std::cout << std::endl;
  }
  std::cout << m << std::endl;
  for(std::string &s : words){
    std::cout << s << std::endl;
  }
  return 0;
}
