#include <bits/stdc++.h>

using namespace std;

// 1_치킨 배달
// https://www.acmicpc.net/problem/15686
// 문제 이해가 너무 안돼서 여기저기 찾아서 최대한 이해를 해봄
// 치킨집의 최대 개수를 M으로 주어짐, M개의 치킨집과 여러 집으로만 생각하면 됨
// 여러 치킨 집 중에서 M개를 고른다? => 문제에서 어떻게 고르면 도시의 치킨 거리가 가장 적게 될지 프로그램을 작성하라고 했으므로 순서와 관계없이 무작위로 M개를 선정하여 가장 거리가 적은 수를 출력하면 됨
// 즉 각 집과 가장 가까운 치킨 집 사이의 거리를 모두 합한 거리를 도시의 치킨 거리로 가장 적은 치킨 거리를 구하면 됨
// ***** 각 집과 가장 가까운 치킨 집 사이의 거리를 모두 합한 거리 ***** => 완전 중요 포인트
// N: 도시 크기, M: 최대 치킨집 개수
//int N, M, ret = 100000, City[50][50];
//vector<pair<int, int>> Homes, Chickens, ChickenList;
//
//void Combi(int Start)
//{
//	if (M == ChickenList.size())
//	{
//		// 치킨 거리 구하기 로직
//		int Cal = 0;
//		for (pair<int, int> Home : Homes)
//		{
//			// 거리 최소값을 구하기 위한 최대값 초기화
//			int HomeMin = N * N;
//
//			for (pair<int, int> Chicken : ChickenList)
//			{
//				// 거리 연산
//				int Dir = abs(Home.first - Chicken.first) + abs(Home.second - Chicken.second);
//				// 집을 기준으로 치킨집과의 최소거리
//				HomeMin = min(HomeMin, Dir);
//			}
//			// 집을 기준으로 최소거리 합연산
//			Cal += HomeMin;
//		}
//
//		// 최종 최소거리 연산을 위한 min 확인
//		ret = min(ret, Cal);
//
//		return;
//	}
//
//	// 치킨집 조합
//	for (int i = Start + 1; i < Chickens.size(); ++i)
//	{
//		ChickenList.push_back(Chickens[i]);
//		Combi(i);
//		ChickenList.pop_back();
//	}
//}
//
//int main()
//{
//	cin >> N >> M;
//
//	for (int i = 0; i < N; ++i)
//	{
//		for (int j = 0; j < N; ++j)
//		{
//			cin >> City[i][j];
//
//			// 집과 치킨집 위치 정보 담기
//			if (1 == City[i][j]) Homes.push_back({ i,j });
//			if (2 == City[i][j]) Chickens.push_back({ i,j });
//		}
//	}
//
//	Combi(-1);
//
//	cout << ret;
//
//	return 0;
//}

// 또 다른 풀이법(Combi완전탐색 및 인덱스 활용)
// 무식하게 풀 수 있는가? -> 로직 -> 시간복잡도 계산 -> 가능하다?(무식 GO), 불가능하다?(다른 알고리즘)
// 치킨집을 선별하고 모든 집과의 거리를 비교해서 집 거리 중 가장 최소값을 더하면 됨
//int n, m, a[54][54], result = 987654321;
//vector<vector<int>> ChickenList;		// 치킨 위치가 담겨 있는 Chicken의 인덱스를 담아 놓은 리스트
//vector<pair<int, int>> Home, Chicken;
//
//void Combi(int Start, vector<int> v)
//{
//	// 최대 치킨집 개수와 v 사이즈가 같을 때
//	if (m == v.size())
//	{
//		// 로직
//		// 조합들 저장
//		ChickenList.push_back(v);
//		return;
//	}
//
//	// 조합
//	for (int i = Start + 1; i < Chicken.size(); ++i)
//	{
//		v.push_back(i);
//		Combi(i, v);
//		v.pop_back();
//	}
//}
//
//int main()
//{
//	cin >> n >> m;
//
//	for (int i = 0; i < n; ++i)
//	{
//		for (int j = 0; j < n; ++j)
//		{
//			cin >> a[i][j];
//
//			if (1 == a[i][j]) Home.push_back({ i,j });
//			if (2 == a[i][j]) Chicken.push_back({ i,j });
//		}
//	}
//
//	vector<int> v;
//	Combi(-1, v);
//
//	// 치킨집 뽑기
//	for (vector<int> cList : ChickenList)
//	{
//		int ret = 0;
//		for (pair<int, int> _Home : Home)
//		{
//			int _Min = 987654321;
//
//			// 치킨 리스트 중에서 집과의 거리
//			for (int ch : cList)
//			{
//				int _Dist = abs(_Home.first - Chicken[ch].first) + abs(_Home.second - Chicken[ch].second);
//				// 거리 비교해서 최소값 구하기(집과 치킨집들 중에서 최소 치킨 거리)
//				_Min = min(_Min, _Dist);
//			}
//			
//			// 최소 값들 합
//			ret += _Min;
//		}
//
//		// 전체적 최소 값
//		result = min(result, ret);
//	}
//
//	// 출력
//	cout << result;
//
//	return 0;
//}

