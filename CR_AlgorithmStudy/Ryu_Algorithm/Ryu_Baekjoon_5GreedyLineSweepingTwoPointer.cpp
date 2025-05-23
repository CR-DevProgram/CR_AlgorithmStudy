#include <bits/stdc++.h>

using namespace std;

// 1_순회강연
// https://www.acmicpc.net/problem/2109
// 우선순위 큐를 사용해서 강연료 높은 것을 기준으로 측정
//int N, D, P, Sum;
//vector<pair<int, int>> Vec;
//priority_queue<int, vector<int>, greater<int>> PQ;
//
//int main()
//{
//	cin >> N;
//
//	for (int i = 0; i < N; ++i)
//	{
//		cin >> P >> D;
//
//		Vec.push_back({D, P});
//	}
//
//	sort(Vec.begin(), Vec.end());
//
//	for (int i = 0; i < N; ++i)
//	{
//		// 강의 추가
//		PQ.push(Vec[i].second);
//
//		// 현재까지 수락한 강의 수가 마감일보다 많은 경우
//		// 하루에 하나만 가능하므로 초과될 경우 제일 적은 강연료를 제거
//		if (PQ.size() > Vec[i].first)
//		{
//			PQ.pop();
//		}
//	}
//
//	while (true != PQ.empty())
//	{
//		Sum += PQ.top();
//		PQ.pop();
//	}
//
//	cout << Sum;
//
//	return 0;
//}

// 2_문자열 폭발
// https://www.acmicpc.net/problem/9935
//string Str, BoomStr, S, CompStr;
//stack<char> Stk;

//int main()
//{
//	cin >> Str >> BoomStr;
//
//	for (int i = 0; i < Str.length(); ++i)
//	{
//		S += Str[i];
//
//		if (S.size() >= BoomStr.size())
//		{
//			CompStr = S.substr((S.size() - BoomStr.size()));
//			if (0 == CompStr.compare(BoomStr))
//			{
//				S.erase(S.size() - BoomStr.size());
//			}
//		}
//	}
//
//	cout << (true == S.empty() ? "FRULA" : S);
//
//	return 0;
//}

//int main()
//{
//	cin >> Str >> BoomStr;
//
//	for (char Ch : Str)
//	{
//		S += Ch;
//		if (S.size() >= BoomStr.size() && S.substr(S.size() - BoomStr.size(), BoomStr.size()) == BoomStr)
//		{
//			S.erase(S.end() - BoomStr.size(), S.end());
//		}
//	}
//
//	if (true == S.empty())
//	{
//		cout << "FRULA";
//	}
//	else
//	{
//		cout << S;
//	}
//
//	return 0;
//}

// 폭발 혹은 짝짓기 문제면 stack일 확률이 높음
//int main()
//{
//	cin >> Str >> BoomStr;
//
//	for (char Ch : Str)
//	{
//		Stk.push(Ch);
//
//		// 스택의 상단과 폭발 문자열의 끝 부분이 같은지 확인
//		if (Stk.size() >= BoomStr.size() && Stk.top() == BoomStr[BoomStr.size() - 1])
//		{
//			string Ss = "";
//
//			for (char C : BoomStr)
//			{
//				Ss += Stk.top();
//				Stk.pop();
//			}
//
//			reverse(Ss.begin(), Ss.end());
//
//			// 폭발 문자열과 다르다면 다시 넣어주는 작업
//			if (BoomStr != Ss)
//			{
//				for (int i : Ss)
//				{
//					Stk.push(i);
//				}
//			}
//		}
//	}
//
//	if (0 == Stk.size())
//	{
//		cout << "FRULA";
//	}
//	else
//	{
//		while (true != Stk.empty())
//		{
//			S += Stk.top();
//			Stk.pop();
//		}
//
//		reverse(S.begin(), S.end());
//
//		cout << S;
//	}
//
//	return 0;
//}

