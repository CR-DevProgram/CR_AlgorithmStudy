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
//const int MAX_SIZE = 100;
//int M, N, K, areasize;
//int graphpaper[MAX_SIZE][MAX_SIZE], visited[MAX_SIZE][MAX_SIZE];
//int dy[] = { -1, 0, 1, 0 };
//int dx[] = { 0, 1, 0, -1 };
//
//void areaserch(int y, int x)
//{
//	visited[y][x] = 1;
//
//	for (int i = 0; i < 4; ++i)
//	{
//		int ny = y + dy[i];
//		int nx = x + dx[i];
//
//		if (0 > ny || 0 > nx || M <= ny || N <= nx) continue;
//		if (0 == graphpaper[ny][nx] && 0 == visited[ny][nx])
//		{
//			++areasize;
//			areaserch(ny, nx);
//		}
//	}
//}
//
//int main()
//{
//	cin >> M >> N >> K;
//
//	for (int i = 0; i < K; ++i)
//	{
//		pair<int, int> lefttop, rightbot;
//		// 사각형 좌상단
//		cin >> lefttop.first >> lefttop.second;
//		// 사각형 우하단
//		cin >> rightbot.first >> rightbot.second;
//
//		// 모눈 종이에 직사각형 그리기
//		for (int rectY = lefttop.second; rectY < rightbot.second; ++rectY)
//		{
//			for (int rectX = lefttop.first; rectX < rightbot.first; ++rectX)
//			{
//				graphpaper[rectY][rectX] = 1;
//			}
//		}
//	}
//
//	// 영역 크기 담을 vector
//	vector<int> vecareasize;
//	for (int i = 0; i < M; ++i)
//	{
//		for (int j = 0; j < N; ++j)
//		{
//			// 커넥티드 컴포넌트 별 영역 크기 파악을 위한 변수 초기화
//			areasize = 0;
//			if (0 == graphpaper[i][j] && 0 == visited[i][j])
//			{
//				++areasize;
//				areaserch(i, j);
//
//				if (0 != areasize) vecareasize.push_back(areasize);
//			}
//		}
//	}
//
//	// 크기 오름차순 정렬
//	sort(vecareasize.begin(), vecareasize.end());
//
//	cout << vecareasize.size() << "\n";
//	for (int i = 0; i < vecareasize.size(); ++i)
//	{
//		cout << vecareasize[i] << " ";
//	}
//
//	return 0;
//}

// 또 다른 풀이법(커넥티드 컴포넌트_DFS int형)
// 문제를 보고 커넥티드 컴포넌트를 떠올려야 함
// y1을 사용하려면 #define 걸어줘야 됨 => #include <bits/stdc++.h>에 y1라는 전역변수가 걸려있기 때문, 따라서 임의로 할당해야 사용 가능
// 변수명에서 에러가 뜬다면 해당 변수명을 define 작업해 볼 것
// 문제의 핵심은 dfs를 void가 아닌 int로 했는가
//#define y1 yy
//vector<int> vec;
//int a[104][104], visited[104][104], m, n, k, x1, x2, y1, y2;
//const int dy[] = { -1, 0, 1, 0 };
//const int dx[] = { 0, 1, 0, -1 };
//
//// 반환 타입을 void가 아닌 int로 쓴 이유 => 사이즈 누적 연산을 위함, 커넥티드 컴포넌트로 해당 사이즈를 구하기 위해 int 반환 센스 이용
//int dfs(int y, int x)
//{
//	visited[y][x] = 1;
//
//	// 정점의 값 1을 기반으로 이동한 위치들의 값을 더함
//	int ret = 1;
//	for (int i = 0; i < 4; ++i)
//	{
//		int ny = y + dy[i];
//		int nx = x + dx[i];
//
//		if (0 > ny || 0 > nx || m <= ny || n <= nx) continue;
//		if (1 == a[ny][nx] || 1 == visited[ny][nx]) continue;
//
//		ret += dfs(ny, nx);
//	}
//
//	return ret;
//}
//
//int main()
//{
//	cin >> m >> n >> k;
//
//	for (int i = 0; i < k; ++i)
//	{
//		cin >> x1 >> y1 >> x2 >> y2;
//
//		for (int x = x1; x < x2; ++x)
//		{
//			for (int y = y1; y < y2; ++y)
//			{
//				a[y][x] = 1;
//			}
//		}
//	}
//
//	for (int i = 0; i < m; ++i)
//	{
//		for (int j = 0; j < n; ++j)
//		{
//			// 강사님께선 논리연산자(&&)가 아닌 비트연산자(&)를 사용
//			// &&과 || 같은 연산들은 어차피 0, 1의 결과값을 가지므로 & 연산을 해줘도 &&을 한 것과 같기 때문
//			// 초록 밑줄이 신경쓰여서 비트 말고 논리로 바꿈
//			if (1 != a[i][j] && 0 == visited[i][j])
//			{
//				// 사이즈를 구해서 벡터에 넣기
//				vec.push_back(dfs(i, j));
//			}
//		}
//	}
//
//	sort(vec.begin(), vec.end());
//
//	// 커넥티드 컴포넌트가 몇 개인지
//	cout << vec.size() << "\n";
//	// 사이즈들은 어떻게 되는지
//	for (int a : vec) cout << a << " ";
//
//	return 0;
//}

// 5_쿼드트리
// https://www.acmicpc.net/problem/1992
// (왼쪽위 오른쪽위 왼쪽아래 오른쪽아래)
// 0과 1이 섞여있다면 해당 부분을 괄호로 표시
// N: 영상 크기
//int quadtree[64][64];
//int N;
//
//void quadtreeserch(int y, int x, int quadsize)
//{
//	for (int i = y; i < y + quadsize; ++i)
//	{
//		for (int j = x; j < x + quadsize; ++j)
//		{
//			// 기준으로 세운 y,x와 다르다면
//			if (quadtree[y][x] != quadtree[i][j])
//			{
//				cout << "(";
//				// 왼쪽위
//				quadtreeserch(y, x, quadsize / 2);
//				// 오른쪽위
//				quadtreeserch(y, x + quadsize / 2, quadsize / 2);
//				// 왼쪽아래
//				quadtreeserch(y + quadsize / 2, x, quadsize / 2);
//				// 오른쪽아래
//				quadtreeserch(y + quadsize / 2, x + quadsize / 2, quadsize / 2);
//				cout << ")";
//				return;
//			}
//		}
//	}
//
//	// 다르지 않다면 해당 값으로 출력
//	cout << quadtree[y][x];
//}
//
//int main()
//{
//	cin >> N;
//
//	for (int i = 0; i < N; ++i)
//	{
//		string s = "";
//		cin >> s;
//
//		// quadtree 채우기
//		for (int j = 0; j < s.size(); ++j)
//		{
//			quadtree[i][j] = s[j] - '0';
//		}
//	}
//
//	quadtreeserch(0, 0, N);
//
//	return 0;
//}

