#include<iostream>
#include<cstdio>
#include<string>
#include<queue>
using namespace std;
priority_queue<int> q;
int const maxn=100000+10;
int d,n,m,a,b,ind[maxn];
int ok,xb;
int s[maxn];
struct Edge{
    int to,next;
}edge[maxn];
int head[maxn];
int num;
void addEdge(int from ,int to){
    num++;
    edge[num].to=to;
    edge[num].next=head[from];
    head[from]=num;
}
void sort(){
    for(int i=1;i<=n;++i)
        if(ind[i]==0) q.push(i);
    while(!q.empty()){
        int u=q.top();
        s[++xb]=u;
        q.pop();
        for(int i=head[u];i;i=edge[i].next){
            int to=edge[i].to;
            ind[to]--;
            if(ind[to]==0)
               q.push(to);
        }
    }
    return;
}
int main(){
    cin>>d;
    for(int i=1;i<=d;i++){
        cin>>n>>m;
        num=0;ok=0;xb=0;
        for(int j=1;j<=n;j++)
            ind[j]=0,s[j]=0,head[j]=0;
        while(!q.empty()) q.pop();
        for(int j=1;j<=m;j++) {
            cin>>a>>b;
            ind[a]++;
            addEdge(b,a);
        }
        sort();
        for(int j=1;j<=n;j++)
           if(ind[j]!=0){
            ok=1;
            break;
           }
        if(ok==1) cout<<"Impossible!"<<endl;
        else {
            for(int j=xb;j>=1;j--) {
                printf("%d",s[j]);
                cout<<" ";
            }
            cout<<endl;
        } 
    }
}