// 3_컵라면
// https://www.acmicpc.net/problem/1781
// 데드라인에 컵라면 수량을 우선으로 따지는 우선순위 큐를 사용
//int N, Total;
//pair<int, int> Pii;
//vector<pair<int, int>> Vec;
//priority_queue<int, vector<int>, greater<int>> PQ;
//
//int main()
//{
//	cin >> N;
//
//	for (int i = 0; i < N; ++i)
//	{
//		cin >> Pii.first >> Pii.second;
//
//		Vec.push_back(Pii);
//	}
//
//	sort(Vec.begin(), Vec.end());
//
//	for (int i = 0; i < N; ++i)
//	{
//		PQ.push(Vec[i].second);
//
//		if (PQ.size() > Vec[i].first)
//		{
//			PQ.pop();
//		}
//	}
//
//	while (true != PQ.empty())
//	{
//		Total += PQ.top();
//		PQ.pop();
//	}
//
//	cout << Total;
//
//	return 0;
//}

// 4_소가 길을 건너간 이유 3
// https://www.acmicpc.net/problem/14469
// 라인 스위핑 문제
//int N, Time, Wait, Sum;
//vector<pair<int, int>> Cows;
//
//int main()
//{
//	cin >> N;
//	
//	for (int i = 0; i < N; ++i)
//	{
//		cin >> Time >> Wait;
//
//		Cows.push_back({Time, Wait});
//	}
//
//	sort(Cows.begin(), Cows.end());
//
//	for(int i = 0; i < N; ++i)
//	{
//		if (Sum < Cows[i].first)
//		{
//			Sum = Cows[i].first + Cows[i].second;
//		}
//		else
//		{
//			Sum += Cows[i].second;
//		}
//	}
//
//	cout << Sum;
//
//	return 0;
//}

// 5_회의실 배정
// https://www.acmicpc.net/problem/1931
//int I, LastTime, Count = 1;
//pair<int, int> Pii;
//vector<pair<int, int>> Vec;
//
//bool Compare(const pair<int, int>& Left, const pair<int, int>& Right)
//{
//	if(Left.second == Right.second) return Left.first < Right.first;
//
//	return Left.second < Right.second;
//}
//
//int main()
//{
//	cin >> I;
//
//	for (int i = 0; i < I; ++i)
//	{
//		cin >> Pii.first >> Pii.second;
//
//		Vec.push_back(Pii);
//	}
//	
//	sort(Vec.begin(), Vec.end(), Compare);
//
//	LastTime = Vec[0].second;
//
//	for (int i = 1; i < I; ++i)
//	{
//		if (Vec[i].first >= LastTime)
//		{
//			LastTime = Vec[i].second;
//			++Count;
//		}
//	}
//
//	cout << Count;
//
//	return 0;
//}

// 정렬의 기준 변경
// 회의가 겹치지 않게 최대 회의 갯수
// 라인 스위핑
// 구간 관련된 문제인 경우 정렬을 생각하며 라인 스위핑을 떠올리면 됨
// 구간이면 정렬한다!
//int From, To, I, Index, Count = 1;
//
//int main()
//{
//	cin >> I;
//
//	vector<pair<int, int>> Vec;
//
//	for (int i = 0; i < I; ++i)
//	{
//		cin >> From >> To;
//
//		Vec.push_back({To, From});
//	}
//
//	sort(Vec.begin(), Vec.end());
//
//	From = Vec[0].second;
//	To = Vec[0].first;
//
//	for (int i = 1; i < I; ++i)
//	{
//		if(To > Vec[i].second) continue;
//
//		From = Vec[i].second;
//		To = Vec[i].first;
//		++Count;
//	}
//
//	cout << Count;
//
//	return 0;
//}

