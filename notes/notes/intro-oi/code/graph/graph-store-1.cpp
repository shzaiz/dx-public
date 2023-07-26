#include<iostream>
#include<vector>
#include<algorithm>

#define N 1010
using namespace std;

int n,m;
bool a[1010][1010];
vector<int> mp[1010];
int main(){
    cin>>n>>m;
    int p,q;
    for(int i=1;i<=m;i++){
        cin>>p>>q;
        a[p][q]=a[q][p]=true;
        mp[p].push_back(q);
        mp[q].push_back(p);      
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]){
                cout<<"1 ";
            }else{
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
    for(int i=1;i<=n;i++){
        cout<<mp[i].size()<<' ';
        sort(mp[i].begin(),mp[i].end());
        for(auto i:mp[i]){
            cout<<i<<" ";
        }
        printf("\n");
    }
    return  0;
}