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
//const int MaxPosition = 100000;
//int visited[MaxPosition + 1], prevIndex[MaxPosition + 1];
//vector<int> cnt;
//
//int main()
//{
//	int n, k;
//	cin >> n >> k;
//
//	queue<int> q;
//	q.push(n);
//	visited[n] = 1;
//
//	while (false == q.empty())
//	{
//		int curIndex = q.front();
//		q.pop();
//
//		if (k == curIndex) break;
//
//		int nextInfo[] = { curIndex - 1, curIndex + 1, curIndex * 2 };
//		for (int i = 0; i < 3; ++i)
//		{
//			// 이동 가능한 범위 확인
//			if (0 <= nextInfo[i] && MaxPosition >= nextInfo[i] && 0 == visited[nextInfo[i]])
//			{
//				q.push(nextInfo[i]);
//				visited[nextInfo[i]] = visited[curIndex] + 1;
//				// Index 별로 이전에 거쳐온 위치를 파악해서 역탐색이 가능
//				prevIndex[nextInfo[i]] = curIndex;
//			}
//		}
//	}
//
//	// 도착지점부터 시작해서 시작지점까지 Index를 역탐색 순으로 순회
//	for (int i = k; i != n; i = prevIndex[i]) cnt.push_back(i);
//	// 시작지점 담기
//	cnt.push_back(n);
//	// 역순이므로 뒤집기
//	reverse(cnt.begin(), cnt.end());
//
//	cout << visited[k] - 1 << "\n";
//	for (int i : cnt) cout << i << " ";
//
//	return 0;
//}

// 9_숨바꼭질5
// https://www.acmicpc.net/problem/17071
// 수빈이가 이동하는 배열, 동생이 이동하는 배열 각자 관리하려고 했으나 500000이라는 수치는 매우 큼(공간 복잡도를 고려)
// 동생의 경우 홀수 짝수와 같이 이동 위치가 바뀜(+1, +2, +3, +4, ...)
// 수빈의 경우 +1, -1 이동 가능 따라서 동생이 3초에 왔다고 했을 때 수빈이 1초에 미리 도착했다면 왔다 갔다 형식으로 만날 수 있음(단, 홀수 짝수 시간이 일치할 때)
// 따라서 수빈이와 동생이 같이 가는 경우와 수빈이가 먼저 도착해서 왔다갔다로 동생과 마주하는 경우 고려
// 수빈이의 위치는 홀짝으로 구분하되 동생의 이동 위치는 파악할 필요 있음
//const int MaxPosition = 500000;
//int MoveCount = 1, visited[2][MaxPosition + 1];		// visited[2][MaxPosition + 1] => [2]: 홀수 짝수인지 해당 턴의 확인용, [MaxPosition + 1]: 동생 위치
//bool IsVisited;
//vector<int> cnt;
//
//int main()
//{
//	int n, k;
//	cin >> n >> k;
//	if (n == k)
//	{
//		cout << 0;
//		return 0;
//	}
//
//	queue<int> q;
//	q.push(n);
//	// 수빈 기준 첫 방문 시작
//	visited[0][n] = 1;
//
//	while (false == q.empty())
//	{
//		// 이동 수치만큼 동생 위치 연산
//		k += MoveCount;
//
//		if (MaxPosition < k) break;
//		// 만약 짝수(, 홀수 턴에 맞춰서)일 때 동생 위치에 미리 방문 했다면 왔다갔다로 만날 수 있으므로 IsVisited가 true
//		if (0 != visited[MoveCount % 2][k])
//		{
//			IsVisited = true;
//			break;
//		}
//
//		// Flood Fill Algorithm(플러드 필 알고리즘)
//		// Leveling 변수가 필요한 이유?
//		// for문에 q.size()로 사용했을 시 q의 사이즈가 변하게 되면서 로직이 뒤틀리게 됨
//		// 따라서 각 탐색 레벨별 파악을 위해 미리 사이즈를 받아서 사용
//		int Leveling = q.size();
//		for (int i = 0; i < Leveling; ++i)
//		{
//			int curIndex = q.front();
//			q.pop();
//
//			int nextInfo[] = { curIndex - 1, curIndex + 1, curIndex * 2 };
//			for (int i = 0; i < 3; ++i)
//			{
//				// 이동 가능한 범위 확인
//				if (0 <= nextInfo[i] && MaxPosition >= nextInfo[i] && 0 == visited[MoveCount % 2][nextInfo[i]])
//				{
//					// + 1을 하는 이유? => 짝수에 방문했다면 다음은 홀수에 방문
//					// 만약 2초에 방문했다면 다음은 3초가 되니까?!
//					visited[MoveCount % 2][nextInfo[i]] = visited[(MoveCount + 1) % 2][curIndex] + 1;
//
//					// 동생과 위치가 동일하다면
//					if (k == nextInfo[i])
//					{
//						IsVisited = true;
//						break;
//					}
//
//					q.push(nextInfo[i]);
//				}
//			}
//
//			if (true == IsVisited) break;
//		}
//
//		if (true == IsVisited) break;
//		++MoveCount;
//	}
//
//	// 만난 적이 없으면 -1, 있으면 이동한 수 출력
//	MoveCount = true == IsVisited ? MoveCount : -1;
//	cout << MoveCount;
//
//	return 0;
//}