// 6_보석 도둑
// https://www.acmicpc.net/problem/1202
// 가방에는 최대 한 개의 보석만 넣을 수 있음
// N: 보석 개수, K: 가방 개수, M: 보석 무게, V: 보석 가격, C: 가방에 담을 수 있는 최대 무게
//int N, M, V, K, C;
//long long Sum;					// 보석 가치에 대한 수치 범위가 크기 때문에 모두 합산한다 했을 시 int로 할 경우 오버플로우로 인해 엉뚱한 값이 나옴
//vector<int> BVec;
//vector<pair<int, int>> JVec;
//priority_queue<int> PQ;
//
//int main()
//{
//	cin >> N >> K;
//
//	for (int i = 0; i < N; ++i)
//	{
//		cin >> M >> V;
//
//		JVec.push_back({M, V});
//	}
//
//	for (int i = 0; i < K; ++i)
//	{
//		cin >> C;
//
//		BVec.push_back(C);
//	}
//
//	// 가방 및 보석 무게 오름차순 정렬
//	sort(JVec.begin(), JVec.end());
//	sort(BVec.begin(), BVec.end());
//
//	// 보석 전체 탐색을 위한 인덱스 변수
//	int JewelIndex = 0;
//	// 가방에 담을 수 있는 보석 확인
//	for (int i = 0; i < K; ++i)
//	{
//		// 현재 가방의 최대 무게
//		int BagMax = BVec[i];
//		
//		// 현재 가방무게보다 적거나 같은 보석을 PQ에 담기
//		// 가방의 작은 무게부터 비교하므로 보석 또한 오름차순으로 정렬되어 있기 때문에 빠짐없이 탐색 가능
//		while (JewelIndex < N && JVec[JewelIndex].first <= BagMax)
//		{
//			PQ.push(JVec[JewelIndex].second);
//			++JewelIndex;
//		}
//
//		if(true != PQ.empty())
//		{
//			Sum += PQ.top();
//			PQ.pop();
//		}
//	}
//
//	cout << Sum;
//
//	return 0;
//}

// 7_소수의 연속합
// https://www.acmicpc.net/problem/1644
// 소수 = 에라토스테네스 체
// 구간의 시작과 끝을 두어 투 포인터를 사용해 푸는 방식
// 구간이 N보다 작을 경우 끝을 오른쪽 이동
// 구간이 N보다 클 경우 시작을 왼쪽 이동
//bool Erab[4000001];
//int N, Erai[4000001], Pos, Sum, Count;
//
//int main()
//{
//	cin >> N;
//
//	// ===에라토스테네스의 체===
//	for (int i = 2; i <= N; ++i)
//	{
//		if (true == Erab[i]) continue;
//
//		// 소수가 아닌 것에 true
//		for (int j = 2 * i; j <= N; j += i)
//		{
//			Erab[j] = true;
//		}
//	}
//
//	for (int i = 2; i <= N; ++i)
//	{
//		// 소수인 경우 int 타입 배열에 담기
//		if (true != Erab[i])
//		{
//			Erai[Pos++] = i;
//		}
//	}
//	// =========================
//
//	int Begin = 0, End = 0;
//
//	while (true)
//	{
//		// 합이 N보다 크면 시작점을 이동시키고 합계에서 시작의 값을 뺌
//		if (Sum >= N)
//		{
//			Sum -= Erai[Begin++];
//		}
//		// 합이 N보다 작으면 끝점을 이동시키고 합계에서 끝 값을 더함
//		else
//		{
//			if (End == Pos) break;
//			Sum += Erai[End++];
//		}
//
//		// 투 포인터 이동 연산 후 최종 합산과 N을 비교하여 같은 경우 카운트 증가
//		if (Sum == N)
//		{
//			++Count;
//		}
//	}
//
//	cout << Count;
//
//	return 0;
//}

// 8_List of Unique Numbers
// https://www.acmicpc.net/problem/13144
// 등차수열의 합 = (n * (n + 1)) / 2
// 경우의 수를 구하라고 할 경우 int 말고 long long으로 시작하는 것을 권장
//long long N, Count, Start, End, Arr[100004], Cnt[100004];
//
//int main()
//{
//	cin >> N;
//	
//	for (int i = 0; i < N; ++i)
//	{
//		cin >> Arr[i];
//	}
//
//	while (End < N)
//	{
//		// 중복되는 것이 없는 경우
//		if (0 == Cnt[Arr[End]])
//		{
//			++Cnt[Arr[End++]];
//		}
//		// 중복되는 것을 만났을 때
//		else
//		{
//			Count += (End - Start);
//			--Cnt[Arr[Start++]];
//		}
//	}
//
//	Count += (End - Start) * (End - Start + 1) / 2;
//	
//	cout << Count;
//
//	return 0;
//}

