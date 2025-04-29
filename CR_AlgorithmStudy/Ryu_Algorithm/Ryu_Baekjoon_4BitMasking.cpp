#include <bits/stdc++.h>

using namespace std;

// 1_다이어트
// https://www.acmicpc.net/problem/19942
// 식재료 조합을 통해 영양 성분과 최소금액 맞추기
// 비트마스킹을 활용하여 특정 인덱스번째의 합산과 최소값 비교
// 조건에 해당되는 경우가 없다면 -1만 출력
// n: 식재료 개수
//const int VAL = 987654321;
//int n, mp, mf, ms, mv;
//int cump, cumf, cums, cumv, ret = VAL, cumc;
//map<int, vector<vector<int>>> ret_v;		// 비용별 조합 자료구조 => 비용이 700(int)인 경우의 조합(vector<int>) 모음(vector<조합>)
//
//struct Table
//{
//	int mp, mf, ms, mv, cost;
//};
//Table table[16];
//
//int main() 
//{
//	cin >> n;
//	cin >> mp >> mf >> ms >> mv;
//	for (int i = 0; i < n; ++i) 
//	{
//		cin >> table[i].mp >> table[i].mf >> table[i].ms >> table[i].mv >> table[i].cost;
//	}
//
//	// 모든 경우의 수 따지기
//	for (int i = 0; i < (1 << n); ++i) 
//	{
//		// 초기화 작업
//		cump = cumf = cums = cumv = cumc = 0;
//		vector<int> v;
//
//		for (int j = 0; j < n; ++j) 
//		{
//			// 조합 확인
//			if (i & (1 << j)) 
//			{
//				// 조합 추가
//				v.push_back(j + 1);
//
//				cump += table[j].mp;
//				cumf += table[j].mf;
//				cums += table[j].ms;
//				cumv += table[j].mv;
//				cumc += table[j].cost;
//			}
//		}
//
//		// 모든 최소 영양성분 수치 이상일 경우
//		if (mp <= cump && mf <= cumf && ms <= cums && mv <= cumv)
//		{
//			// 최소비용 갱신 및 조합 추가 작업
//			if (ret >= cumc)
//			{
//				ret = cumc;
//				ret_v[ret].push_back(v);
//			}
//		}
//	}
//
//	if (VAL != ret)
//	{
//		// 최소 비용 출력
//		cout << ret << "\n";
//		// 오름차순 정렬
//		sort(ret_v[ret].begin(), ret_v[ret].end());
//		// 비용별 조합 목록 출력
//		for (int i : ret_v[ret][0]) cout << i << " ";
//	}
//	else cout << -1 << '\n';
//
//	return 0;
//}

// 2_동전 뒤집기
// https://www.acmicpc.net/problem/1285
// 동전 뒤집기로 뒷면(T)를 최소로 하는 수
// 행과 열을 뒤집는 수를 모든 경우의 수를 생각하면 20(n의 최대) * 2 = 40
// 2의 40승 시간복잡도를 생각하면 불가능, 다른 방법으로 풀어야 함
// 최적해를 생각, T와 H의 수를 고려해서 뒤집을지 뒤집지 않을지 결정
// 행을 뒤집으면 열을 뒤집는다는 것은 최적해가 이미 정해진 것(반대로도 마찬가지)
// 따라서 2의 40승이 아닌 20승으로 행만 뒤집고 각 열을 확인하며 뒤집을지 여부 판단
// 어려와요,,,ㅠ 몰루게따ㅋㅎ
//int n, coinTable[21], ret = 987654321;
//int dy[] = { -1, 0, 1, 0 };
//int dx[] = { 0, 1, 0, -1 };
//
//void go(int here) 
//{
//	// 기저사례(행만 뒤집고 열은 판단해서 뒤집기)
//	if (here == n + 1) 
//	{
//		int sum = 0;
//		// 1, 2, 4, 8,.. 확인
//		for (int i = 1; i <= (1 << (n - 1)); i *= 2) 
//		{
//			int cnt = 0;
//			// 특정 행들의 부분 요소를 확인하기 때문에 ~n = -(n + 1)으로 비트마스킹의 앞부분 고려 X
//			for (int j = 1; j <= n; ++j)
//			{
//				// coinTable[j]: 행
//				// 즉 하나의 행 부분 요소 확인
//				if (coinTable[j] & i) ++cnt;
//			}
//
//			// 최소 및 윗면 합 연산
//			sum += min(cnt, n - cnt);
//		}
//
//		ret = min(ret, sum);
//		return;
//	}
//
//	// 뒤집기 X
//	go(here + 1);
//
//	// 뒤집기
//	coinTable[here] = ~coinTable[here];
//	// 뒤집기 O
//	go(here + 1);
//}
//
//int main() 
//{
//	cin >> n;
//	for (int i = 1; i <= n; ++i) 
//	{
//		string coinInfo;
//		cin >> coinInfo;
//
//		int value = 1;
//		for (int j = 0; j < n; ++j) 
//		{
//			// 각 행(문자열)을 숫자로 표현(HHT -> 4, TTT -> 7, HHH -> 0)
//			if ('T' == coinInfo[j]) coinTable[i] |= value;
//
//			value *= 2;
//		}
//	}
//
//	go(1);
//	
//	cout << ret;
//	
//	return 0;
//}

