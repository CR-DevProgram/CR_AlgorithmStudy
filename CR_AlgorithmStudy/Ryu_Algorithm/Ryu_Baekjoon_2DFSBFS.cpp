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
//int quadtree[64][64];
//int N;
//
//void quadtreeserch(int y, int x, int quadsize)
//{
//	for (int i = y; i < y + quadsize; ++i)
//	{
//		for (int j = x; j < x + quadsize; ++j)
//		{
//			// �������� ���� y,x�� �ٸ��ٸ�
//			if (quadtree[y][x] != quadtree[i][j])
//			{
//				cout << "(";
//				// ������
//				quadtreeserch(y, x, quadsize / 2);
//				// ��������
//				quadtreeserch(y, x + quadsize / 2, quadsize / 2);
//				// ���ʾƷ�
//				quadtreeserch(y + quadsize / 2, x, quadsize / 2);
//				// �����ʾƷ�
//				quadtreeserch(y + quadsize / 2, x + quadsize / 2, quadsize / 2);
//				cout << ")";
//				return;
//			}
//		}
//	}
//
//	// �ٸ��� �ʴٸ� �ش� ������ ���
//	cout << quadtree[y][x];
//}
//
//int main()
//{
//	cin >> N;
//
//	for (int i = 0; i < N; ++i)
//	{
//		string s = "";
//		cin >> s;
//
//		// quadtree ä���
//		for (int j = 0; j < s.size(); ++j)
//		{
//			quadtree[i][j] = s[j] - '0';
//		}
//	}
//
//	quadtreeserch(0, 0, N);
//
//	return 0;
//}

// �� �ٸ� Ǯ�̹�(��������)
// �� Ǯ�̿� ����?
// ��� 0 => 0, ��� 1 =>1, 0��1 ȥ���̸� => (���� ���� �޾� ����)
// �ݺ��Ǵ� ���� ��Ģ�� ���̸� ����Լ� Ȱ��
// ��������: ū ������ ���� ������ �ɰ��� ���, ���� ������ �ذ��ϴ� ������� ���� ������ �ذ�
// ���������� ��� Ȥ�� �������� Ǯ�� ����
//int n;
//string s;
//char a[101][101];
//
//string quard(int y, int x, int size)
//{
//	// ���̻� �ɰ����� ���� ��
//	// string(1, a[y][x]) => ĳ�������� ��Ʈ������ �ٲٱ� ����
//	if (1 == size) return string(1, a[y][x]);
//
//	bool flag = false;
//	char b = a[y][x];
//	string ret = "";
//
//	for (int i = y; i < y + size; ++i)
//	{
//		for (int j = x; j < x + size; ++j)
//		{
//			if (b != a[i][j])
//			{
//				// ���� ���� ��� ��ȣ �� ���ڿ� ����
//				ret += '(';
//				ret += quard(y, x, size / 2);
//				ret += quard(y, x + size / 2, size / 2);
//				ret += quard(y + size / 2, x, size / 2);
//				ret += quard(y + size / 2, x + size / 2, size / 2);
//				ret += ')';
//				
//				return ret;
//			}
//		}
//	}
//
//	// ���� ������ �ɸ��� �ʴ´ٸ� 0 �Ǵ� 1�� ��ȯ�ϰ� ����
//	return string(1, a[y][x]);
//}
//
//int main()
//{
//	cin >> n;
//
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> s;
//
//		for (int j = 0; j < n; ++j)
//		{
//			a[i][j] = s[j];
//		}
//	}
//
//	cout << quard(0, 0, n) << "\n";
//
//	return 0;
//}

// 6_��� ��� ����
// https://www.acmicpc.net/problem/2828
// �ٱ��ϴ� ���� ó�� ���ʿ� ��ġ
// �ٱ��� ������ �������� ũ�⿡ ���� ������ ��ġ�� �缳�����ֱ� ������
// �̵��� �� ���� ��ġ�� ����
// N: ��ũ�� ũ�� M: �ٱ��� ũ��, 1 <= M < N <= 10
// J: ��� ����
//int N, M, J, lpos = 1, rpos, ret;
//
//int main()
//{
//	cin >> N >> M >> J;
//
//	for (int i = 0; i < J; ++i)
//	{
//		int value = 0;
//		cin >> value;
//		// ���� ���� ��ġ �������� ������ ��ġ �ʱ�ȭ
//		rpos = lpos + M - 1;
//		
//		if (0 == (lpos <= value && rpos >= value))
//		{
//			// ���� ��ġ ���� ��� ��ġ�� �� ���� ���
//			if (lpos > value)
//			{
//				ret += (lpos - value);
//				lpos = value;
//			}
//			// ���� ��ġ ���� ��� ��ġ�� �� ���� ���
//			else
//			{
//				ret += (value - rpos);
//				lpos += value - rpos;
//			}
//		}
//	}
//
//	cout << ret << "\n";
//
//	return 0;
//}