// 9_두 수의 합
// https://www.acmicpc.net/problem/3273
// 정렬하여 양 끝에 각 시작과 끝 지점을 이용한 투 포인터 사용
//int N, X, Temp, Count;
//vector<int> Vec;
//
//int main()
//{
//	cin >> N;
//
//	for (int i = 0; i < N; ++i)
//	{
//		cin >> Temp;
//		Vec.push_back(Temp);
//	}
//
//	sort(Vec.begin(), Vec.end());
//
//	cin >> X;
//
//	int Value = 0, Left = 0, Right = N - 1;
//	while (Left < Right)
//	{
//		Value = Vec[Left] + Vec[Right];
//		if (X < Value)
//		{
//			--Right;
//		}
//		else if (X > Value)
//		{
//			++Left;
//		}
//		else
//		{
//			++Count;
//			++Left;
//			--Right;
//		}
//	}
//
//	cout << Count;
//
//	return 0;
//}

// 10_멀티탭 스케줄링
// https://www.acmicpc.net/problem/1700
// Memory Paging Optimal(Optimal Page Replacement Algorithm)
// 가장 미래에 참조되는 페이지를 쫓아내는 방법(Page Swap)
//int N, K, Count, Info[104], Reuse[104];
//vector<int> Vec;
//
//int main()
//{
//	cin >> N >> K;
//
//	for (int i = 0; i < K; ++i)
//	{
//		cin >> Info[i];
//	}
//
//	for (int i = 0; i < K; ++i)
//	{
//		// i번째 사용 기기가 꽂혀있지 않을 때
//		if (0 == Reuse[Info[i]])
//		{
//			// N만큼 꽂을 수 있으므로 꽂혀있는 Vec의 크기 확인
//			// 즉, 멀티탭이 가득 찬 경우
//			if (Vec.size() == N)
//			{
//				int Top = 0, Pos = 0;
//
//				for (int Idx : Vec)
//				{
//					int Current = 987654321;
//
//					// 가장 먼 미래에 참조되는 것을 확인
//					for (int j = i + 1; j < K; ++j)
//					{
//						if (Idx == Info[j])
//						{
//							Current = j;
//							break;
//						}
//					}
//
//					// 가장 먼 미래에 참조되는 것이 현재보다 작은 경우
//					// 즉, 가장 나중에 쓰이거나 아예 안 쓰이는 기기 찾아 뽑는 로직
//					if (Top < Current)
//					{
//						// 가장 먼 미래에 참조되는 것dl 현재로 갱신
//						Top = Current;
//						// Pos는 전기용품을 나타냄
//						Pos = Idx;
//					}
//				}
//
//				// 가장 먼 미래에 참조 되는 것을 찾아 바꿔주는 것, 이 때 지워주고 카운트 증가
//				// 즉, 뽑고 새로 기기 꽂는 로직
//				Reuse[Pos] = 0;
//				++Count;
//				Vec.erase(find(Vec.begin(), Vec.end(), Pos));
//			}
//
//			// N개만큼 채워지기 전까지 push_back, 사용 여부 설정
//			Vec.push_back(Info[i]);
//			Reuse[Info[i]] = 1;
//		}
//	}
//
//	cout << Count;
//
//	return 0;
//}

