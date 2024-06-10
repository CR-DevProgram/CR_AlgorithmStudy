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
//int t, m, n, k, x, y, ny, nx, ret;
//int a[51][51], visited[51][51];
//int dy[] = { -1, 0, 1, 0 };
//int dx[] = { 0, 1, 0, -1 };
//
//void dfs(int y, int x)
//{
//	visited[y][x] = 1;
//
//	for (int i = 0; i < 4; ++i)
//	{
//		ny = y + dy[i];
//		nx = x + dx[i];
//
//		if (0 > ny || 0 > nx || n <= ny || m <= nx) continue;
//		if (1 == a[ny][nx] && !visited[ny][nx])
//		{
//			dfs(ny, nx);
//		}
//	}
//}
//
//int main()
//{
//	cin >> t;
//
//	while (t--)
//	{
//		// ���ɸ��� �ʱ�ȭ
//		fill(&a[0][0], &a[0][0] + 51 * 51, 0);
//		fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
//		ret = 0;
//
//		cin >> m >> n >> k;
//		for (int i = 0; i < k; ++i)
//		{
//			cin >> x >> y;
//			a[y][x] = 1;
//		}
//
//		for (int i = 0; i < n; ++i)
//		{
//			for (int j = 0; j < m; ++j)
//			{
//				if (1 == a[i][j] && !visited[i][j])
//				{
//					dfs(i, j);
//					++ret;
//				}
//			}
//		}
//		cout << ret << "\n";
//	}
//
//	return 0;
//}

// 3_���� ����
// https://www.acmicpc.net/problem/2468
// Ư�� ��ġ �ʰ� Ŀ��Ƽ�� ������Ʈ
// �帶ö������ �� �� ���� ��쵵 ���
// ���� ���� ���� 0 ~ 100�� �� ��(�ִ� 100���� ���� ������ �ǹ��� ���̰� 1 ~ 100�̱� ����)
// N: �࿭ ����
//const int MAX = 100;
//int N, rain, maximum, ret;
//int area[MAX][MAX], visited[MAX][MAX];
//int dy[] = { -1, 0, 1, 0 };
//int dx[] = { 0, 1, 0, -1 };
//
//void safezone(int y, int x)
//{
//	visited[y][x] = 1;
//
//	for (int i = 0; i < 4; ++i)
//	{
//		int ny = y + dy[i];
//		int nx = x + dx[i];
//
//		if (0 > ny || 0 > nx || N <= ny || N <= nx) continue;
//		// ���� �纸�� ���� ���̰� ū ����̸� �湮���� �ʾ��� ���� safezone ��� Ž��
//		if (rain < area[ny][nx] && 0 == visited[ny][nx]) safezone(ny, nx);
//	}
//}
//
//int main()
//{
//	cin >> N;
//
//	for (int i = 0; i < N; ++i)
//	{
//		for (int j = 0; j < N; ++j)
//		{
//			cin >> area[i][j];
//			// ���� �ִ�ġ�� �˾Ƴ� ���� �� ��� �κп��� Ż�� �������� ���
//			maximum = max(maximum, area[i][j]);
//		}
//	}
//
//	// ���� ���� ���� ���� �ִ븦 �Ѿ�� �ߴ�
//	while (rain < maximum)
//	{
//		// ���� �翡 ���� ���� ���� Ȯ���� ���� �ʱ�ȭ ó��
//		fill(&visited[0][0], &visited[99][99], 0);
//		int cnt = 0;
//
//		for (int i = 0; i < N; ++i)
//		{
//			for (int j = 0; j < N; ++j)
//			{
//				if (rain < area[i][j] && 0 == visited[i][j])
//				{
//					++cnt;
//					safezone(i, j);
//				}
//			}
//		}
//
//		// �ܼ��� �������� �� �ִ� ���� ���� �����ϰ� ���Ŀ� �� ū ��ġ�� ���鼭 �ִ� ���� �������� ���� ���̶� �����Ͽ� ���� �ο�
//		// �׷��� �پ��ٰ� �ٽ� �þ�� �κ��� �����ϴ��� 2n�� �� Ʋ�ȴٰ� ����
//		// ���� ������ ���� ������ �ִ븦 �˾Ƴ� ���� ���� ���� ������� �ʰ�(�ð��ʰ� ���� ����) ó��
//		//if (ret > cnt) break;
//
//		// �ִ� ���� ���� ����
//		ret = max(ret, cnt);
//
//		// ���� �� ����
//		++rain;
//	}
//
//	cout << ret << "\n";
//
//	return 0;
//}

