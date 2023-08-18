#include <iostream>
#include <vector>
#define N 100010
using namespace std;

int n, m;
bool vis[N];
vector<int>  adj[N];

bool find_edge(int u, int v) {
  for (int i = 0; i < adj[u].size(); ++i) {
    if (adj[u][i] == v) {
      return true;
    }
  }
  return false;
}

void dfs(int u) {
  if (vis[u]) return;
  vis[u] = true;
  for (int i = 0; i < adj[u].size(); i++) dfs(adj[u][i]);
}

int main() {
  cin >> n >> m;

  for (int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }
  dfs(1);
  return 0;
}
