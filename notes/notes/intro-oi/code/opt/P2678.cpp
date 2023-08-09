#include <bits/stdc++.h>
const int MAXN =100010;
using namespace std;
int d,n,m;
int a[MAXN],l,r,mid,ans;
bool check(int x){
	int tot = 0;
	int i=0;
	int now = 0;
	while(i<n+1){
		i++;
		if(a[i]-a[now]<x){
			tot++;
		}else now = i;
		
	}
	if(tot>m) return false;
	else return true;
}
int main(){
	cin>>d>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	a[n+1]=d;
	l=1,r=d;
	while(l<=r){
		mid = (l+r)/2;
		if(check(mid)){
			ans = mid ;
			l = mid+1;
		}else{
			r= mid-1;
		}
		
	}
	cout<<ans<<endl;
	return 0;
}