// 11_미세먼지 안녕!
// https://www.acmicpc.net/problem/17144
// 확산: Amount - Amount / 5
// 동시 확산
// 공기청정기 위쪽 방향(반시계)
//const int dyup[] = { 0, -1, 0, 1 };
//const int dxup[] = { 1, 0, -1, 0 };
//// 공기청정기 아래쪽 방향(시계)
//const int dydw[] = { 0, 1, 0, -1 };
//const int dxdw[] = { 1, 0, -1, 0 };
//
//int R, C, T, Amount, Arr[54][54], Temp[54][54];
//vector<pair<int, int>> VecUp, VecDown;
//
//void SpreadDust(const int dy[], const int dx[])
//{
//	fill(&Temp[0][0], &Temp[0][0] + 54 * 54, 0);
//
//	queue<pair<int, int>> Q;
//
//	// 확산시킬 미세먼지들 확인
//	for (int i = 0; i < R; ++i)
//	{
//		for (int j = 0; j < C; ++j)
//		{
//			if (-1 != Arr[i][j] && 0 != Arr[i][j])
//			{
//				Q.push({i, j});
//			}
//		}
//	}
//
//	// 확산 실행
//	while (true != Q.empty())
//	{
//		int X, Y;
//		tie(Y, X) = Q.front();
//		Q.pop();
//
//		// 확산될 양
//		int Spread = Arr[Y][X] / 5;
//
//		for (int i = 0; i < 4; ++i)
//		{
//			int ny = Y + dy[i];
//			int nx = X + dx[i];
//
//			if (0 > ny || 0 > nx || R <= ny || C <= nx || -1 == Arr[ny][nx]) continue;
//
//			Temp[ny][nx] += Spread;			// 확산용 처리
//			Arr[Y][X] -= Spread;			// 원본용 처리
//		}
//	}
//
//	// 확산용 결과를 원본에 반영
//	for (int i = 0; i < R; ++i)
//	{
//		for (int j = 0; j < C; ++j)
//		{
//			Arr[i][j] += Temp[i][j];
//		}
//	}
//}
//
//void SpreadPurifier(vector<pair<int, int>>& V)
//{
//	// 공기청정기 경로를 역으로 따라가 먼지 밀어내기
//	for (int i = V.size() - 1; i > 0; --i)
//	{
//		Arr[V[i].first][V[i].second] = Arr[V[i - 1].first][V[i - 1].second];
//	}
//
//	// 공기청정기 다음 칸은 항상 0
//	Arr[V[0].first][V[0].second] = 0;
//}
//
//vector<pair<int, int>> AirClear(int sy, int sx, const int dy[], const int dx[])
//{
//	vector<pair<int, int>> V;
//	int Count = 0, Y = sy, X = sx;
//
//	while (true)
//	{
//		// 다음 위치 이동
//		int ny = Y + dy[Count];
//		int nx = X + dx[Count];
//
//		// 처음 위치로 왔을 경우 탈출
//		if (ny == sy && nx == sx) break;
//
//		// 끝 지점시 방향 전환
//		if (0 > ny || 0 > nx || R <= ny || C <= nx)
//		{
//			++Count;
//			ny = Y + dy[Count];
//			nx = X + dx[Count];
//		}
//
//		if (ny == sy && nx == sx) break;
//
//		Y = ny; 
//		X = nx;
//		V.push_back({ ny, nx });
//	}
//
//	return V;
//}
//
//int main()
//{
//	cin >> R >> C >>  T;
//	bool Flag = true;				// 미세먼지 방향
//
//	for (int i = 0; i < R; ++i)
//	{
//		for (int j = 0; j < C; ++j)
//		{
//			cin >> Arr[i][j];
//
//			if (-1 == Arr[i][j])
//			{
//				if (true == Flag)
//				{
//					VecUp = AirClear(i, j, dyup, dxup);
//					Flag = false;
//				}
//				else
//				{
//					VecDown = AirClear(i, j, dydw, dxdw);
//				}
//			}
//		}
//	}
//
//	// T초 동안 확산
//	while (T--)
//	{
//		SpreadDust(dydw, dxdw);
//		SpreadPurifier(VecUp);
//		SpreadPurifier(VecDown);
//	}
//
//	// 남은 미세먼지 양
//	for (int i = 0; i < R; ++i)
//	{
//		for (int j = 0; j < C; ++j)
//		{
//			if (-1 != Arr[i][j])
//			{
//				Amount += Arr[i][j];
//			}
//		}
//	}
//
//	cout << Amount;
//
//	return 0;
//}

// 12_스타트와 링크
// https://www.acmicpc.net/problem/14889
//int N, Diff = 987654321, S[24][24];
//bool TeamSelect[24];
//
//void DivideTeam(int Index, int Count)
//{
//	// 팀원 모집 완료시
//	if (N / 2 == Count)
//	{
//		int T1 = 0, T2 = 0;
//
//		for (int i = 0; i < N; ++i)
//		{
//			for (int j = i + 1; j < N; ++j)
//			{
//				// T1에 속한 경우 합산
//				if(TeamSelect[i] && TeamSelect[j])
//				{
//					T1 += (S[i][j] + S[j][i]);
//				}
//				// T2에 속한 경우 합산
//				else if (!TeamSelect[i] && !TeamSelect[j])
//				{
//					T2 += (S[i][j] + S[j][i]);
//				}
//			}
//		}
//
//		// 두팀 능력차 최소값 갱신
//		Diff = min(Diff, abs(T1 - T2));
//		return;
//	}
//
//	// 팀 조합
//	for (int i = Index; i < N; ++i)
//	{
//		// 아직 선택되지 않았다면
//		if (false == TeamSelect[i])
//		{
//			// T1 포함
//			TeamSelect[i] = true;
//			DivideTeam(i + 1, Count + 1);
//			// 원복
//			TeamSelect[i] = false;
//		}
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
//			cin >> S[i][j];
//		}
//	}
//
//	DivideTeam(0, 0);
//
//	cout << Diff;
//
//	return 0;
//}

