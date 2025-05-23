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
//		// �ߺ��Ǵ� ���� ���� ���
//		if (0 == Cnt[Arr[End]])
//		{
//			++Cnt[Arr[End++]];
//		}
//		// �ߺ��Ǵ� ���� ������ ��
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

// 9_�� ���� ��
// https://www.acmicpc.net/problem/3273
// �����Ͽ� �� ���� �� ���۰� �� ������ �̿��� �� ������ ���
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

// 10_��Ƽ�� �����ٸ�
// https://www.acmicpc.net/problem/1700
// Memory Paging Optimal(Optimal Page Replacement Algorithm)
// ���� �̷��� �����Ǵ� �������� �ѾƳ��� ���(Page Swap)
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
//		// i��° ��� ��Ⱑ �������� ���� ��
//		if (0 == Reuse[Info[i]])
//		{
//			// N��ŭ ���� �� �����Ƿ� �����ִ� Vec�� ũ�� Ȯ��
//			// ��, ��Ƽ���� ���� �� ���
//			if (Vec.size() == N)
//			{
//				int Top = 0, Pos = 0;
//
//				for (int Idx : Vec)
//				{
//					int Current = 987654321;
//
//					// ���� �� �̷��� �����Ǵ� ���� Ȯ��
//					for (int j = i + 1; j < K; ++j)
//					{
//						if (Idx == Info[j])
//						{
//							Current = j;
//							break;
//						}
//					}
//
//					// ���� �� �̷��� �����Ǵ� ���� ���纸�� ���� ���
//					// ��, ���� ���߿� ���̰ų� �ƿ� �� ���̴� ��� ã�� �̴� ����
//					if (Top < Current)
//					{
//						// ���� �� �̷��� �����Ǵ� ��dl ����� ����
//						Top = Current;
//						// Pos�� �����ǰ�� ��Ÿ��
//						Pos = Idx;
//					}
//				}
//
//				// ���� �� �̷��� ���� �Ǵ� ���� ã�� �ٲ��ִ� ��, �� �� �����ְ� ī��Ʈ ����
//				// ��, �̰� ���� ��� �ȴ� ����
//				Reuse[Pos] = 0;
//				++Count;
//				Vec.erase(find(Vec.begin(), Vec.end(), Pos));
//			}
//
//			// N����ŭ ä������ ������ push_back, ��� ���� ����
//			Vec.push_back(Info[i]);
//			Reuse[Info[i]] = 1;
//		}
//	}
//
//	cout << Count;
//
//	return 0;
//}

// 11_�̼����� �ȳ�!
// https://www.acmicpc.net/problem/17144
// Ȯ��: Amount - Amount / 5
// ���� Ȯ��
// ����û���� ���� ����(�ݽð�)
//const int dyup[] = { 0, -1, 0, 1 };
//const int dxup[] = { 1, 0, -1, 0 };
//// ����û���� �Ʒ��� ����(�ð�)
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
//	// Ȯ���ų �̼������� Ȯ��
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
//	// Ȯ�� ����
//	while (true != Q.empty())
//	{
//		int X, Y;
//		tie(Y, X) = Q.front();
//		Q.pop();
//
//		// Ȯ��� ��
//		int Spread = Arr[Y][X] / 5;
//
//		for (int i = 0; i < 4; ++i)
//		{
//			int ny = Y + dy[i];
//			int nx = X + dx[i];
//
//			if (0 > ny || 0 > nx || R <= ny || C <= nx || -1 == Arr[ny][nx]) continue;
//
//			Temp[ny][nx] += Spread;			// Ȯ��� ó��
//			Arr[Y][X] -= Spread;			// ������ ó��
//		}
//	}
//
//	// Ȯ��� ����� ������ �ݿ�
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
//	// ����û���� ��θ� ������ ���� ���� �о��
//	for (int i = V.size() - 1; i > 0; --i)
//	{
//		Arr[V[i].first][V[i].second] = Arr[V[i - 1].first][V[i - 1].second];
//	}
//
//	// ����û���� ���� ĭ�� �׻� 0
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
//		// ���� ��ġ �̵�
//		int ny = Y + dy[Count];
//		int nx = X + dx[Count];
//
//		// ó�� ��ġ�� ���� ��� Ż��
//		if (ny == sy && nx == sx) break;
//
//		// �� ������ ���� ��ȯ
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
//	bool Flag = true;				// �̼����� ����
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
//	// T�� ���� Ȯ��
//	while (T--)
//	{
//		SpreadDust(dydw, dxdw);
//		SpreadPurifier(VecUp);
//		SpreadPurifier(VecDown);
//	}
//
//	// ���� �̼����� ��
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