// �� �ٸ� Ǯ�̹�(?)
// �� Ǯ�̿� ����
// �ּҷ� �������� �Ѵ�
//int n, m, j, l, r, temp, ret;
//
//int main()
//{
//	cin >> n >> m >> j;
//	// ���� ���� ��ġ ����
//	l = 1;
//
//	for (int i = 0; i < j; ++i)
//	{
//		// l�κ��� �����ؼ� m - 1������ r
//		// ������ l�� ������� r ����
//		r = l + m - 1;
//		cin >> temp;
//
//		// �ٱ��� �ȿ� ������ continue
//		if (l <= temp && r >= temp) continue;
//		// �ٱ��Ͽ� ��� ���� �ٱ��� �̵�
//		else
//		{
//			// ���� �̵�
//			if (l > temp)
//			{
//				ret += (l - temp);
//				l = temp;
//			}
//			// ������ �̵�
//			else
//			{
//				ret += (temp - r);
//				l += (temp - r);
//			}
//		}
//	}
//
//	cout << ret << "\n";
//
//	return 0;
//}

// 7_�� ����
// https://www.acmicpc.net/problem/2910
// ���� �����ϴ� ������ �� ������� ����
// ���� Ƚ���� ���ٸ� ���� ���� ���� �������
// ����, ī��Ʈ, ������ �����ؼ� ���� �ڷ� ���� �ΰ� �̿�, �ϳ��δ� �� �� ���ö�..
// N: �޽��� ���� ����(�ִ� õ)
// C: ����(����)�� �ִ�(�ִ� 10��)
//int N, C;
//vector<int> order;
//vector<pair<int, int>> code;	// first: ī��Ʈ, second: ����
//
//bool compare(const pair<int, int>& a, const pair<int, int>& b)
//{
//	// ī��Ʈ�� ���� ���
//	if (a.first == b.first)
//	{
//		// �Է� ������� ��� order �迭 �̿��� ���� ����
//		for (int i : order)
//		{
//			// a�� ù �ε����� b�� ù �ε����� ��
//			int idxa = find(order.begin(), order.end(), a.second) - order.begin();
//			int idxb = find(order.begin(), order.end(), b.second) - order.begin();
//
//			return idxa < idxb ? true : false;
//		}
//	}
//
//	return a.first > b.first;
//}
//
//int main()
//{
//	cin >> N >> C;
//
//	for (int i = 0; i < N; ++i)
//	{
//		int number = 0;
//		cin >> number;
//
//		order.push_back(number);
//	}
//
//	for (int number : order)
//	{
//		// code�� �̹� ���ڰ� �ִ� ��� ���� ��츦 �����ϱ� ���� flag bool
//		bool flag = false;
//		// code�� ������� ���� ���
//		if (false == code.empty())
//		{
//			for (int i = 0; i < code.size(); ++i)
//			{
//				// ���� ���� �ִٸ� ī��Ʈ ���� �� flag ����
//				if (number == code[i].second)
//				{
//					++code[i].first;
//					flag = true;
//					break;
//				}
//			}
//		}
//		// code�� ����ְų� flag ������ �����ٸ� code�� �߰�
//		if (true == code.empty() || false == flag) code.push_back(make_pair(1, number));
//	}
//
//	// ī��Ʈ ���� �������� ����
//	sort(code.begin(), code.end(), compare);
//
//	for (pair<int, int> temp : code)
//	{
//		// ī��Ʈ ���ڿ� �°� �ݺ� ���
//		for (int i = 0; i < temp.first; ++i)
//		{
//			cout << temp.second << " ";
//		}
//	}
//
//	return 0;
//}

// �� �ٸ� Ǯ�̹�(?)
// �ش� ������ Ŀ���� ���۷�����(?)�� ���÷��� �Ѵ�
// 1���� ����: ī����, 2���� ����: ���� ���� ��
//int n, c, a[1004];
//vector<pair<int, int>> v;
//map<int, int> mp, mp_first;		// mp: ī���� �迭�� ���, mp_first: ù ��° �� �Ҵ�
//
//bool cmp(pair<int, int> a, pair<int, int> b)
//{
//	// ī������ ���ٸ�
//	if (a.first == b.first)
//	{
//		// ���� ���� ���� ��
//		return mp_first[a.second] < mp_first[b.second];
//	}
//
//	return a.first > b.first;
//}
//
//int main()
//{
//	cin >> n >> c;
//
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> a[i];
//		++mp_first[a[i]];
//
//		// mp_first[a[i]]�� ���� �ִ��� ������, 0�̸� ���� ������ ������ ���� �Ҵ�
//		// i + 1�� �� ������, ������ �Ͼ�� �ʾ����� 0�̱� ������ i�� �� ��� �ʹݿ� 0���� �Ǿ� ������ ������ �߻��ϱ� ���� 
//		if (0 == mp_first[a[i]]) mp_first[a[i]] = i + 1;
//	}
//
//	for (auto& it : mp) v.push_back({ it.second, it.first });
//
//	sort(v.begin(), v.end(), cmp);
//
//	for (auto& i : v)
//	{
//		for (int j = 0; j < i.first; ++j)
//		{
//			cout << i.second << " ";
//		}
//	}
//
//	return 0;
//}

