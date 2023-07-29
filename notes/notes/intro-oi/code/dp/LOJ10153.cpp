#include <iostream>
#include <cstring>
using namespace std;

#define N 110

int n, m;
int h[N], w[N*2], e[N*2], ne[N*2], idx = 0;
int f[N][N];

void add(int a, int b, int c){
	e[idx] = b; w[idx] = c; ne[idx] = h[a]; h[a] = idx++;
}

void dfs(int u, int fa){
	for(int i=h[u]; ~i; i = ne[i]){ // item group first
		if(e[i]==fa) continue;
		
		dfs(e[i],u);
		// enumerate total V
		for(int j=m; j>=0; j--){
			// enumerate each group, decision
			for(int k = 0; k<j; k++){
				f[u][j] = max(f[u][j], f[u][j-k-1]+f[e[i]][k]+w[i]);
			}
		}
	}
}

int main(){
	cin>>n>>m;
	memset(h, -1, sizeof h);
	for(int i=0; i<n-1; i++){
		int a, b, c; cin>>a>>b>>c;
		add(a, b, c); add(b, a, c);
	}
	dfs(1, -1);
	cout<<f[1][m]<<endl;
}