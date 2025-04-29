#include <bits/stdc++.h>

using namespace std;

// 1_���̾�Ʈ
// https://www.acmicpc.net/problem/19942
// ����� ������ ���� ���� ���а� �ּұݾ� ���߱�
// ��Ʈ����ŷ�� Ȱ���Ͽ� Ư�� �ε�����°�� �ջ�� �ּҰ� ��
// ���ǿ� �ش�Ǵ� ��찡 ���ٸ� -1�� ���
// n: ����� ����
//const int VAL = 987654321;
//int n, mp, mf, ms, mv;
//int cump, cumf, cums, cumv, ret = VAL, cumc;
//map<int, vector<vector<int>>> ret_v;		// ��뺰 ���� �ڷᱸ�� => ����� 700(int)�� ����� ����(vector<int>) ����(vector<����>)
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
//	// ��� ����� �� ������
//	for (int i = 0; i < (1 << n); ++i) 
//	{
//		// �ʱ�ȭ �۾�
//		cump = cumf = cums = cumv = cumc = 0;
//		vector<int> v;
//
//		for (int j = 0; j < n; ++j) 
//		{
//			// ���� Ȯ��
//			if (i & (1 << j)) 
//			{
//				// ���� �߰�
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
//		// ��� �ּ� ���缺�� ��ġ �̻��� ���
//		if (mp <= cump && mf <= cumf && ms <= cums && mv <= cumv)
//		{
//			// �ּҺ�� ���� �� ���� �߰� �۾�
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
//		// �ּ� ��� ���
//		cout << ret << "\n";
//		// �������� ����
//		sort(ret_v[ret].begin(), ret_v[ret].end());
//		// ��뺰 ���� ��� ���
//		for (int i : ret_v[ret][0]) cout << i << " ";
//	}
//	else cout << -1 << '\n';
//
//	return 0;
//}

// 2_���� ������
// https://www.acmicpc.net/problem/1285
// ���� ������� �޸�(T)�� �ּҷ� �ϴ� ��
// ��� ���� ������ ���� ��� ����� ���� �����ϸ� 20(n�� �ִ�) * 2 = 40
// 2�� 40�� �ð����⵵�� �����ϸ� �Ұ���, �ٸ� ������� Ǯ��� ��
// �����ظ� ����, T�� H�� ���� ����ؼ� �������� ������ ������ ����
// ���� �������� ���� �����´ٴ� ���� �����ذ� �̹� ������ ��(�ݴ�ε� ��������)
// ���� 2�� 40���� �ƴ� 20������ �ุ ������ �� ���� Ȯ���ϸ� �������� ���� �Ǵ�
// ����Ϳ�,,,�� ����Ե�����
//int n, coinTable[21], ret = 987654321;
//int dy[] = { -1, 0, 1, 0 };
//int dx[] = { 0, 1, 0, -1 };
//
//void go(int here) 
//{
//	// �������(�ุ ������ ���� �Ǵ��ؼ� ������)
//	if (here == n + 1) 
//	{
//		int sum = 0;
//		// 1, 2, 4, 8,.. Ȯ��
//		for (int i = 1; i <= (1 << (n - 1)); i *= 2) 
//		{
//			int cnt = 0;
//			// Ư�� ����� �κ� ��Ҹ� Ȯ���ϱ� ������ ~n = -(n + 1)���� ��Ʈ����ŷ�� �պκ� ��� X
//			for (int j = 1; j <= n; ++j)
//			{
//				// coinTable[j]: ��
//				// �� �ϳ��� �� �κ� ��� Ȯ��
//				if (coinTable[j] & i) ++cnt;
//			}
//
//			// �ּ� �� ���� �� ����
//			sum += min(cnt, n - cnt);
//		}
//
//		ret = min(ret, sum);
//		return;
//	}
//
//	// ������ X
//	go(here + 1);
//
//	// ������
//	coinTable[here] = ~coinTable[here];
//	// ������ O
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
//			// �� ��(���ڿ�)�� ���ڷ� ǥ��(HHT -> 4, TTT -> 7, HHH -> 0)
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

