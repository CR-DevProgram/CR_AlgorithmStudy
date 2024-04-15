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
//int arr[9];
//
//int main()
//{
//	// ��ȩ �������� Ű �Է� �ޱ�
//	for (int i = 0; i < 9; ++i)
//	{
//		cin >> arr[i];
//	}
//
//	// ������ �� ���� �׻� ����. ������������ ����� ��
//	sort(arr, arr + 9);
//
//	do
//	{
//		// ����� �ڵ�
//		for (int i : arr) cout << i << " ";
//		cout << "\n";
//
//		// ����
//		// Sum�� 0���� ��� �ʱ�ȭ
//		int Sum = 0;
//		// �ϰ� �������� ��
//		for (int i = 0; i < 7; ++i) Sum += arr[i];
//		// ���� 100�� �� ����
//		if (100 == Sum) break;
//	} while (next_permutation(arr, arr + 9));
//
//	for (int i = 0; i < 7; ++i) cout << arr[i] << "\n";
//
//	return 0;
//}

// �� �ٸ� Ǯ�̹�(����)
// 9C7�� 9C2�� ����
// �������� �ϰ� �����̸� �̴� �Ͱ� ���������� �� �����̸� �̾Ƴ��� ���� �ᱹ ���� �����̳� �ٸ�����
// 100 + A + B�� ��ȩ �������� ���� ��. �� �� A�� B�� ã�Ƴ��ٴ� ���� 100 == ��ü - (A + B)

// 2�� ���̶� pair ���
//pair<int, int> ret;
//vector<int> vec;
//int arr[9];
//int Sum;
//
//void Solve()
//{
//	// 9C2�̴ϱ� ��øfor���� 2����
//	for (int i = 0; i < 9; ++i)
//	{
//		for (int j = 0; j < i; ++j)
//		{
//			// ����
//			if (100 == Sum - (arr[i] + arr[j]))
//			{
//				ret = { i, j };
//				return;
//			}
//		}
//	}
//}
//
//int main()
//{
//	for (int i = 0; i < 9; ++i)
//	{
//		// �Է� �ޱ�
//		cin >> arr[i];
//		// ��ü �� ���ϱ�
//		Sum += arr[i];
//	}
//	
//	Solve();
//
//	for (int i = 0; i < 9; ++i)
//	{
//		// ��¥ ������ �� �� �ϳ��� �ش� �� ��� �ǳ� �ڴ� == continue
//		if (ret.first == i || ret.second == i) continue;
//		// ��¥ ������ �ϰ��� ���Ϳ� �־���
//		vec.push_back(arr[i]);
//	}
//
//	// �������� ����� ���� ����
//	sort(vec.begin(), vec.end());
//	for (int i : vec) cout << i << "\n";
//
//	return 0;
//}

// �� �ٸ� Ǯ�̹�(��ͼ���)
//int arr[9];
//int n = 9, r = 7;
//
//void Solve()
//{
//	// �ջ� 0���� �ʱ�ȭ �۾�
//	int Sum = 0;;
//
//	// �ջ� �۾�
//	for (int i = 0; i < r; ++i) Sum += arr[i];
//	// �ջ��� 100�� ���
//	if (100 == Sum)
//	{
//		// ��������
//		sort(arr, arr + 7);
//		for (int i = 0; i < r; ++i) cout << arr[i] << "\n";
//		// main �Լ� ��ü�� ����
//		// retunr�� �ϰ� �Ǹ� �ش� �Լ��� ����
//		exit(0);
//	}
//}
//
//void MakePermutation(int n, int r, int depth)
//{
//	// 7�� �̱�
//	if (r == depth)
//	{
//		Solve();
//
//		return;
//	}
//
//	for (int i = depth; i < n; ++i)
//	{
//		swap(arr[i], arr[depth]);
//		MakePermutation(n, r, depth + 1);
//		swap(arr[i], arr[depth]);
//	}
//
//	return;
//}
//
//int main()
//{
//	// �Է� �ޱ�
//	for (int i = 0; i < 9; ++i)
//	{
//		cin >> arr[i];
//	}
//
//	MakePermutation(n, r, 0);
//
//	return 0;
//}

// 2_���ĺ� ����
// https://www.acmicpc.net/problem/10808
// �Է����� ������ ���ڿ����� �� ���ĺ� �ܾ �� ������ a~z���� ǥ���ϴ� ������ ���� ī����
//int AlphabetArr[26];
//
//int main()
//{
//	string m_str = "";
//	cin >> m_str;
//
//	for (int i = 0; i < m_str.size(); ++i)
//	{
//		// �ƽ�Ű�ڵ� �����Ͽ� �ε��� ���� ���� ���ĺ� �� ����
//		++AlphabetArr[m_str[i] - 97];
//	}
//
//	for (int i = 0; i < 26; ++i)
//	{
//		cout << AlphabetArr[i] << " ";
//	}
//
//	cout << "\n";
//
//	return 0;
//}

