#include <iostream>
using namespace std;

using namespace std;
bool isp[100],used[100];
int n,a[100],now;
void dfs(int deep){
    if(deep==n+1&&isp[a[1]+a[n]]){
        rep(i,1,n){
            printf("%d",a[i]);
            if(i!=n)printf(" ");
        }
        puts("");
        return;
    }
    for(int i=2; i<=n; i++){
        if(isp[i+a[deep-1]]&&!used[i]){
            used[i]=true;
            a[deep]=i;
            dfs(deep+1);
            used[i]=false;
        }
    }
}
int main(){
    isp[2]=isp[3]=isp[5]=isp[7]=isp[11]=isp[13]=isp[17]=isp[19]=isp[23]=isp[29]=isp[31]=true; 
    bool isf=false;
    while(~scanf("%d",&n)){
        a[1]=1;
        if(isf)puts("");
        isf=true;
        printf("Case %d:\n",++now);
        memset(used,false,sizeof(used));
        dfs(2);
    }
    return 0;
}