// 2_보물섬
// https://www.acmicpc.net/problem/2589
// 각 이동 가능한 땅의 크기와 해당 땅에서의 BFS를 활용하여 경로 구하기
//int n, m, ret, visited[50][50], island[50][50];
//int dy[] = { -1, 0, 1, 0 };
//int dx[] = { 0, 1, 0, -1 };
//queue<pair<int, int>> q;
//
//void BFS(int y, int x)
//{
//	visited[y][x] = 1;
//
//	while (true != q.empty())
//	{
//		tie(y, x) = q.front();
//		q.pop();
//
//		for (int i = 0; i < 4; ++i)
//		{
//			int ny = y + dy[i];
//			int nx = x + dx[i];
//
//			if (0 > ny || 0 > nx || n <= ny || m <= nx) continue;
//			if (0 == island[ny][nx] || 0 != visited[ny][nx]) continue;
//
//			// 경로 수치를 구하기 위함
//			visited[ny][nx] = visited[y][x] + 1;
//			ret = max(ret, visited[ny][nx] - 1);
//			q.push({ ny, nx });
//		}
//	}
//}
//
//int main()
//{
//	cin >> n >> m;
//
//	for (int i = 0; i < n; ++i)
//	{
//		string LandInfo = "";
//		cin >> LandInfo;
//
//		for (int j = 0; j < LandInfo.size(); ++j)
//		{
//			// 바다는 0 육지는 1
//			island[i][j] = 'W' == LandInfo[j] ? 0 : 1;
//		}
//	}
//
//	// 모든 경우 탐색
//	for (int i = 0; i < n; ++i)
//	{
//		for (int j = 0; j < m; ++j)
//		{
//			// 탐색전 방문 기록 초기화
//			fill(&visited[0][0], &visited[0][0] + 50 * 50, 0);
//			// 육지이고 방문하지 않았을 때 BFS 돌리기 
//			if (1 == island[i][j] && 0 == visited[i][j])
//			{
//				q.push({ i,j });
//				BFS(i, j);
//			}
//		}
//	}
//
//	// 결과 출력
//	cout << ret;
//
//	return 0;
//}

// 또 다른 풀이법(?)
// 내 풀이와 유사?
// 육지 -> 육지로 간다 했을 때 최단거리, 보물은 가장 긴 최단거리에 묻혀있음
// 최단 거리 중 가장 Max 값
// 모든 경우의 BFS를 활용하여 최단거리 구하면 됨
//int n, m, mx, visited[54][54];
//int dy[] = { -1, 0, 1, 0 };
//int dx[] = { 0, 1, 0, -1 };
//char a[54][54];
//
//void BFS(int y, int x)
//{
//	// 방문 초기화
//	fill(&visited[0][0], &visited[0][0] + 54 * 54, 0);
//	visited[y][x] = 1;
//	queue<pair<int, int>> q;
//	q.push({ y,x });
//
//	while (true != q.empty())
//	{
//		tie(y, x) = q.front();
//		q.pop();
//
//		for (int i = 0; i < 4; ++i)
//		{
//			int ny = y + dy[i];
//			int nx = x + dx[i];
//
//			if (0 > ny || 0 > nx || n <= ny || m <= nx) continue;
//			if (0 != visited[ny][nx] || 'W' == a[ny][nx]) continue;
//
//			// 최단 거리 배열
//			visited[ny][nx] = visited[y][x] + 1;
//			q.push({ ny, nx });
//			// 최대 값을 구하기 위한 max 활용
//			mx = max(mx, visited[ny][nx]);
//		}
//	}
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
//		}
//	}
//
//	for (int i = 0; i < n; ++i)
//	{
//		for (int j = 0; j < m; ++j)
//		{
//			// 'L'일 때만 BFS 돌리기('W'일 때는 돌릴 필요X)
//			if ('L' == a[i][j]) BFS(i, j);
//		}
//	}
//
//	cout << mx - 1;
//
//	return 0;
//}