// �� �ٸ� Ǯ�̹�(Counting Star - map, array)
// map�� key-value => char(key)-int(value)
// map�� ���� string�� ������� ���� �� ���
// array�� ��Ƽ���� �迭 �ε����� �����Ͽ� ���������ڷ� ī����
// array�� ���� int�� ������� ���� �� ���. ��, 10�� 100�� 1000���� ū ���� ���� ��쿡�� map�� ��õ
// �ٸ� �ش� ������ ���ڸ� ī�����ϴ� ��. ���� �迭�� ���� ���� ��������..?
// �ƽ�Ű�ڵ� - A(65), a(97) / �ƽ�Ű�ڵ�� ���ڰ� ���ڷ� ���εǾ� �ִ� ��
// cnt['a'] == cnt[97]

// * ���������� ����ϰ� �Ǹ� 0���� �ʱ�ȭ �۾��� �� => �����Ͽ��� ����ȭ�� ��Ű�� ����
// * ���������� ���Ե� ��� �׻� ������ ���� ���� ������ �ڵ� �׽�Ʈ�� �Ѵ� ���� �� �������� ����� ���� 
//int cnt[26];
//string str;
//
//int main()
//{
//	cin >> str;
//
//	for (char a : str)
//	{
//		// ��ǥ�̵��� �̿��� �迭�� a(97)��ŭ�� ����Ŵϱ� ������ ���ĺ� - a
//		++cnt[a - 'a'];
//	}
//
//	for (int i : cnt) cout << i << " ";
//
//	return 0;
//}

// 3_Ʈ�� ����
// https://www.acmicpc.net/problem/2979
// �ð��� �迭�� ��� ī�����ϰ� ����
// �ð��� 1�� 100 �����̹Ƿ� array[100]
//int TimeCnt[100];
//int A, B, C, Sum;
//
//int main()
//{
//	// ���� ���� ���� ��� �Է� �ޱ�
//	cin >> A >> B >> C;
//
//	// 3���� ���� ���� �ð�
//	for (int i = 0; i < 3; ++i)
//	{
//		int In, Out = 0;
//		cin >> In >> Out;
//
//		// �ð��� �� ���� �� ī����
//		for (int j = In; j < Out; ++j)
//		{
//			++TimeCnt[j];
//		}
//	}
//
//	// �ð��� ���� ���� ���� ��� ���� ����
//	for (int i : TimeCnt)
//	{
//		if (1 == i) Sum += i * A;
//		else if (2 == i) Sum += i * B;
//		else if (3 == i) Sum += i * C;
//	}
//
//	cout << Sum << "\n";
//
//	return 0;
//}

// �� �ٸ� Ǯ�̹�(Counting)
// �ð��� �̻� �̸��̴�
// Ǯ�̴� �� Ǯ�̶� ����
//int A, B, C, a, b, cnt[104], ret;
//
//int main()
//{
//	cin >> A >> B >> C;
//
//	for (int i = 0; i < 3; ++i)
//	{
//		cin >> a >> b;
//
//		// �ð��� �̻� �̸��� ǥ��. a�� ���ԵǾ� �ְ� b�� ���ԵǾ����� ����
//		for (int j = a; j < b; ++j) ++cnt[j];
//	}
//
//	// ������ �ִ� ������ 100�̱� ������ 100������ Ȯ��
//	for (int j = 1; j < 100; ++j)
//	{
//		// Ʈ���� �ִٸ�
//		if (0 != cnt[j])
//		{
//			if (1 == cnt[j]) ret += A;
//			// ������ �δ�ϱ� ���ϱ� 2(�Ѵ�� ����� B)
//			else if (2 == cnt[j]) ret += B * 2;
//			// ������ ����ϱ� ���ϱ� 3(�Ѵ�� ����� C)
//			else if (3 == cnt[j]) ret += C * 3;
//		}
//	}
//
//	cout << ret << "\n";
//
//	return 0;
//}

// 4_�Ӹ�������� Ȯ���ϱ�
// https://www.acmicpc.net/problem/10988
// �Ӹ�����̶� �յڷ� ���� �� ������ �ܾ�
// ����� ���� ���ڶ� ������ Ȯ���ϸ� ���� ������? 
//string str, revstr;
//bool ret;
//
//int main()
//{
//	cin >> str;
//
//	// ���ڿ� ����
//	revstr = str;
//	// ������ ���ڿ� ������
//	reverse(revstr.begin(), revstr.end());
//
//	// compare �Լ��� �̿��Ͽ� ���� ���ڿ� ������ ���ڰ� ���ٴ� 0�� ��� true 0�� �ƴ� ��� false
//	ret = 0 == str.compare(revstr) ? true : false;
//
//	cout << ret << "\n";
//
//	return 0;
//}

// �� �ٸ� Ǯ�̹�(reverse)
// �Ӹ������ ȸ��, ��� ���ڿ��� ȸ�������� Ȯ���ϴ� ������ �����ϸ� ��
// Ǯ�̴� �� Ǯ�̿� ����
string s, temp;

int main()
{
	cin >> s;

	temp = s;
	reverse(temp.begin(), temp.end());

	if (temp == s) cout << 1 << "\n";
	else cout << 0 << "\n";

	return 0;
}