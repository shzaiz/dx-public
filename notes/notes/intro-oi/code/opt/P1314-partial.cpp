#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define MAXN 200010
int w[MAXN],v[MAXN],l[MAXN],r[MAXN];
ll pren[MAXN],prev[MAXN] ;
ll Y,s,sum;
int n,m,mx = 1,mn = 2147483647;
bool ch(int W){
	ll su = 0;
	for(ll i=1;i<=m;i++){
		ll c = 0;
		ll yi = 0;
		for(ll j=l[i];j<=r[i];j++){
			if(w[j]>=W) {
				c=c+1;
				yi = yi+ v[j];
			}
		}
		yi = yi*c;
		su = su+yi;
	}
	sum = llabs(su-s);
	if(su>s) return 1;
	else return 0;
int main(){
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>w[i]>>v[i];
		mx = max(mx,w[i]);
		mn = min(mn,w[i]);
	}
	for(int i =1;i<=m;i++) cin>>l[i]>>r[i];
	int left = mn-1,right = mx+2,mid;
	ll ans =  0x7fffffffff;
	while(left<=right){
		mid = (left+right)/2;
		if(ch(mid)) left = mid+1;
		else right = mid-1;
		if(sum<ans) ans = sum;
	}
	cout<<ans;
}