// 12_��ŸƮ�� ��ũ
// https://www.acmicpc.net/problem/14889
//int N, Diff = 987654321, S[24][24];
//bool TeamSelect[24];
//
//void DivideTeam(int Index, int Count)
//{
//	// ���� ���� �Ϸ��
//	if (N / 2 == Count)
//	{
//		int T1 = 0, T2 = 0;
//
//		for (int i = 0; i < N; ++i)
//		{
//			for (int j = i + 1; j < N; ++j)
//			{
//				// T1�� ���� ��� �ջ�
//				if(TeamSelect[i] && TeamSelect[j])
//				{
//					T1 += (S[i][j] + S[j][i]);
//				}
//				// T2�� ���� ��� �ջ�
//				else if (!TeamSelect[i] && !TeamSelect[j])
//				{
//					T2 += (S[i][j] + S[j][i]);
//				}
//			}
//		}
//
//		// ���� �ɷ��� �ּҰ� ����
//		Diff = min(Diff, abs(T1 - T2));
//		return;
//	}
//
//	// �� ����
//	for (int i = Index; i < N; ++i)
//	{
//		// ���� ���õ��� �ʾҴٸ�
//		if (false == TeamSelect[i])
//		{
//			// T1 ����
//			TeamSelect[i] = true;
//			DivideTeam(i + 1, Count + 1);
//			// ����
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

// ��Ʈ����ŷ�� ���� ���� ����
//int Go(vector<int>& TeamA, vector<int>& TeamB)
//{
//	// first: TeamA �ɷ�ġ, second: TeamB �ɷ�ġ
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
//	// �� �� ���� �ɷ���
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
//		// __builtin_popcount(int) => ���� �ִ� ��Ʈ�� �� ������
//		// ���õ� ��Ʈ�� ���� ��Ȯ�� N / 2�� ���� ��ȿ�� �� ����
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
//		// �� �� �ɷ��� �ּҰ� ����
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
//// Dir: 0_��, 1_��, 2_��, 3_��
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
//			case 0:	// �� -> ��
//				Value = CurBorad[j][i];
//				break;
//			case 1:	// �� -> ��
//				Value = CurBorad[N - j - 1][i];
//				break;
//			case 2:	// �� -> ��
//				Value = CurBorad[i][j];
//				break;
//			case 3:	// �� -> ��
//				Value = CurBorad[i][N - j - 1];
//				break;
//			}
//
//			// 0�� �ƴ� ��ϸ� ����
//			if (0 != Value)
//			{
//				Line.push_back(Value);
//			}
//		}
//
//		vector<int> Merge;
//
//		// ���� ����
//		for (int j = 0; j < Line.size(); ++j)
//		{
//			// ������ �� ����� ���� ��� ����
//			if (j + 1 < Line.size() && Line[j] == Line[j + 1])
//			{
//				Merge.push_back(Line[j] * 2);
//				// ����� ���Ʊ� ������ ���� �ǳ� �ٱ�
//				++j;
//			}
//			// ������ �� ���� ��
//			else
//			{
//				Merge.push_back(Line[j]);
//			}
//		}
//
//		// ���� �� �� �� 0
//		while (Merge.size() < N)
//		{
//			Merge.push_back(0);
//		}
//
//		// ���� ��� ���忡 ����
//		for (int j = 0; j < N; ++j)
//		{
//			switch (Dir)
//			{
//			case 0:	// ��
//				CurBorad[j][i] = Merge[j];
//				break;
//			case 1:	// ��
//				CurBorad[N - j - 1][i] = Merge[j];
//				break;
//			case 2:	// ��
//				CurBorad[i][j] = Merge[j];
//				break;
//			case 3:	// ��
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
//				// ��� �ִ밪 ����
//				Result = max(Result, CurBoard[i][j]);
//			}
//		}
//
//		return;
//	}
//
//	// �� �������� �̵� Ž��
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
//	// N * N ��� ����
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