// 3_게리맨더링 
// https://www.acmicpc.net/problem/17471
// 노드마다 색칠 할 것, 색칠해서 2가지로 나누어져야함 3 이상으로 나누어지면 X
// 모든 경우의 수를 확인하여 그 중 2개로 나누어진 것 중에서 최솟값을 갱신
// 각 구역들을 2개의 큰 영역으로 나누어 영역별 인구수의 차가 가장 적은 경우의 차이 최솟값
// n: 구역 개수
//const int VAL = 987654321;
//int n, m, ret = VAL, area[11], comp[11], visited[11];
//vector<int> adj[11];
//
//pair<int, int> dfs(int here, int value) 
//{
//    visited[here] = 1;
//                       // 노드 자식의 수, 인구 수
//    pair<int, int> ret = { 1, area[here] };
//    for (int there : adj[here]) 
//    {
//        // 색이 다르면 무시
//        if (comp[there] != value) continue;
//        // 방문한 적이 있다면 무시
//        if (0 != visited[there]) continue;
//
//        pair<int, int> tmp = dfs(there, value);
//        ret.first += tmp.first;
//        ret.second += tmp.second;
//    }
//
//    return ret;
//}
//
//int main() 
//{
//    // 구역 수 입력 받기
//    cin >> n;
//    // 구역당 인구 수 입력 받기
//    for (int i = 1; i <= n; ++i) cin >> area[i];
//    for (int i = 1; i <= n; ++i) 
//    {
//        // 구역 당 다른 구역과 연결 된 수 입력 받기
//        cin >> m;
//        // 어느 구역과 연결되어 있는지 입력 받기 & 연결 작업
//        for (int j = 0; j < m; ++j) 
//        {
//            int temp = 0;
//            cin >> temp;
//
//            // 인접 리스트
//            adj[i].push_back(temp);
//            adj[temp].push_back(i);
//        }
//    }
//
//    // 모든 경우의 수 확인
//    for (int i = 1; i < (1 << n) - 1; ++i) 
//    {
//        // 초기화 작업
//        fill(comp, comp + 11, 0);
//        fill(visited, visited + 11, 0);
//
//        int a = -1;
//        int b = -1;
//        for (int j = 0; j < n; ++j) 
//        {
//            if (i & (1 << j)) 
//            { 
//                // 색칠 작업
//                comp[j + 1] = 1; 
//                // A 시작 지점
//                a = j + 1; 
//            }
//            // B 시작 지점
//            else b = j + 1;
//        }
//
//        pair<int, int> A = dfs(a, 1);
//        pair<int, int> B = dfs(b, 0);
//
//        // n == 합 을 하는 이유: 3개 이상으로 쪼개지는지 확인하기 위함(3개 이상이면 둘을 합했을 때 n보다 작음)
//        if (n == A.first + B.first) ret = min(ret, abs(A.second - B.second));
//    }
//
//    cout << (VAL == ret ? -1 : ret);
//
//    return 0;
//}

