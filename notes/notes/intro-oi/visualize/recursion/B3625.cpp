=#include <iostream>
#include <queue>

using namespace std;

struct Point {
    int x, y;
    Point(int _x, int _y) : x(_x), y(_y) {}
};

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool isValid(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

bool canReachEnd(char maze[][100], int n, int m) {
    bool visited[100][100] = {false};
    queue<Point> q;
    q.push(Point(0, 0));
    visited[0][0] = true;

    while (!q.empty()) {
        Point curr = q.front();
        q.pop();

        if (curr.x == n - 1 && curr.y == m - 1) {
            return true; // Reached the end
        }

        for (int i = 0; i < 4; ++i) {
            int newX = curr.x + dx[i];
            int newY = curr.y + dy[i];

            if (isValid(newX, newY, n, m) && maze[newX][newY] == '.' && !visited[newX][newY]) {
                q.push(Point(newX, newY));
                visited[newX][newY] = true;
            }
        }
    }

    return false; // Unable to reach the end
}

int main() {
    int n, m;
    cin >> n >> m;

    char maze[100][100];
    for (int i = 0; i < n; ++i) {
        cin >> maze[i];
    }

    if (canReachEnd(maze, n, m)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