// 또 다른 풀이법(분할정복)
// 내 풀이와 유사?
// 모두 0 => 0, 모두 1 =>1, 0과1 혼합이면 => (왼위 오위 왼아 오아)
// 반복되는 행위 규칙이 보이면 재귀함수 활용
// 분할정복: 큰 문제를 하위 문제로 쪼개는 방식, 하위 문제를 해결하는 방식으로 상위 문제가 해결
// 분할정복은 재귀 혹은 스택으로 풀이 가능
//int n;
//string s;
//char a[101][101];
//
//string quard(int y, int x, int size)
//{
//	// 더이상 쪼개지지 않을 때
//	// string(1, a[y][x]) => 캐릭터형을 스트링으로 바꾸기 위함
//	if (1 == size) return string(1, a[y][x]);
//
//	bool flag = false;
//	char b = a[y][x];
//	string ret = "";
//
//	for (int i = y; i < y + size; ++i)
//	{
//		for (int j = x; j < x + size; ++j)
//		{
//			if (b != a[i][j])
//			{
//				// 같지 않을 경우 괄호 속 문자열 로직
//				ret += '(';
//				ret += quard(y, x, size / 2);
//				ret += quard(y, x + size / 2, size / 2);
//				ret += quard(y + size / 2, x, size / 2);
//				ret += quard(y + size / 2, x + size / 2, size / 2);
//				ret += ')';
//				
//				return ret;
//			}
//		}
//	}
//
//	// 위의 로직에 걸리지 않는다면 0 또는 1을 반환하게 설계
//	return string(1, a[y][x]);
//}
//
//int main()
//{
//	cin >> n;
//
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> s;
//
//		for (int j = 0; j < n; ++j)
//		{
//			a[i][j] = s[j];
//		}
//	}
//
//	cout << quard(0, 0, n) << "\n";
//
//	return 0;
//}

// 6_사과 담기 게임
// https://www.acmicpc.net/problem/2828
// 바구니는 가장 처음 왼쪽에 위치
// 바구니 왼쪽을 기준으로 크기에 따라 오른쪽 위치를 재설정해주기 때문에
// 이동할 시 왼쪽 위치를 변경
// N: 스크린 크기 M: 바구니 크기, 1 <= M < N <= 10
// J: 사과 개수
//int N, M, J, lpos = 1, rpos, ret;
//
//int main()
//{
//	cin >> N >> M >> J;
//
//	for (int i = 0; i < J; ++i)
//	{
//		int value = 0;
//		cin >> value;
//		// 현재 왼쪽 위치 기준으로 오른쪽 위치 초기화
//		rpos = lpos + M - 1;
//		
//		if (0 == (lpos <= value && rpos >= value))
//		{
//			// 왼쪽 위치 보다 사과 위치가 더 작은 경우
//			if (lpos > value)
//			{
//				ret += (lpos - value);
//				lpos = value;
//			}
//			// 왼쪽 위치 보다 사과 위치가 더 작은 경우
//			else
//			{
//				ret += (value - rpos);
//				lpos += value - rpos;
//			}
//		}
//	}
//
//	cout << ret << "\n";
//
//	return 0;
//}

// 또 다른 풀이법(?)
// 내 풀이와 유사
// 최소로 움직여야 한다
//int n, m, j, l, r, temp, ret;
//
//int main()
//{
//	cin >> n >> m >> j;
//	// 왼쪽 시작 위치 지정
//	l = 1;
//
//	for (int i = 0; i < j; ++i)
//	{
//		// l로부터 시작해서 m - 1까지가 r
//		// 수정된 l을 기반으로 r 정의
//		r = l + m - 1;
//		cin >> temp;
//
//		// 바구니 안에 들어오면 continue
//		if (l <= temp && r >= temp) continue;
//		// 바구니에 담기 위해 바구니 이동
//		else
//		{
//			// 왼쪽 이동
//			if (l > temp)
//			{
//				ret += (l - temp);
//				l = temp;
//			}
//			// 오른쪽 이동
//			else
//			{
//				ret += (temp - r);
//				l += (temp - r);
//			}
//		}
//	}
//
//	cout << ret << "\n";
//
//	return 0;
//}

// 7_빈도 정렬
// https://www.acmicpc.net/problem/2910
// 자주 등장하는 숫자의 빈도 순서대로 정렬
// 등장 횟수가 같다면 먼저 나온 숫자 순서대로
// 숫자, 카운트, 순서를 생각해서 벡터 자료 구조 두개 이용, 하나로는 잘 안 떠올라서..
// N: 메시지 숫자 개수(최대 천)
// C: 숫자(수열)의 최대(최대 10억)
//int N, C;
//vector<int> order;
//vector<pair<int, int>> code;	// first: 카운트, second: 숫자
//
//bool compare(const pair<int, int>& a, const pair<int, int>& b)
//{
//	// 카운트가 같을 경우
//	if (a.first == b.first)
//	{
//		// 입력 순서대로 담긴 order 배열 이용해 정렬 정리
//		for (int i : order)
//		{
//			// a의 첫 인덱스와 b의 첫 인덱스를 비교
//			int idxa = find(order.begin(), order.end(), a.second) - order.begin();
//			int idxb = find(order.begin(), order.end(), b.second) - order.begin();
//
//			return idxa < idxb ? true : false;
//		}
//	}
//
//	return a.first > b.first;
//}
//
//int main()
//{
//	cin >> N >> C;
//
//	for (int i = 0; i < N; ++i)
//	{
//		int number = 0;
//		cin >> number;
//
//		order.push_back(number);
//	}
//
//	for (int number : order)
//	{
//		// code에 이미 숫자가 있는 경우 없는 경우를 구분하기 위한 flag bool
//		bool flag = false;
//		// code가 비어있지 않을 경우
//		if (false == code.empty())
//		{
//			for (int i = 0; i < code.size(); ++i)
//			{
//				// 같은 수가 있다면 카운트 증가 및 flag 변경
//				if (number == code[i].second)
//				{
//					++code[i].first;
//					flag = true;
//					break;
//				}
//			}
//		}
//		// code가 비어있거나 flag 변경이 없었다면 code에 추가
//		if (true == code.empty() || false == flag) code.push_back(make_pair(1, number));
//	}
//
//	// 카운트 중점 내림차순 정렬
//	sort(code.begin(), code.end(), compare);
//
//	for (pair<int, int> temp : code)
//	{
//		// 카운트 숫자에 맞게 반복 출력
//		for (int i = 0; i < temp.first; ++i)
//		{
//			cout << temp.second << " ";
//		}
//	}
//
//	return 0;
//}

