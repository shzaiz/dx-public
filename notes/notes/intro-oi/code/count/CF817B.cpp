#include <bits/stdc++.h>
using namespace std;
#define MAXN 100010
#define pb push_back
#define LL long long
#define INF 0x3f3f3f3f
#define int unsigned long long
#define fi first
#define se second
#define F(i,j,k) for(int i=j;i<=k;i++)
#define Fs(i,j,k) for(i=j;i<=k;i++)
#define Fd(i,j,k) for(int i=j;i>=k;i--)
#define MOD 1000000007
void solve();
int addm(int a, int b){return (a%MOD+b%MOD)%MOD;}
int subm(int a, int b){return MOD+(a%MOD-b%MOD)%MOD;}
int mulm(int a, int b){return (a%MOD*b%MOD)%MOD;}
int fact[MAXN], infact[MAXN];
 
int qpow(int a, int b, int p){int res = 1;while (b){if (b & 1) res = (LL)res * a % p;a = (LL)a * a % p;b >>= 1;}return res;}
void init(){fact[0] = 1, infact[0] = 1;for (int i = 1; i < MAXN; i++){fact[i] = (LL)fact[i - 1] * i % MOD;infact[i] = (LL)infact[i - 1] * qpow(i, MOD - 2, MOD) % MOD;}}
LL C(int a, int b){return (LL)fact[a] * infact[b] % MOD * infact[a - b] % MOD;}

signed main(){
    init();
    int T=1;while(T--)solve();
}
int a[MAXN];
void solve(){
    
    int n; cin>>n;
    F(i, 1, n) cin>>a[i];
    sort(a+1, a+1+n);
    // F(i, 1, n) cout<<a[i]<<endl;
    int m1=0, m2=0, m3=0;
    int m1n, m2n, m3n;
    m1n = a[1]; m1++;
    int i; 
    Fs(i, 2, n){
        if(a[i] != m1n){break;} 
        m1++;
    }
    m2n = a[i]; m2++;
    Fs(i, i+1, n){
        if(a[i] != m2n){break;} 
        m2++;
    }
    m3n = a[i]; m3++;
    Fs(i, i+1, n){
        if(a[i] != m3n){break;} 
        m3++;
    }
    // printf("%d %d %d\n", m1, m2, m3);

    if(m1 == 1){
        if(m2 == 1){
            printf("%lld", m3);
        }else if(m2==2){
            printf("1");
        }else{
            printf("%lld", m2*(m2-1)/2);
        }
    }else if(m1 == 2){
        printf("%lld", m2);
    }else{
        printf("%lld", m1*(m1-1)*(m1-2)/6);
        return;
    }
    

}