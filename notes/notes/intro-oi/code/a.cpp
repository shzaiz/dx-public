#include <iostream>
using namespace std;
struct selfptr{
    selfptr *selfptr;
};

int main(){
    selfptr s;
    s.selfptr = &s;
}