// 4_알파벳  
// https://www.acmicpc.net/problem/1987
// 좌측 상단 시작하여 최대 몇 칸 이동 가능한가
// +) 이동 재귀 부분에서 인자로 방문 기록에 관한 합연사자 인자값을 넘겨서 간단하게 처리하는 방법도 있음
// r: 세로 칸수, c: 가로 칸수,
//int r, c, visited, ret = -1;
//char alphabet[22][22];
//int dy[] = { -1, 0, 1, 0 };
//int dx[] = { 0, 1, 0, -1 };
//
//void move(int y, int x, int cnt)
//{
//	// 최대 카운트 갱신
//	ret = max(ret, cnt);
//
//	// 4방향 이동
//	for (int i = 0; i < 4; ++i)
//	{
//		int ny = y + dy[i];
//		int nx = x + dx[i];
//
//		// 범위 벗어나거나 이미 방문했다면 무시
//		if (0 > ny || 0 > nx || r <= ny || c <= nx) continue;
//		if (visited & (1 << (alphabet[ny][nx] - 'A'))) continue;
//
//		// 방문 처리
//		visited |= (1 << (alphabet[ny][nx] - 'A'));
//		// 재귀 이동 및 이동 카운트 증가
//		move(ny, nx, cnt + 1);
//		// 방문 원복
//		visited &= ~(1 << (alphabet[ny][nx] - 'A'));
//	}
//}
//
//int main()
//{
//	cin >> r >> c;
//	for (int i = 0; i < r; ++i)
//	{
//		for (int j = 0; j < c; ++j)
//		{
//			cin >> alphabet[i][j];
//		}
//	}
//
//	// 시작점 방문처리
//	visited |= (1 << (alphabet[0][0] - 'A'));
//	// 이동 시작
//	move(0, 0, 1);
//
//	cout << ret;
//
//	return 0;
//}

// 5_경사로
// https://www.acmicpc.net/problem/14890
// 주어진 경사로 크기에 높이가 1차이 나는 곳만 경사로 배치 가능
// 경사로 크기보다 작은 곳에 놓을 수 없음
// 이동 가능한 경로수 확인
//int n, l, ret, hor[101][101], ver[101][101];
//
//void go(int a[101][101])
//{
//    for (int i = 0; i < n; ++i) 
//    {
//        int cnt = 1;
//        int j = 0;
//        for (; j < n - 1; ++j) 
//        {
//            // 같은 층수
//            if (a[i][j] == a[i][j + 1]) ++cnt;
//            // 오르막길 초기화(칸수 하나 차이, l인 경사로 크기보다 크거나 같아야 가능)
//            else if (a[i][j] + 1 == a[i][j + 1] && l <= cnt) cnt = 1;
//            // 내리막길 초기화(칸수 하나 차이, 음수가 아닌 양수여야 가능), 음수로 만들어서 시작
//            else if (a[i][j] - 1 == a[i][j + 1] && 0 <= cnt) cnt = -l + 1;
//            else break;
//        }
//
//        // 마지막 지점 최종 확인 & 경로수 증가
//        if (n - 1 == j && 0 <= cnt) ++ret;
//    }
//}
//
//int main()
//{
//    cin >> n >> l;
//    for (int i = 0; i < n; ++i)
//    {
//        for (int j = 0; j < n; ++j)
//        {
//            cin >> hor[i][j];
//            // 가로 세로 대칭 작업
//            ver[j][i] = hor[i][j];
//        }
//    }
//
//    // 가로
//    go(hor);
//    // 세로
//    go(ver);
//
//    cout << ret;
//
//    return 0;
//}

// 6_가르침
// https://www.acmicpc.net/problem/1062
// K: 글자 개수(최대 50), N: 남극에 존재하는 단어(0 <= N <= 26)
// 'anta-'로 시작, '-tica'로 끝
// 가장 많이 배울 수 있는 문자 개수를 구할 것
// 모든 경우의 수(2^26) 완전 탐색 알고리즘 => 조합
//int K, N;
//int Words[50];
//
//int Count(int KnowWords)
//{
//    int Cnt = 0;
//
//    for (int Word : Words) 
//    {
//        // 배운 단어를 기반으로 '&' 연산자를 한 것이 Word이면 읽을 수 있는 단어이므로 Cnt 증가
//        if (Word && Word == (Word & KnowWords)) ++Cnt;
//    }
//
//    return Cnt;
//}
//
//// Idx: 알파벳
//// K: 배울 수 있는 문자 수
//// KnowWords: 배운 단어
//int WordProcess(int Idx, int K, int KnowWords)
//{
//    // 음수
//    if (0 > K) return 0;
//
//    // 모든 문자를 탐색
//    if (26 == Idx) return Count(KnowWords);
//
//    // 문자를 배운 것으로 처리
//    int Result = WordProcess(Idx + 1, K - 1, KnowWords | (1 << Idx));
//
//    // 만약 a, n, t, i, c가 아닌 경우
//    if (Idx != 'a' - 'a' && Idx != 'n' - 'a' && Idx != 't' - 'a' && Idx != 'i' - 'a' && Idx != 'c' - 'a')
//    {
//        // 안 배우는 것으로 처리(a, n, t, i, c 외의 문자를 배우지 않은 것으로 처리하기 위함 => 완탐하기 위해)
//        // Result로 가장 많이 읽을 수 있는 수를 반환하기 위한 것
//        Result = max(Result, WordProcess(Idx + 1, K, KnowWords));
//    }
//
//    return Result;
//}
//
//int main()
//{
//    cin >> N >> K;
//    for (int i = 0; i < N; ++i)
//    {
//        string Temp;
//        cin >> Temp;
//
//        for (char Ch : Temp)
//        {
//            // 단어별 알파벳을 숫자로 계산하여 관리(a: 1, b: 2, c: 4, d: 8, ...)
//            Words[i] |= (1 << (Ch - 'a'));
//        }
//    }
//
//    cout << WordProcess(0, K, 0) << '\n';
//
//    return 0;
//}

