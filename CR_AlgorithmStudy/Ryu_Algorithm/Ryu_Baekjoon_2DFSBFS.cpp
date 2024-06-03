#include <bits/stdc++.h>

using namespace std;

// 1_미로 탐색
// https://www.acmicpc.net/problem/2178
// 1은 이동 가능 0은 이동 불가
// (1, 1)에서 출발 (n, m)로 이동할 때 최소 이동 칸 수
// 인접한 칸만 이동 가능
//int n, m, minvalue, ret = 1;
//int dy[] = { -1, 0, 1, 0 };
//int dx[] = { 0, 1, 0, -1 };
//int maze[100][100];
///*bool*/int visited[100][100];

// DFS 형식으로 할 경우 TC는 통과한다 하더라도 제출시 시간초과 발생
// 문제의 본질이 최소 칸의 수 즉, 최단거리를 구하는 문제이므로 BFS로 풀어야 함
//void move(int y, int x)
//{
//	if (n == y + 1 && m == x + 1)
//	{
//		minvalue = min(minvalue, ret);
//		return;
//	}
//
//	for (int i = 0; i < 4; ++i)
//	{
//		int ny = y + dy[i];
//		int nx = x + dx[i];
//
//		if (0 > ny || 0 > nx || n <= ny || m <= nx) continue;
//		if (1 == maze[ny][nx] && 0 == visited[ny][nx])
//		{
//			++ret;
//			visited[ny][nx] = 1;
//			move(ny, nx);
//			visited[ny][nx] = 0;
//			--ret;
//		}
//	}
//}
//
//int main()
//{
//	cin >> n >> m;
//
//	minvalue = n * m;
//
//	for (int i = 0; i < n; ++i)
//	{
//		string mazeinfo = "";
//		cin >> mazeinfo;
//
//		for (int j = 0; j < m; ++j)
//		{
//			maze[i][j] = mazeinfo[j] - '0';
//		}
//	}
//
//	visited[0][0] = 1;
//	move(0, 0);
//
//	cout << minvalue << "\n";
//
//	return 0;
//}

// BFS 풀이
//int main()
//{
//	cin >> n >> m;
//
//	for (int i = 0; i < n; ++i)
//	{
//		string mazeinfo = "";
//		cin >> mazeinfo;
//
//		// 미로 만들기
//		for (int j = 0; j < m; ++j) maze[i][j] = mazeinfo[j] - '0';
//	}
//
//	// BFS에서 사용할 queue
//	queue<pair<int, int>> qmakepair;
//	// 시작지점 방문 기록
//	visited[0][0] = 1;
//	qmakepair.push({ 0,0 });
//
//	while (true)
//	{
//		// queue가 비어 있을 때까지 반복
//		if (true == qmakepair.empty()) break;
//
//		// 방문 탐색 기준 값 대입
//		int x = qmakepair.front().second;
//		int y = qmakepair.front().first;
//		qmakepair.pop();
//
//		for (int i = 0; i < 4; ++i)
//		{
//			// 다음으로 이동할 위치
//			int ny = y + dy[i];
//			int nx = x + dx[i];
//
//			if (0 > ny || 0 > nx || n <= ny || m <= nx) continue;
//			// 미로 이동이 가능하고 방문한 적이 없을 때만
//			if (1 == maze[ny][nx] && 0 == visited[ny][nx])
//			{
//				// 최단거리를 구하기 위한 visited 누적(가중치가 동일)
//				visited[ny][nx] = visited[y][x] + 1;
//				qmakepair.push({ ny,nx });
//			}
//		}
//	}
//	
//	// 도착 지점의 visited 값이 최단 거리 값
//	cout << visited[n - 1][m - 1] << "\n";
//
//	return 0;
//}

// 또 다른 풀이법(?)
// 내 풀이와 유사?
// 해당 문제는 무조건 BFS라는 말이 나와야 한다
// 가중치가 1로 동일하고 연결되어 있는 것으로 BFS
const int max_n = 104;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int n, m, a[max_n][max_n], visited[max_n][max_n], y, x;

int main()
{
    // 연속적으로 붙어 있는 경우 1)string으로 변환 2)scanf로 받기
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < m; ++j) 
        {
            // 1d로 받을 것!
            scanf("%1d", &a[i][j]);
        }
    }

    queue<pair<int, int>> q;
    visited[0][0] = 1;
    q.push({ 0, 0 });

    while (0 != q.size()) 
    {
        tie(y, x) = q.front(); 
        q.pop();

        for (int i = 0; i < 4; ++i) 
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            // 범위를 먼저 체크하고 배열 체크할 것
            if (0 > ny || 0 > nx || n <= ny || m <= nx) continue;
            if (0 == a[ny][nx] || 1 == visited[ny][nx]) continue;

            visited[ny][nx] = visited[y][x] + 1;
            q.push({ ny, nx });
        }
    }

    printf("%d", visited[n - 1][m - 1]);
    
	return 0;
}