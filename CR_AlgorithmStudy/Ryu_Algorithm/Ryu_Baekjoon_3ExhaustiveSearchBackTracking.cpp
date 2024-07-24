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
//int N, M, ret = 100000, City[50][50];
//vector<pair<int, int>> Homes, Chickens, ChickenList;
//
//void Combi(int Start)
//{
//	if (M == ChickenList.size())
//	{
//		// 치킨 거리 구하기 로직
//		int Cal = 0;
//		for (pair<int, int> Home : Homes)
//		{
//			// 거리 최소값을 구하기 위한 최대값 초기화
//			int HomeMin = N * N;
//
//			for (pair<int, int> Chicken : ChickenList)
//			{
//				// 거리 연산
//				int Dir = abs(Home.first - Chicken.first) + abs(Home.second - Chicken.second);
//				// 집을 기준으로 치킨집과의 최소거리
//				HomeMin = min(HomeMin, Dir);
//			}
//			// 집을 기준으로 최소거리 합연산
//			Cal += HomeMin;
//		}
//
//		// 최종 최소거리 연산을 위한 min 확인
//		ret = min(ret, Cal);
//
//		return;
//	}
//
//	// 치킨집 조합
//	for (int i = Start + 1; i < Chickens.size(); ++i)
//	{
//		ChickenList.push_back(Chickens[i]);
//		Combi(i);
//		ChickenList.pop_back();
//	}
//}
//
//int main()
//{
//	cin >> N >> M;
//
//	for (int i = 0; i < N; ++i)
//	{
//		for (int j = 0; j < N; ++j)
//		{
//			cin >> City[i][j];
//
//			// 집과 치킨집 위치 정보 담기
//			if (1 == City[i][j]) Homes.push_back({ i,j });
//			if (2 == City[i][j]) Chickens.push_back({ i,j });
//		}
//	}
//
//	Combi(-1);
//
//	cout << ret;
//
//	return 0;
//}

// 또 다른 풀이법(Combi완전탐색 및 인덱스 활용)
// 무식하게 풀 수 있는가? -> 로직 -> 시간복잡도 계산 -> 가능하다?(무식 GO), 불가능하다?(다른 알고리즘)
// 치킨집을 선별하고 모든 집과의 거리를 비교해서 집 거리 중 가장 최소값을 더하면 됨
int n, m, a[54][54], result = 987654321;
vector<vector<int>> ChickenList;		// 치킨 위치가 담겨 있는 Chicken의 인덱스를 담아 놓은 리스트
vector<pair<int, int>> Home, Chicken;

void Combi(int Start, vector<int> v)
{
	// 최대 치킨집 개수와 v 사이즈가 같을 때
	if (m == v.size())
	{
		// 로직
		// 조합들 저장
		ChickenList.push_back(v);
		return;
	}

	// 조합
	for (int i = Start + 1; i < Chicken.size(); ++i)
	{
		v.push_back(i);
		Combi(i, v);
		v.pop_back();
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> a[i][j];

			if (1 == a[i][j]) Home.push_back({ i,j });
			if (2 == a[i][j]) Chicken.push_back({ i,j });
		}
	}

	vector<int> v;
	Combi(-1, v);

	// 치킨집 뽑기
	for (vector<int> cList : ChickenList)
	{
		int ret = 0;
		for (pair<int, int> _Home : Home)
		{
			int _Min = 987654321;

			// 치킨 리스트 중에서 집과의 거리
			for (int ch : cList)
			{
				int _Dist = abs(_Home.first - Chicken[ch].first) + abs(_Home.second - Chicken[ch].second);
				// 거리 비교해서 최소값 구하기(집과 치킨집들 중에서 최소 치킨 거리)
				_Min = min(_Min, _Dist);
			}
			
			// 최소 값들 합
			ret += _Min;
		}

		// 전체적 최소 값
		result = min(result, ret);
	}

	// 출력
	cout << result;

	return 0;
}
