#include <iostream>
using namespace std;
int main(){
    int a, b;
    cin>>a>>b;
    if(a>=b){
        cout<<b<<" is the min of {a,b}\n";
    }else if(b>=a){
        cout<<a<<" is the min of {a,b}\n";
    }
    return 0;
}
