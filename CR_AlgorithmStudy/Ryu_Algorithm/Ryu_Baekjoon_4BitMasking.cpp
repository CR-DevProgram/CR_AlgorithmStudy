#include <bits/stdc++.h>

using namespace std;

// 1_다이어트
// https://www.acmicpc.net/problem/19942
// 식재료 조합을 통해 영양 성분과 최소금액 맞추기
// 비트마스킹을 활용하여 특정 인덱스번째의 합산과 최소값 비교
// 조건에 해당되는 경우가 없다면 -1만 출력
// n: 식재료 개수
const int VAL = 987654321;
int n, mp, mf, ms, mv;
int cump, cumf, cums, cumv, ret = VAL, cumc;
map<int, vector<vector<int>>> ret_v;		// 비용별 조합 자료구조 => 비용이 700(int)인 경우의 조합(vector<int>) 모음(vector<조합>)

struct Table
{
	int mp, mf, ms, mv, cost;
};
Table table[16];

int main() 
{
	cin >> n;
	cin >> mp >> mf >> ms >> mv;
	for (int i = 0; i < n; ++i) 
	{
		cin >> table[i].mp >> table[i].mf >> table[i].ms >> table[i].mv >> table[i].cost;
	}

	// 모든 경우의 수 따지기
	for (int i = 0; i < (1 << n); ++i) 
	{
		// 초기화 작업
		cump = cumf = cums = cumv = cumc = 0;
		vector<int> v;

		for (int j = 0; j < n; ++j) 
		{
			// 조합 확인
			if (i & (1 << j)) 
			{
				// 조합 추가
				v.push_back(j + 1);

				cump += table[j].mp;
				cumf += table[j].mf;
				cums += table[j].ms;
				cumv += table[j].mv;
				cumc += table[j].cost;
			}
		}

		// 모든 최소 영양성분 수치 이상일 경우
		if (mp <= cump && mf <= cumf && ms <= cums && mv <= cumv)
		{
			// 최소비용 갱신 및 조합 추가 작업
			if (ret >= cumc)
			{
				ret = cumc;
				ret_v[ret].push_back(v);
			}
		}
	}

	if (VAL != ret)
	{
		// 최소 비용 출력
		cout << ret << "\n";
		// 오름차순 정렬
		sort(ret_v[ret].begin(), ret_v[ret].end());
		// 비용별 조합 목록 출력
		for (int i : ret_v[ret][0]) cout << i << " ";
	}
	else cout << -1 << '\n';

	return 0;
}