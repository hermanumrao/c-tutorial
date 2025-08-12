#include <bits/stdc++.h>
using namespace std;

struct graph {
  int ar_len;
  bool **mtrx;
};

graph *create_graph(int l) {
  graph *g1 = new graph();
  g1->ar_len = l;
  g1->mtrx = new bool *[l];
  for (int i = 0; i < l; i++) {
    g1->mtrx[i] = new bool[l];
  }
  for (int i = 0; i < l; i++)
    for (int j = 0; j < l; j++)
      g1->mtrx[i][j] = false;
  return g1;
}

void dsp_matrix(bool **m) {
  int l = 6; // sizeof(m)/sizeof(m[0]);
  cout << l << endl;
  for (int i = 0; i < l; i++) {
    for (int j = 0; j < l; j++) {
      if (m[i][j] == true)
        cout << "X  ";
      else
        cout << "_  ";
    }
    cout << endl;
  }
}

void link_undirected(graph *G, int a, int b, bool x = true) // a<-->b
{
  G->mtrx[a][b] = x;
  G->mtrx[b][a] = x;
}

void link_directed(graph *G, int a, int b, bool x = true) // a->b
{
  G->mtrx[a][b] = x;
}

void dsp_graph(graph *G, char *ar) {
  int l = G->ar_len;
  for (int i = 0; i < l; i++)
    for (int j = 0; j < l; j++)
      if (G->mtrx[i][j] == true)
        cout << ar[i] << "-->" << ar[j] << endl;
}

int main() {
  char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
  graph *G = create_graph(sizeof(arr) / sizeof(arr[0]));
  dsp_matrix(G->mtrx);
  link_directed(G, 3, 4);   // creates link d-->e
  link_undirected(G, 2, 3); // creates link c<-->d
  dsp_matrix(G->mtrx);
  dsp_graph(G, arr);
  return 0;
}
