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
string Str, BoomStr, S, CompStr;

int main()
{
	cin >> Str >> BoomStr;

	for (int i = 0; i < Str.length(); ++i)
	{
		S += Str[i];

		if (S.size() >= BoomStr.size())
		{
			CompStr = S.substr((S.size() - BoomStr.size()));
			if (0 == CompStr.compare(BoomStr))
			{
				S.erase(S.size() - BoomStr.size());
			}
		}
	}

	cout << (true == S.empty() ? "FRULA" : S);

	return 0;
}