// 10_주난의 난(難)
// https://www.acmicpc.net/problem/14497
// *: 주난의 위치, #: 초코바를 가진 학생
// 0: 이동가능, 1: 시간에 따른 이동 가능한 부분
// 0이면 빈 공간이므로 해당 위치 4방향으로 확산(?)되어 1을 만날때 1을 0으로 바꾸고 멈춤
// N: 가로, M: 세로 교실 크기
//int N, M, JumpCount = 1, visited[301][301];
//pair<int, int> JPos, CPos;
//char JClass[301][301];
//int dy[] = { -1, 0, 1, 0 };
//int dx[] = { 0, 1, 0, -1 };
//
//int main()
//{
//	cin >> N >> M;
//	cin >> JPos.second >> JPos.first >> CPos.second >> CPos.first;
//
//	for (int i = 1; i <= N; ++i)
//	{
//		string str = "";
//		cin >> str;
//		for (int j = 1; j <= str.size(); ++j) JClass[i][j] = str[j - 1];
//	}
//
//	queue<pair<int, int>> q;
//	q.push({ JPos.second, JPos.first });
//	visited[JPos.second][JPos.first] = 1;
//	
//	// 목표 지점이 '0'이 될 때까지 반복
//	while ('0' != JClass[CPos.second][CPos.first])
//	{
//		// 다음 탐색을 위해 모아놓는 큐 자료구조
//		queue<pair<int, int>> nextq;
//
//		while (false == q.empty())
//		{
//			int y = q.front().first;
//			int x = q.front().second;
//			q.pop();
//			
//			for (int i = 0; i < 4; ++i)
//			{
//				int ny = y + dy[i];
//				int nx = x + dx[i];
//
//				if (1 > ny || 1 > nx || N < ny || M < nx || 0 != visited[ny][nx]) continue;
//
//				visited[ny][nx] = JumpCount;
//				// 만약 '1'로 친구가 존재한다면 '0'으로 변경
//				// nextq에 추가
//				if ('0' != JClass[ny][nx])
//				{
//					JClass[ny][nx] = '0';
//					nextq.push({ ny, nx });
//				}
//				// '0'이라면 q에 추가
//				else q.push({ ny, nx });
//			}
//		}
//
//		// '0' 탐색 이후 다음 jump로 탐색 시작을 위해 해당 정보를 q에 대입
//		q = nextq;
//		// 점프 카운트 증가
//		++JumpCount;
//	}
//
//	cout << visited[CPos.second][CPos.first];
//
//	return 0;
//}