// 7_막대기
// https://www.acmicpc.net/problem/1094
// 길이 64, 반으로 쪼개기 가능
// X 길이의 막대기
// * 가지고 있는 막대 중 가장 짧은 것을 절반
// * 자른 막대의 절반 중 하나를 버리고 남아있는 막대의 길이 합이 X보다 크거나 같다면, 자른 막대의 절반 중 하나 버림
// * 남아있는 모든 막대를 풀로 붙여서 X 생성
// 64 -> 32 -> 16 -> 8 -> 4 -> 2 -> 1
// _______ X의 2진수를 보면 합쳐야 되는 개수 파악 가능
//int X, Reslut = 1;
//
//int main() 
//{
//    cin >> X;
//
//    while (1 != X)
//    {
//        // 2진수 & 연산이 1이 되면 증가
//        if(X & 1) ++Reslut;
//        // 절반 자르기
//        X /= 2;
//    }
//
//    cout << Reslut << '\n';
//
//    return 0;
//}

// 8_성곽
// https://www.acmicpc.net/problem/2234
// 방의 개수, 가장 넓은 방의 넓이, 하나의 벽을 제거하여 얻을 수 있는 가장 넓은 방의 크기
// 벽 정보: 서 - 1, 북 - 2, 동 - 4, 남 - 8 => 남동북서 2진수 처리
// 이동 배열의 방향 주의 할 것
// Connected Component
//int dy[] = { 0, -1, 0, 1 };
//int dx[] = { -1, 0, 1, 0 };
//int N, M, Index, Largest, WallRmLargest, WallInfos[50][50], Visited[50][50], RoomSize[2500];
//
//int DFS(int Y, int X, int Cnt)
//{
//	if(0 != Visited[Y][X]) return 0;
//
//	Visited[Y][X] = Cnt;
//
//	int Result = 1;
//
//	for (int i = 0; i < 4; ++i)
//	{
//		// 동서남북 벽이 없을 때 이동
//		if (!(WallInfos[Y][X] & (1 << i)))
//		{
//			int ny = Y + dy[i];
//			int nx = X + dx[i];
//
//			// 방 크기 합산
//			Result += DFS(ny, nx, Cnt);
//		}
//	}
//
//	return Result;
//}
//
//int main()
//{
//	cin >> N >> M;
//
//	// 벽 정보 등록
//	for (int i = 0; i < M; ++i)
//	{
//		for (int j = 0; j < N; ++j)
//		{
//			cin >> WallInfos[i][j];
//		}
//	}
//
//	for (int i = 0; i < M; ++i)
//	{
//		for (int j = 0; j < N; ++j)
//		{
//			if (0 == Visited[i][j])
//			{
//				// 방 수 세기
//				++Index;
//				// 성 탐색, 방 Index의 공간 관리(0번 방 n Size, 1번 방 n Size, ...)
//				RoomSize[Index] = DFS(i, j, Index);
//				// 방 별 가장 넓은 곳 갱신
//				Largest = max(Largest, RoomSize[Index]);
//			}
//		}
//	}
//
//	// 벽 제거하여 가장 넓은 방 크기 구하기
//	for (int i = 0; i < M; ++i)
//	{
//		for (int j = 0; j < N; ++j)
//		{
//			// 오버플로우 방지
//			if (M > i + 1)
//			{
//				int Zone = Visited[i][j];
//				int OtherZone = Visited[i + 1][j];
//
//				if (Zone != OtherZone)
//				{
//					WallRmLargest = max(WallRmLargest, RoomSize[Zone] + RoomSize[OtherZone]);
//				}
//			}
//
//			if (N > j + 1)
//			{
//				int Zone = Visited[i][j];
//				int OtherZone = Visited[i][j + 1];
//
//				if (Zone != OtherZone)
//				{
//					WallRmLargest = max(WallRmLargest, RoomSize[Zone] + RoomSize[OtherZone]);
//				}
//			}
//		}
//	}
//
//	cout << Index << '\n' << Largest << '\n' << WallRmLargest;
//
//	return 0;
//}

