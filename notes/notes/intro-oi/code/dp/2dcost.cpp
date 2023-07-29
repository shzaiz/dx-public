#include <iostream>
using namespace std;

#define N 1050
#define M 505

int n, v1, v2;
int f[N][M];


int main(){
	cin>>v1>>v2>>n;
	
	for(int i=0; i<n; i++){
		int vx, vy; cin>>vx>>vy;
		for(int j=v1;j>=vx; j--){
			for(int k=v2;k>vy;k--){
				f[j][k] = max(f[j][k], f[j-vx][k-vy]+1);
			}
		}
	}
	cout<<f[v1][v2]<<' ';
	int k = v2;
	while(k>0 && f[v1][k] == f[v1][v2]) k--;
	cout<<v2-k<<endl;
	return 0;
}