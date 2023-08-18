#include<bits/stdc++.h>
using namespace std;
const int N=10000011;
const int mod=80112002;
queue<int> q; 
int d[N],in[N],eat[N],head[N];
int n,m,tot,ans;
struct E{
    int to,nxt;
}e[N];
inline void add(int u,int v){
    e[++tot].to=v;
    e[tot].nxt=head[u];
    head[u]=tot;
}
inline void topo(){
    for(int i=1;i<=n;i++){
        if(in[i]==0){
            q.push(i);
            d[i]++;
        }
    }


    while(!q.empty()){
        int p=q.front();
        q.pop();
        for(int i=head[p];i;i=e[i].nxt){
            int go=e[i].to;
            d[go]=(d[go]+d[p])%mod;
            in[go]--;
            if(in[go]==0)
            q.push(go);
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        add(a,b);
        in[b]++;
        eat[a]++;
    }
    topo(); 
    for(int i=1;i<=n;i++){
        if(eat[i]==0)
        ans=(ans+d[i])%mod;
    }
    cout<<ans;
}