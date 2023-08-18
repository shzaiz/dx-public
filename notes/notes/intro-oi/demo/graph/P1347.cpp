#include <bits/stdc++.h>
using namespace std;
#define MAXN 100010
struct Edge{
	int to,nxt;
}e[MAXN];
int cnt=0,head[MAXN],in[MAXN],inn[MAXN],vis[MAXN],p[MAXN];
void adde(int u,int v){
	e[++cnt].to = v;
	e[cnt].nxt = head[u];
	head[u] = cnt;
}
int n,m;
int sum; 
int s;
bool nojudge,v;
queue<int > Q;
int topo(){
	v = false;nojudge = 0,sum=0;
	
	for(int i=1;i<=26;i++){
		inn[i] = in[i];
		if(!inn[i]&& vis[i]){
			if(!v) v = true;
			else nojudge = true;
			Q.push(i);
			p[++sum] = i; // P means the indexes of arrays
			
		}
	}
	if(Q.empty()) return 1;
	while(!Q.empty()){
		int u = Q.front();v = false;Q.pop();
		for(int i = head[u];i;i = e[i].nxt){
			const int w = e[i].to;
			inn[w] --;
			if(!inn[w]){
				Q.push(w);
				
				if(!v) v=true;
				else nojudge = true;
				p[++sum] = w;
			}
			
		}
	}
	if(sum!=s) return 1;
	if(nojudge) return 2;
	return 0;
	
}

int main(){
//	freopen("D:\\in.txt","r",stdin);
	char ch;
	int a,b;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>ch; a = ch-'0'; if(!vis[a]) vis[a] = 1,s++;
		cin>>ch;
		cin>>ch,b=ch-'0';if(!vis[b]) vis[b]=true,s++;
		adde(a,b);
		in[b]++;
		if(topo()==1) return 0*printf("Inconsistency found after %d relations.",i);
		if(sum==n && !topo()){
			printf("Sorted sequence determined after %d relations: ",i);
            for(int j=1;j<=n;j++) printf("%c",p[j]+'0');
            printf(".");
            return 0;
		}
		
	}
	printf("Sorted sequence cannot be determined.");
		return 0;
}