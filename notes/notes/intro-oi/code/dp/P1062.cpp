#include <iostream>
#include <cstring>
using namespace std;

#define N 220

int n, w[N], f[N][N];
int main(){
	cin>>n; 
	for(int i=1; i<=n; i++){cin>>w[i]; w[i+n] = w[i];}
	
	
	for(int len = 3; len <= n+1; len++){
		for(int l=1; l+len-1<=n*2; l++){
			int r = l+len-1;
			for(int k=l+1; k<r;k++){
				f[l][r] = max(f[l][r], f[l][k]+f[k][r]+w[l]*w[k]*w[r]);
			}
		}
	}
	
	int res = 0;
	for(int i=1; i<=n; i++) res = max(res, f[i][i+n]);
	cout<<res<<endl;
}