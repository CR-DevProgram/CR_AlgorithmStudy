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
string s;
int lcnt, vcnt;

bool isVowel(int idx)
{
	return ('a' == idx || 'e' == idx || 'i' == idx || 'o' == idx || 'u' == idx);
}

int main()
{
	while (true)
	{
		cin >> s;

		if ("end" == s) break;

		// 초기화
		lcnt = vcnt = 0;

		bool flag = 0;
		bool is_include_v = 0;
		int prev = -1;

		// s 문자열만큼 순회
		for (int i = 0; i < s.size(); ++i)
		{
			// idx == 알파벳 아스키코드
			int idx = s[i];
			// isVowel함수로 모음인지 확인
			// 모음
			if (true == isVowel(idx))
			{
				++lcnt;
				vcnt = 0;
				// 모음이 반드시 있는지 확인하기 위한 것
				is_include_v = 1;
			}
			// 자음
			else
			{
				++vcnt;
				lcnt = 0;
			}

			// 모음 혹은 자음이 연속 3개일 때를 확인
			if (3 == vcnt || 3 == lcnt) flag = 1;

			// s[i] == a[i - 1]도 가능하지만 prev를 이용하는 방법도 있음
			// 0의 이전은 존재하지 않으니까 1이상인지 확인
			// 현재 idx와 이전이 같은지 확인
			// e,o가 아닌지 확인
			if ((1 <= i) && (idx == prev) && ('e' != idx && 'o' != idx)) flag = 1;
			// 연속된 같은 문자 확인을 위한, 전항에 대한 정보를 업데이트
			// 이와 같이하면 직전 항과 비교를 변수 하나로 쉽게 해결 가능
			prev = idx;
		}

		if (0 == is_include_v) flag = 1;

		if (true == flag) cout << "<" << s << ">" << " is not acceptable.\n";
		else cout << "<" << s << ">" << " is acceptable.\n";
	}

	return 0;
}