// 또 다른 풀이법(?)
// 해당 문제는 커스텀 오퍼레이터(?)를 떠올려야 한다
// 1순위 정렬: 카운팅, 2순위 정렬: 먼저 나온 수
//int n, c, a[1004];
//vector<pair<int, int>> v;
//map<int, int> mp, mp_first;		// mp: 카운팅 배열로 사용, mp_first: 첫 번째 값 할당
//
//bool cmp(pair<int, int> a, pair<int, int> b)
//{
//	// 카운팅이 같다면
//	if (a.first == b.first)
//	{
//		// 먼저 나온 것을 비교
//		return mp_first[a.second] < mp_first[b.second];
//	}
//
//	return a.first > b.first;
//}
//
//int main()
//{
//	cin >> n >> c;
//
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> a[i];
//		++mp_first[a[i]];
//
//		// mp_first[a[i]]에 값이 있는지 없는지, 0이면 값이 없었던 것으로 새로 할당
//		// i + 1로 한 이유는, 참조가 일어나지 않았으면 0이기 때문에 i로 할 경우 초반에 0으로 되어 로직에 문제가 발생하기 때문 
//		if (0 == mp_first[a[i]]) mp_first[a[i]] = i + 1;
//	}
//
//	for (auto& it : mp) v.push_back({ it.second, it.first });
//
//	sort(v.begin(), v.end(), cmp);
//
//	for (auto& i : v)
//	{
//		for (int j = 0; j < i.first; ++j)
//		{
//			cout << i.second << " ";
//		}
//	}
//
//	return 0;
//}

// 8_비밀번호 발음하기
// https://www.acmicpc.net/problem/4659
// 모음 하나를 반드시 포함 / 연속된 모음 3개 혹은 연속된 자음 3개 불가 / 같은 문자 연속 두번X(단, ee나 oo 가능)
// 비밀번호는 20자 이하의 문자열
//string str;
//int vowelcnt, consonantcnt;
//
//bool password()
//{
//	// 초기화
//	vowelcnt = 0;
//	consonantcnt = 0;
//
//	// 모음 포함 확인
//	bool bVowel = false;
//	for (char c : str)
//	{
//		if ('a' == c || 'e' == c || 'i' == c || 'o' == c || 'u' == c)
//		{
//			bVowel = true;
//			break;
//		}
//	}
//
//	if (false == bVowel) return false;
//
//	// 연속 모음 3개, 자음 3개 => false 확인
//	for (int i = 0; i < str.size(); ++i)
//	{
//		// 모음
//		if ('a' == str[i] || 'e' == str[i] || 'i' == str[i] || 'o' == str[i] || 'u' == str[i])
//		{
//			++vowelcnt;
//			consonantcnt = 0;
//		}
//		// 자음
//		else
//		{
//			++consonantcnt;
//			vowelcnt = 0;
//		}
//
//		if (3 <= vowelcnt || 3 <= consonantcnt) return false;
//	}
//
//
//	// 같은 문자 연속 두번 => false
//	// ee, oo => true
//	for (int i = 1; i < str.size(); ++i)
//	{
//		if ('e' == str[i] || 'o' == str[i]) continue;
//		if (str[i] == str[i - 1]) return false;
//	}
//	
//	// 위의 조건들에 안 걸리고 여기까지 왔다면 비밀번호 성공
//	return true;
//}
//
//void print(bool bFT)
//{
//	string ret = bFT ? "> is acceptable." : "> is not acceptable.";
//	
//	cout << '<' << str << ret << "\n";
//}
//
//int main()
//{
//	while (true)
//	{
//		cin >> str;
//
//		if ("end" == str) break;
//
//		print(password());
//	}
//
//	return 0;
//}

// 또 다른 풀이법(?)
// flag를 이용하여 풀이
// 조건1) 모음 또는 자음이 3개 이상X
// 조건2) 모음 반드시 포함
// 조건3) o,e 제외 연속 불가
//string s;
//int lcnt, vcnt;
//
//bool isVowel(int idx)
//{
//	return ('a' == idx || 'e' == idx || 'i' == idx || 'o' == idx || 'u' == idx);
//}
//
//int main()
//{
//	while (true)
//	{
//		cin >> s;
//
//		if ("end" == s) break;
//
//		// 초기화
//		lcnt = vcnt = 0;
//
//		bool flag = 0;
//		bool is_include_v = 0;
//		int prev = -1;
//
//		// s 문자열만큼 순회
//		for (int i = 0; i < s.size(); ++i)
//		{
//			// idx == 알파벳 아스키코드
//			int idx = s[i];
//			// isVowel함수로 모음인지 확인
//			// 모음
//			if (true == isVowel(idx))
//			{
//				++lcnt;
//				vcnt = 0;
//				// 모음이 반드시 있는지 확인하기 위한 것
//				is_include_v = 1;
//			}
//			// 자음
//			else
//			{
//				++vcnt;
//				lcnt = 0;
//			}
//
//			// 모음 혹은 자음이 연속 3개일 때를 확인
//			if (3 == vcnt || 3 == lcnt) flag = 1;
//
//			// s[i] == a[i - 1]도 가능하지만 prev를 이용하는 방법도 있음
//			// 0의 이전은 존재하지 않으니까 1이상인지 확인
//			// 현재 idx와 이전이 같은지 확인
//			// e,o가 아닌지 확인
//			if ((1 <= i) && (idx == prev) && ('e' != idx && 'o' != idx)) flag = 1;
//			// 연속된 같은 문자 확인을 위한, 전항에 대한 정보를 업데이트
//			// 이와 같이하면 직전 항과 비교를 변수 하나로 쉽게 해결 가능
//			prev = idx;
//		}
//
//		if (0 == is_include_v) flag = 1;
//
//		if (true == flag) cout << "<" << s << ">" << " is not acceptable.\n";
//		else cout << "<" << s << ">" << " is acceptable.\n";
//	}
//
//	return 0;
//}