// 비트마스킹을 통해 팀원 선별
//int Go(vector<int>& TeamA, vector<int>& TeamB)
//{
//	// first: TeamA 능력치, second: TeamB 능력치
//	pair<int, int> Result;
//
//	for (int i = 0; i < N / 2; ++i)
//	{
//		for (int j = 0; j < N / 2; ++j)
//		{
//			if (i == j) continue;
//
//			Result.first += S[TeamA[i]][TeamA[j]];
//			Result.second += S[TeamB[i]][TeamB[j]];
//		}
//	}
//	
//	// 두 팀 간의 능력차
//	return abs(Result.first - Result.second);
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
//			cin >> S[i][j];
//		}
//	}
//
//	for (int i = 0; i < (1 << N); ++i)
//	{
//		// __builtin_popcount(int) => 켜져 있는 비트가 몇 개인지
//		// 선택된 비트의 수가 정확히 N / 2일 때만 유효한 팀 구성
//		if (N / 2 != __builtin_popcount(i)) continue;
//
//		vector<int> Start, Link;
//
//		for (int j = 0; j < N; ++j)
//		{
//			// 1
//			if(i & (1 << j))
//			{
//				Start.push_back(j);
//			}
//			// 0
//			else
//			{
//				Link.push_back(j);
//			}
//		}
//		
//		// 두 팀 능력차 최소값 갱신
//		Diff = min(Diff, Go(Start, Link));
//	}
//
//	cout << Diff;
//
//	return 0;
//}

// 13_2048(Easy)
// https://www.acmicpc.net/problem/12100
//int N, Result;
//
//// Dir: 0_상, 1_하, 2_좌, 3_우
//void Move(vector<vector<int>>& CurBorad, int Dir)
//{
//	for (int i = 0; i < i < N; ++i)
//	{
//		vector<int> Line;
//
//		for (int j = 0; j < N; ++j)
//		{
//			int Value;
//
//			switch (Dir)
//			{
//			case 0:	// 상 -> 하
//				Value = CurBorad[j][i];
//				break;
//			case 1:	// 하 -> 상
//				Value = CurBorad[N - j - 1][i];
//				break;
//			case 2:	// 좌 -> 우
//				Value = CurBorad[i][j];
//				break;
//			case 3:	// 우 -> 좌
//				Value = CurBorad[i][N - j - 1];
//				break;
//			}
//
//			// 0이 아닌 블록만 추출
//			if (0 != Value)
//			{
//				Line.push_back(Value);
//			}
//		}
//
//		vector<int> Merge;
//
//		// 병합 로직
//		for (int j = 0; j < Line.size(); ++j)
//		{
//			// 인접한 두 블록이 같을 경우 병합
//			if (j + 1 < Line.size() && Line[j] == Line[j + 1])
//			{
//				Merge.push_back(Line[j] * 2);
//				// 블록을 합쳤기 때문에 다음 건너 뛰기
//				++j;
//			}
//			// 병합이 안 됐을 때
//			else
//			{
//				Merge.push_back(Line[j]);
//			}
//		}
//
//		// 병합 후 빈 곳 0
//		while (Merge.size() < N)
//		{
//			Merge.push_back(0);
//		}
//
//		// 병합 결과 보드에 적용
//		for (int j = 0; j < N; ++j)
//		{
//			switch (Dir)
//			{
//			case 0:	// 상
//				CurBorad[j][i] = Merge[j];
//				break;
//			case 1:	// 하
//				CurBorad[N - j - 1][i] = Merge[j];
//				break;
//			case 2:	// 좌
//				CurBorad[i][j] = Merge[j];
//				break;
//			case 3:	// 우
//				CurBorad[i][N - j - 1] = Merge[j];
//				break;
//			}
//		}
//	}
//}
//
//void FiveCountMove(vector<vector<int>> CurBoard, int Depth)
//{
//	if (5 == Depth)
//	{
//		for (int i = 0; i < N; ++i)
//		{
//			for (int j = 0; j < N; ++j)
//			{
//				// 블록 최대값 갱신
//				Result = max(Result, CurBoard[i][j]);
//			}
//		}
//
//		return;
//	}
//
//	// 네 방향으로 이동 탐색
//	for (int i = 0; i < 4; ++i)
//	{
//		vector<vector<int>> NewBoard = CurBoard;
//		Move(NewBoard, i);
//		FiveCountMove(NewBoard, Depth + 1);
//	}
//}
//
//int main()
//{
//	cin >> N;
//	
//	// N * N 행렬 보드
//	vector<vector<int>> Board(N, vector<int>(N));
//
//	for (int i = 0; i < N; ++i)
//	{
//		for (int j = 0; j < N; ++j)
//		{
//			cin >> Board[i][j];
//		}
//	}
//
//	FiveCountMove(Board, 0);
//
//	cout << Result;
//
//	return 0;
//}

