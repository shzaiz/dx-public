#include<cstdio>
#include<cstring>
#include<queue>
#define inf 0x3f3f3f3f
using namespace std;
const int MAXN=2010;
const int MAXM=3010;
int n,m;
int en=-1,eh[MAXN];
struct edge{
	int u,v,w,next;
	edge(int U=0,int V=0,int W=0,int N=0):u(U),v(V),w(W),next(N){}
};
edge e[MAXM<<1];
inline void add_edge(int u,int v,int w){
	e[++en]=edge(u,v,w,eh[u]);eh[u]=en;
}
void input(){
	scanf("%d %d",&n,&m);
	en=-1;
	memset(eh,-1,sizeof(eh));
	int u,v,w;
	for(int i=1;i<=m;++i){
		scanf("%d %d %d",&u,&v,&w);
		add_edge(u,v,w);
		if(w>=0)add_edge(v,u,w);
	}
}

int dis[MAXN],cnt[MAXN];
bool vis[MAXN];
queue<int> q;
void spfa(){
	fill(dis+1,dis+n+1,inf);
	memset(cnt,0,sizeof(cnt));
	memset(vis,0,sizeof(vis));
	while(!q.empty())q.pop();
	dis[1]=0;vis[1]=1;q.push(1);
	int u,v,w;
	while(!q.empty()){
		u=q.front();vis[u]=0;q.pop();
		for(int i=eh[u];i!=-1;i=e[i].next){
			v=e[i].v;w=e[i].w;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				if(!vis[v]){
					if(++cnt[v]>=n){
						printf("YES\n");return;
					}
					vis[v]=1;q.push(v);
				}
			}
		}
	}
	printf("NO\n");
}

int main()
{
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;++i){
		input();
		spfa();
	}
	return 0;
}