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