// 1) 90도 회전
// 정사각형 배열(직사각형은 교안 참고)
// i, j = n - j - 1, i
// a[i][j] = a[n - j - 1][i]
// 2) Temp 활용
// 2020일 때 0은 제외하고 숫자가 같을 때 곱하기 2
//struct Board
//{
//	int m_B[24][24];
//
//	// 90 회전(1) 내용)
//	void Rotate90() 
//	{
//		int Temp[24][24];
//
//		for (int i = 0; i < N; ++i) 
//		{
//			for (int j = 0; j < N; ++j) 
//			{
//				Temp[i][j] = m_B[N - j - 1][i];
//			}
//		}
//
//		memcpy(m_B, Temp, sizeof(m_B));
//	}
//
//	// 이동하여 합산이 될 경우 합산(2) 내용)
//	void Move() 
//	{
//		int Temp[24][24];
//
//		for (int i = 0; i < N; ++i) 
//		{
//			// ValueCheck: 값이 들어와 있는지 확인
//			int CurIndex = -1, ValueCheck = 0;
//			
//			for (int j = 0; j < N; ++j) 
//			{
//				// 0은 무시
//				if (0 == m_B[i][j]) continue;
//
//				// 값이 들어와 있고 들어와 있는 값(Temp)와 보드 블록(m_B)의 값이 같은 경우
//				if (0 != ValueCheck && m_B[i][j] == Temp[i][CurIndex])
//				{
//					// 이전 값과 합치기
//					Temp[i][CurIndex] *= 2;
//					// 합쳤기 때문에 다음 건 합치지 못 하기 때문에 불가한 상태로 변경
//					ValueCheck = 0;
//				}
//				else 
//				{
//					// 새로 삽입
//					Temp[i][++CurIndex] = m_B[i][j];
//					// 다음 것과 합치기 가능한 상태로 변경
//					ValueCheck = 1;
//				}
//			}
//
//			for (CurIndex++; CurIndex < N; ++CurIndex)
//			{
//				Temp[i][CurIndex] = 0;
//			}
//		}
//		
//		// m_B를 Temp로!
//		memcpy(m_B, Temp, sizeof(m_B));
//	}
//
//	// 최대 값 추출
//	void GetMax() 
//	{
//		for (int i = 0;i < N; i++) 
//		{
//			for (int j = 0; j < N; j++) 
//			{
//				Result = max(Result, m_B[i][j]);
//			}
//		}
//	}
//};
//
//void Go(Board B, int here)
//{
//	if (5 == here)
//	{
//		B.GetMax();
//		
//		return;
//	}
//
//	for (int i = 0; i < 4; ++i)
//	{
//		Board m_B = B;
//
//		m_B.Move();
//		Go(m_B, here + 1);
//		B.Rotate90();
//	}
//}
//
//int main()
//{
//	cin >> N;
//
//	Board B;
//
//	for (int i = 0; i < N; ++i) 
//	{
//		for (int j = 0; j < N; ++j)
//		{
//			cin >> B.m_B[i][j];
//		}
//	}
//
//	Go(B, 0);
//
//	cout << Result;
//
//	return 0;
//}

