#include <iostream>
using namespace std;

#define N 105
#define M 1005
// weight value
int w[N], v[N];
int f[N][M];

int main(){
	int t, m;
	cin>>t>>m;
	for(int i=1;i<=m;i++){
		cin>>w[i]>>v[i];
    }
	for(int i=1; i<=m; i++){
		for(int j=0; j<=t; j++){
			if(j>=w[i])
				f[i][j] = max(f[i-1][j-w[i]]+v[i], f[i-1][j]);
			else
				f[i][j] = f[i-1][j];
		}
	}
	cout<<f[m][t]<<endl;
	return 0;
}