// 3_인구 이동
// https://www.acmicpc.net/problem/16234
// 모든 경우를 탐색하며 해당 되는 나라 위치를 담아서 관리
// DFS로 탐색하며 L과 R범위에 해당하는 나라 관리(윗 문장과 동일한 말) => 해당 정보를 토대로 인구 합산 및 나라 수를 파악해 연산하여 인구 변동
// 반복 처리 후 더이상 이동이 이뤄질 수 없다면 무한루프 탈출
// ***** ㅠ참고하여 풀이ㅠ *****
// N: 땅 크기
//int N, L, R, Count, sum, A[51][51], Border[51][51];
//int dy[] = { -1, 0, 1, 0 };
//int dx[] = { 0, 1, 0, -1 };
//vector<pair<int, int>> VecLocations;
//
//// 두 지역 사이의 차가 L과 R 사이에 있는지 파악
//void DFS(int y, int x)
//{
//	for (int i = 0; i < 4; ++i)
//	{
//		int ny = y + dy[i];
//		int nx = x + dx[i];
//
//		if (0 > ny || 0 > nx || N <= ny || N <= nx || 0 != Border[ny][nx]) continue;
//
//		// 국경선을 공유하는 두 나라의 인구 차이가 L명 이상 R명 이하라면, 두 나라가 공유하는 국경선을 오늘 하루 동안 엶(DFS 탐색)
//		// 열려야하는 국경선이 모두 열렸다면 인구 이동
//		// 국경선이 열려있어 인접한 칸만 이용해 이동할 수 있으면, 그 나라를 오늘 하루 동안 연합
//		if (L <= abs(A[ny][nx] - A[y][x]) && R >= abs(A[ny][nx] - A[y][x]))
//		{
//			Border[ny][nx] = 1;
//			// 국경선이 열려서 이동 가능한 나라들 모음
//			VecLocations.push_back({ ny,nx });
//			// 연합 인구수 구하기(누적)
//			sum += A[ny][nx];
//			DFS(ny, nx);
//		}
//	}
//}
//
//int main()
//{
//	cin >> N >> L >> R;
//
//	for (int i = 0; i < N; ++i)
//	{
//		for (int j = 0; j < N; ++j)
//		{
//			cin >> A[i][j];
//		}
//	}
//
//	while (true)
//	{
//		bool IsMove = false;
//		fill(&Border[0][0], &Border[0][0] + 51 * 51, 0);
//
//		// 모든 정점에 대한 탐색
//		for (int i = 0; i < N; ++i)
//		{
//			for (int j = 0; j < N; ++j)
//			{
//				// 방문하지 않았다면? 해당 위치로부터 탐색 시작
//				if (0 == Border[i][j])
//				{
//					// 인구 이동가능 나라를 파악하기 위한 자료구조 초기화
//					VecLocations.clear();
//					Border[i][j] = 1;
//					VecLocations.push_back({ i,j });
//					sum = A[i][j];
//					DFS(i, j);
//
//					// 사이즈가 1이면 국경선 열린 곳X, 해당 조건 안해주면 끝없이 체크해서 시간초과 나옴
//					if (1 == VecLocations.size()) continue;
//
//					// 국경선이 열려서 이동 가능한 나라들 모음 확인해서 변화 적용
//					for (pair<int, int> Location : VecLocations)
//					{
//						// 연합을 이루고 있는 칸의 인구수는 연합의 인구수 / 연합을 이루고 있는 칸의 수
//						A[Location.first][Location.second] = sum / VecLocations.size();
//						// 인구 이동 일어남
//						IsMove = true;
//					}
//				}
//			}
//		}
//
//		// 연합을 해체하고 모든 국경선 닫음
//		if (false == IsMove) break;
//		++Count;
//	}
//
//	cout << Count;
//
//	return 0;
//}