// 11_백조의 호수
// https://www.acmicpc.net/problem/3197
// 하루 간격으로 물이 닿아있는 빙판은 녹는다(상하좌우이며 대각선은 고려X)
// R: 행, C: 열
//const int Max_num = 1501;
//int R, C, day, Svisited[Max_num][Max_num], Wvisited[Max_num][Max_num];
//int SwanY, SwanX, CurY, CurX;
//char Lake[Max_num][Max_num];
//queue<pair<int, int>> WaterQ, SwanQ, Water_NextQ, Swan_NextQ;   // BFS, Flood Fill에 사용할 각 큐 2개
//int dy[4] = { 0, 1, 0, -1 };
//int dx[4] = { 1, 0, -1, 0 };
//
//// 큐를 클리어 해주는 기능이 없으므로 생성하여 스왑해 바꿈
//void Qclear(queue<pair<int, int>>& Inq) 
//{
//    queue<pair<int, int>> EmptyQ;
//    // 빈 큐와 교체하여 큐를 비움
//    swap(Inq, EmptyQ); 
//}
//
//void IceMelting() 
//{
//    while (false == WaterQ.empty())
//    {
//        tie(CurY, CurX) = WaterQ.front();
//        WaterQ.pop();
//
//        for (int i = 0; i < 4; ++i) 
//        {
//            int ny = CurY + dy[i];
//            int nx = CurX + dx[i];
//
//            if (0 > ny || 0 > nx || R < ny || C < nx || 0 != Wvisited[ny][nx]) continue;
//            
//            // 다음 이동이 빙하라면 물로 변경
//            if ('X' == Lake[ny][nx])
//            {
//                Wvisited[ny][nx] = 1;
//                Lake[ny][nx] = '.';
//                Water_NextQ.push({ ny, nx });
//            }
//        }
//    }
//}
//
//bool MoveAndMeet() 
//{
//    while (false == SwanQ.empty())
//    {
//        tie(CurY, CurX) = SwanQ.front();
//        SwanQ.pop();
//
//        for (int i = 0; i < 4; ++i) 
//        {
//            int ny = CurY + dy[i];
//            int nx = CurX + dx[i];
//
//            if (0 > ny || 0 > nx || R < ny || C < nx || 0 != Svisited[ny][nx]) continue;
//
//            Svisited[ny][nx] = 1;
//            // 다음 이동이 물이라면 현재큐에 추가
//            if ('.' == Lake[ny][nx]) SwanQ.push({ny, nx});
//            // 다음 이동이 빙하라면 다음큐에 추가
//            else if ('X' == Lake[ny][nx]) Swan_NextQ.push({ny, nx});
//            // 다음 이동에 백조가 있다면 만났으므로 true
//            else if ('L' == Lake[ny][nx]) return true;
//        }
//    }
//
//    // 여기까지 오면 만나지 못한 경우
//    return false;
//}
//
//int main() 
//{
//    cin >> R >> C;
//    for (int i = 0; i < R; ++i)
//    {
//        string str = "";
//        cin >> str;
//        for (int j = 0; j < C; ++j) 
//        {
//            Lake[i][j] = str[j];
//
//            if ('L' == Lake[i][j] || '.' == Lake[i][j])
//            {
//                if ('L' == Lake[i][j])
//                {
//                    SwanY = i;
//                    SwanX = j;
//                }
//
//                Wvisited[i][j] = 1;
//                WaterQ.push({ i, j });                          // 물 큐 추가
//            }
//        }
//    }
//
//    SwanQ.push({ SwanY, SwanX });
//    Svisited[SwanY][SwanX] = 1;
//
//    while (true) 
//    {
//        // 두 백조가 만나면 종료
//        if (true == MoveAndMeet()) break;
//        
//        // 하루 간격 빙판 녹이기
//        IceMelting();
//        
//        // 큐 업데이트(빙하 녹는 정보와, 백조 이동)
//        WaterQ = Water_NextQ;
//        SwanQ = Swan_NextQ;
//        
//        // 큐 비우기
//        Qclear(Water_NextQ);
//        Qclear(Swan_NextQ);
//        
//        // 하루 경과
//        ++day;
//    }
//
//    cout << day;
//
//    return 0;
//}

// 12_알파벳
// https://www.acmicpc.net/problem/1987
// 칸마다 대문자 존재, 말은 4방향 이동 가능 지금까지 지나온 칸과 다른 알파벳 칸만 이동 가능
// 시작 지점은 좌상단(1,1), 최대 몇 칸 이동 가능한가
// 알파벳 방문 배열로 해당 알파벳에 방문했는지 여부를 확인하여 탐색
// R: 세로, C: 가로
//int R, C, visited[30];
//char Board[21][21];
//int dy[] = { -1, 0, 1, 0 };
//int dx[] = { 0, 1, 0, -1 };
//
//int DFS(int y, int x)
//{
//	int value = 0;
//
//	for (int i = 0; i < 4; ++i)
//	{
//		int ny = y + dy[i];
//		int nx = x + dx[i];
//
//		if (0 > ny || 0 > nx || R <= ny || C <= nx) continue;
//		if (0 != visited[Board[ny][nx] - 'A']) continue;
//
//		// 방문 체크
//		visited[Board[ny][nx] - 'A'] = 1;
//		// 재귀 및 반환 카운트를 통해 최대로 탐색한 길이 구하기
//		value = max(value, DFS(ny, nx));
//		// 방문 해제
//		visited[Board[ny][nx] - 'A'] = 0;
//	}
//
//	// 현재위치 포함하여 반환
//	return value + 1;
//}
//
//int main()
//{
//	cin >> R >> C;
//	for (int i = 0; i < R; ++i)
//	{
//		for (int j = 0; j < C; ++j) cin >> Board[i][j];
//	}
//
//	visited[Board[0][0]- 'A'] = 1;
//
//	cout << DFS(0, 0);
//
//	return 0;
//}

