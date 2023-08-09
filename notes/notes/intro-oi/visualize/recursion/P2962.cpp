#include <stdio.h>
#include <stdint.h>

int reach[101][601]; // 邻接矩阵存储图，注意这里数组大小可能需要根据题目的要求进行调整
long long statu[101]; // 灯亮状态
long long log[71]; // log数组，同样注意数组大小
long long xx[101]; // 用于计算贡献的数组
int hash[1000009]; // 哈希表
int n, m, mid, ans, right;

int arfa(long long num) {
    return ((num % 1000007) * (num % 1000007) * 99971) % 1000007;
}

void Dfs(int mode, int choose, int x) {
    if (x > right) {
        long long k = 0;
        int num = 0;
        if (mode == 1) {
            for (int i = 1; i <= mid; ++i) {
                if (statu[i] > 0) {
                    k ^= xx[i];
                    ++num;
                }
            }
            ++num;
            int kk = arfa(k);
            if (hash[kk] == 0) {
                hash[kk] = num;
            } else {
                hash[kk] = (hash[kk] < num) ? hash[kk] : num;
            }
        } else {
            for (int i = mid + 1; i <= n; ++i) {
                if (statu[i] > 0) {
                    k ^= xx[i];
                    ++num;
                }
            }
            int kk = arfa(log[n] - k - 1);
            if (hash[kk] > 0) {
                ans = (ans < (hash[kk] - 1 + num)) ? ans : (hash[kk] - 1 + num);
            }
        }
        return;
    }
    statu[x] = 0;
    Dfs(mode, choose, x + 1);
    statu[x] = 1;
    Dfs(mode, choose + 1, x + 1);
}

void readin() {
	int l,  r;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d", &l, &r);
        reach[l][0]++;
        reach[l][reach[l][0]] = r;
        reach[r][0]++;
        reach[r][reach[r][0]] = l;
    }
    log[0] = 1;
    for (int i = 1; i <= n + 1; ++i) {
        log[i] += log[i - 1] * 2;
    }
    for (int i = 1; i <= n; ++i) {
        xx[i] = log[i - 1];
        for (int j = 1; j <= reach[i][0]; ++j) {
            xx[i] += log[reach[i][j] - 1];
        }
    }
    ans = (1 << 30);
}

int main() {
    readin();
    mid = n / 2;
    right = n / 2;
    Dfs(1, 0, 1);
    right = n;
    Dfs(2, 0, mid + 1);
    printf("%d\n", ans);
    return 0;
}
