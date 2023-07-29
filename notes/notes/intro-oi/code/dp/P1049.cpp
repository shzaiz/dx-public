#include <iostream>
using namespace std;

#define N 20004

int m, n;
int f[N];
int main(){
	cin>>m>>n;
	for(int i=0; i<n; i++){
		int v; cin>>v;
		for(int j=m; j>=v; j--)
			f[j] = max(f[j],f[j-v]+v);
	}
	cout<<m-f[m]<<endl;
	return 0;
}