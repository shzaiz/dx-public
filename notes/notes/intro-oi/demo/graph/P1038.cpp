#include <iostream>
using namespace std;
struct Edge {
	int next,to,d;
} e[10010];
int head[10010],c[10010],u[10010],st[10010];
int cnt = 0,top=0;
int ind[10010],outd[10010];
void adde(int from,int to,int dis) {
	e[++cnt].next = head[from];
	e[cnt].to = to;
	e[cnt].d=dis;
	head[from]=cnt;
}

int main(){
	int n,p;
	cin>>n>>p;
	for(int i=1;i<=n;i++){
		cin>>c[i]>>u[i];
		if(c[i]>0) st[++top]=i;
	}
	for(int i=1;i<=p;i++){
		int x,y,d;
		cin>>x>>y>>d;
		adde(x,y,d);
		ind[y]++;
		outd[x]++;
	}
	while(top>0){
		int x=st[top--];
		for(int i=head[x];i;i=e[i].next){
			ind[e[i].to]--;
			if(c[x]>0) c[e[i].to] += e[i].d*c[x];
			if(ind[e[i].to]==0){
				st[++top] =e[i].to;
				c[e[i].to] -=u[e[i].to];
			}
		}
	}
	
	bool active = false;
	for(int i=1;i<=n;i++){
		if(outd[i]==0&&c[i]>0) cout<<i<<" "<<c[i]<<endl,active=1;
		
	}
	if(!active) cout<<"NULL"<<endl;
}
