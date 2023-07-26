#include<cstdio>
#include<iostream>
using namespace std;
double d[10],pi[10];
int main(){
    double d1,c,d2,p,pmin=100,l=0,pz=0;
    int n;
    cin>>d1>>c>>d2>>p>>n;
    d[0]=0;
    double d0=0;
    pi[0]=p;
    double x=c*d2;
    for(int i=1;i<=n;i++){
        cin>>d[i]>>pi[i];
    }
    for(int i=1;i<=n;i++){
        if(d[i]-d[i-1]>x){cout<<"No Solution";return 0;}
    }
    int ii=0;
    while(d1-d0){
        for(int i=ii+1;d[i]-d0<=x&&i<=n;i++){
            if(pi[i]<pmin){
                pmin=pi[i];ii=i;
            }
        }
        if(pmin<=p){
            pz+=((d[ii]-d0)/d2-l)*p;l=(d[ii]-d0)/d2;
        }   
        else if(d1-d0>x){
            pz+=(c-l)*p;
            l=c;
        }
        else{
            pz+=((d1-d0)/d2-l)*p;break; 
        }
        l=l-(d[ii]-d0)/d2;
        d0=d[ii];
        p=pmin;
        pmin=1000;
    }
    printf("%.2lf",pz);
}