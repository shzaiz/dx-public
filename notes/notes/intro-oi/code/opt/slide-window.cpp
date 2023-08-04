#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000100
// 队列里面存放的是下标
int n,k, a[MAXN], q[MAXN];

int main(){
  scanf("%d%d", &n, &k);
  int hh = 0, tt = -1;
  for(int i=0; i<n;i++){
    scanf("%d", &a[i]);
  }
  for(int i=0; i<n; i++){
    // 判断队头是不是划出了窗口
    if(hh <= tt && i-k+1>q[hh]) hh++;
    while(hh<=tt && a[q[tt]]>=a[i]) tt--;
    q[++tt] = i;
    if(i>=k-1) printf("%d ", a[q[hh]]);
  }
  puts("");
  hh=0, tt=1;
  for(int i=0; i<n; i++){
    // 判断队头是不是划出了窗口
    if(hh <= tt && i-k+1>q[hh]) hh++;
    while(hh<=tt && a[q[tt]]<=a[i]) tt--;
    q[++tt] = i;
    if(i>=k-1) printf("%d ", a[q[hh]]);
  }
  
}