// ¹Ì·Î Å½»ö
// https://www.acmicpc.net/problem/2178
//#include <iostream>
//#include <vector>
//#include <queue>
//using namespace std;
//
//int dx[4] = { 1, -1, 0, 0 };
//int dy[4] = { 0, 0, 1, -1 };
//
//int bfs(vector<vector<char>>& v, int n, int m)
//{
//    queue<pair<int, int>> q;
//    q.push({ 0, 0 });
//    vector<vector<bool>> isVisited(n, vector<bool>(m, false));
//    vector<vector<int>> visitedCnt(n, vector<int>(m, 0));
//    isVisited[0][0] = true;
//    visitedCnt[0][0] = 1;
//
//    while (!q.empty())
//    {
//        int x = q.front().first;
//        int y = q.front().second;
//        q.pop();
//
//        for (int i = 0; i < 4; i++)
//        {
//            int nx = x + dx[i];
//            int ny = y + dy[i];
//
//            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
//            if (isVisited[nx][ny] || v[nx][ny] == '0') continue;
//            isVisited[nx][ny] = true;
//            visitedCnt[nx][ny] = visitedCnt[x][y] + 1;
//            q.push({ nx, ny });
//        }
//    }
//
//    return visitedCnt[n - 1][m - 1];
//}
//
//int main()
//{
//    int n, m;
//    cin >> n >> m;
//    vector<vector<char>> v(n, vector<char>(m));
//
//    for (int i = 0; i < n; i++)
//    {
//        string temp;
//        cin >> temp;
//
//        for (int j = 0; j < m; j++)
//        {
//            v[i][j] = temp[j];
//        }
//    }
//
//    cout << bfs(v, n, m);
//}

// À¯±â³ó¹èÃß
// https://www.acmicpc.net/problem/1012
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void bfs(vector<vector<bool>>& v, int x, int y, int mx, int my)
{
    queue<pair<int, int>> q;
    q.push({ x, y });

    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || nx >= mx || ny < 0 || ny >= my) continue;
            if (v[nx][ny] == false) continue;
            v[nx][ny] = false;
            q.push({ nx, ny });
        }
    }
}

int main()
{
    int tc;
    cin >> tc;

    for (int i = 0; i < tc; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        vector<vector<bool>> v(x, vector<bool>(y, false));
        for (int i = 0; i < z; i++)
        {
            int tx, ty;
            cin >> tx >> ty;
            v[tx][ty] = true;
        }

        int cnt = 0;
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                if (v[i][j] == true)
                {
                    bfs(v, i, j, x, y);
                    ++cnt;
                }
            }
        }

        cout << cnt << '\n';
    }
}