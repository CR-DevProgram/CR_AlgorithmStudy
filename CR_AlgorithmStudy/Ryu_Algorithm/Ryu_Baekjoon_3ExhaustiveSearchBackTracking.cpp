#include <bits/stdc++.h>

using namespace std;

// 1_ġŲ ���
// https://www.acmicpc.net/problem/15686
// ���� ���ذ� �ʹ� �ȵż� �������� ã�Ƽ� �ִ��� ���ظ� �غ�
// ġŲ���� �ִ� ������ M���� �־���, M���� ġŲ���� ���� �����θ� �����ϸ� ��
// ���� ġŲ �� �߿��� M���� ����? => �������� ��� ���� ������ ġŲ �Ÿ��� ���� ���� ���� ���α׷��� �ۼ��϶�� �����Ƿ� ������ ������� �������� M���� �����Ͽ� ���� �Ÿ��� ���� ���� ����ϸ� ��
// �� �� ���� ���� ����� ġŲ �� ������ �Ÿ��� ��� ���� �Ÿ��� ������ ġŲ �Ÿ��� ���� ���� ġŲ �Ÿ��� ���ϸ� ��
// ***** �� ���� ���� ����� ġŲ �� ������ �Ÿ��� ��� ���� �Ÿ� ***** => ���� �߿� ����Ʈ
// N: ���� ũ��, M: �ִ� ġŲ�� ����
//int N, M, ret = 100000, City[50][50];
//vector<pair<int, int>> Homes, Chickens, ChickenList;
//
//void Combi(int Start)
//{
//	if (M == ChickenList.size())
//	{
//		// ġŲ �Ÿ� ���ϱ� ����
//		int Cal = 0;
//		for (pair<int, int> Home : Homes)
//		{
//			// �Ÿ� �ּҰ��� ���ϱ� ���� �ִ밪 �ʱ�ȭ
//			int HomeMin = N * N;
//
//			for (pair<int, int> Chicken : ChickenList)
//			{
//				// �Ÿ� ����
//				int Dir = abs(Home.first - Chicken.first) + abs(Home.second - Chicken.second);
//				// ���� �������� ġŲ������ �ּҰŸ�
//				HomeMin = min(HomeMin, Dir);
//			}
//			// ���� �������� �ּҰŸ� �տ���
//			Cal += HomeMin;
//		}
//
//		// ���� �ּҰŸ� ������ ���� min Ȯ��
//		ret = min(ret, Cal);
//
//		return;
//	}
//
//	// ġŲ�� ����
//	for (int i = Start + 1; i < Chickens.size(); ++i)
//	{
//		ChickenList.push_back(Chickens[i]);
//		Combi(i);
//		ChickenList.pop_back();
//	}
//}
//
//int main()
//{
//	cin >> N >> M;
//
//	for (int i = 0; i < N; ++i)
//	{
//		for (int j = 0; j < N; ++j)
//		{
//			cin >> City[i][j];
//
//			// ���� ġŲ�� ��ġ ���� ���
//			if (1 == City[i][j]) Homes.push_back({ i,j });
//			if (2 == City[i][j]) Chickens.push_back({ i,j });
//		}
//	}
//
//	Combi(-1);
//
//	cout << ret;
//
//	return 0;
//}

// �� �ٸ� Ǯ�̹�(Combi����Ž�� �� �ε��� Ȱ��)
// �����ϰ� Ǯ �� �ִ°�? -> ���� -> �ð����⵵ ��� -> �����ϴ�?(���� GO), �Ұ����ϴ�?(�ٸ� �˰���)
// ġŲ���� �����ϰ� ��� ������ �Ÿ��� ���ؼ� �� �Ÿ� �� ���� �ּҰ��� ���ϸ� ��
int n, m, a[54][54], result = 987654321;
vector<vector<int>> ChickenList;		// ġŲ ��ġ�� ��� �ִ� Chicken�� �ε����� ��� ���� ����Ʈ
vector<pair<int, int>> Home, Chicken;

void Combi(int Start, vector<int> v)
{
	// �ִ� ġŲ�� ������ v ����� ���� ��
	if (m == v.size())
	{
		// ����
		// ���յ� ����
		ChickenList.push_back(v);
		return;
	}

	// ����
	for (int i = Start + 1; i < Chicken.size(); ++i)
	{
		v.push_back(i);
		Combi(i, v);
		v.pop_back();
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> a[i][j];

			if (1 == a[i][j]) Home.push_back({ i,j });
			if (2 == a[i][j]) Chicken.push_back({ i,j });
		}
	}

	vector<int> v;
	Combi(-1, v);

	// ġŲ�� �̱�
	for (vector<int> cList : ChickenList)
	{
		int ret = 0;
		for (pair<int, int> _Home : Home)
		{
			int _Min = 987654321;

			// ġŲ ����Ʈ �߿��� ������ �Ÿ�
			for (int ch : cList)
			{
				int _Dist = abs(_Home.first - Chicken[ch].first) + abs(_Home.second - Chicken[ch].second);
				// �Ÿ� ���ؼ� �ּҰ� ���ϱ�(���� ġŲ���� �߿��� �ּ� ġŲ �Ÿ�)
				_Min = min(_Min, _Dist);
			}
			
			// �ּ� ���� ��
			ret += _Min;
		}

		// ��ü�� �ּ� ��
		result = min(result, ret);
	}

	// ���
	cout << result;

	return 0;
}
