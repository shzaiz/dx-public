#include <iostream>
#include <vector>
#define N 100010
using namespace std;

int n, m, cnt=0;
bool vis[N];
int head[N], nxt[N], to[N];

// head[u] 和 cnt 的初始值都为 -1
void add(int u, int v) {
  nxt[++cnt] = head[u];  // 当前边的后继
  head[u] = cnt;         // 起点 u 的第一条边
  to[cnt] = v;           // 当前边的终点
}


bool find_edge(int u, int v) {
  for (int i = head[u]; ~i; i = nxt[i]) {  // ~i 表示 i != -1
    if (to[i] == v) {
      return true;
    }
  }
  return false;
}

void dfs(int u) {
  if (vis[u]) return;
  vis[u] = true;
  for (int i = head[u]; ~i; i = nxt[i]) {
  	dfs(to[i]);
  }
  	
}

int main() {
  cin >> n >> m;
  memset(head, -1, sizeof head);
  for (int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    add(u, v);
  }
  dfs(1);

  return 0;
}
