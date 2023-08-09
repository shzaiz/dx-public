#include <bits/stdc++.h>
#define fo(i,x) for(int i = 1;i<=x;i++)
#define fo_(i,a,b) for(int i = a;i<=b;i++)
#define rep(i,b,a) for(int i = b;i>=a;i--)
#define fl(x) freopen("#x.in","r",stdin);freopen("#x.out","w",stdout)
#define mod 1000000007
#define int long long
using namespace std;
struct Matrix {
    int a[3][3];
    Matrix() { memset(a, 0, sizeof a); } // 构造函数，矩阵初始化全零
    Matrix operator*(const Matrix &b) const {
        Matrix res;
        for (int i = 0; i <= 1; ++i)
            for (int j = 0; j <= 1; ++j)
                for (int k = 0; k <= 1; ++k)
                    res.a[i][j] = (res.a[i][j] + a[i][k] * b.a[k][j]) % mod;
        return res;
    }
} ans, base;

void qp(int b){
	while(b){
		if(b&1) ans = ans*base;
		base=base*base;
		b>>=1;
	}
}
int n;
signed main(){
	cin>>n;
	n = n+1;

	if(n<=2){
		cout<<"1";
		return 0;
	}
	base.a[0][0] = base.a[0][1] = base.a[1][0] = 1;
    ans.a[0][0] = ans.a[1][1] = 1;
	qp(n-2);
	cout<<ans.a[0][0];
	return 0;
}