#include <bits/stdc++.h>

using namespace std;

// 1_�ϰ� ������
// https://www.acmicpc.net/problem/2309
// 9�� �� 7���� ���� 100
// ������ ������� ���Ͽ� 100�̹Ƿ� ����
vector<int> vecN(9);
int Sum;

void Combi(int start, vector<int> vec)
{
	if (7 == vec.size() && 100 == Sum)
	{
		sort(vec.begin(), vec.end());
		for (int i : vec) cout << i << "\n";

		// return�� ���� �� ������ ������ ���������� ��� ��� ȣ��Ǳ� ������ �������� ó����
		// ���� �ش� ��͸� �ƿ� Ż���� �� �ְ� exit(0)���� ����� ��
		exit(0);
	}

	for (int i = start + 1; i < vecN.size(); ++i)
	{
		vec.push_back(vecN[i]);
		Sum += vecN[i];
		Combi(i, vec);
		vec.pop_back();
		Sum -= vecN[i];
	}

	return;
}

int main()
{
	for (int i = 0; i < vecN.size(); ++i)
	{
		cin >> vecN[i];
	}

	vector<int> m_vector;

	Combi(-1, m_vector);

	return 0;
}
