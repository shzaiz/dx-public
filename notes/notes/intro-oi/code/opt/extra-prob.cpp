#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
struct ballList {
	int pos[10];
};
ballList operator - (const ballList A, const ballList B) {
	ballList C, temp;
	for (int i = 0; i < 10; ++i) {
		temp.pos[B.pos[i]] = i;
	}
	for (int i = 0; i < 10; ++i) {
		C.pos[i] = temp.pos[A.pos[i]];
	}
	return C;
}
ostream & operator << (ostream& os, const ballList &ob) {
	for (int i = 0; i < 10; ++i) {
		if (i)os << ' ';
		os << ob.pos[i];
	}
	return os;
}
ballList presum[MAXN];
int n, m, u[MAXN], v[MAXN], l, r;
ballList bf(int l, int r) {
	ballList ret;
	for (int i = 0; i < 10; ++i) {
		ret.pos[i] = i;
	}
	for (int i = l; i <= r; ++i) {
		swap(ret.pos[u[i]], ret.pos[v[i]]);
	}
	return ret;
}

int main()
{
	for (int i = 0; i < 10; ++i) {
		presum->pos[i] = i;
	}
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> u[i] >> v[i];
		presum[i] = presum[i - 1];
		swap(presum[i].pos[u[i]], presum[i].pos[v[i]]);
	}
	for (int i = 1; i <= m; ++i) {
		cin >> l >> r;
		cout << presum[r] - presum[l - 1] << endl;
	}
	return 0;
}
/*

5 3
0 1
1 2
2 3
0 1
9 0
1 5
5 5
3 5




2 1
0 1
0 2
1 2




17 6
0 1
0 5
0 6
0 9
1 5
6 5
7 0
0 1
1 2
2 8
8 3
4 6
3 8
9 1
9 2
0 6
4 5

1 17
5 17
2 13
6 15
3 8
15 17
*/