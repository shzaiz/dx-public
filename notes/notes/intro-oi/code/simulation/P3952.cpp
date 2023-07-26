#include <bits/stdc++.h>
using namespace std; 
#define MAXN 32005
#define F(i, a, b) for(int i=a; i<=b;i++)
#define Fd(i, a, b) for(int i=a;i>=b;i--)
 
void solve();
int main(){
	int T; cin>>T; while(T--) {
		solve();
	}
}
 
vector< vector<int > > vec;
bool used[MAXN];
 
pair<int, int> fact[MAXN];
int skip[MAXN];
int cntf = 0, cnts = 0, factnow = 0, factmx = 0, err=0;
 
 
void solve(){
	memset(used, 0, sizeof used);
	vec.clear();
	cntf = 0, cnts = 0, factnow= 0, factmx =0, err=0;
	int n; string c; cin>>n>>c;
	int ans;
	if(c[2]=='1'){
		ans = 0;
	}else{
		if(c[5] == ')'){
			ans =  c[4]-'0';
		}else{
			ans = (c[4]-'0')*10+(c[5]-'0');
		}
	}
	F(i, 1, n){
		char op=-1, va=0, s[5], e[5];
		cin>>op;
		if(op =='F') {
			scanf(" %c %s %s", &va, s, e);
			int iop, iva, is, ie;
			iop = 1;
			iva = (int) va;
			if(s[0] == 'n') is = 101; else is = atoi(s);
			if(e[0] == 'n') ie = 101; else ie = atoi(e);
			
			
			int exp; 
			if(is > ie) exp = -1;
			else if((is <= 100 && ie <= 100) || is == ie){
				exp = 0;
			}else if(ie == 101){
				exp = 1;
			}else {
				assert(0);
			}
			// printf("Added %d %d %d \n", iop, iva, exp);
			vec.push_back({iop, iva, exp});
		}else{
			// printf("Added %d %d %d\n", 0, 0, 0);
			vec.push_back({0, 0, 0});
		}
	}
	
	F(i, 0, n-1){
		vector<int> line = vec[i];
		#define COEFF line[2]
		#define VAR line[1]
		#define TYPE line[0]
		// printf("Now var= %d\n", VAR);
		if(COEFF == -1){
			skip[++cnts] = 1; 
			while(cnts != 0){
				i++, line = vec[i];
				
				if(i>n) {printf("ERR\n"); return;}
				if(TYPE == 1){
					if(used[VAR]==1){
						printf("ERR\n"); return;
					}else{
						used[VAR]= 1;
					}
					skip[++cnts] = VAR;
				}else if(TYPE == 0){
					used[skip[cnts]] = 0;
					cnts --;
				}else{
					assert(0);
				}
			}
		}else{
			
			if(TYPE == 1){
				if(used[VAR]==1) {
					printf("ERR\n"); return;
				}else{
					used[VAR] = 1;
				}
				fact[++cntf] = {COEFF, VAR};
				factnow += COEFF;
				factmx = max(factmx, factnow);
			}else if(TYPE == 0){
				#define NOWCMP fact[cntf].first
				#define NOWVAR fact[cntf].second
				factnow -= NOWCMP;
				used[NOWVAR] = 0;
				cntf--;
			}
		}
	}
	
	if(cntf != 0 || cnts != 0) {
		cout<<"ERR"<<endl;
		return;
	}
	// cout<<factmx <<endl;
	if(ans == factmx) {
		cout<<"Yes\n";
	}else{
		cout<<"No\n";
	}
}
 