// 9_수학숙제
// https://www.acmicpc.net/problem/2870
// 오름차순 정렬
// 숫자 앞에 0이 있을 경우 생략 가능
// N: 종이 줄 개수
//int N;
//// long long 또한 8바이트로 64자리까지 밖에 표현 못한다..
//// string으로 담아서 sort 할 때 문자열 길이로 정렬하고 길이가 같을 경우 아스키코드상 작은 수가 먼저 오게 정렬하는 함수 필요 할 듯? => 성공
////vector<long long> vec;
//vector<string> vec;
//
//bool compare(string& a, string& b)
//{
//	if (a.size() == b.size()) return a < b;
//
//	return a.size() < b.size();
//}
//
//int main()
//{
//	cin >> N;
//
//	for (int i = 0; i < N; ++i)
//	{
//		string str = "";
//		cin >> str;
//
//		string num = "";
//		for (int j = 0; j < str.size(); ++j)
//		{
//			// 숫자문자 일 경우
//			if (10 > str[j] - '0')
//			{
//				// 숫자 앞에 0이 있으면 제거하기 위함
//				if ("0" == num)
//				{
//					num = str[j];
//					continue;
//				}
//
//				num += str[j];
//			}
//			else
//			{
//				if (false == num.empty())
//				{
//					vec.push_back(num);
//					num = "";
//				}
//			}
//		}
//
//		// 중복되는 코드라 마음에 들지 않지만.. 마지막이 숫자 문자거나 숫자문자로만 들어오는 경우 때문에 추가
//		if (false == num.empty()) vec.push_back(num);
//	}
//
//	sort(vec.begin(), vec.end(), compare);
//
//	for (string i : vec) cout << i << "\n";
//
//	return 0;
//}

// 또 다른 풀이법(?)
// 100글자, 문자열 중 숫자를 찾아 벡터에 담아 숫자 정렬
// int는 10글자 표현 가능
// long long은 19글자 => 엇 비트와 바이트를 생각해서 해당 크기만큼의 자리인줄 알고 64자리까지 되는 줄 알았는데 너무나도 잘못 알고 있었다
// string으로 처리해야됨
// 숫자만 뽑는 로직 -> 앞에 0이 있을 때 뺴는 로직
//int n;
//string s, ret;
//vector<string> v;
//
//// 0에 대한 처리 함수
//void go()
//{
//	// 0 제거
//	while (true)
//	{
//		// ret이 비어있지 않고 ret의 제일 앞이 '0'이라면, 앞 0을 지우기
//		if (0 != ret.size() && '0' == ret.front()) ret.erase(ret.begin());
//		else break;
//	}
//
//	// 0 하나인 경우가 있기 때문에 다 없으면 0이 없어지는 해당 오류부분 잡기
//	if (0 == ret.size()) ret = "0";
//
//	v.push_back(ret);
//	ret = "";
//}
//
//// 문자열 비교를 했을 때 123, 20이 있다면 string sort는 123이 20보다 작다고 처리
//// 따라서 해당 부분에 대한 커스텀 오퍼레이터
//bool cmp(string a, string b)
//{
//	if (a.size() == b.size()) return a < b;
//
//	return a.size() < b.size();
//}
//
//int main()
//{
//	cin >> n;
//
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> s;
//		// 문자 초기화
//		ret = "";
//
//		for (int j = 0; j < s.size(); ++j)
//		{
//			// 숫자 만들기
//			if (65 > s[j]) ret += s[j];
//			// 문자가 숫자가 아니고 ret이 비어있지 않으면 go 호출
//			else if (0 != ret.size()) go();
//		}
//
//		if (0 != ret.size()) go();
//	}
//
//	sort(v.begin(), v.end(), cmp);
//
//	for (string i : v) cout << i << "\n";
//
//	return 0;
//}

// 10_기상캐스터
// https://www.acmicpc.net/problem/10709
// 1분마다 동쪽으로 이동
// 외부 구름 유입X
// H: 행, W: 열
//int H, W;
//int cloudemove[100][100];
//
//int main()
//{
//	cin >> H >> W;
//
//	for (int i = 0; i < H; ++i)
//	{
//		string str = "";
//		cin >> str;
//
//		for (int j = 0; j < W; ++j)
//		{
//			// 구름을 제외한 나머지 -1
//			if ('.' == str[j]) cloudemove[i][j] = -1;
//		}
//	}
//
//	for (int i = 0; i < H; ++i)
//	{
//		int cnt = -1;
//		for (int j = 0; j < W; ++j)
//		{
//			// 구름을 만났을 때 카운팅 시작
//			if (0 == cloudemove[i][j])
//			{
//				cnt = 0;
//				continue;
//			}
//			// 구름 만나서 cnt의 값이 변경되면 카운트
//			else if(-1 != cnt) ++cnt;
//
//			cloudemove[i][j] = cnt;
//		}
//	}
//
//	for (int i = 0; i < H; ++i) 
//	{
//		for (int j = 0; j < W; ++j) cout << cloudemove[i][j] << " ";
//
//		cout << "\n";
//	}
//
//	return 0;
//}

// 또 다른 풀이법(?)
// 구름이 있다면 0으로 시작해서 카운트 증가
// 구름이 계속 없다면 -1
//int n, m, a[104][104];
//string s;
//
//int main()
//{
//	cin >> n >> m;
//
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> s;
//
//		for (int j = 0; j < m; ++j)
//		{
//			//'.' == s[j] ? a[i][j] = -1 : a[i][j] = 0;
//			if ('.' == s[j]) a[i][j] = -1;
//			else a[i][j] = 0;
//		}
//	}
//
//	for (int i = 0; i < n; ++i)
//	{
//		for (int j = 0; j < m; ++j)
//		{
//			// 구름이 있다면
//			if (0 == a[i][j])
//			{
//				int cnt = 0;
//
//				// 구름이 아닌 지점은 계속 탐색해서 증가
//				while (-1 == a[i][j + 1])
//				{
//					a[i][j + 1] = ++cnt;
//					// 끝난 지점부터 시작해야되기 때문
//					++j;
//				}
//			}
//		}
//	}
//
//	for (int i = 0; i < n; ++i)
//	{
//		for (int j = 0; j < m; ++j) cout << a[i][j] << " ";
//
//		cout << "\n";
//	}
//
//	return 0;
//}

// 11_교수가 된 현우
// https://www.acmicpc.net/problem/3474
// 오른쪽 끝에 있는 0의 개수, 10을 만들 수 있는 2,5의 수를 파악하면 0의 개수를 알기 쉬울 듯?
// T: 테스트 케이스 개수
//int T;
//
//int main()
//{
//	// 아래 코드 추가 안하면 시간초과
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	cin >> T;
//
//	while (0 < T)
//	{
//		int N = 0;
//		cin >> N;
//
//		// 5의 배수만 알아도 파악 가능
//		int multi5 = 0;
//		for (int i = 5; i <= N; i *= 5)
//		{
//			multi5 += (N / i);
//		}
//
//		cout << multi5 << "\n";
//
//		--T;
//	}
//
//	return 0;
//}

