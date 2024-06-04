#include <bits/stdc++.h>

using namespace std;

// 1_�̷� Ž��
// https://www.acmicpc.net/problem/2178
// 1�� �̵� ���� 0�� �̵� �Ұ�
// (1, 1)���� ��� (n, m)�� �̵��� �� �ּ� �̵� ĭ ��
// ������ ĭ�� �̵� ����
//int n, m, minvalue, ret = 1;
//int dy[] = { -1, 0, 1, 0 };
//int dx[] = { 0, 1, 0, -1 };
//int maze[100][100];
///*bool*/int visited[100][100];

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
//int main()
//{
//	cin >> n >> m;
//
//	for (int i = 0; i < n; ++i)
//	{
//		string mazeinfo = "";
//		cin >> mazeinfo;
//
//		// �̷� �����
//		for (int j = 0; j < m; ++j) maze[i][j] = mazeinfo[j] - '0';
//	}
//
//	// BFS���� ����� queue
//	queue<pair<int, int>> qmakepair;
//	// �������� �湮 ���
//	visited[0][0] = 1;
//	qmakepair.push({ 0,0 });
//
//	while (true)
//	{
//		// queue�� ��� ���� ������ �ݺ�
//		if (true == qmakepair.empty()) break;
//
//		// �湮 Ž�� ���� �� ����
//		int x = qmakepair.front().second;
//		int y = qmakepair.front().first;
//		qmakepair.pop();
//
//		for (int i = 0; i < 4; ++i)
//		{
//			// �������� �̵��� ��ġ
//			int ny = y + dy[i];
//			int nx = x + dx[i];
//
//			if (0 > ny || 0 > nx || n <= ny || m <= nx) continue;
//			// �̷� �̵��� �����ϰ� �湮�� ���� ���� ����
//			if (1 == maze[ny][nx] && 0 == visited[ny][nx])
//			{
//				// �ִܰŸ��� ���ϱ� ���� visited ����(����ġ�� ����)
//				visited[ny][nx] = visited[y][x] + 1;
//				qmakepair.push({ ny,nx });
//			}
//		}
//	}
//	
//	// ���� ������ visited ���� �ִ� �Ÿ� ��
//	cout << visited[n - 1][m - 1] << "\n";
//
//	return 0;
//}

// �� �ٸ� Ǯ�̹�(?)
// �� Ǯ�̿� ����?
// �ش� ������ ������ BFS��� ���� ���;� �Ѵ�
// ����ġ�� 1�� �����ϰ� ����Ǿ� �ִ� ������ BFS
//const int max_n = 104;
//int dy[4] = { -1, 0, 1, 0 };
//int dx[4] = { 0, 1, 0, -1 };
//int n, m, a[max_n][max_n], visited[max_n][max_n], y, x;
//
//int main()
//{
//    // ���������� �پ� �ִ� ��� 1)string���� ��ȯ 2)scanf�� �ޱ�
//    scanf("%d %d", &n, &m);
//    for (int i = 0; i < n; ++i) 
//    {
//        for (int j = 0; j < m; ++j) 
//        {
//            // 1d�� ���� ��!
//            scanf("%1d", &a[i][j]);
//        }
//    }
//
//    queue<pair<int, int>> q;
//    visited[0][0] = 1;
//    q.push({ 0, 0 });
//
//    while (0 != q.size()) 
//    {
//        tie(y, x) = q.front(); 
//        q.pop();
//
//        for (int i = 0; i < 4; ++i) 
//        {
//            int ny = y + dy[i];
//            int nx = x + dx[i];
//
//            // ������ ���� üũ�ϰ� �迭 üũ�� ��
//            if (0 > ny || 0 > nx || n <= ny || m <= nx) continue;
//            if (0 == a[ny][nx] || 1 == visited[ny][nx]) continue;
//
//            visited[ny][nx] = visited[y][x] + 1;
//            q.push({ ny, nx });
//        }
//    }
//
//    printf("%d", visited[n - 1][m - 1]);
//    
//	return 0;
//}

// 2_����� ����
// https://www.acmicpc.net/problem/1012
// 1: ���߰� �ɾ��� �� 0: ���߰� �ɾ����� ���� ��
// ���߿� �����̷� ���� ��ġ���� �Ѹ����� �־ ������ ���߷� ����
// Ŀ��Ƽ�� ������Ʈ ���
// Ʋ�Ƚ��ϴ� ��� �κ�: �ʱ�ȭ �۾�
// T: ���� ����, M: ���߹� ���α���, N: ���߹� ���α���, K: ���� �ɾ��� ����, XY: ���� ��ġ
//int dy[] = { -1, 0, 1, 0 };
//int dx[] = { 0, 1, 0, -1 };
//int T, M, N, K, X, Y, farm[50][50], visited[50][50];
//
//void earthwormdfs(int y, int x)
//{
//	visited[y][x] = 1;
//
//	for (int i = 0; i < 4; ++i)
//	{
//		int ny = y + dy[i];
//		int nx = x + dx[i];
//
//		if (0 > ny || 0 > nx || N <= ny || M <= nx) continue;
//		if (1 == farm[ny][nx] && 0 == visited[ny][nx]) earthwormdfs(ny, nx);
//	}
//}
//
//int main()
//{
//	cin >> T;
//
//	while (T--)
//	{
//		cin >> M >> N >> K;
//
//		// �ʱ�ȭ �۾�
//		fill(&farm[0][0], &farm[49][49], 0);
//		fill(&visited[0][0], &visited[49][49], 0);
//		int ret = 0;
//
//		// ���߹� ����
//		for (int i = 0; i < K; ++i)
//		{
//			cin >> X >> Y;
//			farm[Y][X] = 1;
//		}
//
//		// ����&������ Ž��
//		for (int i = 0; i < N; ++i)
//		{
//			for (int j = 0; j < M; ++j)
//			{
//				if (1 == farm[i][j] && 0 == visited[i][j])
//				{
//					++ret;
//					earthwormdfs(i, j);
//				}
//			}
//		}
//
//		cout << ret << "\n";
//	}
//
//	return 0;
//}

// �� �ٸ� Ǯ�̹�(Ŀ��Ƽ�� ������Ʈ_DFS)
// �� Ǯ�̿� ����?
// �ִܰŸ��� ã�� ���� �ƴϴϱ� ���� BFS�� �� �ʿ� ����
// ��� BFS�� �����ص� �������
int t, m, n, k, x, y, ny, nx, ret;
int a[51][51], visited[51][51];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

void dfs(int y, int x)
{
	visited[y][x] = 1;

	for (int i = 0; i < 4; ++i)
	{
		ny = y + dy[i];
		nx = x + dx[i];

		if (0 > ny || 0 > nx || n <= ny || m <= nx) continue;
		if (1 == a[ny][nx] && !visited[ny][nx])
		{
			dfs(ny, nx);
		}
	}
}

int main()
{
	cin >> t;

	while (t--)
	{
		// ���ɸ��� �ʱ�ȭ
		fill(&a[0][0], &a[0][0] + 51 * 51, 0);
		fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
		ret = 0;

		cin >> m >> n >> k;
		for (int i = 0; i < k; ++i)
		{
			cin >> x >> y;
			a[y][x] = 1;
		}

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (1 == a[i][j] && !visited[i][j])
				{
					dfs(i, j);
					++ret;
				}
			}
		}
		cout << ret << "\n";
	}

	return 0;
}