// 4_불!
// https://www.acmicpc.net/problem/4179
// 분당 지훈의 1칸 움직임, 불 4방향 확산
// J- 시작 위치 F- 불난 공간 #- 벽 .- 이동 가능
// R: 미로 행 개수, C: 미로 열 개수
//int R, C, cnt, FirePos[1000][1000], visited[1000][1000];
//char Maze[1000][1000];
//pair<int, int> JihoonPos;
//queue<pair<int, int>> qPosInfo;
//int dy[] = { -1, 0, 1, 0 };
//int dx[] = { 0, 1, 0, -1 };
//
//int main()
//{
//	cin >> R >> C;
//
//	for (int i = 0; i < R; ++i)
//	{
//		string str = "";
//		cin >> str;
//		for (int j = 0; j < C; ++j)
//		{
//			Maze[i][j] = str[j];
//
//			if ('J' == Maze[i][j])
//			{
//				visited[i][j] = 1;
//				JihoonPos = make_pair(i, j);
//			}
//			if ('F' == Maze[i][j])
//			{
//				FirePos[i][j] = 1;
//				qPosInfo.push({ i,j });
//			}
//		}
//	}
//	
//	// Fire: 불 확산 시간 범위 표를 미리 작성하기 위해 Fire 먼저 한 후 Jihoon 이동 확인
//	while (false == qPosInfo.empty())
//	{
//		pair<int, int> Fire = qPosInfo.front();
//		qPosInfo.pop();
//
//		for (int i = 0; i < 4; ++i)
//		{
//			int ny = Fire.first + dy[i];
//			int nx = Fire.second + dx[i];
//
//			if (0 > ny || 0 > nx || R <= ny || C <= nx) continue;
//			// 벽이거나 불 확산이 가능한 곳이 아닌 경우 건너뛰기
//			if ('#' == Maze[ny][nx] || 0 != FirePos[ny][nx]) continue;
//
//			// 확산 범위 연산 표시
//			FirePos[ny][nx] = FirePos[Fire.first][Fire.second] + 1;
//			qPosInfo.push({ ny,nx });
//		}
//	}
//
//	qPosInfo.push(JihoonPos);
//	// Jihoon
//	while (false == qPosInfo.empty())
//	{
//		JihoonPos = qPosInfo.front();
//		qPosInfo.pop();
//
//		// 탈출 인정 범위 도달시 시간 결과를 받아두고 while문 탈출
//		if (0 == JihoonPos.first || 0 == JihoonPos.second || R - 1 == JihoonPos.first || C - 1 == JihoonPos.second)
//		{
//			cnt = visited[JihoonPos.first][JihoonPos.second];
//			break;
//		}
//
//		for (int i = 0; i < 4; ++i)
//		{
//			int ny = JihoonPos.first + dy[i];
//			int nx = JihoonPos.second + dx[i];
//
//			if (0 > ny || 0 > nx || R <= ny || C <= nx) continue;
//			// 벽이거나 이동 가능한 곳이 아닌 경우 건너뛰기
//			if ('#' == Maze[ny][nx] || 0 != visited[ny][nx]) continue;
//			// 미리 계산한 불길 시간(0이외, 0은 불길 퍼진 곳이 아님)과 현재 이동 시점의 시간과 비교해서 지나갈 수 없으면 건너뛰기
//			if (0 != FirePos[ny][nx] && FirePos[ny][nx] <= visited[JihoonPos.first][JihoonPos.second] + 1) continue;
//
//			// 이동 시간 연산 표시
//			visited[ny][nx] = visited[JihoonPos.first][JihoonPos.second] + 1;
//			
//			// 탈출 인점 범위 도달 못했을 시 반복을 위한 다음 위치 push
//			qPosInfo.push({ ny,nx });
//		}
//	}
//
//	// 탈출 실패(0)면 IMPOSSIBLE, 탈출 성공하면(cnt) 탈출 시간
//	string ret = 0 == cnt ? "IMPOSSIBLE" : to_string(cnt);
//	cout << ret;
//
//	return 0;
//}

