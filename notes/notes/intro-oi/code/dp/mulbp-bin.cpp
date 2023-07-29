#include <bits/stdc++.h>
using namespace std;
#define MAXN 100010
int N, V;
int v1[MAXN], w1[MAXN], s1[MAXN];
int v[MAXN], w[MAXN], dp[MAXN], cnt = 0;

int main(){
  cin>>N>>V;
  for(int i=1; i<=N; i++){
    cin>>v1[i]>>w1[i]>>s1[i];
  }
  
  for(int i=1; i<=N; i++){
    int k = 1;
    while(s1[i] >= k){
      cnt ++;
      v[cnt] = v1[i] * k;
      w[cnt] = w1[i] * k;
      s1[i] -= k;
      k *= 2;
    }
  
    if(s1[i]){
        cnt ++;
        v[cnt] =  v1[i] * s1[i];
        w[cnt] = w1[i] * s1[i];
    }
  }
  
  for(int i=1; i<=cnt; i++){
    for(int j=V;j>=v[i];j--){
      dp[j] = max(dp[j],dp[j-v[i]]+w[i]);
    }
  }
  
  cout<<dp[V]<<endl;
  
}