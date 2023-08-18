#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#define endl '\n'
typedef long long ll;
using namespace std;
const int N = 4e4 + 10, mod = 1e9 + 7;
int f[N];
vector<int>v;
int main(){
	string s, t;
	for (int i = 1; i <=40000; i++){
		s = to_string(i);
		t = s;
		reverse(t.begin(), t.end());
		if (s == t) v.push_back(i);
	}
	
	f[0] = 1;
	for (int i = 1; i <= v.size(); i++){
		int m = v[i - 1];
		for (int j = m; j <= 40000; j++){
			f[j] = (f[j]+f[j-m])% mod;
		}
	}
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		cout << f[n] << '\n';
	}

	return 0;
}