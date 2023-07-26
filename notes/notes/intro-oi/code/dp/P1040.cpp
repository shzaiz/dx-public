#include <iostream>
#include <cstring>
using namespace std;

#define N 35

int n, w[N], f[N][N], g[N][N];

void dfs(int l, int r){
	// printf(">>%d %d\n", l, r);
	if(l>r) return ;
	int root = g[l][r];
	cout<<root<<" ";
	dfs(l, root-1);
	dfs(root+1, r);
}

int main(){
	cin>>n;
	for(int i=1; i<=n; i++) cin>>w[i];
	for(int len = 1; len<=n; len++){
		for(int l = 1; l +len-1<=n; l++){
			int r = l+len-1;
			if(len == 1) {f[l][r] = w[l]; g[l][r] = l;continue;}
			for(int k=l; k<=r; k++){
				int left = k == l ? 1 : f[l][k - 1];
                int right = k == r ? 1 : f[k + 1][r];
                int score = left * right + w[k];
                if (l == r) score = w[k];
                if (f[l][r] < score){f[l][r] = score;g[l][r] = k;}
			}
			
		}
	}
	cout<<f[1][n]<<endl;
	dfs(1, n);
	cout<<endl;
	return 0;
}