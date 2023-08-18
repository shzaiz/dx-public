#include <bits/stdc++.h>
using namespace std;
#define MAXN 105
#define F(i, j, k) for(int i = j; i <= k; i ++)
#define Fd(i, j, k) for(int i = j; i >= k; i --)

int n, m; 
int f[MAXN], v[MAXN], w[MAXN];
int main(){
	cin>>n>>m;
	F(i, 1, n){
		int s; cin>>s;
		F(j, 1, s)cin>>v[j]>>w[j];
		Fd(j, m, 0
		  F(k, 1, s)
		    if(j-v[k]>=0)
		      f[j] = max(f[j], f[j-v[k]]+w[k]);
	}
	cout<<f[m]<<endl;
}