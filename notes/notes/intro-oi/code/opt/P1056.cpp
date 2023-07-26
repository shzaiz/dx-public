#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std; 
int m,n,k,l,d;
int x[1005],y[1005];
int c[1005],o[1005];
int main() {
    cin>>m>>n>>k>>l>>d; 
    for(int i=1;i<=d;i++) { 
        int xi,yi,pi,qi; 
        cin>>xi>>yi>>pi>>qi;
        if(xi==pi) 
            x[min(yi,qi)]++;
        else 
            y[min(xi,pi)]++;
    } 
    for(int i=1;i<=k;i++){
        int maxn=-1;
        int p; 
        for(int j=1;j<m;j++){ 
            if(y[j]>maxn){ 
                maxn=y[j]; 
                p=j; 
            } 
        } 
        y[p]=0;c[p]++;
    } 
    for(int i=1;i<=l;i++){ 
        int maxn=-1; 
        int p; 
        for(int j=1;j<n;j++){ 
            if(x[j]>maxn){ 
                maxn=x[j]; 
                p=j; 
            } 
        } 
        x[p]=0; 
        o[p]++; 
    }
    for(int i=0;i<1005;i++)
    { 
        if(c[i])
            cout<<i<<" ";
    } 
    cout<<endl;
    for(int i=0;i<1005;i++) 
    { 
        if(o[i]) 
            cout<<i<<" ";
    } 
}