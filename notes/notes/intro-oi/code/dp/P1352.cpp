#include <iostream>
#include <cstring>
using namespace std;

#define N 6010

int n, happy[N];
int h[N], edge[N], nxt[N], cnt=0;
int f[N][2];
bool isfa[N];
void add(int a, int b){
	edge[cnt] = b;
	nxt[cnt]=h[a];
	h[a]=cnt++;
}

void dfs(int u){
	f[u][1] = happy[u];
	for(int i=h[u]; i!=-1; i=nxt[i]){
		int j = edge[i];
		dfs(j);
		f[u][0] += max(f[j][0], f[j][1]);
		f[u][1] += f[j][0];
	} 
}

int main(){
	cin>>n;
	for(int i=1; i<=n; i++) cin>>happy[i];
	memset(h, -1, sizeof h);
	for(int i=0; i<n-1; i++){
		int a, b;
		cin>>a>>b;
		isfa[a] = 1;
		add(b, a);
	}
	int root = 1; 
	while(isfa[root]) root++;
	
	dfs(root);
	
	cout<<max(f[root][0], f[root][1])<<endl;
	
}