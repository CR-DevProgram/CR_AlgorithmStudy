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
//int arr[9];
//
//int main()
//{
//	// 아홉 난쟁이의 키 입력 받기
//	for (int i = 0; i < 9; ++i)
//	{
//		cin >> arr[i];
//	}
//
//	// 순열을 할 때는 항상 정렬. 오름차순으로 해줘야 함
//	sort(arr, arr + 9);
//
//	do
//	{
//		// 디버깅 코드
//		for (int i : arr) cout << i << " ";
//		cout << "\n";
//
//		// 로직
//		// Sum을 0으로 계속 초기화
//		int Sum = 0;
//		// 일곱 난쟁이의 합
//		for (int i = 0; i < 7; ++i) Sum += arr[i];
//		// 합이 100일 때 멈춤
//		if (100 == Sum) break;
//	} while (next_permutation(arr, arr + 9));
//
//	for (int i = 0; i < 7; ++i) cout << arr[i] << "\n";
//
//	return 0;
//}

// 또 다른 풀이법(조합)
// 9C7은 9C2와 같다
// 정상적인 일곱 난쟁이를 뽑는 것과 비정상적인 두 난쟁이를 뽑아내는 것은 결국 같은 로직이나 다름없다
// 100 + A + B가 아홉 난쟁이의 합일 것. 그 중 A와 B를 찾아낸다는 것은 100 == 전체 - (A + B)

// 2개 뽑이라 pair 사용
//pair<int, int> ret;
//vector<int> vec;
//int arr[9];
//int Sum;
//
//void Solve()
//{
//	// 9C2이니까 중첩for문은 2번만
//	for (int i = 0; i < 9; ++i)
//	{
//		for (int j = 0; j < i; ++j)
//		{
//			// 로직
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
//		// 입력 받기
//		cin >> arr[i];
//		// 전체 합 구하기
//		Sum += arr[i];
//	}
//	
//	Solve();
//
//	for (int i = 0; i < 9; ++i)
//	{
//		// 가짜 난쟁이 둘 중 하나에 해당 할 경우 건너 뛴다 == continue
//		if (ret.first == i || ret.second == i) continue;
//		// 진짜 난쟁이 일곱만 벡터에 넣어줌
//		vec.push_back(arr[i]);
//	}
//
//	// 오름차순 출력을 위한 정렬
//	sort(vec.begin(), vec.end());
//	for (int i : vec) cout << i << "\n";
//
//	return 0;
//}

// 또 다른 풀이법(재귀순열)
//int arr[9];
//int n = 9, r = 7;
//
//void Solve()
//{
//	// 합산 0으로 초기화 작업
//	int Sum = 0;;
//
//	// 합산 작업
//	for (int i = 0; i < r; ++i) Sum += arr[i];
//	// 합산이 100일 경우
//	if (100 == Sum)
//	{
//		// 오름차순
//		sort(arr, arr + 7);
//		for (int i = 0; i < r; ++i) cout << arr[i] << "\n";
//		// main 함수 자체가 종료
//		// retunr을 하게 되면 해당 함수만 종료
//		exit(0);
//	}
//}
//
//void MakePermutation(int n, int r, int depth)
//{
//	// 7개 뽑기
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
//	// 입력 받기
//	for (int i = 0; i < 9; ++i)
//	{
//		cin >> arr[i];
//	}
//
//	MakePermutation(n, r, 0);
//
//	return 0;
//}

// 2_알파벳 개수
// https://www.acmicpc.net/problem/10808
// 입력으로 들어오는 문자열에서 각 알파벳 단어가 몇 개인지 a~z까지 표현하는 것으로 개별 카운팅
int AlphabetArr[26];

int main()
{
	string m_str = "";
	cin >> m_str;

	for (int i = 0; i < m_str.size(); ++i)
	{
		// 아스키코드 생각하여 인덱스 별로 동일 알파벳 수 누적
		++AlphabetArr[m_str[i] - 97];
	}

	for (int i = 0; i < 26; ++i)
	{
		cout << AlphabetArr[i] << " ";
	}

	cout << "\n";

	return 0;
}