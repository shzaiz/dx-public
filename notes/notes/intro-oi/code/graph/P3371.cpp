#define MAXN 1001000
#include <bits/stdc++.h>
#include <string.h>
using namespace std;
const int INF = 2147483647;
struct Edge{
	int to,nxt,val;
}edge[MAXN];
int cnt = 0;
int head[MAXN] = {0};
void adde(int u,int v,int vval){
	edge[++cnt].to = v;
	edge[cnt].nxt = head[u];
	edge[cnt].val = vval;
	head[u] = cnt;
}
int vis[MAXN];
int dis[MAXN];
void spfa(int s){
	queue <int>q;
	memset(vis,0,sizeof(vis));
	memset(dis,0x7f,sizeof(dis));
	vis[s]=1,dis[s]=0;
	q.push(s);
	while(!q.empty()){
		int hea=q.front();
		q.pop();
		vis[hea]=0;
		for(int i=head[hea];i;i=edge[i].nxt)
		if(dis[edge[i].to]>dis[hea]+edge[i].val){
			dis[edge[i].to]=dis[hea]+edge[i].val;
			if(!vis[edge[i].to])
				vis[edge[i].to]=1,q.push(edge[i].to);
		}
	}
	return ;
	
}

int main(){
	int n,m,s;
	cin>>n>>m>>s;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		adde(x,y,z);
	}
	spfa(s);
	for(int i=1; i<=n; i++){
		if(s==i) cout<<0<<" ";
      		else if(dis[i]==2139062143) cout<<2147483647<<" ";
			  else cout<<dis[i]<<" ";
	}
	return 0;
    
}