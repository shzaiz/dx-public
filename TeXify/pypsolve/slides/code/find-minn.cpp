#include <iostream>
using namespace std;
#define MAXN 101
int main(){
    int n;
    int a[MAXN];
    cin>>n;
    int counter = 0;
    while(counter < n){
        cin>>a[counter];
        counter = counter +1;
    }
    counter = 0;
    int mi = INT_MAX;
    while(counter < n){
        if(mi>a[counter]){
            mi = a[counter];
        }
        counter = counter + 1;
    }
    cout<<"The min val is "<< mi<<"\n";
    return 0;
}