// 9_집합
// https://www.acmicpc.net/problem/11723
// 공집합에 value를 추가
// value번째에 1을 연산(비트마스킹)
//// value는 20이하
//int M, S, Value;
//string Command;
//
//int main()
//{
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	cin >> M;
//
//	for (int i = 0; i < M; ++i)
//	{
//		cin >> Command;
//
//		// add: Value 추가, Value가 있는 경우 무시
//		if ('a' == Command[0] && 'd' == Command[1])
//		{
//			cin >> Value;
//			S |= (1 << Value);
//		}
//		// all: {1, 2, ..., 20}으로 바꿈
//		else if ('a' == Command[0] && 'l' == Command[1])
//		{
//			S = (1 << 21) - 1;
//		}
//		// remove: Value 제거, Value가 없는 경우 무시
//		else if ('r' == Command[0])
//		{
//			cin >> Value;
//			S &= ~(1 << Value);
//		}
//		// check: Value가 있으면 1, 없으면 0 출력
//		else if ('c' == Command[0])
//		{
//			cin >> Value;
//			cout << ((S & (1 << Value)) ? true : false) << '\n';
//		}
//		// toggle: Value가 있으면 Value 제거, 없으면 추가
//		else if ('t' == Command[0])
//		{
//			cin >> Value;
//			S ^= (1 << Value);
//		}
//		else
//		{
//			S = 0;
//		}
//	}
//
//	return 0;
//}

// 10_종이 조각
// https://www.acmicpc.net/problem/14391
// 행은 위에서 아래, 열을 좌에서 우
// 종이를 적절히 잘라서 종이 조각의 최대 합 구하기
// k로 자르는 위치를 파악하여 가로 세로 합
// N: 세로 크기, M: 가로 크기(두 변수 모두 최대 4)
// 0: 가로, 1: 세로 (N * M + M번째)
//int N, M, Result, Paper[4][4];
//string Nums;
//
//int main()
//{
//	cin >> N >> M;
//
//	// 종이 숫자 입력
//	for (int i = 0; i < N; ++i)
//	{
//		cin >> Nums;
//
//		for (int j = 0; j < M; ++j)
//		{
//			Paper[i][j] = Nums[j] - '0';
//		}
//	}
//
//	// 0과 1을 구분(가로로 자를지 세로로 자를지 모든 가능한 자르기 경우의 수 확인)
//	for (int k = 0; k < (1 << (N * M)); ++k)
//	{
//		int Sum = 0;
//
//		// 0: 가로
//		for (int i = 0; i < N; ++i)
//		{
//			int Current = 0;
//
//			for (int j = 0; j < M; ++j)
//			{
//				int Temp = i * M + j;
//
//				// 0이라면 현재 수 확인 연결
//				if (0 == (k & (1 << Temp)))
//				{
//					Current = Current * 10 + Paper[i][j];
//				}
//				// 0이 아니라면 합산
//				else
//				{
//					Sum += Current;
//					Current = 0;
//				}
//			}
//		
//			Sum += Current;
//		}
//
//		// 1: 세로
//		for (int j = 0; j < M; ++j)
//		{
//			int Current = 0;
//
//			for (int i = 0; i < N; ++i)
//			{
//				int Temp = i * M + j;
//
//				// 0이 아닌(1-세로-) 수라면 현재 수 확인 연결
//				if (0 != (k & (1 << Temp)))
//				{
//					Current = Current * 10 + Paper[i][j];
//				}
//				// 0이라면 합산
//				else
//				{
//					Sum += Current;
//					Current = 0;
//				}
//			}
//
//			Sum += Current;
//		}
//
//		// 최대값 갱신
//		Result = max(Result, Sum);
//	}
//
//	cout << Result;
//
//	return 0;
//}

