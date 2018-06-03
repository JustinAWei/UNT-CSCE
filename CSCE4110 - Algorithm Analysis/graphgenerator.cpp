#include "graphgenerator.h"
void graphgenerator(int n) {
  srand(time(NULL));

  stringstream ss;
  ss << "graphs/graph_" << n;
  ofstream fout(ss.str().c_str());
  fout << n << endl;
  const int INF = (1 << 29);
  vector<vector<int> > g(n,vector<int>(n, INF));
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(i == j) {
        g[i][j] = 0;
      } else {
        int r = rand() % 100 + 1;
        g[i][j] = r;
      }
      fout << g[i][j] << " ";
    }
    fout << endl;
  }


  return;
}

int main() {
  for(int i = 0; i <= 500; i+=10) {
    graphgenerator(i);
  }

  for(int i = 600; i <= 1000; i+=100) {
    graphgenerator(i);
  }

  return 0;
}
