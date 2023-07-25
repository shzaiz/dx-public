#include <iostream>
using namespace std;

#define N 310
#define INF 100000000
//     sum   state array
int n, s[N], f[N][N];

int main(){
	cin>>n;
	// prefix sum
	for(int i=1; i<=n; i++) cin>>s[i];
	for(int i=1; i<=n; i++) s[i]+=s[i-1];
	
	// length from the shortest to longest
	for(int len=1; len<=n; len++){
		// i is the starting point
		for(int i=1; i+len-1<=n; i++){
			// then the l, r can be calculated
			int l=i, r = i+len-1;
			// Base case: If len is 1, then the cost is 0.
			if(len == 1) continue;
			f[l][r] = INF;
			// the splitting point
			for(int k=l; k<r; k++){
				f[l][r] = min(f[l][r], f[l][k]+f[k+1][r]+s[r]-s[l-1]);
			}
		}
	}
	
	cout<<f[1][n]<<endl;
	
}
