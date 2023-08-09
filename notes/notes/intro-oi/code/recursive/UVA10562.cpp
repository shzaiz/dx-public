#include <iostream>
#include <string>
using namespace std;
const int maxn = 200 + 10;
string tree[maxn];
int t;

void print(int r,int c){
    cout << tree[r][c] << '(';
    if(tree[r+1][c] == '|' && r+1<t){
        int j = c;
        while(j-1>=0&&tree[r+2][j-1]=='-'){
            j--;
        }
        while(j<tree[r+2].length()&&tree[r+2][j]=='-'){
            if(tree[r+3][j] != ' ' && j<tree[r+3].length() && j>=0){
                //cout << r+3 << ',' << j;
                print(r+3,j);
            }
            j++;
        }
    }
    cout << ')';
}

int main(){
    int n = 0;
    cin >> n;
    cin.get();
    string temp;
    while(n--){
        t = 0;
        while(getline(cin,temp) && temp!="#"){
            tree[t++] = temp;
        }
        cout << '(';
        if(tree[0][tree[0].length()-1] != ' ' && t > 0){
            print(0,tree[0].length()-1);
        }
        cout << ")\n";
    }
    return 0;
}