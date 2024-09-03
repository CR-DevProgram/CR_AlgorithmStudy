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
const int VAL = 987654321;
int n, m, ret = VAL, area[11], comp[11], visited[11];
vector<int> adj[11];

pair<int, int> dfs(int here, int value) 
{
    visited[here] = 1;
                       // ��� �ڽ��� ��, �α� ��
    pair<int, int> ret = { 1, area[here] };
    for (int there : adj[here]) 
    {
        // ���� �ٸ��� ����
        if (comp[there] != value) continue;
        // �湮�� ���� �ִٸ� ����
        if (0 != visited[there]) continue;

        pair<int, int> tmp = dfs(there, value);
        ret.first += tmp.first;
        ret.second += tmp.second;
    }

    return ret;
}

int main() 
{
    // ���� �� �Է� �ޱ�
    cin >> n;
    // ������ �α� �� �Է� �ޱ�
    for (int i = 1; i <= n; ++i) cin >> area[i];
    for (int i = 1; i <= n; ++i) 
    {
        // ���� �� �ٸ� ������ ���� �� �� �Է� �ޱ�
        cin >> m;
        // ��� ������ ����Ǿ� �ִ��� �Է� �ޱ� & ���� �۾�
        for (int j = 0; j < m; ++j) 
        {
            int temp = 0;
            cin >> temp;

            // ���� ����Ʈ
            adj[i].push_back(temp);
            adj[temp].push_back(i);
        }
    }

    // ��� ����� �� Ȯ��
    for (int i = 1; i < (1 << n) - 1; ++i) 
    {
        // �ʱ�ȭ �۾�
        fill(comp, comp + 11, 0);
        fill(visited, visited + 11, 0);

        int a = -1;
        int b = -1;
        for (int j = 0; j < n; ++j) 
        {
            if (i & (1 << j)) 
            { 
                // ��ĥ �۾�
                comp[j + 1] = 1; 
                // A ���� ����
                a = j + 1; 
            }
            // B ���� ����
            else b = j + 1;
        }

        pair<int, int> A = dfs(a, 1);
        pair<int, int> B = dfs(b, 0);

        // n == �� �� �ϴ� ����: 3�� �̻����� �ɰ������� Ȯ���ϱ� ����(3�� �̻��̸� ���� ������ �� n���� ����)
        if (n == A.first + B.first) ret = min(ret, abs(A.second - B.second));
    }

    cout << (VAL == ret ? -1 : ret);

    return 0;
}