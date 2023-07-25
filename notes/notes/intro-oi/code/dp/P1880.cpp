#include <iostream>
#include <cstring>
using namespace std;

#define N 420
#define INF 100000000
//     sum   original mimimals  maximals
int n, s[N], w[N],    f[N][N]  ,g[N][N];

int main(){
	cin>>n;
	// prefix sum
	for(int i=1; i<=n; i++) {cin>>w[i];w[i+n]=w[i];} 
	for(int i=1; i<=n*2; i++) s[i]=s[i-1]+w[i];
	
	memset(f, 0x3f, sizeof f);
	memset(g, -0x3f, sizeof g);
	// length from the shortest to longest
	for(int len=1; len<=n; len++){
		// i is the starting point
		for(int i=1; i+len-1<=2*n; i++){
			// then the l, r can be calculated
			int l=i, r = i+len-1;
			// Base case: If len is 1, then the cost is 0.
			if(len == 1) {f[l][r]=g[l][r]=0; continue;}
			
			// the splitting point
			for(int k=l; k<r; k++){
				f[l][r] = min(f[l][r], f[l][k]+f[k+1][r]+s[r]-s[l-1]);
				g[l][r] = max(g[l][r], g[l][k]+g[k+1][r]+s[r]-s[l-1]);
			}
		}
	}
	
	int mi = INF, ma = -INF;
	for(int i=1; i<=n*2; i++){
		mi = min(mi, f[i][i+n-1]);
		ma = max(ma, g[i][i+n-1]);
	}
	cout<<mi<<endl<<ma<<endl;
	return 0;
	
}
