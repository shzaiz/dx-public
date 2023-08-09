#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 10010

int a[MAXN], goal[MAXN], tp=0;

void flip(int x){
	for(int l=1, r=x; l<r; l++, r--){
		swap(a[l], a[r]);
	} 
}

bool chk(int tot){
	for(int i=1; i<tot; i++){
		if(a[i] != goal[i]) return false;
	}
	return true;
}

string s; 

void solve(){
	memset(a, 0, sizeof a);
	memset(goal, 0, sizeof a);
	tp = 0;
	
	
	int len = s.length();
	int tmp = 0;
	for(int i=0; i<len; i++){
		if(s[i] == ' '){
			a[++tp] = tmp;
			goal[tp] = tmp;
			cout<<tmp<<' ';
			tmp = 0;
		}else{
			tmp = tmp * 10; 
			tmp += (s[i] - '0');
		}
	}
	a[++tp] = tmp;
	goal[tp] = tmp;
	cout<<tmp<<' ';

	cout<<"\n";
	sort(goal+1, goal+tp+1);
	for(int bk = tp; bk>0; bk--){
		if(a[bk] == goal[bk]) continue;
		int i,j;
		for(i=1,j=bk; j>1; j--,i++){
			// printf("a[%d]=%d, b[%d]=%d\n", j, a[j], bk, goal[bk]);
			if(a[j] == goal[bk]) {
				cout<<tp-j+1<<" "<<tp-bk+1<<" "; flip(j), flip(bk);
				break;
			}
		}
		if(j==1) {cout<<tp-bk+1<<" "; flip(bk);}
		if(chk(tp)) {break;}
	}
	cout<<"0\n";
	
	
	
}

int main(){
	while(getline(cin, s)){
		solve();
	}
	return 0;
}