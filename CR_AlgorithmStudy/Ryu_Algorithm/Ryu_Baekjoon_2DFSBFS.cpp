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
//const int max_n = 104;
//int dy[4] = { -1, 0, 1, 0 };
//int dx[4] = { 0, 1, 0, -1 };
//int n, m, a[max_n][max_n], visited[max_n][max_n], y, x;
//
//int main()
//{
//    // 연속적으로 붙어 있는 경우 1)string으로 변환 2)scanf로 받기
//    scanf("%d %d", &n, &m);
//    for (int i = 0; i < n; ++i) 
//    {
//        for (int j = 0; j < m; ++j) 
//        {
//            // 1d로 받을 것!
//            scanf("%1d", &a[i][j]);
//        }
//    }
//
//    queue<pair<int, int>> q;
//    visited[0][0] = 1;
//    q.push({ 0, 0 });
//
//    while (0 != q.size()) 
//    {
//        tie(y, x) = q.front(); 
//        q.pop();
//
//        for (int i = 0; i < 4; ++i) 
//        {
//            int ny = y + dy[i];
//            int nx = x + dx[i];
//
//            // 범위를 먼저 체크하고 배열 체크할 것
//            if (0 > ny || 0 > nx || n <= ny || m <= nx) continue;
//            if (0 == a[ny][nx] || 1 == visited[ny][nx]) continue;
//
//            visited[ny][nx] = visited[y][x] + 1;
//            q.push({ ny, nx });
//        }
//    }
//
//    printf("%d", visited[n - 1][m - 1]);
//    
//	return 0;
//}

// 2_유기농 배추
// https://www.acmicpc.net/problem/1012
// 1: 배추가 심어진 곳 0: 배추가 심어지지 않은 곳
// 배추에 지렁이로 해충 퇴치문제 한마리만 있어도 인접한 배추로 퍼짐
// 커넥티드 컴포넌트 방식
// 틀렸습니다 헤맨 부분: 초기화 작업
// T: 테케 개수, M: 배추밭 가로길이, N: 배추밭 세로길이, K: 배추 심어진 개수, XY: 배추 위치
//int dy[] = { -1, 0, 1, 0 };
//int dx[] = { 0, 1, 0, -1 };
//int T, M, N, K, X, Y, farm[50][50], visited[50][50];
//
//void earthwormdfs(int y, int x)
//{
//	visited[y][x] = 1;
//
//	for (int i = 0; i < 4; ++i)
//	{
//		int ny = y + dy[i];
//		int nx = x + dx[i];
//
//		if (0 > ny || 0 > nx || N <= ny || M <= nx) continue;
//		if (1 == farm[ny][nx] && 0 == visited[ny][nx]) earthwormdfs(ny, nx);
//	}
//}
//
//int main()
//{
//	cin >> T;
//
//	while (T--)
//	{
//		cin >> M >> N >> K;
//
//		// 초기화 작업
//		fill(&farm[0][0], &farm[49][49], 0);
//		fill(&visited[0][0], &visited[49][49], 0);
//		int ret = 0;
//
//		// 배추밭 생성
//		for (int i = 0; i < K; ++i)
//		{
//			cin >> X >> Y;
//			farm[Y][X] = 1;
//		}
//
//		// 배추&지렁이 탐색
//		for (int i = 0; i < N; ++i)
//		{
//			for (int j = 0; j < M; ++j)
//			{
//				if (1 == farm[i][j] && 0 == visited[i][j])
//				{
//					++ret;
//					earthwormdfs(i, j);
//				}
//			}
//		}
//
//		cout << ret << "\n";
//	}
//
//	return 0;
//}

// 또 다른 풀이법(커넥티드 컴포넌트_DFS)
// 내 풀이와 유사?
// 최단거리를 찾는 것이 아니니까 굳이 BFS로 할 필요 없음
// 대신 BFS로 구현해도 상관없음
int t, m, n, k, x, y, ny, nx, ret;
int a[51][51], visited[51][51];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

void dfs(int y, int x)
{
	visited[y][x] = 1;

	for (int i = 0; i < 4; ++i)
	{
		ny = y + dy[i];
		nx = x + dx[i];

		if (0 > ny || 0 > nx || n <= ny || m <= nx) continue;
		if (1 == a[ny][nx] && !visited[ny][nx])
		{
			dfs(ny, nx);
		}
	}
}

int main()
{
	cin >> t;

	while (t--)
	{
		// 테케마다 초기화
		fill(&a[0][0], &a[0][0] + 51 * 51, 0);
		fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
		ret = 0;

		cin >> m >> n >> k;
		for (int i = 0; i < k; ++i)
		{
			cin >> x >> y;
			a[y][x] = 1;
		}

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (1 == a[i][j] && !visited[i][j])
				{
					dfs(i, j);
					++ret;
				}
			}
		}
		cout << ret << "\n";
	}

	return 0;
}