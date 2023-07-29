#include <iostream>
using namespace std;

const int N = 1500 + 5;

int n, num;
int head[N], f[N][2];

struct node {
    int to, Next;
} edge[N << 1];


 void adde(int x, int y){
    edge[++num].to = y;
    edge[num].Next = head[x];
    head[x] = num;
}

 void dfs(int u, int fa){
    f[u][1] = 1, f[u][0] = 0;
    for (int i = head[u]; i; i = edge[i].Next) {
        int v = edge[i].to;
        if (v == fa) continue;
        dfs(v, u);
        f[u][0] += f[v][1];
        f[u][1] += min(f[v][0], f[v][1]);
    }
}

int main(){
    cin>>n;
    for (int i = 1; i <= n; i++) {
        int u, k; cin>>u; u++; cin>>k;
        for (int j = 1; j <= k; j++) {
            int v; cin>>v; v++;
            adde(u, v);
            adde(v, u);
        }
    }
    dfs(1, 0);
    printf("%d", min(f[1][0], f[1][1]));
    return 0;
}