// 8_��й�ȣ �����ϱ�
// https://www.acmicpc.net/problem/4659
// ���� �ϳ��� �ݵ�� ���� / ���ӵ� ���� 3�� Ȥ�� ���ӵ� ���� 3�� �Ұ� / ���� ���� ���� �ι�X(��, ee�� oo ����)
// ��й�ȣ�� 20�� ������ ���ڿ�
//string str;
//int vowelcnt, consonantcnt;
//
//bool password()
//{
//	// �ʱ�ȭ
//	vowelcnt = 0;
//	consonantcnt = 0;
//
//	// ���� ���� Ȯ��
//	bool bVowel = false;
//	for (char c : str)
//	{
//		if ('a' == c || 'e' == c || 'i' == c || 'o' == c || 'u' == c)
//		{
//			bVowel = true;
//			break;
//		}
//	}
//
//	if (false == bVowel) return false;
//
//	// ���� ���� 3��, ���� 3�� => false Ȯ��
//	for (int i = 0; i < str.size(); ++i)
//	{
//		// ����
//		if ('a' == str[i] || 'e' == str[i] || 'i' == str[i] || 'o' == str[i] || 'u' == str[i])
//		{
//			++vowelcnt;
//			consonantcnt = 0;
//		}
//		// ����
//		else
//		{
//			++consonantcnt;
//			vowelcnt = 0;
//		}
//
//		if (3 <= vowelcnt || 3 <= consonantcnt) return false;
//	}
//
//
//	// ���� ���� ���� �ι� => false
//	// ee, oo => true
//	for (int i = 1; i < str.size(); ++i)
//	{
//		if ('e' == str[i] || 'o' == str[i]) continue;
//		if (str[i] == str[i - 1]) return false;
//	}
//	
//	// ���� ���ǵ鿡 �� �ɸ��� ������� �Դٸ� ��й�ȣ ����
//	return true;
//}
//
//void print(bool bFT)
//{
//	string ret = bFT ? "> is acceptable." : "> is not acceptable.";
//	
//	cout << '<' << str << ret << "\n";
//}
//
//int main()
//{
//	while (true)
//	{
//		cin >> str;
//
//		if ("end" == str) break;
//
//		print(password());
//	}
//
//	return 0;
//}

// �� �ٸ� Ǯ�̹�(?)
// flag�� �̿��Ͽ� Ǯ��
// ����1) ���� �Ǵ� ������ 3�� �̻�X
// ����2) ���� �ݵ�� ����
// ����3) o,e ���� ���� �Ұ�
string s;
int lcnt, vcnt;

bool isVowel(int idx)
{
	return ('a' == idx || 'e' == idx || 'i' == idx || 'o' == idx || 'u' == idx);
}

int main()
{
	while (true)
	{
		cin >> s;

		if ("end" == s) break;

		// �ʱ�ȭ
		lcnt = vcnt = 0;

		bool flag = 0;
		bool is_include_v = 0;
		int prev = -1;

		// s ���ڿ���ŭ ��ȸ
		for (int i = 0; i < s.size(); ++i)
		{
			// idx == ���ĺ� �ƽ�Ű�ڵ�
			int idx = s[i];
			// isVowel�Լ��� �������� Ȯ��
			// ����
			if (true == isVowel(idx))
			{
				++lcnt;
				vcnt = 0;
				// ������ �ݵ�� �ִ��� Ȯ���ϱ� ���� ��
				is_include_v = 1;
			}
			// ����
			else
			{
				++vcnt;
				lcnt = 0;
			}

			// ���� Ȥ�� ������ ���� 3���� ���� Ȯ��
			if (3 == vcnt || 3 == lcnt) flag = 1;

			// s[i] == a[i - 1]�� ���������� prev�� �̿��ϴ� ����� ����
			// 0�� ������ �������� �����ϱ� 1�̻����� Ȯ��
			// ���� idx�� ������ ������ Ȯ��
			// e,o�� �ƴ��� Ȯ��
			if ((1 <= i) && (idx == prev) && ('e' != idx && 'o' != idx)) flag = 1;
			// ���ӵ� ���� ���� Ȯ���� ����, ���׿� ���� ������ ������Ʈ
			// �̿� �����ϸ� ���� �װ� �񱳸� ���� �ϳ��� ���� �ذ� ����
			prev = idx;
		}

		if (0 == is_include_v) flag = 1;

		if (true == flag) cout << "<" << s << ">" << " is not acceptable.\n";
		else cout << "<" << s << ">" << " is acceptable.\n";
	}

	return 0;
}