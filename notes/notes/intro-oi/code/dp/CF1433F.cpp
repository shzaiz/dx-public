// CF 1433F.
// http://codeforces.com/problemset/problem/1433/F

#include <iostream>
using namespace std;
#define N 75
int a[N][N];
int dp[N][N][N][N];
#define mmax(x,y) (x) = max((x),(y))
int n,m,u,k;
int solve(int i,int j,int mod,int taken) {
	if(dp[i][j][mod][taken]!=-1)return dp[i][j][mod][taken];
	if(i==n)
		return mod?-999999:0;
	if(j==m || taken==m/2)
		return solve(i+1,0,mod,0);
	return dp[i][j][mod][taken]=max(
	solve(i,j+1,mod,taken),a[i][j]+solve(i,j+1,(mod+a[i][j])%k,taken+1));
}

int main() {
	cin>>n>>m>>k;
	memset(dp,-1,sizeof(dp));
	for(int i=0; i<n; ++i)
		for(int j=0; j<m; ++j)
			cin>>a[i][j];
	cout<<solve(0,0,0,0)<<endl;
	return 0;
}
