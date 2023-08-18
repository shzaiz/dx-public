#include <iostream>
#include <vector>
#define MAXN 10007
using namespace std;

struct Edge {
  int u, v;
};

int n, m;
Edge e[MAXN];
bool vis[MAXN];

bool find_edge(int u, int v) {
  for (int i = 1; i <= m; ++i) {
    if (e[i].u == u && e[i].v == v) {
      return true;
    }
  }
  return false;
}

void dfs(int u) {
  if (vis[u]) return;
  vis[u] = true;
  for (int i = 1; i <= m; ++i) {
    if (e[i].u == u) {
      dfs(e[i].v);
    }
  }
}

int main() {
  cin >> n >> m;


  for (int i = 1; i <= m; ++i) cin >> e[i].u >> e[i].v;

  return 0;
}