// 3_�Ը��Ǵ��� 
// https://www.acmicpc.net/problem/17471
// ��帶�� ��ĥ �� ��, ��ĥ�ؼ� 2������ ������������ 3 �̻����� ���������� X
// ��� ����� ���� Ȯ���Ͽ� �� �� 2���� �������� �� �߿��� �ּڰ��� ����
// �� �������� 2���� ū �������� ������ ������ �α����� ���� ���� ���� ����� ���� �ּڰ�
// n: ���� ����
//const int VAL = 987654321;
//int n, m, ret = VAL, area[11], comp[11], visited[11];
//vector<int> adj[11];
//
//pair<int, int> dfs(int here, int value) 
//{
//    visited[here] = 1;
//                       // ��� �ڽ��� ��, �α� ��
//    pair<int, int> ret = { 1, area[here] };
//    for (int there : adj[here]) 
//    {
//        // ���� �ٸ��� ����
//        if (comp[there] != value) continue;
//        // �湮�� ���� �ִٸ� ����
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
//    // ���� �� �Է� �ޱ�
//    cin >> n;
//    // ������ �α� �� �Է� �ޱ�
//    for (int i = 1; i <= n; ++i) cin >> area[i];
//    for (int i = 1; i <= n; ++i) 
//    {
//        // ���� �� �ٸ� ������ ���� �� �� �Է� �ޱ�
//        cin >> m;
//        // ��� ������ ����Ǿ� �ִ��� �Է� �ޱ� & ���� �۾�
//        for (int j = 0; j < m; ++j) 
//        {
//            int temp = 0;
//            cin >> temp;
//
//            // ���� ����Ʈ
//            adj[i].push_back(temp);
//            adj[temp].push_back(i);
//        }
//    }
//
//    // ��� ����� �� Ȯ��
//    for (int i = 1; i < (1 << n) - 1; ++i) 
//    {
//        // �ʱ�ȭ �۾�
//        fill(comp, comp + 11, 0);
//        fill(visited, visited + 11, 0);
//
//        int a = -1;
//        int b = -1;
//        for (int j = 0; j < n; ++j) 
//        {
//            if (i & (1 << j)) 
//            { 
//                // ��ĥ �۾�
//                comp[j + 1] = 1; 
//                // A ���� ����
//                a = j + 1; 
//            }
//            // B ���� ����
//            else b = j + 1;
//        }
//
//        pair<int, int> A = dfs(a, 1);
//        pair<int, int> B = dfs(b, 0);
//
//        // n == �� �� �ϴ� ����: 3�� �̻����� �ɰ������� Ȯ���ϱ� ����(3�� �̻��̸� ���� ������ �� n���� ����)
//        if (n == A.first + B.first) ret = min(ret, abs(A.second - B.second));
//    }
//
//    cout << (VAL == ret ? -1 : ret);
//
//    return 0;
//}

// 4_���ĺ�  
// https://www.acmicpc.net/problem/1987
// ���� ��� �����Ͽ� �ִ� �� ĭ �̵� �����Ѱ�
// +) �̵� ��� �κп��� ���ڷ� �湮 ��Ͽ� ���� �տ����� ���ڰ��� �Ѱܼ� �����ϰ� ó���ϴ� ����� ����
// r: ���� ĭ��, c: ���� ĭ��,
//int r, c, visited, ret = -1;
//char alphabet[22][22];
//int dy[] = { -1, 0, 1, 0 };
//int dx[] = { 0, 1, 0, -1 };
//
//void move(int y, int x, int cnt)
//{
//	// �ִ� ī��Ʈ ����
//	ret = max(ret, cnt);
//
//	// 4���� �̵�
//	for (int i = 0; i < 4; ++i)
//	{
//		int ny = y + dy[i];
//		int nx = x + dx[i];
//
//		// ���� ����ų� �̹� �湮�ߴٸ� ����
//		if (0 > ny || 0 > nx || r <= ny || c <= nx) continue;
//		if (visited & (1 << (alphabet[ny][nx] - 'A'))) continue;
//
//		// �湮 ó��
//		visited |= (1 << (alphabet[ny][nx] - 'A'));
//		// ��� �̵� �� �̵� ī��Ʈ ����
//		move(ny, nx, cnt + 1);
//		// �湮 ����
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
//	// ������ �湮ó��
//	visited |= (1 << (alphabet[0][0] - 'A'));
//	// �̵� ����
//	move(0, 0, 1);
//
//	cout << ret;
//
//	return 0;
//}

