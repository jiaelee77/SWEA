//4615. 재미있는 오셀로 게임

#include<iostream>
#include<vector>
using namespace std;
 
int dx[8] = { 0,0,1,-1,1,1,-1,-1};
int dy[8] = { 1,-1,0,0,1,-1,1,-1};
int n, m;
int map[8][8] = { 0, };
void init()
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            map[i][j] = 0;
}
void reset_map(int x,int y)
{
    for (int d = 0; d < 8; d++) {
        int color = map[x][y];
        int nx = x + dx[d];
        int ny = y + dy[d];
        bool chk = false;
        while (nx >= 0 && ny >= 0 && nx < n && ny < n && map[nx][ny]!=0)
        {
            if (map[nx][ny] == color)
            {
                chk = true;
                break;
            }
 
            nx += dx[d];
            ny += dy[d];
        }
 
        while (chk)
        {
            if (nx==x && ny==y)
            {
                break;
            }
            map[nx][ny] = color;
            nx -= dx[d];
            ny -= dy[d];
        }
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        init();
 
        cin >> n >> m;
        
        //중앙값 초기화
        int mid_left_top_x = (n / 2) - 1;
        int mid_left_top_y = (n / 2) - 1;
 
        map[mid_left_top_x][mid_left_top_y] = 2;
        map[mid_left_top_x + 1][mid_left_top_y]=1;
        map[mid_left_top_x][mid_left_top_y + 1] = 1;
        map[mid_left_top_x + 1][mid_left_top_y + 1] = 2;
 
        for (int i = 0; i < m; i++)
        {
            int x, y, color;
            cin >> y >> x >> color;
            map[x -1][y - 1] = color;
            reset_map(x - 1, y - 1);
        }
 
        int ans1 = 0, ans2 = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
            {
                if (map[i][j] == 1)
                    ans1++;
                else if (map[i][j] == 2)
                    ans2++;
            }
        }
        cout << "#" << t << " " << ans1 << " " << ans2 << endl;
    }
 
 
    return 0;
}