// 5_뮤탈리스크
// https://www.acmicpc.net/problem/12869
// BFS 문제 => 경우의 수를 통해 최소한의 횟수로 SCV를 0으로 만들기 위함(가중치 동일)
// ***** SCVVisited[61][61][61]: 각 SCV의 체력을 나타내는 상태를 방문했는지 여부를 기록하는 배열 ***** 메모이제이션 처리 위함
// N: SCV의 수
//int N, SCV[3], SCVVisited[61][61][61];
//int Damage[6][3] =
//{
//	{9, 3, 1},
//	{9, 1, 3},
//	{3, 1, 9},
//	{3, 9 ,1},
//	{1, 3, 9},
//	{1, 9 ,3},
//};
//
//struct Attack
//{
//	int Attack1;
//	int Attack2;
//	int Attack3;
//};
//
//int BFS()
//{
//	queue<Attack> q;
//	q.push({ SCV[0], SCV[1], SCV[2] });
//	SCVVisited[SCV[0]][SCV[1]][SCV[2]] = 1;
//
//	while (false == q.empty())
//	{
//		Attack atk = q.front();
//		q.pop();
//
//		// 모든 체력이 0이 되어 최소한의 공격 횟수가 존재한다면 BFS While문 탈출
//		if (0 != SCVVisited[0][0][0]) break;
//
//		// 공격 대미지 패턴에 대한 반복
//		for (int i = 0; i < 6; ++i)
//		{
//			// 배열이 음수가 될 수 없으므로 값이 음수로 떨어진다면 0으로 설정
//			int na1 = max(0, atk.Attack1 - Damage[i][0]);
//			int na2 = max(0, atk.Attack2 - Damage[i][1]);
//			int na3 = max(0, atk.Attack3 - Damage[i][2]);
//			// 해당 체력 상태에 대한 정보가 있다면 건너뛰기
//			if (0 != SCVVisited[na1][na2][na3]) continue;
//
//			// 공격 횟수 파악을 위한 누적 연산
//			SCVVisited[na1][na2][na3] = SCVVisited[atk.Attack1][atk.Attack2][atk.Attack3] + 1;
//			// 다음 탐색을 위해 큐에 저장
//			q.push({ na1,na2,na3 });
//		}
//	}
//
//	return SCVVisited[0][0][0] - 1;
//}
//
//int main()
//{
//	cin >> N;
//
//	for (int i = 0; i < N; ++i)
//	{
//		cin >> SCV[i];
//	}
//
//	cout << BFS();
//
//	return 0;
//}

// 6_괄호 추가하기
// https://www.acmicpc.net/problem/16637
// 완탐의 경우 인덱스를 기반으로 로직구현 => 방향성이 있고 사이클이 없다
// 중첩 괄호 불가, 연산은 좌에서 우로 이루어진다
// 누적합과 Index를 기반으로 탐색 필요
// 연산자와 숫자로 나누어 해볼 것
// 함수포인터로 계산식 나누어 설계 가능할 듯한데 해볼 것
// N: 수식 길이
//int N, ret = -987654321;
//string Str;
//vector<int> Numbers;
//vector<char> Operations;
//
//int Add(int Left, int Right) { return Left + Right; }
//int Sub(int Left, int Right) { return Left - Right; }
//int Mul(int Left, int Right) { return Left * Right; }
//
//int Calculation(char InOperation, int InLeft, int InRight)
//{
//	int (*Oper)(int, int) = nullptr;
//	switch (InOperation)
//	{
//	case '+':
//		Oper = Add;
//		break;
//	case '-':
//		Oper = Sub;
//		break;
//	case '*':
//		Oper = Mul;
//		break;
//	}
//
//	return nullptr != Oper ? Oper(InLeft, InRight) : 0;
//}
//
//void MakeExpression(int Index, int Value)
//{
//	// 계산의 끝
//	if (Numbers.size() - 1 == Index)
//	{
//		// 최대값 갱신 작업
//		ret = max(ret, Value);
//		return;
//	}
//
//	// 먼저 연산
//	MakeExpression(Index + 1, Calculation(Operations[Index], Value, Numbers[Index + 1]));
//	// 괄호가 있다 했을 때의 연산
//	if (Numbers.size() - 1 >= Index + 2)
//	{
//		int ParenthesesValue = Calculation(Operations[Index + 1], Numbers[Index + 1], Numbers[Index + 2]);
//		MakeExpression(Index + 2, Calculation(Operations[Index], Value, ParenthesesValue));
//	}
//}
//
//int main()
//{
//	cin >> N >> Str;
//	for (char ch : Str)
//	{
//		if (0 != isdigit(ch)) Numbers.push_back(ch - '0');
//		else Operations.push_back(ch);
//	}
//
//	MakeExpression(0, Numbers[0]);
//	cout << ret;
//
//	return 0;
//}