// 5_����
// https://www.acmicpc.net/problem/14890
// �־��� ���� ũ�⿡ ���̰� 1���� ���� ���� ���� ��ġ ����
// ���� ũ�⺸�� ���� ���� ���� �� ����
// �̵� ������ ��μ� Ȯ��
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
//            // ���� ����
//            if (a[i][j] == a[i][j + 1]) ++cnt;
//            // �������� �ʱ�ȭ(ĭ�� �ϳ� ����, l�� ���� ũ�⺸�� ũ�ų� ���ƾ� ����)
//            else if (a[i][j] + 1 == a[i][j + 1] && l <= cnt) cnt = 1;
//            // �������� �ʱ�ȭ(ĭ�� �ϳ� ����, ������ �ƴ� ������� ����), ������ ���� ����
//            else if (a[i][j] - 1 == a[i][j + 1] && 0 <= cnt) cnt = -l + 1;
//            else break;
//        }
//
//        // ������ ���� ���� Ȯ�� & ��μ� ����
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
//            // ���� ���� ��Ī �۾�
//            ver[j][i] = hor[i][j];
//        }
//    }
//
//    // ����
//    go(hor);
//    // ����
//    go(ver);
//
//    cout << ret;
//
//    return 0;
//}

// 6_����ħ
// https://www.acmicpc.net/problem/1062
// K: ���� ����(�ִ� 50), N: ���ؿ� �����ϴ� �ܾ�(0 <= N <= 26)
// 'anta-'�� ����, '-tica'�� ��
// ���� ���� ��� �� �ִ� ���� ������ ���� ��
// ��� ����� ��(2^26) ���� Ž�� �˰��� => ����
//int K, N;
//int Words[50];
//
//int Count(int KnowWords)
//{
//    int Cnt = 0;
//
//    for (int Word : Words) 
//    {
//        // ��� �ܾ ������� '&' �����ڸ� �� ���� Word�̸� ���� �� �ִ� �ܾ��̹Ƿ� Cnt ����
//        if (Word && Word == (Word & KnowWords)) ++Cnt;
//    }
//
//    return Cnt;
//}
//
//// Idx: ���ĺ�
//// K: ��� �� �ִ� ���� ��
//// KnowWords: ��� �ܾ�
//int WordProcess(int Idx, int K, int KnowWords)
//{
//    // ����
//    if (0 > K) return 0;
//
//    // ��� ���ڸ� Ž��
//    if (26 == Idx) return Count(KnowWords);
//
//    // ���ڸ� ��� ������ ó��
//    int Result = WordProcess(Idx + 1, K - 1, KnowWords | (1 << Idx));
//
//    // ���� a, n, t, i, c�� �ƴ� ���
//    if (Idx != 'a' - 'a' && Idx != 'n' - 'a' && Idx != 't' - 'a' && Idx != 'i' - 'a' && Idx != 'c' - 'a')
//    {
//        // �� ���� ������ ó��(a, n, t, i, c ���� ���ڸ� ����� ���� ������ ó���ϱ� ���� => ��Ž�ϱ� ����)
//        // Result�� ���� ���� ���� �� �ִ� ���� ��ȯ�ϱ� ���� ��
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
//            // �ܾ ���ĺ��� ���ڷ� ����Ͽ� ����(a: 1, b: 2, c: 4, d: 8, ...)
//            Words[i] |= (1 << (Ch - 'a'));
//        }
//    }
//
//    cout << WordProcess(0, K, 0) << '\n';
//
//    return 0;
//}

