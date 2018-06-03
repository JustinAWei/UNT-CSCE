#include "floydwarshall.h"
#include "dijkstra.h"
#include "main.h"

void write_matrix(const vector<vector<int> > &matrix, ofstream &fout) {
  for(int i = 0; i < matrix.size(); i++) {
    for(int j = 0; j < matrix[i].size(); j++) {
      fout << matrix[i][j] << " ";
    }
     fout << endl;
  }
  return;
}

int main(int argc, char* argv[]) {
  ofstream fout("OUTPUT");
  int n;
  vector<vector<int> > cost_matrix;
  if(argc > 1) {
    ifstream fin(argv[1]);
    fout << "file: " << argv[1] << endl;
    fin>>n;
    for(int i = 0; i < n; i++) {
      cost_matrix.push_back(vector<int>(n));
      for(int j = 0; j < n; j++) {
        fin >> cost_matrix[i][j];
      }
    }
  } else {
    fout << "Please specify a file in the argument that contains the integer n followed by n rows of n integers that represents a cost matrix of a directed graph." << endl;

    fout << "For example: \n";
    fout << 3 << endl;
    fout << "0 20 30\n15 0 15\n70 10 0\n";
    return 1;
  }

  vector<vector<int> > d(n, vector<int>(n)), fw(n, vector<int>(n));

  fout << "Cost Matrix:" << endl;
  write_matrix(cost_matrix, fout);
  fout << endl;

  clock_t dijkstra_begin = clock();
  for(int i = 0; i < n; i++) {
    d[i] = dijkstra(cost_matrix, i);
  }
  clock_t dijkstra_end = clock();
  double dijkstra_time = double(dijkstra_end - dijkstra_begin) / CLOCKS_PER_SEC;

  clock_t fw_begin = clock();
  fw = floydwarshall(cost_matrix);
  clock_t fw_end = clock();
  double fw_time = double(fw_end - fw_begin) / CLOCKS_PER_SEC;

  fout << fixed;
  fout << "Dijkstra -- " << dijkstra_time << " seconds" << endl;
  write_matrix(d, fout);
  fout << endl;

  fout << "Floyd Warshall -- " << fw_time << " seconds" << endl;
  write_matrix(fw, fout);
  fout << endl;

  //fout << dijkstra_time << "," << fw_time << endl;
  return 0;
}
