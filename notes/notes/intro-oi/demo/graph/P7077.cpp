#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
using namespace std;

const int N=100005,MOD=998244353;

int n,m,Q;
vector<int> G1[N],G2[N];
int cnt[N];
int data[N],type[N],mul[N],add[N],pos[N];
//data：原序列
//type：操作类型
//mul：记录每个操作执行一次后会把序列乘多少，操作1和3初始化为1，操作2初始化为读入数据、
//add：记录操作1的加数
//pos：记录操作1的操作位置


//用于算出每个函数执行完会将序列乘多少
int deg1[N];
void topo1(){
	queue<int> q;
	for(int i=0;i<=m;++i){
		deg1[i]=G2[i].size();
		if(deg1[i]==0)q.push(i);
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i!=G1[u].size();++i){
			int v=G1[u][i];
			mul[v]=(long long)mul[v]*mul[u]%MOD;
			deg1[v]--;
			if(deg1[v]==0)q.push(v);
		}
	}
}




// 调用次数
int deg2[N];
void topo2(){
	static std::queue<int> q;
	for(int i=0;i<=m;++i)
	{
		deg2[i]=G1[i].size();
		if(deg2[i]==0)q.push(i);
	}
	while(!q.empty())
	{
		int u=q.front();
		int now_mul=1;//当前函数内的乘法标记
		q.pop();
		// 倒着遍历
		for(int i=G2[u].size();i!=0;--i){
			int v=G2[u][i-1];
			cnt[v]=(cnt[v]+(long long)cnt[u]*now_mul)%MOD;
			now_mul=(long long)now_mul*mul[v]%MOD;
			deg2[v]--;
			if(deg2[v]==0)q.push(v);
		}
	}
}




int main(){
	cin>>n;
	for(int i=1;i<=n;++i)cin>>data[i];
	cin>>m;
	mul[0]=1;
	for(int i=1;i<=m;++i){
		cin>>type[i];
		if(type[i]==1){
			cin>>pos[i]>>add[i];
			mul[i]=1;
		}
		if(type[i]==2){
			cin>>mul[i];
		}
		if(type[i]==3){
			mul[i]=1;
			int len;cin>>len;
			for(int j=0;j<len;++j){
				int v;cin>>v;
				G1[v].push_back(i);
				G2[i].push_back(v);
			}
		}
	}
	cin>>Q;
	cnt[0]=1;//把0号函数作为主函数
	for(int i=0;i<Q;++i){
		int x;
		cin>>x;
		G2[0].push_back(x);
		G1[x].push_back(0);
	}
	topo1();
	topo2();
	for(int i=1;i<=n;++i)data[i]=(long long)data[i]*mul[0]%MOD;
	for(int i=1;i<=m;++i){
		if(type[i]==1){
			data[pos[i]]=(data[pos[i]]+(long long)cnt[i]*add[i])%MOD;
		}
	}
	for(int i=1;i<=n;++i){
		printf("%d ",data[i]);
	}
	return 0;
}