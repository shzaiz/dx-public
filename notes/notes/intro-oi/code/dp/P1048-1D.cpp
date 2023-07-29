#include <bits/stdc++.h>
using namespace std;
#define MAXN 1010
int N, V, v[MAXN],w[MAXN], dp[MAXN];

int main(){
  cin>>V>>N;
  for(int i=1; i<=N;i++) cin>>v[i]>>w[i];
  for(int i=1; i<=N;i++){
    for(int j = V; j>=v[i]; j--){
      dp[j] = max(dp[j],dp[j-v[i]]+w[i]);
    }
  }
  int ans = -1;
  cout<<dp[V];
}