// 7_�����
// https://www.acmicpc.net/problem/1094
// ���� 64, ������ �ɰ��� ����
// X ������ �����
// * ������ �ִ� ���� �� ���� ª�� ���� ����
// * �ڸ� ������ ���� �� �ϳ��� ������ �����ִ� ������ ���� ���� X���� ũ�ų� ���ٸ�, �ڸ� ������ ���� �� �ϳ� ����
// * �����ִ� ��� ���븦 Ǯ�� �ٿ��� X ����
// 64 -> 32 -> 16 -> 8 -> 4 -> 2 -> 1
// _______ X�� 2������ ���� ���ľ� �Ǵ� ���� �ľ� ����
//int X, Reslut = 1;
//
//int main() 
//{
//    cin >> X;
//
//    while (1 != X)
//    {
//        // 2���� & ������ 1�� �Ǹ� ����
//        if(X & 1) ++Reslut;
//        // ���� �ڸ���
//        X /= 2;
//    }
//
//    cout << Reslut << '\n';
//
//    return 0;
//}

// 8_����
// https://www.acmicpc.net/problem/2234
// ���� ����, ���� ���� ���� ����, �ϳ��� ���� �����Ͽ� ���� �� �ִ� ���� ���� ���� ũ��
// �� ����: �� - 1, �� - 2, �� - 4, �� - 8 => �����ϼ� 2���� ó��
// �̵� �迭�� ���� ���� �� ��
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
//		// �������� ���� ���� �� �̵�
//		if (!(WallInfos[Y][X] & (1 << i)))
//		{
//			int ny = Y + dy[i];
//			int nx = X + dx[i];
//
//			// �� ũ�� �ջ�
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
//	// �� ���� ���
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
//				// �� �� ����
//				++Index;
//				// �� Ž��, �� Index�� ���� ����(0�� �� n Size, 1�� �� n Size, ...)
//				RoomSize[Index] = DFS(i, j, Index);
//				// �� �� ���� ���� �� ����
//				Largest = max(Largest, RoomSize[Index]);
//			}
//		}
//	}
//
//	// �� �����Ͽ� ���� ���� �� ũ�� ���ϱ�
//	for (int i = 0; i < M; ++i)
//	{
//		for (int j = 0; j < N; ++j)
//		{
//			// �����÷ο� ����
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

// 9_����
// https://www.acmicpc.net/problem/11723
// �����տ� value�� �߰�
// value��°�� 1�� ����(��Ʈ����ŷ)
//// value�� 20����
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
//		// add: Value �߰�, Value�� �ִ� ��� ����
//		if ('a' == Command[0] && 'd' == Command[1])
//		{
//			cin >> Value;
//			S |= (1 << Value);
//		}
//		// all: {1, 2, ..., 20}���� �ٲ�
//		else if ('a' == Command[0] && 'l' == Command[1])
//		{
//			S = (1 << 21) - 1;
//		}
//		// remove: Value ����, Value�� ���� ��� ����
//		else if ('r' == Command[0])
//		{
//			cin >> Value;
//			S &= ~(1 << Value);
//		}
//		// check: Value�� ������ 1, ������ 0 ���
//		else if ('c' == Command[0])
//		{
//			cin >> Value;
//			cout << ((S & (1 << Value)) ? true : false) << '\n';
//		}
//		// toggle: Value�� ������ Value ����, ������ �߰�
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

