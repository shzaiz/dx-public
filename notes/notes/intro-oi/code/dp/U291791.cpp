#include <iostream>
#include <cstring>
using namespace std;

#define N 50
#define M 160

int n, m, k;
int f[N][M];

int main(){
	cin>>n>>m>>k;
	memset(f, 0x3f, sizeof f);
	f[0][0] = 0;
	while(k--){
		int v1, v2, w; cin>>v1>>v2>>w;
		for(int i=N-1; i>=0; i--){
			for(int j = M-1; j>=0; j--){
				f[i][j] = min(f[i][j], f[max(0, i-v1)][max(0, j-v2)]+w);
			}
		}
	}
	int res = 1e9;
	for(int i=n; i<N; i++)
		for(int j=m; j<M; j++)
			res = min(res, f[i][j]);
	cout<<res<<endl;
	return 0;
}