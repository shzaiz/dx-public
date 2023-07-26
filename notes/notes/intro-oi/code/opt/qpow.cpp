#include <iostream>
#include<cstdio>
using namespace std;
LL B,P,K;

LL qpow(int base,int p){
    LL ans=1,tmp=base;
    while(p!=0){
        if(p&1){
            ans=(ans%K*tmp%K)%K;
        } 
        tmp=(tmp%K*tmp%K)%K;
        p=p/2;
    } 
    ans=ans%K;
    return ans;
} 
int main(){
    cin>>B>>P>>K;
    LL ans=qpow(B,P);
    ans=ans%K;
    printf("%lld^%lld mod %lld=%lld",B,P,K,ans);
	return 0;
}