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
//int t, m, n, k, x, y, ny, nx, ret;
//int a[51][51], visited[51][51];
//int dy[] = { -1, 0, 1, 0 };
//int dx[] = { 0, 1, 0, -1 };
//
//void dfs(int y, int x)
//{
//	visited[y][x] = 1;
//
//	for (int i = 0; i < 4; ++i)
//	{
//		ny = y + dy[i];
//		nx = x + dx[i];
//
//		if (0 > ny || 0 > nx || n <= ny || m <= nx) continue;
//		if (1 == a[ny][nx] && !visited[ny][nx])
//		{
//			dfs(ny, nx);
//		}
//	}
//}
//
//int main()
//{
//	cin >> t;
//
//	while (t--)
//	{
//		// 테케마다 초기화
//		fill(&a[0][0], &a[0][0] + 51 * 51, 0);
//		fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
//		ret = 0;
//
//		cin >> m >> n >> k;
//		for (int i = 0; i < k; ++i)
//		{
//			cin >> x >> y;
//			a[y][x] = 1;
//		}
//
//		for (int i = 0; i < n; ++i)
//		{
//			for (int j = 0; j < m; ++j)
//			{
//				if (1 == a[i][j] && !visited[i][j])
//				{
//					dfs(i, j);
//					++ret;
//				}
//			}
//		}
//		cout << ret << "\n";
//	}
//
//	return 0;
//}

// 3_안전 영역
// https://www.acmicpc.net/problem/2468
// 특정 수치 초과 커넥티드 컴포넌트
// 장마철이지만 비가 안 오는 경우도 고려
// 따라서 비의 양이 0 ~ 100이 될 것(최대 100으로 잡은 이유는 건물의 높이가 1 ~ 100이기 때문)
// N: 행열 개수
//const int MAX = 100;
//int N, rain, maximum, ret;
//int area[MAX][MAX], visited[MAX][MAX];
//int dy[] = { -1, 0, 1, 0 };
//int dx[] = { 0, 1, 0, -1 };
//
//void safezone(int y, int x)
//{
//	visited[y][x] = 1;
//
//	for (int i = 0; i < 4; ++i)
//	{
//		int ny = y + dy[i];
//		int nx = x + dx[i];
//
//		if (0 > ny || 0 > nx || N <= ny || N <= nx) continue;
//		// 비의 양보다 지역 높이가 큰 경우이며 방문하지 않았을 때만 safezone 재귀 탐색
//		if (rain < area[ny][nx] && 0 == visited[ny][nx]) safezone(ny, nx);
//	}
//}
//
//int main()
//{
//	cin >> N;
//
//	for (int i = 0; i < N; ++i)
//	{
//		for (int j = 0; j < N; ++j)
//		{
//			cin >> area[i][j];
//			// 지역 최대치를 알아내 비의 양 계산 부분에서 탈출 구문으로 사용
//			maximum = max(maximum, area[i][j]);
//		}
//	}
//
//	// 비의 양이 지역 높이 최대를 넘어서면 중단
//	while (rain < maximum)
//	{
//		// 비의 양에 따른 안전 영역 확인을 위한 초기화 처리
//		fill(&visited[0][0], &visited[99][99], 0);
//		int cnt = 0;
//
//		for (int i = 0; i < N; ++i)
//		{
//			for (int j = 0; j < N; ++j)
//			{
//				if (rain < area[i][j] && 0 == visited[i][j])
//				{
//					++cnt;
//					safezone(i, j);
//				}
//			}
//		}
//
//		// 단순히 생각했을 때 최대 영역 개수 도달하고 이후에 더 큰 수치로 잠기면서 최대 영역 개수보다 작을 것이라 생각하여 조건 부여
//		// 그러나 줄었다가 다시 늘어나는 부분이 존재하는지 2n퍼 쯤 틀렸다고 나옴
//		// 따라서 별도로 지역 높이의 최대를 알아내 많은 비의 양을 계산하지 않게(시간초과 방지 차원) 처리
//		//if (ret > cnt) break;
//
//		// 최대 안전 영역 개수
//		ret = max(ret, cnt);
//
//		// 비의 양 증가
//		++rain;
//	}
//
//	cout << ret << "\n";
//
//	return 0;
//}

