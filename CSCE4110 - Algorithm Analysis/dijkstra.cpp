#include "dijkstra.h"
#define DEBUG false

vector<int> dijkstra(const vector<vector<int> > &cost_matrix, const int start) {
  const int n = cost_matrix.size();
  if(n <= 0) {
    cout << "Error: cost matrix is empty" << endl;
  }

  const int INF = (1 << 29);
  vector<int> d(n, INF);
  vector<int> s(n, 0);

  for(int i = 0; i < n; i++) {
    d[i] = cost_matrix[start][i];
  }
  s[start] = true;
  d[start] = 0;

  for(int i = 2; i < n; i++) {
    int min = INF;
    int u = 0;
    for(int j = 0; j < n; j++) {
      if(!s[j] && min > d[j]) {
        min = d[j];
        u = j;
      }
    }
      s[u] = true;

      if(DEBUG) cout << "u " << u << endl;
      for(int j = 0; j < n; j++) {
        if(!s[j] && d[j] > d[u] + cost_matrix[u][j]) {
          if(DEBUG) cout << "j " << j << "  c " << cost_matrix[u][j] << endl;
          d[j] = d[u] + cost_matrix[u][j];
        }
      }
    }
  return d;
}