// 13_부등호
// https://www.acmicpc.net/problem/2529
// 주어진 부등호 순서에 맞게 숫자가 만족되는 것들을 모아 최소 최대
// k: 부등호 개수
//int k, number[10];
//char sign[10];
//vector<string> ret;
//
//// 등호가 올바르게 되었는지 확인하여 반환
//bool Check(char Left, char Right, char Oper)
//{
//	if (Left < Right && '<' == Oper) return true;
//	if (Left > Right && '>' == Oper) return true;
//
//	return false;
//}
//
//void Make(int Index, string strNum)
//{
//	// 부등호 끝 => 현재 생성 숫자 모으기
//	if (k + 1 == Index)
//	{
//		ret.push_back(strNum);
//		return;
//	}
//
//	for (int i = 0; i < 10; ++i)
//	{
//		// 이미 사용한 숫자면 무시
//		if (0 != number[i]) continue;
//
//		// 인덱스가 0이거나 (생성 끝숫자) (부등호) (추가될 숫자)가 옳은 식일 때
//		if (0 == Index || true == Check(strNum[Index - 1], i + '0', sign[Index - 1]))
//		{
//			// (추가될 숫자) 사용 체크
//			number[i] = 1;
//			// 완탐 숫자 만들기(인덱스 증가, 생성 숫자 + 추가될 숫자 넘기기)
//			Make(Index + 1, strNum + to_string(i));
//			// (추가될 숫자) 사용 해제 => 복원 작업
//			number[i] = 0;
//		}
//	}
//}
//
//int main()
//{
//	cin >> k;
//	for (int i = 0; i < k; ++i) cin >> sign[i];
//
//	// 완탐 숫자 만들기(인덱스 기반 탐색)
//	Make(0, "");
//	// 정렬
//	sort(ret.begin(), ret.end());
//
//	// 최대 최소 출력
//	cout << ret[ret.size() - 1] << "\n" << ret[0];
//
//	return 0;
//}

// 14_완전 이진 트리
// https://www.acmicpc.net/problem/9934
// 1)가장 처음 트리의 루트에 있는 빌딩 앞
// 2)현재 빌딩의 왼쪽 자식에 있는 빌딩에 아직 들어가지 않았다면, 왼쪽 자식으로 이동
// 3)현재 있는 노드가 왼쪽 자식을 가지고 있지 않거나 왼쪽 자식에 있는 빌딩을 이미 들어갔다면, 현재 노드에 있는 빌딩 진입, 종이에 번호 기록
// 4)현재 빌딩을 이미 들어갔다 온 상태이고, 오른쪽 자식을 가지고 있는 경우 오른쪽 자식 이동
// 5)현재 빌딩과 왼쪽, 오른쪽 자식에 있는 빌딩을 모두 방문했다면, 부모 노드로 이동
// 중위 순회 방법
// 모든 빌딩의 번호는 중복X, 1 ~ 2^K - 1, 즉 K는 1 ~ 10이므로 빌딩 최대 숫자는 2^10 - 1
// K: 완전 이진 트리 깊이
//int K, Building[1025];
//vector<int> ret[11];			// 깊이 별 빌딩 숫자 파악
//
//void Go(int StartIndex, int EndIndex, int Depth)
//{
//	if (StartIndex > EndIndex) return;
//	if (StartIndex == EndIndex)
//	{
//		ret[Depth].push_back(Building[StartIndex]);
//		return;
//	}
//
//	// 절반을 기점으로 깊이 파악
//	int Mid = (StartIndex + EndIndex) / 2;
//	ret[Depth].push_back(Building[Mid]);
//
//	// 왼쪽 자식 탐색
//	Go(StartIndex, Mid - 1, Depth + 1);
//	// 오른쪽 자식 탐색
//	Go(Mid + 1, EndIndex, Depth + 1);
//}
//
//int main()
//{
//	cin >> K;
//	int LastBuildingNum = static_cast<int>(pow(2, K)) - 1;
//	for (int i = 0; i < LastBuildingNum; ++i) cin >> Building[i];
//
//	Go(0, LastBuildingNum, 1);
//
//	for (int i = 1; i <= K; ++i)
//	{
//		for (int j : ret[i]) cout << j << " ";
//
//		cout << "\n";
//	}
//
//	return 0;
//}