// 11_Tree
// https://www.acmicpc.net/problem/13244
// 노드들이 연결되어 있어 edge 따라 다른 노드로 이동 가능
// 간선이 제거되면 연결되어 있지X 따라서 일부 노드에 접근 불가
// A노드와 B노드 사이에 간선이 추가되면 사이클 생성, A노드에서 B노드로 가는 방법이 두 가지 이상인 경우 사이클 존재
// 조건을 통해 그래프인지 트리인지 판별
// DFS 한 번으로 연결된 모든 정점 탐색이 가능한가 == 트리
// E = V - 1 == 트리
// T: 그래프 개수 판별 수(최대 10), N: 노드 개수(1 <= N <= 1000), M: 간선 개수
//const int MaxNum = 1000;
//int T, N, M, A, B, Visited[MaxNum];
//vector<int> Adj[MaxNum];
//
//void DFS(int Here)
//{
//	Visited[Here] = 1;
//
//	for (int There : Adj[Here])
//	{
//		if (0 == Visited[There])
//		{
//			DFS(There);
//		}
//	}
//}
//
//int main()
//{
//	cin >> T;
//
//	for (int k = 0; k < T; ++k)
//	{
//		// 초기화
//		for (int i = 0; i < MaxNum; ++i)
//		{
//			Adj[i].clear();
//		}
//		fill(Visited, Visited + MaxNum, 0);
//
//		int Count = 0;
//
//		cin >> N >> M;
//
//		// 양방향 간선 만들기
//		for (int i = 0; i < M; ++i)
//		{
//			cin >> A >> B;
//			Adj[A].push_back(B);
//			Adj[B].push_back(A);
//		}
//
//		// DFS를 한 번만 도는지 확인
//		for (int i = 1; i <= N; ++i)
//		{
//			if (0 == Visited[i])
//			{
//				DFS(i);
//				// Count가 1이면 한 번만 돈 것
//				++Count;
//			}
//		}
//
//		// 트리 조건을 확인하여 트리인지 그래프인지 판별
//		cout << ((N - 1 == M && 1 == Count) ? "tree" : "graph") << '\n';
//	}
//
//	return 0;
//}

// 12_AC
// https://www.acmicpc.net/problem/5430
// R: 순서 뒤집기 함수, D: 첫번째 수 버리기 함수(배열이 비어있을 때 사용하면 에러 발생)
// T: 테스트 케이스 수(최대 100), Strp: 수행할 함수(1 <= p길이 <= 100000), N: 배열에 들어있는 수의 개수(0 <= N <= 100000)
int T, N, X;
string Strp, Str;

int main()
{
	cin >> T;

	for (int i = 0; i < T; ++i)
	{
		deque<int> Deq;
		X = 0;

		cin >> Strp >> N >> Str;
		
		// 배열 만들기
		for (char Ch : Str)
		{
			if('[' == Ch || ']' == Ch) continue;
			
			// 숫자 생성
			if ('0' <= Ch && '9' >= Ch)
			{
				X = X * 10 + (Ch - '0');
			}
			else
			{
				if (0 < X)
				{
					Deq.push_back(X);
				}

				X = 0;
			}
		}

		if (0 < X)
		{
			Deq.push_back(X);
		}

		// Flag 활용
		bool Err = false, Rev = false;

		for (char Ch : Strp)
		{
			if ('R' == Ch)
			{
				Rev = !Rev;
			}
			else
			{
				// 배열이 비어 있을 때 D를 할 경우 Error
				if (true == Deq.empty())
				{
					Err = true;
					break;
				}

				// 뒤집어져있다면 뒷 부분 제거
				if (true == Rev)
				{
					Deq.pop_back();
				}
				// 뒤집어진게 아니라면 원래대로 앞 부분 제거
				else
				{
					Deq.pop_front();
				}
			}
		}

		if (true == Err)
		{
			cout << "error" << '\n';
		}
		else
		{
			cout << "[";

			// 최종적으로 R라면 뒤집기
			if (true == Rev)
			{
				reverse(Deq.begin(), Deq.end());
			}

			// 배열 출력
			for (int i = 0; i < Deq.size(); ++i)
			{
				 cout << Deq[i];

				 if (Deq.size() - 1 > i)
				 {
					 cout << ",";
				 }
			}
			cout << "]\n";
		}
	}

	return 0;
}
