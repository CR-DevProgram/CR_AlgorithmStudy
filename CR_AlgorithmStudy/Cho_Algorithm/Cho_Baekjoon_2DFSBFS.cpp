// 미로 탐색
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

// 유기농배추
// https://www.acmicpc.net/problem/1012
//#include <iostream>
//#include <vector>
//#include <queue>
//using namespace std;
//
//int dx[4] = { 1, -1, 0, 0 };
//int dy[4] = { 0, 0, 1, -1 };
//
//void bfs(vector<vector<bool>>& v, int x, int y, int mx, int my)
//{
//    queue<pair<int, int>> q;
//    q.push({ x, y });
//
//    while (!q.empty())
//    {
//        int cx = q.front().first;
//        int cy = q.front().second;
//        q.pop();
//
//        for (int i = 0; i < 4; i++)
//        {
//            int nx = cx + dx[i];
//            int ny = cy + dy[i];
//
//            if (nx < 0 || nx >= mx || ny < 0 || ny >= my) continue;
//            if (v[nx][ny] == false) continue;
//            v[nx][ny] = false;
//            q.push({ nx, ny });
//        }
//    }
//}
//
//int main()
//{
//    int tc;
//    cin >> tc;
//
//    for (int i = 0; i < tc; i++)
//    {
//        int x, y, z;
//        cin >> x >> y >> z;
//        vector<vector<bool>> v(x, vector<bool>(y, false));
//        for (int i = 0; i < z; i++)
//        {
//            int tx, ty;
//            cin >> tx >> ty;
//            v[tx][ty] = true;
//        }
//
//        int cnt = 0;
//        for (int i = 0; i < x; i++)
//        {
//            for (int j = 0; j < y; j++)
//            {
//                if (v[i][j] == true)
//                {
//                    bfs(v, i, j, x, y);
//                    ++cnt;
//                }
//            }
//        }
//
//        cout << cnt << '\n';
//    }
//}

// 안전 영역
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <queue>
//
//using namespace std;
//
//int dx[4] = { 1, -1, 0, 0 };
//int dy[4] = { 0, 0, 1, -1 };
//
//void bfs(vector<vector<int>>& v, vector<vector<bool>>& isVisited, int x, int y, int rain, int n)
//{
//    queue<pair<int, int>> q;
//    q.push({ x, y });
//
//    while (!q.empty())
//    {
//        int cx = q.front().first;
//        int cy = q.front().second;
//        q.pop();
//
//        for (int i = 0; i < 4; i++)
//        {
//            int nx = cx + dx[i];
//            int ny = cy + dy[i];
//
//            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
//            if (isVisited[nx][ny] || v[nx][ny] <= rain) continue;
//
//            q.push({ nx, ny });
//            isVisited[nx][ny] = true;
//        }
//    }
//}
//
//int main()
//{
//    int n;
//    int minValue = 101;
//    int maxValue = 0;
//    cin >> n;
//    vector<vector<int>> v(n, vector<int>(n));
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            int temp;
//            cin >> temp;
//            v[i][j] = temp;
//            minValue = min(minValue, temp);
//            maxValue = max(maxValue, temp);
//        }
//    }
//
//    int answer = 1;
//    while (minValue < maxValue)
//    {
//        int cnt = 0;
//        vector<vector<bool>> isVisited(n, vector<bool>(n, false));
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < n; j++)
//            {
//                if (isVisited[i][j] == false &&
//                    v[i][j] > minValue)
//                {
//                    ++cnt;
//                    isVisited[i][j] = true;
//                    bfs(v, isVisited, i, j, minValue, n);
//                }
//            }
//        }
//
//        answer = max(answer, cnt);
//        ++minValue;
//    }
//
//    cout << answer;
//}

// 영역 구하기
// https://www.acmicpc.net/problem/2583
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//using namespace std;
//
//int dx[4] = { 1, -1, 0, 0 };
//int dy[4] = { 0, 0, 1, -1 };
//
//int bfs(vector<vector<bool>>& v, int x, int y, int m, int n)
//{
//    queue<pair<int, int>> q;
//    q.push({ x, y });
//    v[x][y] = false;
//    int cnt = 1;
//    while (!q.empty())
//    {
//        int cx = q.front().first;
//        int cy = q.front().second;
//
//        q.pop();
//
//        for (int i = 0; i < 4; i++)
//        {
//            int nx = cx + dx[i];
//            int ny = cy + dy[i];
//
//            if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
//            if (!v[nx][ny]) continue;
//
//            v[nx][ny] = false;
//            q.push({ nx, ny });
//            ++cnt;
//        }
//    }
//
//    return cnt;
//}
//
//int main()
//{
//    // 영역을 만든다.
//    int m, n, k;
//    cin >> m >> n >> k;
//    vector<vector<bool>> v(m, vector<bool>(n, true));
//
//    for (int i = 0; i < k; i++)
//    {
//        int x1, y1, x2, y2;
//        cin >> x1 >> y1 >> x2 >> y2;
//
//        for (int i = x1; i < x2; i++)
//        {
//            for (int j = y1; j < y2; j++)
//            {
//                v[j][i] = false;
//            }
//        }
//    }
//
//    int cnt = 0;
//    vector<int> answer;
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            if (v[i][j])
//            {
//                ++cnt;
//                answer.push_back(bfs(v, i, j, m, n));
//            }
//        }
//    }
//
//    sort(answer.begin(), answer.end());
//
//    cout << cnt << '\n';
//    for (auto i : answer)
//    {
//        cout << i << ' ';
//    }
//}

// 쿼드트리
// https://www.acmicpc.net/problem/1992
#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>>& v, int x, int y, int gap)
{
	if (gap == 1)
	{
		cout << v[x][y];
		return;
	}

	bool isAllOne = true;
	bool isAllZero = true;
	for (int i = x; i < x + gap; i++)
	{
		for (int j = y; j < y + gap; j++)
		{
			if (v[i][j] == 0)
				isAllOne = false;
			if (v[i][j] == 1)
				isAllZero = false;
		}
	}

	if (isAllOne)
	{
		cout << 1;
		return;
	}
	if (isAllZero)
	{
		cout << 0;
		return;
	}

	cout << '(';
	dfs(v, x, y, gap / 2);
	dfs(v, x, y + gap / 2, gap / 2);
	dfs(v, x + gap / 2, y, gap / 2);
	dfs(v, x + gap / 2, y + gap / 2, gap / 2);
	cout << ')';
}

int main()
{
	int n;
	cin >> n;

	vector<vector<int>> v(n, vector<int>(n));

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < n; j++)
		{
			v[i][j] = s[j] - '0';
		}
	}

	dfs(v, 0, 0, n);
}