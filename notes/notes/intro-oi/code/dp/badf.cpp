#include <iostream>
using namespace std;

#define N 505

int n,c;
int pos[N], w[N];
int sw[N];
int f[N][N][2];

#define sum(which, left, right) (which[right] - which[left-1])

int main(){
	cin>>n>>c;
	for(int i=1; i<=n; i++){
		cin>>pos[i]>>w[i];
	}
	for(int i=1; i<=n; i++){
		sw[i] = sw[i-1] + w[i];
	}
	memset(f, 0x3f, sizeof f);
	for(int len = 1; len<=n; len++){
		for(int i=1; i+len-1<=n; i++){
			int l=i, r=i+len-1;
			if(len == 1) {f[l][r][0] = f[l][r][1] = 0; continue;}
			for(int k = l+1; k<=r; k++){

				f[l][r][0] = min(
					f[k][r][0] + f[l][k-1][0] + sum(pos, k, k)*sum(sw, l, k-1),
					f[k][r][1] + f[l][k-1][0] + (2*sum(pos, k, r)+sum(pos, k+1, k))*sum(sw, l, k-1)
				);
				
				f[l][r][1] = min(
					f[k][r][1] + f[l][k-1][1] + sum(pos, k, k)*sum(sw, k, r),
					f[k][r][1] + f[l][k-1][0] + (2*sum(pos, l, k)+sum(pos, k+1, k))*sum(sw, k, r)
				);
				printf("f[%d][%d][%d]=%d, f[%d][%d][%d]=%d\n", l, r, 0, f[l][r][0], l, r, 1, f[l][r][1]);
			}
		}
	}
	cout<<f[1][n][0]<<" "<<f[1][n][1];
	
}