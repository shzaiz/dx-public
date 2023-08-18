#include <bits/stdc++.h>
using namespace std;
#define fo(i,x) for(int i = 1;i<=x;i++)
#define fo_(i,b,x) for(int i = b;i<=x;i++)
#define re(i,x,b) for(int i = x;i>b;i--)
#define N 1000010
int f[N];
bool ed[N];
int dis[N];
int head[N];
priority_queue <pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > que;
int n,m,b;
int t;
struct edge{
	int to,next,len;
}e[N];
void add(int x,int y,int z){
	e[++t].len=z;
	e[t].to=y;
	e[t].next=head[x];
	head[x]=t;
}
int read(){
	int sum=0;char a=getchar();
	while(a<'0'||a>'9')a=getchar();
	while(a>='0'&&a<='9'){
		sum=(sum<<3)+(sum<<1)+a-'0';
		a=getchar();
	}
	return sum;
}
bool work(int x){
   if(x<f[1])return 0;
	for(int i=1;i<=n;i++){
		dis[i]=1e9;
	}
	memset(ed,0,sizeof(ed));
	dis[1]=0;
	que.push(make_pair(0,1));
	int s1,s2;
	while(que.size()){
		s1=que.top().second;que.pop();
		if(ed[s1])continue;
		ed[s1]=1;
		s2=head[s1];
		while(s2){
			if(f[e[s2].to]<=x&&ed[e[s2].to]==0&&dis[s1]+e[s2].len<dis[e[s2].to])
			{dis[e[s2].to]=dis[s1]+e[s2].len;
			que.push(make_pair(dis[e[s2].to],e[s2].to));}
			s2=e[s2].next;
		}
	}
	if(dis[n]<b){
		return 1;
	}
	return 0;
}
int main(){
	n=read();m=read();b=read();
	for(int i=1;i<=n;i++)
	f[i]=read();//储存费用
	int a1,a2,a3;
	for(int i=1;i<=m;i++){
		a1=read();a2=read();a3=read();
		add(a1,a2,a3);
		add(a2,a1,a3);
	}
	if(work(998244353)==0){
		cout<<"AFK"<<endl;
		return 0; 
	} 
	int l=1,r=998244353,mid=(l+r)>>1;
 	int c;
 	while(l<=r){
 		c=work(mid);
 		if(c){
 			r=mid-1;
 			mid=(l+r)>>1;
		 }
 		else{
 			l=mid+1;
 			mid=(l+r)>>1;
		 }
	 }
	 cout<<l<<endl;
     return 0;
}