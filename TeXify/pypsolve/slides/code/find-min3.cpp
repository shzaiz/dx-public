#include <iostream>
using namespace std;
int main(){
    int a, b, c;
    cin>>a>>b>>c;
    int mi = INT_MAX;
    if(a>b){
        if(b>c){
            mi = c;
        }else{
            mi = b;
        }
    }else{
        if(a<c){
            mi = a;
        }else{
            mi = c;
        }
    }
    cout<<"The min val is "<<mi<<endl;
    return 0;

}
