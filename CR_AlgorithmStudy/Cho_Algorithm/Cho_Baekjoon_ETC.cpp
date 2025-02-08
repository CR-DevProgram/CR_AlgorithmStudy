// N과 M (12)
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<int> num;
set<vector<int>> answer;
int N, M;

void dfs(vector<int>& curNum, int c, int s)
{
	if (c == M)
	{
		answer.insert(curNum);
		return;
	}

	for (int i = s; i < N; i++)
	{
		curNum.push_back(num[i]);
		dfs(curNum, c + 1, i);
		curNum.pop_back();
	}
}


int main()
{
	cin >> N >> M;
	num.resize(N);

	for (int i = 0; i < N; i++)
		cin >> num[i];

	sort(num.begin(), num.end());

	vector<int> curNum;
	dfs(curNum, 0, 0);

	for (auto i : answer)
	{
		for (auto j : i)
			cout << j << ' ';
		cout << '\n';
	}
}

// 행성 탐사
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	// (1) 행성을 만든다.
	int n, m, cnt;
	cin >> n >> m >> cnt;

	vector<vector<char>> v(n + 1, vector<char>(m + 1));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			cin >> v[i][j];
	}
	
	// (2) cnt 만큼 돌면서 각 위치별로 정글(J), 바다(O), 얼음(I)의 수를 구해 출력한다.
	vector<vector<vector<int>>> answer(n + 1, vector<vector<int>>(m + 1, vector<int>(3, 0)));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			int isJungle = v[i][j] == 'J' ? 1 : 0;
			int isOcean = v[i][j] == 'O' ? 1 : 0;
			int isIce = v[i][j] == 'I' ? 1 : 0;

			answer[i][j][0] = isJungle + answer[i - 1][j][0] + answer[i][j - 1][0] - answer[i - 1][j - 1][0];
			answer[i][j][1] = isOcean + answer[i - 1][j][1] + answer[i][j - 1][1] - answer[i - 1][j - 1][1];
			answer[i][j][2] = isIce + answer[i - 1][j][2] + answer[i][j - 1][2] - answer[i - 1][j - 1][2];
		}
	}
	
	for (auto i : answer)
	{
		for (auto j : i)
		{
			for (auto k : j)
				cout << k << ' ';
			cout << '|';
		}
		cout << '\n';
	}
	
	for (int i = 0; i < cnt; i++)
	{
		int fx, fy, tx, ty;
		cin >> fx >> fy >> tx >> ty;

		int jCnt = answer[tx][ty][0] - answer[fx - 1][ty][0] - answer[tx][fy - 1][0] + answer[fx - 1][fy - 1][0];
		int oCnt = answer[tx][ty][1] - answer[fx - 1][ty][1] - answer[tx][fy - 1][1] + answer[fx - 1][fy - 1][1];
		int iCnt = answer[tx][ty][2] - answer[fx - 1][ty][2] - answer[tx][fy - 1][2] + answer[fx - 1][fy - 1][2];

		cout << jCnt << ' ' << oCnt << ' ' << iCnt << '\n';
	}
}