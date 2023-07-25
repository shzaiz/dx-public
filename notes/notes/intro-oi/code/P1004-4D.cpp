#include <iostream>
using namespace std;
int f[12][12][12][12],a[12][12];
int n,x,y,z;
int main() {
    cin>>n>>x>>y>>z;
    while(x!=0||y!=0||z!=0){
        a[x][y]=z;
        cin>>x>>y>>z;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                for(int l=1;l<=n;l++){
                    f[i][j][k][l]=max(max(f[i-1][j][k-1][l],f[i-1][j][k][l-1]),max(f[i][j-1][k-1][l],f[i][j-1][k][l-1]))+a[i][j]+a[k][l];
                    if(i==k&&l==j)f[i][j][k][l]-=a[i][j];
                }
            }
        }
    }
    cout<<f[n][n][n][n];
}