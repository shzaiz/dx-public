#include <iostream>
#include <cstring>
using namespace std;

#define N 55
#define INF 1000000000

int n, w[N], f[N][N];
int main(){
	cin>>n; 
	for(int i=1; i<=n; i++){cin>>w[i];}
	
	
	for(int len = 3; len <= n; len++){
		for(int l=1; l+len-1<=n; l++){
			int r = l+len-1;
			f[l][r]=INF;
			for(int k=l+1; k<r;k++){
				f[l][r] = min(f[l][r], f[l][k]+f[k][r]+w[l]*w[k]*w[r]);
			}
		}
	}
	
	cout<<f[1][n]<<endl;
	return 0;
}