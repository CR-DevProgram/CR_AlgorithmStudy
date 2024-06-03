#include <bits/stdc++.h>

using namespace std;

// 1_�̷� Ž��
// https://www.acmicpc.net/problem/2178
// 1�� �̵� ���� 0�� �̵� �Ұ�
// (1, 1)���� ��� (n, m)�� �̵��� �� �ּ� �̵� ĭ ��
// ������ ĭ�� �̵� ����
int n, m, minvalue, ret = 1;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
int maze[100][100];
/*bool*/int visited[100][100];

// DFS �������� �� ��� TC�� ����Ѵ� �ϴ��� ����� �ð��ʰ� �߻�
// ������ ������ �ּ� ĭ�� �� ��, �ִܰŸ��� ���ϴ� �����̹Ƿ� BFS�� Ǯ��� ��
//void move(int y, int x)
//{
//	if (n == y + 1 && m == x + 1)
//	{
//		minvalue = min(minvalue, ret);
//		return;
//	}
//
//	for (int i = 0; i < 4; ++i)
//	{
//		int ny = y + dy[i];
//		int nx = x + dx[i];
//
//		if (0 > ny || 0 > nx || n <= ny || m <= nx) continue;
//		if (1 == maze[ny][nx] && 0 == visited[ny][nx])
//		{
//			++ret;
//			visited[ny][nx] = 1;
//			move(ny, nx);
//			visited[ny][nx] = 0;
//			--ret;
//		}
//	}
//}
//
//int main()
//{
//	cin >> n >> m;
//
//	minvalue = n * m;
//
//	for (int i = 0; i < n; ++i)
//	{
//		string mazeinfo = "";
//		cin >> mazeinfo;
//
//		for (int j = 0; j < m; ++j)
//		{
//			maze[i][j] = mazeinfo[j] - '0';
//		}
//	}
//
//	visited[0][0] = 1;
//	move(0, 0);
//
//	cout << minvalue << "\n";
//
//	return 0;
//}

// BFS Ǯ��
int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		string mazeinfo = "";
		cin >> mazeinfo;

		// �̷� �����
		for (int j = 0; j < m; ++j) maze[i][j] = mazeinfo[j] - '0';
	}

	// BFS���� ����� queue
	queue<pair<int, int>> qmakepair;
	// �������� �湮 ���
	visited[0][0] = 1;
	qmakepair.push({ 0,0 });

	while (true)
	{
		// queue�� ��� ���� ������ �ݺ�
		if (true == qmakepair.empty()) break;

		// �湮 Ž�� ���� �� ����
		int x = qmakepair.front().second;
		int y = qmakepair.front().first;
		qmakepair.pop();

		for (int i = 0; i < 4; ++i)
		{
			// �������� �̵��� ��ġ
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (0 > ny || 0 > nx || n <= ny || m <= nx) continue;
			// �̷� �̵��� �����ϰ� �湮�� ���� ���� ����
			if (1 == maze[ny][nx] && 0 == visited[ny][nx])
			{
				// �ִܰŸ��� ���ϱ� ���� visited ����(����ġ�� ����)
				visited[ny][nx] = visited[y][x] + 1;
				qmakepair.push({ ny,nx });
			}
		}
	}
	
	// ���� ������ visited ���� �ִ� �Ÿ� ��
	cout << visited[n - 1][m - 1] << "\n";

	return 0;
}