// 또 다른 풀이법(커넥티드 컴포넌트_DFS)
// 내리는 비의 양에 따라 모두 조사해서 그 중에서 가장 큰 안전 영역 개수 구하기
// 깊이높이 관련도 DFS 매개 변수로 넣을 것
// ***반례: 최소, 최대, 없거나, 있거나***
// ***변수명의 통일***
// 해당 문제의 반례는 아무 지역도 물에 잠기지 않을 수도 있다.
//int n, ret = 1;
//int a[101][101], visited[101][101];
//int dy[] = { -1, 0, 1, 0 };
//int dx[] = { 0, 1, 0, -1 };
//
//// d를 전역으로 두어도 되지만 명시적으로 하기 위해 매개변수 사용
//void dfs(int y, int x, int d)
//{
//	visited[y][x] = 1;
//
//	for (int i = 0; i < 4; ++i)
//	{
//		int ny = y + dy[i];
//		int nx = x + dx[i];
//
//		if (0 > ny || 0 > nx || n <= ny || n <= nx) continue;
//		if (!visited[ny][nx] && d < a[ny][nx]) dfs(ny, nx, d);
//	}
//}
//
//int main()
//{
//	cin >> n;
//
//	for (int i = 0; i < n; ++i)
//	{
//		for (int j = 0; j < n; ++j)
//		{
//			cin >> a[i][j];
//		}
//	}
//
//	for (int d = 1; d < 101; ++d)
//	{
//		fill(&visited[0][0], &visited[0][0] + 101 * 101, 0);
//
//		int cnt = 0;
//		for (int i = 0; i < n; ++i)
//		{
//			for (int j = 0; j < n; ++j)
//			{
//				if (d < a[i][j] && !visited[i][j])
//				{
//					dfs(i, j, d);
//					++cnt;
//				}
//			}
//		}
//
//		ret = max(ret, cnt);
//	}
//
//	cout << ret << "\n";
//
//	return 0;
//}

// 4_영역 구하기
// https://www.acmicpc.net/problem/2583
// M*N: 직사각형 모눈 종이 크기, K: 직사각형 개수
const int MAX_SIZE = 100;
int M, N, K, areasize;
int graphpaper[MAX_SIZE][MAX_SIZE], visited[MAX_SIZE][MAX_SIZE];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

void areaserch(int y, int x)
{
	visited[y][x] = 1;

	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (0 > ny || 0 > nx || M <= ny || N <= nx) continue;
		if (0 == graphpaper[ny][nx] && 0 == visited[ny][nx])
		{
			++areasize;
			areaserch(ny, nx);
		}
	}
}

int main()
{
	cin >> M >> N >> K;

	for (int i = 0; i < K; ++i)
	{
		pair<int, int> lefttop, rightbot;
		// 사각형 좌상단
		cin >> lefttop.first >> lefttop.second;
		// 사각형 우하단
		cin >> rightbot.first >> rightbot.second;

		// 모눈 종이에 직사각형 그리기
		for (int rectY = lefttop.second; rectY < rightbot.second; ++rectY)
		{
			for (int rectX = lefttop.first; rectX < rightbot.first; ++rectX)
			{
				graphpaper[rectY][rectX] = 1;
			}
		}
	}

	// 영역 크기 담을 vector
	vector<int> vecareasize;
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			// 커넥티드 컴포넌트 별 영역 크기 파악을 위한 변수 초기화
			areasize = 0;
			if (0 == graphpaper[i][j] && 0 == visited[i][j])
			{
				++areasize;
				areaserch(i, j);

				if (0 != areasize) vecareasize.push_back(areasize);
			}
		}
	}

	// 크기 오름차순 정렬
	sort(vecareasize.begin(), vecareasize.end());

	cout << vecareasize.size() << "\n";
	for (int i = 0; i < vecareasize.size(); ++i)
	{
		cout << vecareasize[i] << " ";
	}

	return 0;
}