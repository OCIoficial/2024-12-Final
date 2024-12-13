#include "testlib.h"
#include <vector>
#include <string>

int main() {
  registerValidation();
  int n = inf.readInt(2, 50, "n");
  inf.readEoln();
  std::vector <std::string> grid(n);
  for(int i=0; i<n; i++){
    grid[i] = inf.readLine();
    for(char c : grid[i]){
      ensuref('A' <= c && c <= 'Z', "los caracteres de la grilla deben ser letras mayúsculas");
    }
  }
  int m = inf.readInt(1, 50, "m");
  inf.readEoln();

  auto match_horizontal = [&](int x, int y, std::string &pattern){
    bool match = true;
    for(int i=0; i<pattern.size(); i++){
      if(grid[x][(y+i)%n] != pattern[i]) match = false;
    }
    return match;
  };
  
  for(int i=0; i<m; i++){
    std::string pattern = inf.readLine();
    ensuref(2 <= pattern.size() and pattern.size() <= n, "el largo de cada palabra debe estar entre 2 y n");
    for(char c : pattern){
      ensuref('A' <= c && c <= 'Z', "los caracteres de las palabras deben ser letras mayúsculas");
    }

    for(int x=0; x<n; x++){
      for(int y=0; y<n; y++){
        ensuref(!match_horizontal(x, y, pattern), "las palabras no pueden aparecer de forma horizontal");
      }
    }
  }
  inf.readEof();
}