// �� �ٸ� Ǯ�̹�(Ŀ��Ƽ�� ������Ʈ_DFS)
// ������ ���� �翡 ���� ��� �����ؼ� �� �߿��� ���� ū ���� ���� ���� ���ϱ�
// ���̳��� ���õ� DFS �Ű� ������ ���� ��
// ***�ݷ�: �ּ�, �ִ�, ���ų�, �ְų�***
// ***�������� ����***
// �ش� ������ �ݷʴ� �ƹ� ������ ���� ����� ���� ���� �ִ�.
//int n, ret = 1;
//int a[101][101], visited[101][101];
//int dy[] = { -1, 0, 1, 0 };
//int dx[] = { 0, 1, 0, -1 };
//
//// d�� �������� �ξ ������ ��������� �ϱ� ���� �Ű����� ���
//void dfs(int y, int x, int d)
//{
//	visited[y][x] = 1;
//
//	for (int i = 0; i < 4; ++i)
//	{
//		int ny = y + dy[i];
//		int nx = x + dx[i];
//
//		if (0 > ny || 0 > nx || n <= ny || n <= nx) continue;
//		if (!visited[ny][nx] && d < a[ny][nx]) dfs(ny, nx, d);
//	}
//}
//
//int main()
//{
//	cin >> n;
//
//	for (int i = 0; i < n; ++i)
//	{
//		for (int j = 0; j < n; ++j)
//		{
//			cin >> a[i][j];
//		}
//	}
//
//	for (int d = 1; d < 101; ++d)
//	{
//		fill(&visited[0][0], &visited[0][0] + 101 * 101, 0);
//
//		int cnt = 0;
//		for (int i = 0; i < n; ++i)
//		{
//			for (int j = 0; j < n; ++j)
//			{
//				if (d < a[i][j] && !visited[i][j])
//				{
//					dfs(i, j, d);
//					++cnt;
//				}
//			}
//		}
//
//		ret = max(ret, cnt);
//	}
//
//	cout << ret << "\n";
//
//	return 0;
//}

// 4_���� ���ϱ�
// https://www.acmicpc.net/problem/2583
// M*N: ���簢�� �� ���� ũ��, K: ���簢�� ����
//const int MAX_SIZE = 100;
//int M, N, K, areasize;
//int graphpaper[MAX_SIZE][MAX_SIZE], visited[MAX_SIZE][MAX_SIZE];
//int dy[] = { -1, 0, 1, 0 };
//int dx[] = { 0, 1, 0, -1 };
//
//void areaserch(int y, int x)
//{
//	visited[y][x] = 1;
//
//	for (int i = 0; i < 4; ++i)
//	{
//		int ny = y + dy[i];
//		int nx = x + dx[i];
//
//		if (0 > ny || 0 > nx || M <= ny || N <= nx) continue;
//		if (0 == graphpaper[ny][nx] && 0 == visited[ny][nx])
//		{
//			++areasize;
//			areaserch(ny, nx);
//		}
//	}
//}
//
//int main()
//{
//	cin >> M >> N >> K;
//
//	for (int i = 0; i < K; ++i)
//	{
//		pair<int, int> lefttop, rightbot;
//		// �簢�� �»��
//		cin >> lefttop.first >> lefttop.second;
//		// �簢�� ���ϴ�
//		cin >> rightbot.first >> rightbot.second;
//
//		// �� ���̿� ���簢�� �׸���
//		for (int rectY = lefttop.second; rectY < rightbot.second; ++rectY)
//		{
//			for (int rectX = lefttop.first; rectX < rightbot.first; ++rectX)
//			{
//				graphpaper[rectY][rectX] = 1;
//			}
//		}
//	}
//
//	// ���� ũ�� ���� vector
//	vector<int> vecareasize;
//	for (int i = 0; i < M; ++i)
//	{
//		for (int j = 0; j < N; ++j)
//		{
//			// Ŀ��Ƽ�� ������Ʈ �� ���� ũ�� �ľ��� ���� ���� �ʱ�ȭ
//			areasize = 0;
//			if (0 == graphpaper[i][j] && 0 == visited[i][j])
//			{
//				++areasize;
//				areaserch(i, j);
//
//				if (0 != areasize) vecareasize.push_back(areasize);
//			}
//		}
//	}
//
//	// ũ�� �������� ����
//	sort(vecareasize.begin(), vecareasize.end());
//
//	cout << vecareasize.size() << "\n";
//	for (int i = 0; i < vecareasize.size(); ++i)
//	{
//		cout << vecareasize[i] << " ";
//	}
//
//	return 0;
//}

