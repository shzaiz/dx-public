#include <bits/stdc++.h>
using namespace std;
struct edge{
	int to,next,weight;
}a[6000060];
struct node{
	int dist,id;
	node(){}
	node(int dist,int id):dist(dist),id(id){}
};
bool operator <(node xi,node yi){
	return xi.dist>yi.dist;
}
int n,m,k;
int s,t;
int x,y,w;
int cnt(0);
int head[1000010];
int vis[1000010];
int dist[1000010];
void addedge(int xi,int yi,int wi){
	a[cnt].to=yi;
	a[cnt].next=head[xi];
	a[cnt].weight=wi;
	head[xi]=cnt++;
}
void dijkstra(int s){
	memset(vis,0,sizeof(vis));
	memset(dist,INF,sizeof(dist));
	priority_queue<node> q;
	q.push(node(0,s));
	dist[s]=0;
	while(!q.empty()){
		node t(q.top());
		q.pop();
		if(vis[t.id])continue;
		vis[t.id]=1;
		for(int i=head[t.id];i!=-1;i=a[i].next){
			int v=a[i].to;
			if(dist[v]>a[i].weight+t.dist){
				dist[v]=a[i].weight+t.dist;
				q.push(node(dist[v],v));
			}
		}
	}
}
int main(){
	memset(head,-1,sizeof(head));
	scanf("%d%d%d",&n,&m,&k);
	scanf("%d%d",&s,&t);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&w);
		addedge(x,y,w);
		addedge(y,x,w);
		for(int j=1;j<=k;j++){
			addedge(x+(j*n),y+(j*n),w);
			addedge(y+(j*n),x+(j*n),w);
			addedge(x+((j-1)*n),y+(j*n),0);
			addedge(y+((j-1)*n),x+(j*n),0);
		}
	}
	for(int i=1;i<=k;i++)
		addedge(t+(i-1)*n,t+i*n,0);
	dijkstra(s);
	printf("%d",dist[t+k*n]);
	return 0;
}