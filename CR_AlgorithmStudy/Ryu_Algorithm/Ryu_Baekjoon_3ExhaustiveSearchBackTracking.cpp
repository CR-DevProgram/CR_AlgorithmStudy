#include <bits/stdc++.h>

using namespace std;

// 1_치킨 배달
// https://www.acmicpc.net/problem/15686
// 문제 이해가 너무 안돼서 여기저기 찾아서 최대한 이해를 해봄
// 치킨집의 최대 개수를 M으로 주어짐, M개의 치킨집과 여러 집으로만 생각하면 됨
// 여러 치킨 집 중에서 M개를 고른다? => 문제에서 어떻게 고르면 도시의 치킨 거리가 가장 적게 될지 프로그램을 작성하라고 했으므로 순서와 관계없이 무작위로 M개를 선정하여 가장 거리가 적은 수를 출력하면 됨
// 즉 각 집과 가장 가까운 치킨 집 사이의 거리를 모두 합한 거리를 도시의 치킨 거리로 가장 적은 치킨 거리를 구하면 됨
// ***** 각 집과 가장 가까운 치킨 집 사이의 거리를 모두 합한 거리 ***** => 완전 중요 포인트
// N: 도시 크기, M: 최대 치킨집 개수
int N, M, ret = 100000, City[50][50];
vector<pair<int, int>> Homes, Chickens, ChickenList;

void Combi(int Start)
{
	if (M == ChickenList.size())
	{
		// 치킨 거리 구하기 로직
		int Cal = 0;
		for (pair<int, int> Home : Homes)
		{
			// 거리 최소값을 구하기 위한 최대값 초기화
			int HomeMin = N * N;

			for (pair<int, int> Chicken : ChickenList)
			{
				// 거리 연산
				int Dir = abs(Home.first - Chicken.first) + abs(Home.second - Chicken.second);
				// 집을 기준으로 치킨집과의 최소거리
				HomeMin = min(HomeMin, Dir);
			}
			// 집을 기준으로 최소거리 합연산
			Cal += HomeMin;
		}

		// 최종 최소거리 연산을 위한 min 확인
		ret = min(ret, Cal);

		return;
	}

	// 치킨집 조합
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

			// 집과 치킨집 위치 정보 담기
			if (1 == City[i][j]) Homes.push_back({ i,j });
			if (2 == City[i][j]) Chickens.push_back({ i,j });
		}
	}

	Combi(-1);

	cout << ret;

	return 0;
}