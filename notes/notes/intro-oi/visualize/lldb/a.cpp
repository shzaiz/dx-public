#include <iostream>
using namespace std;

int a[20050];

int main(){
    for(int i=1; i<=5; i++){
        for(int j=1; j<=5; j++){
            printf("i=%d, j=%d\n", i, j);
            cout<<a[i+j]<<endl;
        }
    }
    return 0;
}