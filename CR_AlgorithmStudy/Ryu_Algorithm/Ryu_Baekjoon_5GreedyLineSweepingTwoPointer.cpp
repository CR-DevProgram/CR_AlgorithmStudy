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
long long N, Count, Start, End, Arr[100004], Cnt[100004];

int main()
{
	cin >> N;
	
	for (int i = 0; i < N; ++i)
	{
		cin >> Arr[i];
	}

	while (End < N)
	{
		// 중복되는 것이 없는 경우
		if (0 == Cnt[Arr[End]])
		{
			++Cnt[Arr[End++]];
		}
		// 중복되는 것을 만났을 때
		else
		{
			Count += (End - Start);
			--Cnt[Arr[Start++]];
		}
	}

	Count += (End - Start) * (End - Start + 1) / 2;
	
	cout << Count;

	return 0;
}