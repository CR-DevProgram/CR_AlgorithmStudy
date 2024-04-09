#include <bits/stdc++.h>

using namespace std;

// 1_일곱 난쟁이
// https://www.acmicpc.net/problem/2309
//// 9명 중 7명의 합이 100
//// 순서와 상관없이 합하여 100이므로 조합
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
//		// return을 했을 때 가능한 정답이 여러가지인 경우 모두 호출되기 때문에 오답으로 처리됨
//		// 따라서 해당 재귀를 아예 탈출할 수 있게 exit(0)으로 해줘야 함
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

// 또 다른 풀이법(순열)
// 9개 중 7개 뽑는다, 순서와 상관이 없다 9C7
// 그런데 이 문제는 9P7로도 뽑을 수 있다 Permutation은 순서와 상관있지만 n(== 9)의 수 자체가 작기 때문에 가능
// 9P7 => 9! / 2! => 9 * 8 * 7 * 6 * 5 * 4 * 3 => 181440
int arr[9];

int main()
{
	// 아홉 난쟁이의 키 입력 받기
	for (int i = 0; i < 9; ++i)
	{
		cin >> arr[i];
	}

	// 순열을 할 때는 항상 정렬. 오름차순으로 해줘야 함
	sort(arr, arr + 9);

	do
	{
		// 디버깅 코드
		for (int i : arr) cout << i << " ";
		cout << "\n";

		// 로직
		// Sum을 0으로 계속 초기화
		int Sum = 0;
		// 일곱 난쟁이의 합
		for (int i = 0; i < 7; ++i) Sum += arr[i];
		// 합이 100일 때 멈춤
		if (100 == Sum) break;
	} while (next_permutation(arr, arr + 9));

	for (int i = 0; i < 7; ++i) cout << arr[i] << "\n";

	return 0;
}