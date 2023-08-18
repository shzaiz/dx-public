#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 666;
typedef long long ll;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

struct Fra
{
    ll p, q;
    Fra(ll x = 0, ll y = 1) : p(x), q(y) { normal(p, q); }
    void normal(ll &p, ll &q) { ll g = gcd(p, q); p /= g; q /= g; }
    Fra operator = (int x) { p = x; q = 1; return *this; }
    Fra operator = (ll x) { p = x; q = 1; return *this; }
    Fra operator - () { return { -p, q }; }
    Fra operator + (Fra &r) {
        ll m, n;
        m = p * r.q + r.p * q;
        n = q * r.q;
        normal(m, n);
        return { m, n };
    }
    Fra operator += (Fra &r) { return *this = *this + r; }
    Fra operator - (Fra &r) { return (-r) + *this; }
    Fra operator -= (Fra &r) { return *this = *this - r; }
    Fra operator * (Fra &r) {
        ll m, n;
        m = p * r.p;
        n = q * r.q;
        normal(m, n);
        return { m, n };
    }
    Fra operator *= (Fra &r) { return (*this) = (*this) * r; }
    Fra operator / (Fra &r) { return Fra(r.q, r.p) * (*this); }
    Fra operator /= (Fra &r) { return (*this) = (*this) / r; }
    bool operator == (const Fra& r) const { return p * r.q == r.p * q; }
    bool operator < (Fra& r) { return p * r.q < r.p * q; }
    void print() { normal(p, q); if (q < 0) q = -q, p = -p; printf("%lld/%lld\n", p, q); }
};

struct Node
{
    int l, r; // Use indices as left and right children
    Fra f; char op;
    bool fx;
    Node() {};
    Node(Fra &v, int a = -1, int b = -1) : f(v), l(a), r(b) {};

} nd[maxn];

bool isOp[256];
char rev[256];

Fra cal(Fra &x, Fra &y, char op)
{
    //assert(isOp[op] == true)
    switch (op) {
        case '+': return x + y;
        case '-': return x - y;
        case '*': return x * y;
        case '/': return x / y;
    }
    return { 233, 1 };
}

Fra ans;

void calRev(Fra &x, char op)
{
    switch (op) {
        case '+': ans -= x; return;
        case '*': ans /= x; return;
        case '-': ans = x - ans; return;
        case '/': ans = x / ans; return;
    }
}

bool dfs(int u)
{
    if (nd[u].l == -1) return true;
    //assert(nd.r)
    if (nd[nd[u].l].fx) {
        ans = cal(ans, nd[nd[u].r].f, rev[nd[u].op]); //乘以0的情况已经预处理了
        if (!dfs(nd[u].l)) return false;
    }
    else if (nd[nd[u].r].fx) {
        calRev(nd[nd[u].l].f, nd[u].op);//移项，ans本身可能会是0
        if (ans.q == 0) { return false; }
        if (!dfs(nd[u].r)) return false;
    }
    return true;
}

int cnt = 0;

int read(char ch)
{
    while (ch == ' ') ch = getchar();
    Node &cur = nd[cnt];
    if (isOp[ch]) {
        cur.op = ch;
        cur.r = cnt - 1; // Use the previous node as the right child
        cur.l = cnt - 2; // Use the second previous node as the left child
        cur.fx = cur.l < 0 ? false : (nd[cur.l].fx || nd[cur.r].fx);
        if (cur.fx) { //系数为0的处理
            if ((cur.op == '*' && (cur.r >= 0 ? (nd[cur.r].fx ? nd[cur.l].f == 0 : nd[cur.r].f == 0) : false))
                || (cur.op == '/' && (cur.r >= 0 ? nd[cur.r].fx && nd[cur.l].f == 0 : false))) {
                cur.fx = false;
                cur.f = 0; cur.l = cur.r = -1;
            }
        }
        else { //预处理，边读边算
            cur.f = cal(nd[cur.l].f, nd[cur.r].f, cur.op);
            cur.l = cur.r = -1;
        }
    }
    else {
        if (ch == 'X') {
            cur.fx = true;
        }
        else {
            cur.fx = false;
            int data = ch - '0';
            while (ch = getchar(), ch >= '0' && ch <= '9') data = data * 10 + ch - '0';
            cur.f = data;
        }
        cur.l = cur.r = -1;
    }
    cnt++;
    return cnt - 1;
}

int main()
{
    //freopen("in.txt","r",stdin);
    isOp['+'] = isOp['-'] = isOp['*'] = isOp['/'] = true;
    rev['+'] = '-'; rev['-'] = '+'; rev['*'] = '/'; rev['/'] = '*';
    char head;
    while (~(head = getchar())) {
        cnt = 0;
        int root = read(head);
        if (!nd[root].fx) {
            if (nd[root].f == 0) puts("MULTIPLE");
            else puts("NONE");
            continue;
        }
        ans = 0;
        if (dfs(root)) { printf("X = "); ans.print(); }
        else { puts("NONE"); continue; }
    }
    return 0;
}