// 15_사다리 조작
// https://www.acmicpc.net/problem/15684
// 시작 값과 도착 값이 같게 만들기
// 이 때 추가해야하는 가로선의 최소 개수
// N: 세로선, M: 가로선, H: 세로선마다 가로선 놓을 수 있는 위치 개수
//const int inf = 987654321;
//int n, m, h, a, b, ret = inf, visited[31][31];
//
//// 시작과 도착이 같은 수인지 판별
//bool check()
//{
//	for (int i = 1; i <= n; ++i)
//	{
//		// 위치 지점을 파악하기 위한 pos 변수
//		int pos = i;
//		for (int j = 1; j <= h; ++j)
//		{
//			// 위치에 따른 사다리가 놓인 방향(오른쪽 ++, 왼쪽 --)
//			if (0 != visited[j][pos]) ++pos;
//			else if (0 != visited[j][pos - 1]) --pos;
//		}
//
//		// 시작 도착이 다를 경우 false
//		if (i != pos) return false;
//	}
//
//	return true;
//}
//
//void move(int here, int cnt)
//{
//	// 3 혹은 기존 최소값보다 클 경우 return
//	if (3 < cnt || ret <= cnt) return;
//	if (true == check())
//	{
//		ret = min(ret, cnt);
//		return;
//	}
//
//	for (int i = here; i <= h; ++i)
//	{
//		for (int j = 1; j < n; ++j)
//		{
//			// 사다리 연속 놓기 불가(무시)
//			if (0 != visited[i][j] || 0 != visited[i][j - 1] || 0 != visited[i][j + 1]) continue;
//
//			// 사다리 놓기
//			visited[i][j] = 1;
//			move(i, cnt + 1);
//			// 사다리 원복
//			visited[i][j] = 0;
//		}
//	}
//}
//
//int main()
//{
//	cin >> n >> m >> h;
//
//	// 사다리 만들기
//	for (int i = 0; i < m; ++i)
//	{
//		cin >> a >> b;
//		visited[a][b] = 1;;
//	}
//
//	// 사다리 조작 시작
//	move(1, 0);
//
//	cout << (inf == ret ? -1 : ret) << "\n";
//
//	return 0;
//}

// 16_꽃길
// https://www.acmicpc.net/problem/14620
// 상하좌우로 꽃잎이 펼쳐지며 겹칠 경우 죽음
// 3개의 씨앗을 최소 비용으로 꽃 피우기
// 전부 탐색하되 꽃을 피울 수 있는지 확인하고 가능한 지역에서 피웠을 때 비용 연산 후 원복 작업 처리 필요
// n: 화단 한 변의 길이
int n, ret = 987654321, ground[11][11];
bool bloomed[11][11];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

// 꽃 피우기 가능한지 확인
bool check(int y, int x)
{
	// 이미 피어있는 곳이면 불가능
	if (true == bloomed[y][x]) return false;

	// 꽃잎 4방향 확인
	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		// 범위 이탈 및 피어 있는 곳이면 불가능
		if (0 > ny || 0 > nx || n <= ny || n <= nx || true == bloomed[ny][nx]) return false;
	}

	return true;
}

// y, x 기준으로 꽃 피웠을 때 비용 연산
int cost(int y, int x)
{
	// 꽃 피움 처리
	bloomed[y][x] = true;

	// 씨앗 뿌린 지점 비용
	int totalcost = ground[y][x];
	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		// 꽃잎 피움 처리
		bloomed[ny][nx] = true;
		// 피워진 꽃잎 자리 비용 추가
		totalcost += ground[ny][nx];
	}

	// 최종 비용 반환
	return totalcost;
}

// 꽃 핀 자리 원복 작업 처리
void eraseFlower(int y, int x)
{
	// 피운 자리 원복
	bloomed[y][x] = false;

	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		// 폈던 꽃잎 자리 원복
		bloomed[ny][nx] = false;
	}
}

void flower(int cnt, int curcost)
{
	// 씨앗 3개 모두 뿌렸을 때 최소 비용 갱신
	if (3 == cnt)
	{
		ret = min(ret, curcost);
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			// 꽃 피기 불가능한 곳이면 무시
			if (false == check(i, j)) continue;
			
			// 씨 카운트 및 비용 연산 합 재귀 꽃 피우기
			flower(cnt + 1, curcost + cost(i, j));
			// 원복
			eraseFlower(i, j);
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> ground[i][j];
		}
	}

	flower(0, 0);

	cout << ret;

	return 0;
}