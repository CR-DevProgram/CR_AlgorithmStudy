#include <bits/stdc++.h>

using namespace std;

// 1_일곱 난쟁이
// https://www.acmicpc.net/problem/2309
// 9명 중 7명의 합이 100
// 순서와 상관없이 합하여 100이므로 조합
vector<int> vecN(9);
int Sum;

void Combi(int start, vector<int> vec)
{
	if (7 == vec.size() && 100 == Sum)
	{
		sort(vec.begin(), vec.end());
		for (int i : vec) cout << i << "\n";

		// return을 했을 때 가능한 정답이 여러가지인 경우 모두 호출되기 때문에 오답으로 처리됨
		// 따라서 해당 재귀를 아예 탈출할 수 있게 exit(0)으로 해줘야 함
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
