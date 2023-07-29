#include <iostream>
#include <cstring>
using namespace std;

#define N 1550
#define INF 100000000

int n, m;
int h[N], w[N], e[N], ne[N], idx = 0;
int f[N][3];
bool st[N];

void add(int a, int b){
	e[idx] = b; ne[idx] = h[a]; h[a] = idx++;
}

void dfs(int u){
	f[u][2] = w[u];
	for(int i=h[u]; ~i; i = ne[i]){ // item group first
		int j = e[i];
		
		dfs(j);
		f[u][0] += min(f[j][1], f[j][2]);
		f[u][2] += min(min(f[j][0], f[j][1]), f[j][2]); 
	}
	f[u][1] = INF;
	for(int i=h[u]; ~i; i = ne[i]){
		int j = e[i];
		f[u][1] = min(f[u][1], f[j][2]+f[u][0]-min(f[j][1], f[j][2]));
	}
}

int main(){
	cin>>n;
	memset(h, -1, sizeof h);
	for(int i=1; i<=n; i++){
		int id, cost, ct;
		cin>>id>>cost>>ct;
		w[id] = cost;
		while(ct--){
			int v;
			cin>>v;
			add(id, v);
			st[v] = 1;
		}
	}
	int root = 1;
	while(st[root]) root++;
	dfs(root);
	cout<<min(f[root][1], f[root][2])<<endl;
}