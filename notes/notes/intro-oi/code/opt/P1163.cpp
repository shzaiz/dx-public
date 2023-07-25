#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
long long n, m, k;

double calc(double p){
    double ans = 0, res = 1.0+p;
    for(int i=1; i<=k; i++){
        ans += m/res;
        res *= (1.0+p);
    }
    return ans;
}

double query(double le, double ri){
    double l = le, r = ri;
    #define mid ((l+r)/2.0)

    for(int i=0; i<10000; i++){
        double hm = calc(mid * 0.01);
        if(hm < (double)n){
            r = mid;
        }else if(hm > (double)n){
            l = mid;
        }else{
            return mid;
        }
    }
    return mid;
}
int main(){
    cin>>n>>m>>k;
    cout<<fixed<<setprecision(1)<<query(0.0, 300.0)<<endl;
    
}