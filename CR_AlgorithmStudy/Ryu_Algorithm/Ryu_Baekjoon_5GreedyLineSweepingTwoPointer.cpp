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
int N, Total;
pair<int, int> Pii;
vector<pair<int, int>> Vec;
priority_queue<int, vector<int>, greater<int>> PQ;

int main()
{
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> Pii.first >> Pii.second;

		Vec.push_back(Pii);
	}

	sort(Vec.begin(), Vec.end());

	for (int i = 0; i < N; ++i)
	{
		PQ.push(Vec[i].second);

		if (PQ.size() > Vec[i].first)
		{
			PQ.pop();
		}
	}

	while (true != PQ.empty())
	{
		Total += PQ.top();
		PQ.pop();
	}

	cout << Total;

	return 0;
}