#include "floydwarshall.h"
#define DEBUG false

const vector<vector<int> > floydwarshall(const vector<vector<int> > &cost_matrix) {
  const int n = cost_matrix.size();
  if(n <= 0) {
    cout << "Error: cost matrix is empty" << endl;
  }
  vector<vector<int> > dist(n, vector<int>(n));
  for(int i =  0; i < n; i++) {
    for(int j =  0; j < n; j++) {
      dist[i][j] = cost_matrix[i][j];
      if(DEBUG) cout << dist[i][j] << " ";
    }
    if(DEBUG) cout << endl;
  }

  for(int k =  0; k < n; k++) {
    for(int i =  0; i < n; i++) {
      for(int j =  0; j < n; j++) {
          if (dist[i][j] > dist[i][k] + dist[k][j]) {
            if(DEBUG) cout << "A"  << dist[i][j] << endl;
            if(DEBUG) cout << "B" << dist[i][k] + dist[k][j] << endl;
             dist[i][j] = dist[i][k] + dist[k][j];
          }
      }
    }
  }
  return dist;
}
