/*
������Ϊn�����л���m�β�����
1 l r ѯ������[l,r]�ڵ�Ԫ�غ�
2 l r ѯ������[l,r]�ڵ�Ԫ�ص�ƽ�� ��
3 l r x ������[l,r]�ڵ�ÿһ��Ԫ�ض�����x
4 l r x ������[l,r]�ڵ�ÿһ��Ԫ�ض�����x

��һ��������n,m

������һ��n������ʾ��ʼ����

������m��ÿ�е�һ����Ϊ��������opt��

��opt=1����opt=2����֮������������Ϊl,r

��opt=3����opt=4����֮������������Ϊl,r,x

������˼Ϊ��Ŀ������˵��

����ÿһ������1,2������һ�б�ʾ����
*/
#include <bits/stdc++.h>
#define MAXN 100010
#define F(i, a, b) for(int i=a; i<=b; i++)
#define Fd(i, b, a) for(int i=b; i>=a; i--)
#define ll long long
using namespace std;
struct tnode{
	int l=0, r=0; ll sum[2], lazy[2]; 
};
int a[MAXN];
struct SegTree{
	// x |--> ax+b
	tnode t[MAXN*4];
	void init_lazy(int o){
		#define a t[o].lazy[0]
		#define b t[o].lazy[1]
		a = 1; 
		b = 0;
		#undef a
		#undef b
	}
	
	void union_lazy(int fa, int ch){
		ll tmp[2];
		#define a tmp[0] 
		#define b tmp[1]
		#define a1 t[fa].lazy[0]
		#define b1 t[fa].lazy[1]
		#define a2 t[ch].lazy[0]
		#define b2 t[ch].lazy[1]
		a = a1*a2;
		b = a1*b2+b1;
		a2 = a;
		b2 = b;
		#undef a 
		#undef b
		#undef a1
		#undef a2
		#undef b1
		#undef b2
	}
	
	void cal_lazy(int o){
		#define S_xi t[o].sum[0]
		#define S_xi2 t[o].sum[1]
		#define a t[o].lazy[0]
		#define b t[o].lazy[1]
		#define len (t[o].r - t[o].l+1)
		ll tmp[2];
		tmp[1] = a*a*S_xi2 + 2*a*b*(S_xi) + len*b*b;
		tmp[0] = len*b+a*S_xi;
		S_xi = tmp[0];
		S_xi2 = tmp[1];
		#undef S_xi
		#undef S_xi2
		#undef a
		#undef b
		#undef len
	}
	void push_down(int o){
		if(t[o].lazy[0] != 1 || t[o].lazy[1] != 0){
			cal_lazy(o);
			if(t[o].l != t[o].r){
				int ch = o*2;
				union_lazy(o, ch);
				union_lazy(o, ch+1); 
			}
			init_lazy(o);
		}
	}
	void update(int o){
		int ch = o*2;
		push_down(ch); push_down(ch+1);
		t[o].sum[0] = t[ch].sum[0]+t[ch+1].sum[0];
		t[o].sum[1] = t[ch].sum[1]+t[ch+1].sum[1];
	}
	
	void build(int o, int l, int r){
		t[o].l = l, t[o].r = r;
		init_lazy(o);
		if(l != r){
			int ch = o*2; 
			int mid = (l+r)/2;
			build(ch, l, mid);
			build(ch+1, mid+1, r);
			update(o); 
		}else{
			t[o].sum[0] = a[l];
			t[o].sum[1] = a[l]*a[l];
		}
	}
	
	void change(int o, int l, int r, int delta, int op){
		push_down(o);
		if(l==t[o].l && r== t[o].r) {
			t[o].lazy[op] = delta;
			return;
		}
		int  mid = (t[o].r+t[o].l)/2, ch = o*2;
		if(r<=mid) change(ch, l, r, delta, op);
		else if(mid<l) change(ch+1, l, r, delta, op);
		else{
			change(ch, l, mid, delta, op);
			change(ch+1, mid+1, r, delta, op);
		}
		update(o);
	}
	
	ll sum(int o, int l, int r, int op){
		push_down(o);
		if(t[o].l ==l && r== t[o].r) return t[o].sum[op];
		int ch = o*2, mid = (t[o].r+t[o].l)/2;
		if(r<=mid) return sum(ch, l, r, op);
		else if(mid<l) return sum(ch+1, l, r, op);
		else return sum(ch, l, mid, op)+sum(ch+1, mid+1, r, op);
	}
	
}ST;
int n, m, op, l, r;
long long x;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld", &a[i]);
    }
    ST.build(1, 1, n);
    for (int _ = 1; _ <= m; ++_)
    {
        scanf("%d %d %d", &op, &l, &r);
        if (op >= 3)
        {
            scanf("%lld", &x);
            ST.change(1, l, r, x, op - 3);
        }
        else
        {
            printf("%lld\n", ST.sum(1, l, r, op-1));
        }
    }
    return 0;
}