// 10_���� ����
// https://www.acmicpc.net/problem/14391
// ���� ������ �Ʒ�, ���� �¿��� ��
// ���̸� ������ �߶� ���� ������ �ִ� �� ���ϱ�
// k�� �ڸ��� ��ġ�� �ľ��Ͽ� ���� ���� ��
// N: ���� ũ��, M: ���� ũ��(�� ���� ��� �ִ� 4)
// 0: ����, 1: ���� (N * M + M��°)
//int N, M, Result, Paper[4][4];
//string Nums;
//
//int main()
//{
//	cin >> N >> M;
//
//	// ���� ���� �Է�
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
//	// 0�� 1�� ����(���η� �ڸ��� ���η� �ڸ��� ��� ������ �ڸ��� ����� �� Ȯ��)
//	for (int k = 0; k < (1 << (N * M)); ++k)
//	{
//		int Sum = 0;
//
//		// 0: ����
//		for (int i = 0; i < N; ++i)
//		{
//			int Current = 0;
//
//			for (int j = 0; j < M; ++j)
//			{
//				int Temp = i * M + j;
//
//				// 0�̶�� ���� �� Ȯ�� ����
//				if (0 == (k & (1 << Temp)))
//				{
//					Current = Current * 10 + Paper[i][j];
//				}
//				// 0�� �ƴ϶�� �ջ�
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
//		// 1: ����
//		for (int j = 0; j < M; ++j)
//		{
//			int Current = 0;
//
//			for (int i = 0; i < N; ++i)
//			{
//				int Temp = i * M + j;
//
//				// 0�� �ƴ�(1-����-) ����� ���� �� Ȯ�� ����
//				if (0 != (k & (1 << Temp)))
//				{
//					Current = Current * 10 + Paper[i][j];
//				}
//				// 0�̶�� �ջ�
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
//		// �ִ밪 ����
//		Result = max(Result, Sum);
//	}
//
//	cout << Result;
//
//	return 0;
//}

// 11_Tree
// https://www.acmicpc.net/problem/13244
// ������ ����Ǿ� �־� edge ���� �ٸ� ���� �̵� ����
// ������ ���ŵǸ� ����Ǿ� ����X ���� �Ϻ� ��忡 ���� �Ұ�
// A���� B��� ���̿� ������ �߰��Ǹ� ����Ŭ ����, A��忡�� B���� ���� ����� �� ���� �̻��� ��� ����Ŭ ����
// ������ ���� �׷������� Ʈ������ �Ǻ�
// DFS �� ������ ����� ��� ���� Ž���� �����Ѱ� == Ʈ��
// E = V - 1 == Ʈ��
// T: �׷��� ���� �Ǻ� ��(�ִ� 10), N: ��� ����(1 <= N <= 1000), M: ���� ����
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
//		// �ʱ�ȭ
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
//		// ����� ���� �����
//		for (int i = 0; i < M; ++i)
//		{
//			cin >> A >> B;
//			Adj[A].push_back(B);
//			Adj[B].push_back(A);
//		}
//
//		// DFS�� �� ���� ������ Ȯ��
//		for (int i = 1; i <= N; ++i)
//		{
//			if (0 == Visited[i])
//			{
//				DFS(i);
//				// Count�� 1�̸� �� ���� �� ��
//				++Count;
//			}
//		}
//
//		// Ʈ�� ������ Ȯ���Ͽ� Ʈ������ �׷������� �Ǻ�
//		cout << ((N - 1 == M && 1 == Count) ? "tree" : "graph") << '\n';
//	}
//
//	return 0;
//}

// 12_AC
// https://www.acmicpc.net/problem/5430
// R: ���� ������ �Լ�, D: ù��° �� ������ �Լ�(�迭�� ������� �� ����ϸ� ���� �߻�)
// T: �׽�Ʈ ���̽� ��(�ִ� 100), Strp: ������ �Լ�(1 <= p���� <= 100000), N: �迭�� ����ִ� ���� ����(0 <= N <= 100000)
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
		
		// �迭 �����
		for (char Ch : Str)
		{
			if('[' == Ch || ']' == Ch) continue;
			
			// ���� ����
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

		// Flag Ȱ��
		bool Err = false, Rev = false;

		for (char Ch : Strp)
		{
			if ('R' == Ch)
			{
				Rev = !Rev;
			}
			else
			{
				// �迭�� ��� ���� �� D�� �� ��� Error
				if (true == Deq.empty())
				{
					Err = true;
					break;
				}

				// ���������ִٸ� �� �κ� ����
				if (true == Rev)
				{
					Deq.pop_back();
				}
				// ���������� �ƴ϶�� ������� �� �κ� ����
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

			// ���������� R��� ������
			if (true == Rev)
			{
				reverse(Deq.begin(), Deq.end());
			}

			// �迭 ���
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
