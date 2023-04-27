#include <iostream>
using namespace std;
int f(int x){return x*2;}
int g(double x){return x+3.5;}

int main(){
    cout<<f((0.2,1));
    return 0;
}