// 또 다른 풀이법(?)
// 내 풀이와 유사
// 만약 2400이라는 수가 있으면 24 x 10 x 10
// 즉 0의 개수는 10의 개수
// 10은 2 x 5, 따라서 2의 개수 5의 개수를 알면 0의 개수를 구할 수 있음
// 순차적 탐색은 무리, 따라서 2와 5의 승수 배수를 구하는 것이 빠름
// 해당 개수를 구한 것을 바탕은 최소 min 값을 구하면 됨
//int n, a;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	cin >> n;
//
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> a;
//		int ret2 = 0, ret5 = 0;
//		// 2의 승수
//		for (int j = 2; j <= a; j *= 2)
//		{
//			ret2 += a / j;
//		}
//		// 5의 승수
//		for (int j = 5; j <= a; j *= 5)
//		{
//			ret5 += a / j;
//		}
//
//		cout << min(ret2, ret5) << "\n";
//	}
//
//	return 0;
//}

// 12_NBA 농구
// https://www.acmicpc.net/problem/2852
// 48분은 48 x 60 = 2880초
// N: 골 들어간 횟수
//int N, Team1, Team2, LastScore;
//vector<int> Record(2);
//
//// 문자열로 받은 시간을 정수형 초로 변환
//int TimeToSeconds(const string& InTime)
//{
//	return atoi(InTime.substr(0, 2).c_str()) * 60 + atoi(InTime.substr(3, 2).c_str());
//}
//
//int main()
//{
//	cin >> N;
//
//	for (int i = 0; i < N; ++i)
//	{
//		int Winner = 0;
//		string ScoreTime = "";
//		cin >> Winner;
//		cin >> ScoreTime;
//
//		// 각 팀이 이기고 있을 때 현재 시간과 이전 점수 낸 시간차를 누적
//		if (Team1 > Team2)
//		{
//			Record[0] += TimeToSeconds(ScoreTime) - LastScore;
//		}
//		else if (Team1 < Team2)
//		{
//			Record[1] += TimeToSeconds(ScoreTime) - LastScore;
//		}
//
//		// 팀 점수 계산
//		1 == Winner ? ++Team1 : ++Team2;
//		// 현재 점수 낸 시간을 초로 변환하여 다음 계산 시 이전 시간으로 활용
//		LastScore = TimeToSeconds(ScoreTime);
//	}
//
//	// 최종 우승팀의 경기 종료 시간까지의 합산
//	if (Team1 > Team2) Record[0] += 2880 - LastScore;
//	else if (Team1 < Team2) Record[1] += 2880 - LastScore;
//
//	// '00' 두자리 표시를 위해 분 및 초 시간 길이를 통하여 시간 앞에 0 붙이는 작업이자 출력
//	cout << string(2 - to_string(Record[0] / 60).size(), '0').append(to_string(Record[0] / 60)) << ":" << string(2 - to_string(Record[0] % 60).size(), '0').append(to_string(Record[0] % 60)) << "\n";
//	cout << string(2 - to_string(Record[1] / 60).size(), '0').append(to_string(Record[1] / 60)) << ":" << string(2 - to_string(Record[1] % 60).size(), '0').append(to_string(Record[1] % 60)) << "\n";
//
//	return 0;
//}

// 또 다른 풀이법(prev 활용 및 단위 통일)
// 내 풀이와 유사...한가?
// prev를 이용하여 변수 하나만으로 직전 값을 쉽게 활용(define을 사용해야함, 번거로워서 pre로 사용)
// 시간의 간격을 기반으로 시간 합산
// 시, 분, 초가 나오면 하나의 단위로 통일할 것(작은 단위 기반의 단위로 통일하는 것이 좋음)
//int n, o, A, B, asum, bsum;
//string s, pre;
//
//// MM:SS 로 변경
//string print(int a)
//{
//	// 포맷화 작업
//	string d = "00" + to_string(a / 60);
//	string e = "00" + to_string(a % 60);
//
//	return d.substr(d.size() - 2, 2) + ":" + e.substr(e.size() - 2, 2);
//}
//
//// 초 단위로 변경
//int changeToInt(string a)
//{
//	return atoi(a.substr(0, 2).c_str()) * 60 + atoi(a.substr(3, 2).c_str());
//}
//
//void go(int& sum, string s)
//{
//	// 시간차 간격을 합산
//	sum += (changeToInt(s) - changeToInt(pre));
//}
//
//int main()
//{
//	cin >> n;
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> o >> s;
//		// A팀이 이기고 있는지 B팀이 이기고 있는지에 따라 얼마만큼 이기고 있는지 연산
//		if (A > B) go(asum, s);
//		else if (A < B) go(bsum, s);
//
//		1 == o ? ++A : ++B;
//		pre = s;
//	}
//
//	// 마지막 끝 점수 처리
//	if (A > B) go(asum, "48:00");
//	else if (A < B) go(bsum, "48:00");
//
//	cout << print(asum) << "\n";
//	cout << print(bsum) << "\n";
//
//	return 0;
//}

// 13_영화감독 숌
// https://www.acmicpc.net/problem/1436
// N: 숌의 N번째 영화 제목
//int N, cnt, number = 666;
//
//int main()
//{
//	cin >> N;
//
//	// number(666부터 시작, 666이 첫번째 시리즈)가 주어진 조건 만족될 때까지 증가
//	while(true)
//	{
//		// number에 666이 있을 경우 카운트
//		if (string::npos != to_string(number).find("666")) ++cnt;
//		// N번째 시리즈와 카운트가 같다면 종료
//		if (N == cnt) break;
//
//		++number;
//	}
//
//	// N번째 시리즈의 숫자
//	cout << number << "\n";
//
//	return 0;
//}

// 또 다른 풀이법(?)
// 내 풀이와 유사
// 666이 들어간 n번째의 숫자
// 해당 문제는 어떻게 풀지 생각하기 보단 무식하게 먼저 푸는 것을 고려
// n의 범위가 10000 => 어림잡아 6660000
// 보통은 10000000까지는 무식하게 해볼 법 함
//int n;
//
//int main()
//{
//	cin >> n;
//
//	int i = 666;
//	for (;; ++i)					// 해당 부분은 무한루프와도 같다고 보면 됨, 끝조건이 없으므로 무한
//	{
//		// 666이 포함되면 n을 감소
//		if (string::npos != to_string(i).find("666")) --n;
//		if (0 == n) break;
//
//	}
//
//	cout << i << "\n";
//
//	return 0;
//}

