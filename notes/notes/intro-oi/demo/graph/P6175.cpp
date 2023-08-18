#include <iostream>
#include <cstring>
using namespace std;
int n,m;
int g[110][110];
int dis[110][110],ans;
int main(){
	cin>>n>>m;
	int a,b,c;
	memset(dis,0x1f,sizeof(dis));
	memset(g,0x1f,sizeof(g));
	for(int i=1;i<=m;i++){
	  	cin>>a>>b>>c;
	  	g[a][b]=g[b][a]=min(g[b][a],c);
	  	dis[a][b]=dis[b][a]=min(dis[b][a],c);
	}
	ans=0x7ffffff;
	for(int k=1;k<=n;k++){
	  	for(int i=1;i<=k-1;i++)
	  	  for(int j=i+1;j<=k-1;j++)
	  	    ans=min(ans,dis[i][j]+g[j][k]+g[k][i]);
	  	for(int i=1;i<=n;i++)
	  	  for(int j=1;j<=n;j++)
	  	    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	}
	if(ans==134217727) cout<<"No solution.";
	else cout<<ans;
	return 0;
}
