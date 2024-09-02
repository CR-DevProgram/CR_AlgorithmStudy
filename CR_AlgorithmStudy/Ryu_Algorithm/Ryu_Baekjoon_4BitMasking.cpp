#include <bits/stdc++.h>

using namespace std;

// 1_다이어트
// https://www.acmicpc.net/problem/19942
// 식재료 조합을 통해 영양 성분과 최소금액 맞추기
// 비트마스킹을 활용하여 특정 인덱스번째의 합산과 최소값 비교
// 조건에 해당되는 경우가 없다면 -1만 출력
// n: 식재료 개수
//const int VAL = 987654321;
//int n, mp, mf, ms, mv;
//int cump, cumf, cums, cumv, ret = VAL, cumc;
//map<int, vector<vector<int>>> ret_v;		// 비용별 조합 자료구조 => 비용이 700(int)인 경우의 조합(vector<int>) 모음(vector<조합>)
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
//	// 모든 경우의 수 따지기
//	for (int i = 0; i < (1 << n); ++i) 
//	{
//		// 초기화 작업
//		cump = cumf = cums = cumv = cumc = 0;
//		vector<int> v;
//
//		for (int j = 0; j < n; ++j) 
//		{
//			// 조합 확인
//			if (i & (1 << j)) 
//			{
//				// 조합 추가
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
//		// 모든 최소 영양성분 수치 이상일 경우
//		if (mp <= cump && mf <= cumf && ms <= cums && mv <= cumv)
//		{
//			// 최소비용 갱신 및 조합 추가 작업
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
//		// 최소 비용 출력
//		cout << ret << "\n";
//		// 오름차순 정렬
//		sort(ret_v[ret].begin(), ret_v[ret].end());
//		// 비용별 조합 목록 출력
//		for (int i : ret_v[ret][0]) cout << i << " ";
//	}
//	else cout << -1 << '\n';
//
//	return 0;
//}

// 2_동전 뒤집기
// https://www.acmicpc.net/problem/1285
// 동전 뒤집기로 뒷면(T)를 최소로 하는 수
// 행과 열을 뒤집는 수를 모든 경우의 수를 생각하면 20(n의 최대) * 2 = 40
// 2의 40승 시간복잡도를 생각하면 불가능, 다른 방법으로 풀어야 함
// 최적해를 생각, T와 H의 수를 고려해서 뒤집을지 뒤집지 않을지 결정
// 행을 뒤집으면 열을 뒤집는다는 것은 최적해가 이미 정해진 것(반대로도 마찬가지)
// 따라서 2의 40승이 아닌 20승으로 행만 뒤집고 각 열을 확인하며 뒤집을지 여부 판단
// 어려와요,,,ㅠ 몰루게따ㅋㅎ
int n, coinTable[21], ret = 987654321;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

void go(int here) 
{
	// 기저사례(행만 뒤집고 열은 판단해서 뒤집기)
	if (here == n + 1) 
	{
		int sum = 0;
		// 1, 2, 4, 8,.. 확인
		for (int i = 1; i <= (1 << (n - 1)); i *= 2) 
		{
			int cnt = 0;
			// 특정 행들의 부분 요소를 확인하기 때문에 ~n = -(n + 1)으로 비트마스킹의 앞부분 고려 X
			for (int j = 1; j <= n; ++j)
			{
				// coinTable[j]: 행
				// 즉 하나의 행 부분 요소 확인
				if (coinTable[j] & i) ++cnt;
			}

			// 최소 및 윗면 합 연산
			sum += min(cnt, n - cnt);
		}

		ret = min(ret, sum);
		return;
	}

	// 뒤집기 X
	go(here + 1);

	// 뒤집기
	coinTable[here] = ~coinTable[here];
	// 뒤집기 O
	go(here + 1);
}

int main() 
{
	cin >> n;
	for (int i = 1; i <= n; ++i) 
	{
		string coinInfo;
		cin >> coinInfo;

		int value = 1;
		for (int j = 0; j < n; ++j) 
		{
			// 각 행(문자열)을 숫자로 표현(HHT -> 4, TTT -> 7, HHH -> 0)
			if ('T' == coinInfo[j]) coinTable[i] |= value;

			value *= 2;
		}
	}

	go(1);
	
	cout << ret;
	
	return 0;
}