// 14_괄호
// https://www.acmicpc.net/problem/9012
// 스택 활용 문제
// T: 입력 테스트 데이터 개수
//int T;
//
//int main()
//{
//	cin >> T;
//
//	while (T--)
//	{
//		string Parentheses = "";
//		stack<char> stk;
//		cin >> Parentheses;
//
//		for (int i = 0; i < Parentheses.size(); ++i)
//		{
//			// 처음으로 )이 들어 올경우 NO 반환
//			if (true == stk.empty() && ')' == Parentheses[i])
//			{
//				stk.push(Parentheses[i]);
//				break;
//			}
//
//			// 스택이 비어 있지 않고 들어온 문자가 ')'이고 스택의 탑이 '('이면 탑 삭제 하고 컨티뉴
//			if (false == stk.empty() && ')' == Parentheses[i] && '(' == stk.top())
//			{
//				stk.pop();
//				continue;
//			}
//
//			// 위에 아무 조건도 해당 안된다면 스택에 추가
//			stk.push(Parentheses[i]);
//		}
//
//		// 스택이 비어있으면 YES, 비어있지 않으면 NO
//		string ret = true == stk.empty() ? "YES" : "NO";
//
//		cout << ret << "\n";
//	}
//
//	return 0;
//}

// 또 다른 풀이법(stack)
// 짝짓기, 폭발, 아름다운 괄호만들기 => stack으로 풀지 않을까 생각할 것
// 해당 문제의 로직을 작성할 때 2가지 고려할 것
// 1. ()가 될 때 pop
// 2. 빈 스택에 ')'이 들어오면 더이상 처리될 필요 없이 바로 NO
//int n;
//string s;
//
//// 올바른 괄호인지 아닌지 확인해주는 불리언 함수
//bool check(string s)
//{
//	// 스택을 매번 정의해서 새로운 스택을 초기화한다고 생각하면 됨
//	stack<char> stk;
//	for (char c : s)
//	{
//		// '('이면 그냥 push
//		if ('(' == c) stk.push(c);
//		// 그게 아니면(')'일 때)
//		else
//		{
//			// 만약 스택이 비어있지 않으면 pop
//			// 즉 ')'인데 스택이 비어있지 않으면 '()'이 만들어지므로 pop
//			if (false == stk.empty()) stk.pop();
//			// 스택이 비어있다면 결과는 false
//			// 즉 빈 공간에 ')'이면 뭘해도 빈 스택을 만들 수 없기 때문
//			else return false;
//		}
//	}
//
//	return stk.empty();
//}
//
//int main()
//{
//	cin >> n;
//
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> s;
//		if (true == check(s)) cout << "YES\n";
//		else cout << "NO\n";
//	}
//
//	return 0;
//}

// 15_균형잡힌 세상
// https://www.acmicpc.net/problem/4949
// 문자열에 포함되는 괄호는 소괄호("()") 와 대괄호("[]")로 2종류
// - 모든 왼쪽 소괄호("(")는 오른쪽 소괄호(")")와만 짝
// - 모든 왼쪽 대괄호("[")는 오른쪽 대괄호("]")와만 짝
// - 모든 오른쪽 괄호들은 자신과 짝을 이룰 수 있는 왼쪽 괄호가 존재
// - 모든 괄호들의 짝은 1:1 매칭만 가능 즉, 괄호 하나가 둘 이상의 괄호와 짝지어지지X
// - 짝을 이루는 두 괄호가 있을 때, 그 사이에 있는 문자열도 균형
// 입력의 종료조건으로 맨 마지막에 온점 하나(".")
//string str;
//
//int main()
//{
//	while (true)
//	{
//		getline(cin, str);
//
//		stack<char> stk;
//
//		// "."이면 종료
//		if (0 == str.compare(".")) break;
//
//		for (int i = 0; i < str.size(); ++i)
//		{
//			// ( 혹은 [ 이면 스택에 넣기
//			if ('(' == str[i] || '[' == str[i]) stk.push(str[i]);
//			// ) 혹은 ] 일 때
//			else if (')' == str[i] || ']' == str[i])
//			{
//				// 스택이 비어있는데 들어오면 무조건 no
//				if (true == stk.empty())
//				{
//					stk.push(str[i]);
//					break;
//				}
//
//				// 짝맞춰서 파괴하기
//				if ('(' == stk.top() && ')' == str[i]) stk.pop();
//				else if ('[' == stk.top() && ']' == str[i]) stk.pop();
//				else break;
//			}
//		}
//
//		// 스택이 비어있다면 yes, 비어있지 않다면 no
//		string ret = true == stk.empty() ? "yes" : "no";
//		cout << ret << "\n";
//	}
//
//	return 0;
//}

// 또 다른 풀이법(stack)
// 괄호에 따른 판별해주는 프로그램 작성
// 짝짓기 문제, 짝짓기는 스택 문제
// 띄어쓰기가 포함된 문자 받기 => cin 사용X, getline 사용O
// 왼쪽괄호는 스택에 쌓고 오른쪽괄호가 왔을 때 짝을 짓는 괄호가 되는지 판별 로직 설계
//int main()
//{
//	// 계속해서 문자열을 받아야하므로 while문 사용
//	while (true)
//	{
//		string s;
//		// 문자열 받기
//		getline(cin, s);
//		
//		// .이 들어왔을 때 종료
//		if ("." == s) break;
//
//		// 매버 테케마다 스택으로 새로이 정의
//		stack<int> stk;
//		bool check = true;
//		// 문자열 탐색
//		for (int i = 0; i < s.length(); ++i)
//		{
//			// 오른쪽 괄호 짝짓기 판별 로직
//			if (')' == s[i])
//			{
//				// 스택 사이즈 확인 후 스택 탑 확인
//				if (0 == stk.size() || '[' == stk.top())
//				{
//					check = false;
//					break;
//				}
//				// ()
//				else stk.pop();
//			}
//			if (']' == s[i])
//			{
//				// 스택 사이즈 확인 후 스택 탑 확인
//				if (0 == stk.size() || '(' == stk.top())
//				{
//					check = false;
//					break;
//				}
//				// []
//				else stk.pop();
//			}
//
//			// 왼쪽 괄호 스택에 넣기
//			if ('(' == s[i]) stk.push(s[i]);
//			if ('[' == s[i]) stk.push(s[i]);
//		}
//
//		if (true == check && 0 == stk.size()) cout << "yes\n";
//		else cout << "no\n";
//	}
//
//	return 0;
//}