// 14_뱀
// https://www.acmicpc.net/problem/3190
//const int Max_n = 100;
//int N, K, L;
//int dy[] = { 1, 0, -1, 0 }; // 오른쪽, 아래, 왼쪽, 위쪽
//int dx[] = { 0, 1, 0, -1 };
//int a[Max_n][Max_n];
//
//pair<int, char> Dir;
//queue<pair<int, char>> Qdir;
//
//int main()
//{
//	cin >> N >> K;
//
//	for (int i = 0; i < K; ++i)
//	{
//		int row, col;
//		cin >> row >> col;
//		a[row][col] = 1;						// 사과 위치
//	}
//
//	cin >> L;
//
//	for (int i = 0; i < L; ++i)
//	{
//		cin >> Dir.first >> Dir.second;
//		Qdir.push(Dir);
//	}
//
//	int Time = 0;
//	int Direction = 0;							// 초기 방향은 오른쪽
//	deque<pair<int, int>> Snake;
//	Snake.push_back({ 1, 1 });					// 뱀의 시작 위치
//
//	while (true) 
//	{
//		++Time;
//		int ny = Snake.front().second + dy[Direction];
//		int nx = Snake.front().first + dx[Direction];
//
//		// 벽에 부딪히거나 몸에 부딪히면 게임 종료
//		if (1 > ny || 1 > nx || N < ny || N < nx || find(Snake.begin(), Snake.end(), make_pair(nx, ny)) != Snake.end())
//		{
//			cout << Time << endl;
//			break;
//		}
//
//		Snake.push_front({ nx, ny });			// 새로운 머리 위치
//
//		if (a[nx][ny] == 1) a[nx][ny] = 0;		// 사과가 있으면 사과 제거
//		else Snake.pop_back();					// 사과가 없으면 꼬리를 제거
//
//		// 방향 전환이 필요한 경우
//		if (true != Qdir.empty() && Time == Qdir.front().first)
//		{
//			//                                          왼쪽 회전               오른쪽 회전
//			Direction = 'L' == Qdir.front().second ? (Direction + 3) % 4 : (Direction + 1) % 4;
//			Qdir.pop();
//		}
//	}
//
//	return 0;
//}

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int N, K, L, Y, X, T, Result, Index, Time, Dir = 1;
int a[104][104], Visited[104][104];
char Ch;
deque<pair<int, int>> DQ;
vector<pair<int, int>> TransInfo;

int main() 
{
	cin >> N >> K;

	for (int i = 0; i < K; ++i)
	{
		cin >> Y >> X;
		a[--Y][--X] = 1;								// 사과 위치
	}

	cin >> L;

	for (int i = 0; i < L; ++i)
	{
		cin >> T >> Ch;

		// 시간에 따른 방향 전환
		if ('D' == Ch) TransInfo.push_back({ T, 1 });
		else TransInfo.push_back({ T, 3 });
	}

	DQ.push_back({ 0, 0 });

	while (true != DQ.empty())
	{
		++Time;
		tie(Y, X) = DQ.front();
		int ny = Y + dy[Dir];
		int nx = X + dx[Dir];

		// 벽에 부딪히거나 몸에 부딪히면 게임 종료
		if (0 > ny || 0 > nx || N <= ny || N <= nx || Visited[ny][nx]) break;

		// 사과가 없을 때
		if (0 == a[ny][nx])
		{
			// 꼬리 방문 기록 삭제
			Visited[DQ.back().first][DQ.back().second] = 0;
			// 꼬리 정보 제거
			DQ.pop_back();
		}
		// 사과를 먹은 것으로 처리
		else a[ny][nx] = 0;

		// 머리 처리
		Visited[ny][nx] = 1;
		DQ.push_front({ ny, nx });
		
		if (Time == TransInfo[Index].first)
		{
			Dir = (Dir + TransInfo[Index].second) % 4;
			++Index;
		}
	}

	cout << Time;
	
	return 0;
}