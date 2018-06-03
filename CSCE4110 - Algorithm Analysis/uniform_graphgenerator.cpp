#include "uniform_graphgenerator.h"
void uniform_graphgenerator(int n) {
  srand(time(NULL));

  stringstream ss;
  ss << "ugraphs/graph_" << n;
  ofstream fout(ss.str().c_str());
  fout << n << endl;
  vector<vector<int> > g(n,vector<int>(n));
  int r = rand() % 100 + 1;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(i == j) {
        g[i][j] = 0;
      } else {
        g[i][j] = r;
      }
      fout << g[i][j] << " ";
    }
    fout << endl;
  }


  return;
}

int main() {
  for(int i = 10; i <= 500; i+=10) {
    uniform_graphgenerator(i);
  }

  for(int i = 600; i <= 1000; i+=100) {
    uniform_graphgenerator(i);
  }

  return 0;
}
