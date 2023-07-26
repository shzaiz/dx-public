#include <bits/stdc++.h>
using namespace std;
#define int long long
int cnt = 0;
void msort(int a[], int tmp[], int l, int r){
    if(l>=r) return ;
    int mid = l+r>>1;
    msort(a, tmp, l, mid);
    msort(a, tmp, mid+1, r);
    int i = l, j = mid+1, k=0;
    while(i<=mid && j<=r){
        if(a[i]<=a[j]){
            tmp[k++]=a[i++];
        }else{
            cnt += (mid-i+1);
            tmp[k++]=a[j++];
            
        }
    }
    while(i<=mid) tmp[k++]=a[i++];
    while(j<=r) tmp[k++]=a[j++];
    for(i=l, j=0;i<=r;i++, j++) a[i]=tmp[j];
    
}
#define MAXN 500010
int a[MAXN], tmp[MAXN];
signed main(){
    int n; cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    msort(a, tmp, 1, n);
    cout<<cnt<<endl;
}