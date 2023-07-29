#include <iostream>
#include <string.h>
using namespace std;
#define N 20010

int n, m;
int f[N], g[N], q[N];

int main(){
	cin>>n>>m;
	for(int i=0; i<n; i++){
		int v, w, s;
		cin>>v>>w>>s;
		memcpy(g, f, sizeof f);
		for(int j=0; j<v; j++){
			int hh = 0, tt = -1;
			for(int k=j; k<=m; k+=v){

				// deque's head and tail
				#define HEAD q[hh]
				#define TAIL q[tt]
				// Head is away from the window? 
				if(hh<=tt && HEAD<k-s*v) hh++;
				if(hh<=tt) f[k] = max(f[k], g[HEAD]+(k-HEAD)/v*w);
				while(hh<=tt && 
					  g[TAIL] - (TAIL-j)/v*w <= g[k]-(k-j)/v*w
					 ) tt--; // The tail is out? 
				q[++tt]=k;  
			}
		}
	}
	cout<<f[m]<<endl;
	return 0;
}