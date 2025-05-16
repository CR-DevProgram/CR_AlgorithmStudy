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

// 4_�Ұ� ���� �ǳʰ� ���� 3
// https://www.acmicpc.net/problem/14469
// ���� ������ ����
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

// 5_ȸ�ǽ� ����
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

// ������ ���� ����
// ȸ�ǰ� ��ġ�� �ʰ� �ִ� ȸ�� ����
// ���� ������
// ���� ���õ� ������ ��� ������ �����ϸ� ���� �������� ���ø��� ��
// �����̸� �����Ѵ�!
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

// 6_���� ����
// https://www.acmicpc.net/problem/1202
// ���濡�� �ִ� �� ���� ������ ���� �� ����
// N: ���� ����, K: ���� ����, M: ���� ����, V: ���� ����, C: ���濡 ���� �� �ִ� �ִ� ����
//int N, M, V, K, C;
//long long Sum;					// ���� ��ġ�� ���� ��ġ ������ ũ�� ������ ��� �ջ��Ѵ� ���� �� int�� �� ��� �����÷ο�� ���� ������ ���� ����
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
//	// ���� �� ���� ���� �������� ����
//	sort(JVec.begin(), JVec.end());
//	sort(BVec.begin(), BVec.end());
//
//	// ���� ��ü Ž���� ���� �ε��� ����
//	int JewelIndex = 0;
//	// ���濡 ���� �� �ִ� ���� Ȯ��
//	for (int i = 0; i < K; ++i)
//	{
//		// ���� ������ �ִ� ����
//		int BagMax = BVec[i];
//		
//		// ���� ���湫�Ժ��� ���ų� ���� ������ PQ�� ���
//		// ������ ���� ���Ժ��� ���ϹǷ� ���� ���� ������������ ���ĵǾ� �ֱ� ������ �������� Ž�� ����
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

// 7_�Ҽ��� ������
// https://www.acmicpc.net/problem/1644
// �Ҽ� = �����佺�׳׽� ü
// ������ ���۰� ���� �ξ� �� �����͸� ����� Ǫ�� ���
// ������ N���� ���� ��� ���� ������ �̵�
// ������ N���� Ŭ ��� ������ ���� �̵�
//bool Erab[4000001];
//int N, Erai[4000001], Pos, Sum, Count;
//
//int main()
//{
//	cin >> N;
//
//	// ===�����佺�׳׽��� ü===
//	for (int i = 2; i <= N; ++i)
//	{
//		if (true == Erab[i]) continue;
//
//		// �Ҽ��� �ƴ� �Ϳ� true
//		for (int j = 2 * i; j <= N; j += i)
//		{
//			Erab[j] = true;
//		}
//	}
//
//	for (int i = 2; i <= N; ++i)
//	{
//		// �Ҽ��� ��� int Ÿ�� �迭�� ���
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
//		// ���� N���� ũ�� �������� �̵���Ű�� �հ迡�� ������ ���� ��
//		if (Sum >= N)
//		{
//			Sum -= Erai[Begin++];
//		}
//		// ���� N���� ������ ������ �̵���Ű�� �հ迡�� �� ���� ����
//		else
//		{
//			if (End == Pos) break;
//			Sum += Erai[End++];
//		}
//
//		// �� ������ �̵� ���� �� ���� �ջ�� N�� ���Ͽ� ���� ��� ī��Ʈ ����
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
// ���������� �� = (n * (n + 1)) / 2
// ����� ���� ���϶�� �� ��� int ���� long long���� �����ϴ� ���� ����
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
		// �ߺ��Ǵ� ���� ���� ���
		if (0 == Cnt[Arr[End]])
		{
			++Cnt[Arr[End++]];
		}
		// �ߺ��Ǵ� ���� ������ ��
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