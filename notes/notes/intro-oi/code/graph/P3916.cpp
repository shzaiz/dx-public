#include<iostream>
#include<cstdio>
#define MAXN 500005
using namespace std;
int n,m,tot=0;
int ans[MAXN],head[MAXN];
struct Edge{
	int to, nxt;
}e[MAXN];
void adde(int x, int y){
    
    e[++tot].nxt=head[x];
    head[x]=tot;
    e[tot].to=y;
}
void dfs(int now,int st){
    if(ans[now]) return;
    ans[now]=st;	
    for(int i=head[now];i;i=e[i].nxt)
        if(!ans[e[i].to]) dfs(e[i].to,st);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i){
    	int a, b; cin>>a>>b;
    	adde(b, a);
    }
    for(int i=n;i;--i)dfs(i,i);
    for(int i=1;i<=n;++i)
        printf("%d ",ans[i]);
    return 0;
}