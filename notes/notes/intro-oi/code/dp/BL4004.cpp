#include <iostream>
#include <cstring>
using namespace std;

#define N 10010

int n, m;
int f[N];

int main(){
	cin>>n>>m;
	f[0] = 1;
	while(n--){
		int v1; cin>>v1;
		for(int i=m; i>=v1; i--){
			f[i] += f[i-v1];
		}
	}
	cout<<f[m]<<endl;
	return 0;
}