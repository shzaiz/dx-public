#include <iostream>
using namespace std;
int f[24][12][12],w[12][12];
int n,x,y,z;
int main() {
    cin>>n;
    int a, b, c;
    while(cin>>a>>b>>c, a||b||c) w[a][b] = c;
    for(int k=2; k<=n+n; k++){
        for(int i1=1; i1<=n; i1++){
            for(int i2=1; i2<=n; i2++){
                int j1 = k-i1, j2 = k-i2;
                if(j1>=1 && j1<=n && j2>=1 && j2<=n){
                    int t = w[i1][j1];
                    if(i1 != i2) t+= w[i2][j2];

                    // int &x = f[k][i1][i2];
                    // DD
                    f[k][i1][i2] = max(f[k][i1][i2], f[k-1][i1-1][i2-1]+t);

                    //DR
                    f[k][i1][i2] = max(f[k][i1][i2], f[k-1][i1-1][i2]+t);

                    //RD
                    f[k][i1][i2] = max(f[k][i1][i2], f[k-1][i1][i2-1]+t);

                    //RR
                    f[k][i1][i2] = max(f[k][i1][i2], f[k-1][i1][i2]+t);
                }
            }
        }
    }

    cout<<f[n+n][n][n];
    return 0;

}