// 16_연구소 
// https://www.acmicpc.net/problem/14502
// 인접한 빈칸으로 바이러스가 퍼져나간다 => 커넥티드 컴포넌트(DFS)
// 벽 3개를 세워서 바이러스가 퍼지지 않은 최대 안전 영역 구하기
// 현재 벽 정보와 바이러스 정보를 통해서 3개를 순차적으로 세워 체크하는 방식으로 우선 다 해보는 것은 어느 정도?
// N: 세로, M: 가로
// 0: 빈 칸, 1: 벽, 2: 바이러스 위치
//int N, M, ret;
//int lab[10][10], visited[10][10];
//int dy[] = { -1, 0, 1, 0 };
//int dx[] = { 0, 1, 0, -1 };
//vector<pair<int, int>> virvec, wallvec;
//
//void DFS(int y, int x)
//{
//	visited[y][x] = 1;
//
//	for (int i = 0; i < 4; ++i)
//	{
//		int ny = y + dy[i];
//		int nx = x + dx[i];
//
//		if (0 > ny || 0 > nx || N <= ny || M <= nx) continue;
//		if (1 == lab[ny][nx] || 1 == visited[ny][nx]) continue;
//
//		DFS(ny, nx);
//	}
//}
//
//int spread()
//{
//	fill(&visited[0][0], &visited[0][0] + 10 * 10, 0);
//
//	// 바이러스 정보를 통해 탐색
//	for (const auto& i : virvec)
//	{
//		DFS(i.first, i.second);
//	}
//
//	int cnt = 0;
//
//	for (int i = 0; i < N; ++i)
//	{
//		for (int j = 0; j < M; ++j)
//		{
//			// 안전 영역 크기 카운트
//			if (0 == lab[i][j] && 0 == visited[i][j]) ++cnt;
//		}
//	}
//
//	// 최종 안전 영역 크기 반환
//	return cnt;
//}
//
//int main()
//{
//	cin >> N >> M;
//
//	// 연구실 구조 입력 받기
//	for (int i = 0; i < N; ++i)
//	{
//		for (int j = 0; j < M; ++j)
//		{
//			cin >> lab[i][j];
//
//			// 벽 정보
//			if (0 == lab[i][j]) wallvec.push_back({ i,j });
//			// 바이러스 정보
//			if (2 == lab[i][j]) virvec.push_back({ i,j });
//		}
//	}
//
//	for (int i = 0; i < wallvec.size(); ++i)
//	{
//		for (int j = 0; j < i; ++j)
//		{
//			for (int k = 0; k < j; ++k)
//			{
//				// 벽 3개 세우기
//				lab[wallvec[i].first][wallvec[i].second] = 1;
//				lab[wallvec[j].first][wallvec[j].second] = 1;
//				lab[wallvec[k].first][wallvec[k].second] = 1;
//				// 커넥티드 컴포넌트로 안전 구역 파악(최대 크기 판별)
//				ret = max(ret, spread());
//				// 벽 3개 허물기
//				lab[wallvec[i].first][wallvec[i].second] = 0;
//				lab[wallvec[j].first][wallvec[j].second] = 0;
//				lab[wallvec[k].first][wallvec[k].second] = 0;
//			}
//		}
//	}
//
//	cout << ret;
//
//	return 0;
//}

// 또 다른 풀이법(?)
// 내 풀이와 완전 유사
// 1. 벽을 세운다 2. 바이러스가 퍼진다 3. 바이러스가 퍼진 영역, 안전 영역 카운팅 => max 값
// 벽을 효율적으로 세운다 가 아닌 무식하게 벽을 세워볼까 해야 함
// 먼저 모든 경우의 수를 고려하고 이후에 효율적으로 할 수 있을까를 생각해야함
// 맵의 최대 범위는 8 * 8 => 64
// 64에서 3개의 벽을 세운다? => 64C3
//int a[10][10], visited[10][10], n, m, ret;
//vector<pair<int, int>> virusList, wallList;
//const int dy[] = { -1, 0, 1, 0 };
//const int dx[] = { 0, 1, 0, -1 };
//
//void dfs(int y, int x)
//{
//	for (int i = 0; i < 4; ++i)
//	{
//		int ny = y + dy[i];
//		int nx = x + dx[i];
//
//		if (0 > ny || 0 > nx || n <= ny || m <= nx) continue;
//		if (0 != visited[ny][nx] || 1 == a[ny][nx]) continue;
//
//		visited[ny][nx] = 1;
//
//		dfs(ny, nx);
//	}
//}
//
//int solve()
//{
//	// 경우의 수마다 방문 배열을 초기화
//	fill(&visited[0][0], &visited[0][0] + 10 * 10, 0);
//
//	// 바이러스 퍼뜨리기
//	for (pair<int, int> b : virusList)
//	{
//		visited[b.first][b.second] = 1;
//		dfs(b.first, b.second);
//	}
//
//	int cnt = 0;
//	for (int i = 0; i < n; ++i)
//	{
//		for (int j = 0; j < m; ++j)
//		{
//			if (0 == a[i][j] && false == visited[i][j]) ++cnt;
//		}
//	}
//
//	return cnt;
//}
//
//int main()
//{
//	// 입력 받기
//	cin >> n >> m;
//
//	for (int i = 0; i < n; ++i)
//	{
//		for (int j = 0; j < m; ++j)
//		{
//			cin >> a[i][j];
//
//			// 바이러스 퍼뜨릴 때 해당 지점 정보를 사용
//			if (2 == a[i][j]) virusList.push_back({ i,j });
//			// 벽은 바이러스 있는 지점에 세울 수 없음 따라서 벽을 세울 수 있는 지점을 담아 추후 벽 세울 때 사용
//			if (0 == a[i][j]) wallList.push_back({ i,j });
//		}
//	}
//
//	for (int i = 0; i < wallList.size(); ++i)
//	{
//		for (int j = 0; j < i; ++j)
//		{
//			for (int k = 0; k < j; ++k)
//			{
//				// 벽 놓을 수 있는 위치에 벽 세우기
//				a[wallList[i].first][wallList[i].second] = 1;
//				a[wallList[j].first][wallList[j].second] = 1;
//				a[wallList[k].first][wallList[k].second] = 1;
//				ret = max(ret, solve());
//				// 원복 작업
//				a[wallList[i].first][wallList[i].second] = 0;
//				a[wallList[j].first][wallList[j].second] = 0;
//				a[wallList[k].first][wallList[k].second] = 0;
//			}
//		}
//	}
//
//	cout << ret << "\n";
//
//	return 0;
//}

