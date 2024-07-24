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
int N, M, ret = 100000, City[50][50];
vector<pair<int, int>> Homes, Chickens, ChickenList;

void Combi(int Start)
{
	if (M == ChickenList.size())
	{
		// ġŲ �Ÿ� ���ϱ� ����
		int Cal = 0;
		for (pair<int, int> Home : Homes)
		{
			// �Ÿ� �ּҰ��� ���ϱ� ���� �ִ밪 �ʱ�ȭ
			int HomeMin = N * N;

			for (pair<int, int> Chicken : ChickenList)
			{
				// �Ÿ� ����
				int Dir = abs(Home.first - Chicken.first) + abs(Home.second - Chicken.second);
				// ���� �������� ġŲ������ �ּҰŸ�
				HomeMin = min(HomeMin, Dir);
			}
			// ���� �������� �ּҰŸ� �տ���
			Cal += HomeMin;
		}

		// ���� �ּҰŸ� ������ ���� min Ȯ��
		ret = min(ret, Cal);

		return;
	}

	// ġŲ�� ����
	for (int i = Start + 1; i < Chickens.size(); ++i)
	{
		ChickenList.push_back(Chickens[i]);
		Combi(i);
		ChickenList.pop_back();
	}
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> City[i][j];

			// ���� ġŲ�� ��ġ ���� ���
			if (1 == City[i][j]) Homes.push_back({ i,j });
			if (2 == City[i][j]) Chickens.push_back({ i,j });
		}
	}

	Combi(-1);

	cout << ret;

	return 0;
}