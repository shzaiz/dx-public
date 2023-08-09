#include <bits/stdc++.h>
using namespace std;
int n,m,z,x,y,fa[10000];
inline int find(int x) {
	while(x!=fa[x]) x=fa[x]=fa[fa[x]];
	return x;
}
int main() {
	cin>>n>>m;
	for(int i=1; i<=n; ++i) {
		fa[i]=i;
	}
	while(m--) {
		cin>>z>>x>>y;
		int a=find(x),b=find(y);
		if(z==1) {
			fa[a]=b;
		}
		if(z==2) {
			if(a==b) {
				puts("Y");
			} else {
				puts("N");
			}
		}
	}
}