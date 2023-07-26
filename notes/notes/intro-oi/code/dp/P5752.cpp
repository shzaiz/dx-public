#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip>
using namespace std;

#define N 15
#define M 9
#define INF 1000000000

int n, m=8;
double s[M][M];
double f[M][M][M][M][N];
double xbar;

double get(int x1, int y1, int x2, int y2){
	double sum = s[x2][y2]-s[x2][y1-1]-s[x1-1][y2]+s[x1-1][y1-1]-xbar;
	return sum * sum / n;
}

double dp(int x1, int y1, int x2, int y2, int k){
	double &v = f[x1][y1][x2][y2][k];
	if(v>0) return v; // Memorized
	if(k==1) return v = get(x1, y1, x2, y2);
	
	v = INF;
	for(int i=x1; i<x2; i++){
		// Upper
		v = min(v, dp(x1, y1, i, y2, k-1) + get(i+1,y1,x2,y2));
		
		// Lower
		v = min(v, dp(i+1,y1,x2,y2, k-1) + get(x1, y1, i, y2));
	}
	
	for(int i=y1; i<y2; i++){
		// Left
		v = min(v, dp(x1, y1, x2, i, k-1)+get(x1, i+1, x2, y2));
		
		// Right
		v = min(v, dp(x1, i+1, x2, y2, k-1)+get(x1, y1, x2, i));
	}
	return  v;
}

int main(){
	cin>>n;
	for(int i=1; i<=m; i++)
		for(int j=1; j<=m; j++){
			cin>>s[i][j];
			s[i][j] += s[i-1][j] + s[i][j-1] - s[i-1][j-1];
		}
	#define F(i, UP) for(int i=0; i<UP; i++)
	F(i, M) F(j, M) F(k, M) F(l, M) F(q, N) f[i][j][k][l][q] = -1;
	xbar = (double)s[m][m]/n;
	cout<<sqrt(dp(1,1,8,8,n))<<endl;
}