// �� �ٸ� Ǯ�̹�(Ŀ��Ƽ�� ������Ʈ_DFS int��)
// ������ ���� Ŀ��Ƽ�� ������Ʈ�� ���÷��� ��
// y1�� ����Ϸ��� #define �ɾ���� �� => #include <bits/stdc++.h>�� y1��� ���������� �ɷ��ֱ� ����, ���� ���Ƿ� �Ҵ��ؾ� ��� ����
// �������� ������ ��ٸ� �ش� �������� define �۾��� �� ��
// ������ �ٽ��� dfs�� void�� �ƴ� int�� �ߴ°�
//#define y1 yy
//vector<int> vec;
//int a[104][104], visited[104][104], m, n, k, x1, x2, y1, y2;
//const int dy[] = { -1, 0, 1, 0 };
//const int dx[] = { 0, 1, 0, -1 };
//
//// ��ȯ Ÿ���� void�� �ƴ� int�� �� ���� => ������ ���� ������ ����, Ŀ��Ƽ�� ������Ʈ�� �ش� ����� ���ϱ� ���� int ��ȯ ���� �̿�
//int dfs(int y, int x)
//{
//	visited[y][x] = 1;
//
//	// ������ �� 1�� ������� �̵��� ��ġ���� ���� ����
//	int ret = 1;
//	for (int i = 0; i < 4; ++i)
//	{
//		int ny = y + dy[i];
//		int nx = x + dx[i];
//
//		if (0 > ny || 0 > nx || m <= ny || n <= nx) continue;
//		if (1 == a[ny][nx] || 1 == visited[ny][nx]) continue;
//
//		ret += dfs(ny, nx);
//	}
//
//	return ret;
//}
//
//int main()
//{
//	cin >> m >> n >> k;
//
//	for (int i = 0; i < k; ++i)
//	{
//		cin >> x1 >> y1 >> x2 >> y2;
//
//		for (int x = x1; x < x2; ++x)
//		{
//			for (int y = y1; y < y2; ++y)
//			{
//				a[y][x] = 1;
//			}
//		}
//	}
//
//	for (int i = 0; i < m; ++i)
//	{
//		for (int j = 0; j < n; ++j)
//		{
//			// ����Բ��� ��������(&&)�� �ƴ� ��Ʈ������(&)�� ���
//			// &&�� || ���� ������� ������ 0, 1�� ������� �����Ƿ� & ������ ���൵ &&�� �� �Ͱ� ���� ����
//			// �ʷ� ������ �Ű澲���� ��Ʈ ���� ���� �ٲ�
//			if (1 != a[i][j] && 0 == visited[i][j])
//			{
//				// ����� ���ؼ� ���Ϳ� �ֱ�
//				vec.push_back(dfs(i, j));
//			}
//		}
//	}
//
//	sort(vec.begin(), vec.end());
//
//	// Ŀ��Ƽ�� ������Ʈ�� �� ������
//	cout << vec.size() << "\n";
//	// ��������� ��� �Ǵ���
//	for (int a : vec) cout << a << " ";
//
//	return 0;
//}

// 5_����Ʈ��
// https://www.acmicpc.net/problem/1992
// (������ �������� ���ʾƷ� �����ʾƷ�)
// 0�� 1�� �����ִٸ� �ش� �κ��� ��ȣ�� ǥ��
// N: ���� ũ��
int quadtree[64][64];
int N;

void quadtreeserch(int y, int x, int quadsize)
{
	for (int i = y; i < y + quadsize; ++i)
	{
		for (int j = x; j < x + quadsize; ++j)
		{
			// �������� ���� y,x�� �ٸ��ٸ�
			if (quadtree[y][x] != quadtree[i][j])
			{
				cout << "(";
				// ������
				quadtreeserch(y, x, quadsize / 2);
				// ��������
				quadtreeserch(y, x + quadsize / 2, quadsize / 2);
				// ���ʾƷ�
				quadtreeserch(y + quadsize / 2, x, quadsize / 2);
				// �����ʾƷ�
				quadtreeserch(y + quadsize / 2, x + quadsize / 2, quadsize / 2);
				cout << ")";
				return;
			}
		}
	}

	// �ٸ��� �ʴٸ� �ش� ������ ���
	cout << quadtree[y][x];
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		string s = "";
		cin >> s;

		// quadtree ä���
		for (int j = 0; j < s.size(); ++j)
		{
			quadtree[i][j] = s[j] - '0';
		}
	}

	quadtreeserch(0, 0, N);

	return 0;
}