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

  for(int i=0; i<m; i++){
    std::string pattern = inf.readLine();
    ensuref(2 <= pattern.size() and pattern.size() <= n, "el largo de cada palabra debe estar entre 2 y n");
    for(char c : pattern){
      ensuref('A' <= c && c <= 'Z', "los caracteres de las palabras deben ser letras mayúsculas");
    }
  }
  inf.readEof();
}
