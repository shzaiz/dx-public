#include <iostream>
using namespace std;
#define LL long long
int n , m;

int gcd(int a , int b){
    return b ? gcd(b , a % b) : a;
}
LL C(int a){
    return (LL)a * (a - 1) * (a - 2) / 6;
}
int main(){
    cin >> n >> m;
    n++ , m++;
    LL res = C(n * m) - n * C(m) - m * C(n);
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= m ; j++)
            res -= 2ll * (gcd(i , j) - 1) * (n - i) * (m - j);
    cout << res << endl;
    return 0;
}