// 7_숨바꼭질2(46% -> 오답)
// https://www.acmicpc.net/problem/12851
// N: 수빈 위치, K: 동생 위치
//int N, K, minCount, minTime = 987654321, visited[100001];
//
//void Move()
//{
//	queue<int> q;
//	q.push(N);
//	// 첫 위치 방문 처리
//	visited[N] = 1;
//
//	while (false == q.empty()) 
//	{
//		int curIndex = q.front();
//		q.pop();
//
//		// 동생 위치와 겹쳤을 때
//		if (K == curIndex) 
//		{
//			// 최소 시간 갱신
//			if (minTime > visited[curIndex]) 
//			{
//				minTime = visited[curIndex];
//				// 동일 최소 시간 카운트 값 초기화
//				minCount = 1;
//			}
//			// 동일 최소 시간 카운트 증가
//			else if (minTime == visited[curIndex]) ++minCount;
//			
//			continue;
//		}
//
//		// 수빈 이동 위치 탐색
//		int nextInfo[] = { curIndex - 1, curIndex + 1, curIndex * 2 };
//		for (int i = 0; i < 3; ++i) 
//		{
//			int nextIndex = nextInfo[i];
//
//			// 이동할 다음 위치가 배열 범위 초과하면 무시
//			if (0 > nextIndex || 100000 < nextIndex ) continue;
//			// 방문 여부와 최소 시간보다 탐색 시간이 더 걸린다면 굳이 더 탐색할 필요 없으므로 무시
//			if (0 != visited[nextIndex] || minTime < visited[curIndex] + 1) continue;
//
//			// 탐색 시간 파악
//			visited[nextIndex] = visited[curIndex] + 1;
//			q.push(nextIndex);
//		}
//	}
//}
//
//int main()
//{
//	cin >> N >> K;
//
//	Move();
//
//	cout << minTime - 1 << "\n" << minCount;
//
//	return 0;
//}

// 7_다른 풀이
// 가장 빠른 시간(BFS), 경우의 수
//const int MaxPosition = 100000;
//int visited[MaxPosition + 1], cnt[MaxPosition + 1];
//
//int main()
//{
//	int n, k;
//	cin >> n >> k;
//	// 추가 반례(같은 위치일 경우), 반례 추가 안해주면 오답처리됨
//	if (n == k)
//	{
//		cout << '0' << "\n" << '1';
//
//		return 0;
//	}
//
//	visited[n] = 1;
//	cnt[n] = 1;
//
//	queue<int> q;
//	q.push(n);
//
//	while (false == q.empty())
//	{
//		int curIndex = q.front();
//		q.pop();
//
//		int nextInfo[] = { curIndex - 1, curIndex + 1, curIndex * 2 };
//		for (int i = 0; i < 3; ++i)
//		{
//			// 이동 가능한 범위 확인
//			if (0 <= nextInfo[i] && MaxPosition >= nextInfo[i])
//			{
//				// 첫 방문
//				if (0 == visited[nextInfo[i]])
//				{
//					q.push(nextInfo[i]);
//					visited[nextInfo[i]] = visited[curIndex] + 1;
//					// 경우의 수를 구하기 위해 누적
//					cnt[nextInfo[i]] += cnt[curIndex];
//				}
//				// 동일하지만 다른 최단 루트가 있을 때 경우의 수 추가
//				// 해당 부분을 고려 못해서 46%에서 틀렸던게 아닐까 싶음
//				else if (visited[nextInfo[i]] == visited[curIndex] + 1) cnt[nextInfo[i]] += cnt[curIndex];
//			}
//		}
//	}
//
//	cout << visited[k] - 1 << "\n" << cnt[k];
//
//	return 0;
//}

// 8_숨바꼭질4
// https://www.acmicpc.net/problem/13913
// BFS, ***** Trace(경로 추적): prev[next] = here *****
const int MaxPosition = 100000;
int visited[MaxPosition + 1], prevIndex[MaxPosition + 1];
vector<int> cnt;

int main()
{
	int n, k;
	cin >> n >> k;

	queue<int> q;
	q.push(n);
	visited[n] = 1;

	while (false == q.empty())
	{
		int curIndex = q.front();
		q.pop();

		if (k == curIndex) break;

		int nextInfo[] = { curIndex - 1, curIndex + 1, curIndex * 2 };
		for (int i = 0; i < 3; ++i)
		{
			// 이동 가능한 범위 확인
			if (0 <= nextInfo[i] && MaxPosition >= nextInfo[i] && 0 == visited[nextInfo[i]])
			{
				q.push(nextInfo[i]);
				visited[nextInfo[i]] = visited[curIndex] + 1;
				// Index 별로 이전에 거쳐온 위치를 파악해서 역탐색이 가능
				prevIndex[nextInfo[i]] = curIndex;
			}
		}
	}

	// 도착지점부터 시작해서 시작지점까지 Index를 역탐색 순으로 순회
	for (int i = k; i != n; i = prevIndex[i]) cnt.push_back(i);
	// 시작지점 담기
	cnt.push_back(n);
	// 역순이므로 뒤집기
	reverse(cnt.begin(), cnt.end());

	cout << visited[k] - 1 << "\n";
	for (int i : cnt) cout << i << " ";

	return 0;
}