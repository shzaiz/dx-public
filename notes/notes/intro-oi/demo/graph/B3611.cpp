#include <stdio.h>

// 定义图的最大节点数
#define MAX_N 100

// 计算传递闭包
void transitiveClosure(int graph[MAX_N][MAX_N], int n) {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int graph[MAX_N][MAX_N];

    // 读取邻接矩阵
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &graph[i][j]);
        }
    }

    // 计算传递闭包
    transitiveClosure(graph, n);

    // 输出传递闭包矩阵
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}
