#include <bits/stdc++.h>

using namespace std;

// 1_��ȸ����
// https://www.acmicpc.net/problem/2109
// �켱���� ť�� ����ؼ� ������ ���� ���� �������� ����
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
//		// ���� �߰�
//		PQ.push(Vec[i].second);
//
//		// ������� ������ ���� ���� �����Ϻ��� ���� ���
//		// �Ϸ翡 �ϳ��� �����ϹǷ� �ʰ��� ��� ���� ���� �����Ḧ ����
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

// 2_���ڿ� ����
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

// ���� Ȥ�� ¦���� ������ stack�� Ȯ���� ����
//int main()
//{
//	cin >> Str >> BoomStr;
//
//	for (char Ch : Str)
//	{
//		Stk.push(Ch);
//
//		// ������ ��ܰ� ���� ���ڿ��� �� �κ��� ������ Ȯ��
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
//			// ���� ���ڿ��� �ٸ��ٸ� �ٽ� �־��ִ� �۾�
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

// 3_�Ŷ��
// https://www.acmicpc.net/problem/1781
// ������ο� �Ŷ�� ������ �켱���� ������ �켱���� ť�� ���
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