#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int p[N], d[N]; //p[]寻找祖宗节点，d[]求到祖宗节点的距离

int find(int x){
    if (p[x] != x){
        int t = find(p[x]); // u暂时存一下p[x]根节点，辅助变量
        d[x] += d[p[x]];    // 更新距离
        p[x] = t;
    }
    return p[x];
}


int main(){
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i ++ ) p[i] = i;

    int res = 0;//记录错误数
    while (m -- ){
        int t, x, y;
        scanf("%d%d%d", &t, &x, &y);

        if (x > n || y > n) res ++ ; // 当前的话中X或Y比N大，是假话
        else{
            int px = find(x), py = find(y); // 查找根节点
            // 判断是否同类
            if (t == 1) {
                if (px == py) {  // 若 x 与 y 在同一个集合中
                    if ((d[x] - d[y]) % 3) res ++ ; // 两数到根节点距离之差的模不为 0，说明不是同一类，是假话
                    // 其中 (d[x] - d[y]) % 3 不可写为 d[x] % 3 != d[y] % 3
                    // 因为 d[x], d[y] 可能为负数（一正一负），可改做 (d[x] % 3 + 3) % 3 != (d[y] % 3 + 3) % 3
                    // 负数 mod 正数为负数
                } else {    // 则 x 与 y 不在同一个集合中
                    p[px] = py;     // x 所在集合 合并到 y 所在集合
                    d[px] = d[y] - d[x];
                    // d[x] 的距离为什么不更新？
                    // 只是暂时不更新，在调用 find 时再更新
                }
            }
            else // X 是否吃 Y
            {
                if (px == py) {     // 若 x 与 y 在同一个集合中
                    // 若 X 吃 Y，则 d[x] 比 d[y] 大 1
                    if ((d[x] - d[y] - 1) % 3) res ++ ;  // 若距离之差 - 1 的模不为 0，说明吃不掉，是假话
                } else {    // 则 x 与 y 不在同一个集合中
                    p[px] = py;
                    // (d[x] - d[y] - 1) % 3 == 0
                    // d[x] + d[px] - 1 = d[y]  则：
                    d[px] = d[y] + 1 - d[x];
                }
            }
        }
    }

    printf("%d\n", res);

    return 0;
}

作者：yxc
链接：https://www.acwing.com/activity/content/code/content/45325/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。