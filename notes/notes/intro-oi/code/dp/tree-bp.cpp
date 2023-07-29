#include <iostream>
using namespace std;
#include <cstring>

#define N 110

int n, m; 
int h[N], e[N], ne[N], idx=0;
int f[N][N];
int v[N], w[N];

void add(int a, int b){
	e[idx]=b, ne[idx]=h[a], h[a]=idx++;
}

void dfs(int u){
	for(int i=h[u]; ~i; i=ne[i]){
		int son = e[i];
		dfs(son);
		
		for(int j = m-v[u]; j>=0; j--){ // V
			for(int k=0; k<=j; k++){
				f[u][j] = max(f[u][j], f[u][j-k]+f[son][k]);
			}
		}
		
		
	}
	for(int i=m; i>=v[u]; i--) f[u][i] = f[u][i-v[u]]+w[u];
	for(int i=0; i<v[u]; i++) f[u][i]=0;
}
int main(){
	cin>>n>>m;
	memset(h, -1, sizeof h);
	int root;
	for(int i=1; i<=n; i++){
		int p;
		cin>>v[i]>>w[i]>>p;
		if(p == -1) root = i;
		else add(p, i);
	}
	dfs(root);
	cout<<f[root][m]<<endl;
	return 0;
}