#include <bits/stdc++.h>

using namespace std;

// 1_�ϰ� ������
// https://www.acmicpc.net/problem/2309
//// 9�� �� 7���� ���� 100
//// ������ ������� ���Ͽ� 100�̹Ƿ� ����
//vector<int> vecN(9);
//int Sum;
//
//void Combi(int start, vector<int> vec)
//{
//	if (7 == vec.size() && 100 == Sum)
//	{
//		sort(vec.begin(), vec.end());
//		for (int i : vec) cout << i << "\n";
//
//		// return�� ���� �� ������ ������ ���������� ��� ��� ȣ��Ǳ� ������ �������� ó����
//		// ���� �ش� ��͸� �ƿ� Ż���� �� �ְ� exit(0)���� ����� ��
//		exit(0);
//	}
//
//	for (int i = start + 1; i < vecN.size(); ++i)
//	{
//		vec.push_back(vecN[i]);
//		Sum += vecN[i];
//		Combi(i, vec);
//		vec.pop_back();
//		Sum -= vecN[i];
//	}
//
//	return;
//}
//
//int main()
//{
//	for (int i = 0; i < vecN.size(); ++i)
//	{
//		cin >> vecN[i];
//	}
//
//	vector<int> m_vector;
//
//	Combi(-1, m_vector);
//
//	return 0;
//}

// �� �ٸ� Ǯ�̹�(����)
// 9�� �� 7�� �̴´�, ������ ����� ���� 9C7
// �׷��� �� ������ 9P7�ε� ���� �� �ִ� Permutation�� ������ ��������� n(== 9)�� �� ��ü�� �۱� ������ ����
// 9P7 => 9! / 2! => 9 * 8 * 7 * 6 * 5 * 4 * 3 => 181440
int arr[9];

int main()
{
	// ��ȩ �������� Ű �Է� �ޱ�
	for (int i = 0; i < 9; ++i)
	{
		cin >> arr[i];
	}

	// ������ �� ���� �׻� ����. ������������ ����� ��
	sort(arr, arr + 9);

	do
	{
		// ����� �ڵ�
		for (int i : arr) cout << i << " ";
		cout << "\n";

		// ����
		// Sum�� 0���� ��� �ʱ�ȭ
		int Sum = 0;
		// �ϰ� �������� ��
		for (int i = 0; i < 7; ++i) Sum += arr[i];
		// ���� 100�� �� ����
		if (100 == Sum) break;
	} while (next_permutation(arr, arr + 9));

	for (int i = 0; i < 7; ++i) cout << arr[i] << "\n";

	return 0;
}