// 1) 90�� ȸ��
// ���簢�� �迭(���簢���� ���� ����)
// i, j = n - j - 1, i
// a[i][j] = a[n - j - 1][i]
// 2) Temp Ȱ��
// 2020�� �� 0�� �����ϰ� ���ڰ� ���� �� ���ϱ� 2
//struct Board
//{
//	int m_B[24][24];
//
//	// 90 ȸ��(1) ����)
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
//	// �̵��Ͽ� �ջ��� �� ��� �ջ�(2) ����)
//	void Move() 
//	{
//		int Temp[24][24];
//
//		for (int i = 0; i < N; ++i) 
//		{
//			// ValueCheck: ���� ���� �ִ��� Ȯ��
//			int CurIndex = -1, ValueCheck = 0;
//			
//			for (int j = 0; j < N; ++j) 
//			{
//				// 0�� ����
//				if (0 == m_B[i][j]) continue;
//
//				// ���� ���� �ְ� ���� �ִ� ��(Temp)�� ���� ���(m_B)�� ���� ���� ���
//				if (0 != ValueCheck && m_B[i][j] == Temp[i][CurIndex])
//				{
//					// ���� ���� ��ġ��
//					Temp[i][CurIndex] *= 2;
//					// ���Ʊ� ������ ���� �� ��ġ�� �� �ϱ� ������ �Ұ��� ���·� ����
//					ValueCheck = 0;
//				}
//				else 
//				{
//					// ���� ����
//					Temp[i][++CurIndex] = m_B[i][j];
//					// ���� �Ͱ� ��ġ�� ������ ���·� ����
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
//		// m_B�� Temp��!
//		memcpy(m_B, Temp, sizeof(m_B));
//	}
//
//	// �ִ� �� ����
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

// 14_��
// https://www.acmicpc.net/problem/3190
//const int Max_n = 100;
//int N, K, L;
//int dy[] = { 1, 0, -1, 0 }; // ������, �Ʒ�, ����, ����
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
//		a[row][col] = 1;						// ��� ��ġ
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
//	int Direction = 0;							// �ʱ� ������ ������
//	deque<pair<int, int>> Snake;
//	Snake.push_back({ 1, 1 });					// ���� ���� ��ġ
//
//	while (true) 
//	{
//		++Time;
//		int ny = Snake.front().second + dy[Direction];
//		int nx = Snake.front().first + dx[Direction];
//
//		// ���� �ε����ų� ���� �ε����� ���� ����
//		if (1 > ny || 1 > nx || N < ny || N < nx || find(Snake.begin(), Snake.end(), make_pair(nx, ny)) != Snake.end())
//		{
//			cout << Time << endl;
//			break;
//		}
//
//		Snake.push_front({ nx, ny });			// ���ο� �Ӹ� ��ġ
//
//		if (a[nx][ny] == 1) a[nx][ny] = 0;		// ����� ������ ��� ����
//		else Snake.pop_back();					// ����� ������ ������ ����
//
//		// ���� ��ȯ�� �ʿ��� ���
//		if (true != Qdir.empty() && Time == Qdir.front().first)
//		{
//			//                                          ���� ȸ��               ������ ȸ��
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
		a[--Y][--X] = 1;								// ��� ��ġ
	}

	cin >> L;

	for (int i = 0; i < L; ++i)
	{
		cin >> T >> Ch;

		// �ð��� ���� ���� ��ȯ
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

		// ���� �ε����ų� ���� �ε����� ���� ����
		if (0 > ny || 0 > nx || N <= ny || N <= nx || Visited[ny][nx]) break;

		// ����� ���� ��
		if (0 == a[ny][nx])
		{
			// ���� �湮 ��� ����
			Visited[DQ.back().first][DQ.back().second] = 0;
			// ���� ���� ����
			DQ.pop_back();
		}
		// ����� ���� ������ ó��
		else a[ny][nx] = 0;

		// �Ӹ� ó��
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