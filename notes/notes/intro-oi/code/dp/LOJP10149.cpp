#include <iostream>
#include <cstring>
using namespace std;

#define N 55
#define M 55
#define INF 1000000000

#define LL long long

int n;
LL w[N], f[N][N][N];

void mul(LL a[], LL b) {
    static LL c[M]; // Use heap memory, can be seen as global
                    // variable, but only can be accessed via 
                    // this block. This is the result. 
    memset(c, 0, sizeof c);
    LL t = 0;

    for (int i = 0; i < M; i++) {
        t += a[i] * b;
        c[i] = t % 10;
        t /= 10;
    }

    memcpy(a, c, sizeof c);
}

void add(LL a[], LL b[]) {
    LL t = 0;

    for (int i = 0; i < M ; i++) {
        t += a[i] + b[i];
        a[i] = t % 10;
        t /= 10;
    }
}

int cmp(LL a[], LL b[]){
	for(int i=M-1; i>=0; i--){
		if(a[i]>b[i]) return 1;
		else if(a[i]<b[i]) return -1;
	}
	return 0;
}

void print(LL a[]){
	int k = M-1;
	while(k && !a[k]) k--;
	while(k>=0) cout<<a[k--];
	cout<<endl;
}

int main(){
	cin>>n; 
	for(int i=1; i<=n; i++){cin>>w[i];}
	
	LL tmp[N];
	for(int len = 3; len <= n; len++){
		for(int l=1; l+len-1<=n; l++){
			int r = l+len-1;
			// f[l][r]=INF;
			f[l][r][M-1] = 1;
			for(int k=l+1; k<r;k++){
				memset(tmp, 0, sizeof tmp);
				// f[l][r] = min(f[l][r], f[l][k]+f[k][r]+w[l]*w[k]*w[r]);
				tmp[0] = w[l];
				mul(tmp, w[k]);
				mul(tmp, w[r]);
				add(tmp, f[l][k]);
				add(tmp, f[k][r]);
				if(cmp(f[l][r], tmp)>0) memcpy(f[l][r], tmp, sizeof tmp);
			}
		}
	}
	
	print(f[1][n]);
	return 0;
}