#include <cstdio> 
#include <cmath>
#include <algorithm>
int f[100001][40],a,x,LC,n,m,p,len,l,r;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){	
        scanf("%d",&a);
        f[i][0]=a;
    }
    LC=(int)(log(n)/log(2)); // log count
    for(int j=1;j<=LC;j++)
        for (int i=1;i<=n-(1<<j)+1;i++)
    		f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&l,&r);
  		p=(int)(log(r-l+1)/log(2));
        printf("%d\n",max(f[l][p],f[r-(1<<p)+1][p]));
    }
    return 0;
}