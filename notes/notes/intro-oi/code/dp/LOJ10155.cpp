#include <iostream>
#include <cstring>
#define N 50010
using namespace std;

int n; 
int h[N], e[N], ne[N], idx=0, ans = 0;
int sum[N];
bool root[N];

void add(int a, int b){
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int dfs(int u){
	int d1 = 0, d2 = 0;
	for(int i=h[u]; i!=-1; i = ne[i]){
		int j = e[i];
		int d = dfs(j) + 1;
		
		if(d>=d1)d2=d1, d1=d;
		else if(d>d2) d2 = d;
	}
	ans = max(ans, d1+d2);
	return d1;
}

int main(){
	cin>>n;
	for(int i=1; i<=n; i++){
		for(int j=2; j<=n/i; j++){
			sum[i*j] += i;
		}
	}
	
	memset(h, -1, sizeof h);
	for(int i=2; i<=n; i++){
		if(i>sum[i]){ add(sum[i], i); root[i] = true;}
	}
	
	for(int i=1; i<=n; i++){
		if(!root[i]) dfs(i);
	}
	
	cout<<ans<<endl;
}
