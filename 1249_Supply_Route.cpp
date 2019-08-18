//1249. [S/W 문제해결 응용] 4일차 - 보급로

#include <stdio.h>
#include <queue>
#include <memory.h>
using namespace std;
 
int t, n;
int map[100][100];
int d[100][100];
 
struct Node {
    int x;
    int y;
    Node(int _x, int _y) {
        x = _x;
        y = _y;
    }
};
 
void bfs() {
    queue<Node> q;
    q.push(Node(0, 0));
    int dx[] = { 1,-1,0,0 };
    int dy[] = { 0,0,1,-1 };
    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ax = x + dx[i];
            int ay = y + dy[i];
            if (ax >= 0 && ay >= 0 && ax < n&&ay < n) {
                if (d[ax][ay] > d[x][y] + map[ax][ay]) {
                    d[ax][ay] = d[x][y] + map[ax][ay];
                    q.push(Node(ax, ay));
                }
            }
        }
    }
}
 
void init() {
    memset(d, 9999, sizeof(d));
    d[0][0] = 0;
}
 
int main() {
    scanf("%d", &t);
    for (int tc = 1; tc <= t; tc++) {
        init();
        scanf("%d", &n);
        char buf[101];
        for (int i = 0; i < n; i++) {
            scanf("%s", &buf);
            for (int j = 0; j < n; j++) {
                map[i][j] = buf[j] - '0';
            }
        }
 
        bfs();
        printf("#%d %d\n", tc, d[n - 1][n - 1]);
    }
}