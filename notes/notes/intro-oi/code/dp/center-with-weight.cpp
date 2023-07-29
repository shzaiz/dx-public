#include <iostream>
#include <cstring>
using namespace std;

#define N 100010
#define INF 0x3f3f3f3f

int n, happy[N];
int h[N*2], edge[N*2], nxt[N*2], w[N*2], cnt=0;
int d1[N], d2[N], frm1[N], frm2[N], up[N]; // max and next max routine, up max routine
int ans;
void add(int a, int b, int c){
	edge[cnt] = b;
	nxt[cnt]=h[a];
	w[cnt] = c;
	h[a]=cnt++;
}

int dfs_d(int u, int fa){
	
	d1[u] = 0, d2[u] = 0; // max and next max
	for(int i=h[u]; i!=-1; i=nxt[i]){
		int j = edge[i];
		if(j==fa) continue;
		int d = dfs_d(j, u)+w[i];
		
		if(d >= d1[u]) {d2[u]=d1[u], d1[u] = d; frm2[u] = frm1[u], frm1[u]=j;}
		else if(d>d2[u]) d2[u] = d, frm2[u]=j;
	} 
	
	// if(d1[u] == -INF) d1[u] = d2[u] = 0;
	
	return d1[u];
}

void dfs_u(int u, int fa){
	for(int i=h[u]; i!=-1; i = nxt[i]){
		int j = edge[i];
		if(j==fa) continue;
		
		if(frm1[u] == j) up[j] = max(up[u], d2[u])+w[i];
		else up[j] = max(up[u], d1[u])+w[i];
		
		dfs_u(j, u);
	}
}

int main(){
	cin>>n;
	memset(h, -1, sizeof h);
	for(int i=0; i<n-1; i++){
		int a, b, c;
		cin>>a>>b>>c;
		add(a, b, c); add(b, a, c);
	}
	dfs_d(1, -1);
	dfs_u(1, -1);
	int res = INF;
	for(int i=1; i<=n; i++) res = min(res, max(d1[i], up[i]));
	cout<<res<<endl;
}