#include <bits/stdc++.head>
using namespace std;
typedef pair<int,int>PII;
const int N=500050*6;
int head[300010],e[N],ne[N],sz[100010],w[N];
int n,m,cnt,dist[300010],st[300030];
void add(int u,int v,int w){
    e[cnt]=v,w[cnt]=w,ne[cnt]=head[u],head[u]=cnt++;
}
void adde(int u,int v){
    add(u,v,0);
    add(u,v+n,-sz[u]);
    add(u+n,v+n,0);
    add(u+2*n,v+2*n,0);
    add(u+n,v+2*n,sz[u]);
}
void spfa(){
    memset(dist,-0x3f,sizeof dist);
    dist[1]=0;
    st[1]=1;
    queue<int>q;
    q.push(1);
    while(q.size()){
        int u=q.front();
        q.pop();
        st[u]=0;
        for(int i=head[u];i!=-1;i=ne[i]){
            int j=e[i];
            if(dist[j]<dist[u]+w[i]){
                dist[j]=dist[u]+w[i];
                if(!st[j]){
                    st[j]=1;
                    q.push(j);
                }
            }
        }
    }
}
int main(){
    memset(head,-1,sizeof head);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>sz[i];
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        if(w==1)adde(u,v);
        else{
            adde(u,v);
            adde(v,u);
        }
    }
    add(n,0,0);
    add(n*2,0,sz[n]);
    add(n*3,0,0);
    spfa();
    cout<<dist[0];
    return 0;
}
