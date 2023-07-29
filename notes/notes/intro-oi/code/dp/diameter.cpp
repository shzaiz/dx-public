#include <iostream>
#include <cstring>
using namespace std;

#define N 10010

int n, happy[N];
int h[N*2], edge[N*2], nxt[N*2], w[N*2], cnt=0;
int ans;
void add(int a, int b, int c){
	edge[cnt] = b;
	nxt[cnt]=h[a];
	w[cnt] = c;
	h[a]=cnt++;
}

int dfs(int u, int fa){
	int dist = 0; // down
	
	int d1 = 0, d2 = 0; // max and next max
	for(int i=h[u]; i!=-1; i=nxt[i]){
		int j = edge[i];
		if(j==fa) continue;
		int d = dfs(j, u)+w[i];
		dist = max(dist, d);
		
		if(d >= d1) {d2=d1, d1 = d;}
		else if(d>d2) d2 = d;
	} 
	ans = max(ans, d1+d2);
	return dist;
}

int main(){
	cin>>n;
	memset(h, -1, sizeof h);
	for(int i=0; i<n-1; i++){
		int a, b, c;
		cin>>a>>b>>c;
		add(a, b, c); add(b, a, c);
	}
	dfs(1, -1);
	cout<<ans<<endl;
}