// 17_치즈 
// https://www.acmicpc.net/problem/2636
// 공기에 닿아 있는 치즈만이 녹음
// 1)모두 녹아서 사라지는 시간, 2)다 녹기 한시간 직전의 치즈 조각 구하기
//const int max_ch = 100;
//int m, n, melttime, piece, cheese[max_ch][max_ch], visited[max_ch][max_ch];
//const int dy[] = { -1, 0, 1, 0 };
//const int dx[] = { 0, 1, 0, -1 };
//
//void DFS(int y, int x)
//{
//	visited[y][x] = 1;
//
//	for (int i = 0; i < 4; ++i)
//	{
//		int ny = y + dy[i];
//		int nx = x + dx[i];
//
//		if (0 > ny || 0 > nx || m <= ny || n <= nx) continue;
//		if (0 == cheese[ny][nx] && 0 == visited[ny][nx]) DFS(ny, nx);
//		if (1 == cheese[ny][nx] && 0 == visited[ny][nx])
//		{
//			++piece;					// 조각 파악하기
//			cheese[ny][nx] = 0;			// 치즈 녹이기
//			visited[ny][nx] = 1;		// 중복 및 다음 치즈 녹임을 방지하고자 방문 체크
//		}
//	}
//}
//
//int main()
//{
//	// 치즈 입력 받기
//	cin >> m >> n;
//	for (int i = 0; i < m; ++i)
//	{
//		for (int j = 0; j < n; ++j)
//		{
//			cin >> cheese[i][j];
//		}
//	}
//
//	while (true)
//	{
//		// 방문기록 및 치즈 조각 초기화 
//		fill(&visited[0][0], &visited[0][0] + max_ch * max_ch, 0);
//		// 최종적으로 녹기 전 치즈 개수를 구하기 위한 코드 위치 및 초기화
//		piece = 0;
//
//		++melttime;
//		DFS(0, 0);
//
//		bool check = false;
//		for (int i = 0; i < m; ++i)
//		{
//			for (int j = 0; j < n; ++j)
//			{
//				// 치즈가 하나라도 존재하면 반복
//				if (1 == cheese[i][j]) check = true;
//			}
//		}
//
//		// 치즈가 하나도 없으면 check가 바뀔리X
//		// 따라서 false이면 while문 탈출
//		if (false == check) break;
//	}
//
//	cout << melttime << "\n";
//	cout << piece << "\n";
//
//	return 0;
//}

// 또 다른 풀이법(?)
// 내 풀이와 유사
// 판의 가장자리는 모두 0, 치즈 존재X
// 판의 가장자리는 모두 0이라는 조건이 없었다면, 치즈가 없는 부분을 찾는 로직을 우선적으로 작성해야됨
// 0 방문, 1 멈춤
// 1로 닿아서 멈추는 부분을 특정 자료 구조에 담아둔 후 담은 것들을 모두 0으로 변경
// 담아 놓은 자료구조의 사이즈가 치즈의 크기
// 1) DFS(0 탐색, 1 자료구조 담기) 2) 시간 증가, 자료구조에 담긴 것들 0으로 변경
//int n, m, cnt, cnt2, a[104][104], visited[104][104];
//const int dy[] = { -1, 0, 1, 0 };
//const int dx[] = { 0, 1, 0, -1 };
//vector<pair<int, int>> v;
//
//void go(int y, int x)
//{
//	visited[y][x] = 1;
//
//	// 치즈면 더이상 방문X
//	if (1 == a[y][x])
//	{
//		// 벡터로 치즈 위치 관리
//		v.push_back({ y,x });
//		return;
//	}
//
//	for (int i = 0; i < 4; ++i)
//	{
//		int ny = y + dy[i];
//		int nx = x + dx[i];
//
//		// 언더 오버 플로우 체크 + 방문 기록 체크
//		if (0 > ny || 0 > nx || n <= ny || m <= nx || 0 != visited[ny][nx]) continue;
//		go(ny, nx);
//	}
//}
//
//int main()
//{
//	cin >> n >> m;
//	for (int i = 0; i < n; ++i)
//	{
//		for (int j = 0; j < m; ++j)
//		{
//			cin >> a[i][j];
//		}
//	}
//
//	while (true)
//	{
//		// 초기화
//		fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);
//		v.clear();
//
//		go(0, 0);
//		// 치즈 크기
//		cnt2 = v.size();
//		// 치즈 녹이기
//		for (pair<int, int> b : v) a[b.first][b.second] = 0;
//
//		// 치즈가 다 녹아있는지 확인
//		bool flag = false;
//		for (int i = 0; i < n; ++i)
//		{
//			for (int j = 0; j < m; ++j)
//			{
//				if (0 != a[i][j]) flag = true;
//			}
//		}
//
//		++cnt;
//
//		if (true != flag) break;
//	}
//
//	cout << cnt << "\n" << cnt2 << "\n";
//
//	return 0;
//}

// 18_tree
// https://www.acmicpc.net/problem/1068
// 트리의 노드 끊기.. 큐를 이용하면 되려나 큐가 아니라 연결 리스트 형식으로 해야하나
// 루트는 -1
// 들어오는 수는 -1을 제외하고 본인의 부모 인덱스를 뜻함
// N: 노드 개수
int N, cnt, visited[50];
vector<int> Tree[50];

void leaf(int node, int deletenode)
{
	for (int num : Tree[node])
	{
		// 탐색할 노드가 있다면 탐색
		if (0 != Tree[num].size()) leaf(num, deletenode);
		// 삭제된 노드 최상단 노드가 아니면 리프노드로 카운트 증가
		else if (num != deletenode) ++cnt;
		// 삭제된 노드 최상단 노드이고 해당 노드가 혼자 존재했다면 리프노드로 카운트 증가
		else if (num == deletenode && 1 == Tree[node].size()) ++cnt;
	}
}

void noderemove(int nodenum)
{
	// 지울 수 있는 노드 탐색
	for (int num : Tree[nodenum]) noderemove(num);

	// 노드 정리
	Tree[nodenum].clear();
}

int main()
{
	cin >> N;

	int node, removenode, root = 0;
	for (int i = 0; i < N; ++i)
	{
		cin >> node;

		if (-1 == node)
		{
			root = i;
		}
		else Tree[node].push_back(i);
	}

	cin >> removenode;
	noderemove(removenode);
	leaf(root, removenode);

	cout << cnt << "\n";

	return 0;
}