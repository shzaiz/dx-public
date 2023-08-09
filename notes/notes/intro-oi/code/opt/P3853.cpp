#include <iostream>
#include <cmath>
using namespace std;
#define MAXN 100010
int a[MAXN], b[MAXN], f[MAXN],g[MAXN];
int L,n,k;
bool solve(int np){
    int ans=0;
    for(int i=1; i<n; i++) {
        int diff = a[i+1]-a[i]; 
        if(diff >= np){
            ans += floor((double)diff/(double)np); 
            if(diff%np==0) ans-=1;
        }
    }
    if(ans>k) return 0; else return 1;
}
signed main(){
    cin>>L>>n>>k;
    for(int i=1; i<=n; i++) cin>>a[i];
    int l = 1, r=L;
    while(l<r){
        // printf("l=%d, r=%d\n",l,r);
        int mid = (l+r)/2;
        if(solve(mid)==1) r=mid;
        else l=mid+1;
    
    
    
    }
    printf("%d",l);
    return 0;
}