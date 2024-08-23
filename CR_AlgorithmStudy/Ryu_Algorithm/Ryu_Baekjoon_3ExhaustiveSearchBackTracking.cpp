#include <bits/stdc++.h>

using namespace std;

// 1_ġŲ ���
// https://www.acmicpc.net/problem/15686
// ���� ���ذ� �ʹ� �ȵż� �������� ã�Ƽ� �ִ��� ���ظ� �غ�
// ġŲ���� �ִ� ������ M���� �־���, M���� ġŲ���� ���� �����θ� �����ϸ� ��
// ���� ġŲ �� �߿��� M���� ����? => �������� ��� ���� ������ ġŲ �Ÿ��� ���� ���� ���� ���α׷��� �ۼ��϶�� �����Ƿ� ������ ������� �������� M���� �����Ͽ� ���� �Ÿ��� ���� ���� ����ϸ� ��
// �� �� ���� ���� ����� ġŲ �� ������ �Ÿ��� ��� ���� �Ÿ��� ������ ġŲ �Ÿ��� ���� ���� ġŲ �Ÿ��� ���ϸ� ��
// ***** �� ���� ���� ����� ġŲ �� ������ �Ÿ��� ��� ���� �Ÿ� ***** => ���� �߿� ����Ʈ
// N: ���� ũ��, M: �ִ� ġŲ�� ����
//int N, M, ret = 100000, City[50][50];
//vector<pair<int, int>> Homes, Chickens, ChickenList;
//
//void Combi(int Start)
//{
//	if (M == ChickenList.size())
//	{
//		// ġŲ �Ÿ� ���ϱ� ����
//		int Cal = 0;
//		for (pair<int, int> Home : Homes)
//		{
//			// �Ÿ� �ּҰ��� ���ϱ� ���� �ִ밪 �ʱ�ȭ
//			int HomeMin = N * N;
//
//			for (pair<int, int> Chicken : ChickenList)
//			{
//				// �Ÿ� ����
//				int Dir = abs(Home.first - Chicken.first) + abs(Home.second - Chicken.second);
//				// ���� �������� ġŲ������ �ּҰŸ�
//				HomeMin = min(HomeMin, Dir);
//			}
//			// ���� �������� �ּҰŸ� �տ���
//			Cal += HomeMin;
//		}
//
//		// ���� �ּҰŸ� ������ ���� min Ȯ��
//		ret = min(ret, Cal);
//
//		return;
//	}
//
//	// ġŲ�� ����
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
//			// ���� ġŲ�� ��ġ ���� ���
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

// �� �ٸ� Ǯ�̹�(Combi����Ž�� �� �ε��� Ȱ��)
// �����ϰ� Ǯ �� �ִ°�? -> ���� -> �ð����⵵ ��� -> �����ϴ�?(���� GO), �Ұ����ϴ�?(�ٸ� �˰���)
// ġŲ���� �����ϰ� ��� ������ �Ÿ��� ���ؼ� �� �Ÿ� �� ���� �ּҰ��� ���ϸ� ��
//int n, m, a[54][54], result = 987654321;
//vector<vector<int>> ChickenList;		// ġŲ ��ġ�� ��� �ִ� Chicken�� �ε����� ��� ���� ����Ʈ
//vector<pair<int, int>> Home, Chicken;
//
//void Combi(int Start, vector<int> v)
//{
//	// �ִ� ġŲ�� ������ v ����� ���� ��
//	if (m == v.size())
//	{
//		// ����
//		// ���յ� ����
//		ChickenList.push_back(v);
//		return;
//	}
//
//	// ����
//	for (int i = Start + 1; i < Chicken.size(); ++i)
//	{
//		v.push_back(i);
//		Combi(i, v);
//		v.pop_back();
//	}
//}
//
//int main()
//{
//	cin >> n >> m;
//
//	for (int i = 0; i < n; ++i)
//	{
//		for (int j = 0; j < n; ++j)
//		{
//			cin >> a[i][j];
//
//			if (1 == a[i][j]) Home.push_back({ i,j });
//			if (2 == a[i][j]) Chicken.push_back({ i,j });
//		}
//	}
//
//	vector<int> v;
//	Combi(-1, v);
//
//	// ġŲ�� �̱�
//	for (vector<int> cList : ChickenList)
//	{
//		int ret = 0;
//		for (pair<int, int> _Home : Home)
//		{
//			int _Min = 987654321;
//
//			// ġŲ ����Ʈ �߿��� ������ �Ÿ�
//			for (int ch : cList)
//			{
//				int _Dist = abs(_Home.first - Chicken[ch].first) + abs(_Home.second - Chicken[ch].second);
//				// �Ÿ� ���ؼ� �ּҰ� ���ϱ�(���� ġŲ���� �߿��� �ּ� ġŲ �Ÿ�)
//				_Min = min(_Min, _Dist);
//			}
//			
//			// �ּ� ���� ��
//			ret += _Min;
//		}
//
//		// ��ü�� �ּ� ��
//		result = min(result, ret);
//	}
//
//	// ���
//	cout << result;
//
//	return 0;
//}

// 2_������
// https://www.acmicpc.net/problem/2589
// �� �̵� ������ ���� ũ��� �ش� �������� BFS�� Ȱ���Ͽ� ��� ���ϱ�
//int n, m, ret, visited[50][50], island[50][50];
//int dy[] = { -1, 0, 1, 0 };
//int dx[] = { 0, 1, 0, -1 };
//queue<pair<int, int>> q;
//
//void BFS(int y, int x)
//{
//	visited[y][x] = 1;
//
//	while (true != q.empty())
//	{
//		tie(y, x) = q.front();
//		q.pop();
//
//		for (int i = 0; i < 4; ++i)
//		{
//			int ny = y + dy[i];
//			int nx = x + dx[i];
//
//			if (0 > ny || 0 > nx || n <= ny || m <= nx) continue;
//			if (0 == island[ny][nx] || 0 != visited[ny][nx]) continue;
//
//			// ��� ��ġ�� ���ϱ� ����
//			visited[ny][nx] = visited[y][x] + 1;
//			ret = max(ret, visited[ny][nx] - 1);
//			q.push({ ny, nx });
//		}
//	}
//}
//
//int main()
//{
//	cin >> n >> m;
//
//	for (int i = 0; i < n; ++i)
//	{
//		string LandInfo = "";
//		cin >> LandInfo;
//
//		for (int j = 0; j < LandInfo.size(); ++j)
//		{
//			// �ٴٴ� 0 ������ 1
//			island[i][j] = 'W' == LandInfo[j] ? 0 : 1;
//		}
//	}
//
//	// ��� ��� Ž��
//	for (int i = 0; i < n; ++i)
//	{
//		for (int j = 0; j < m; ++j)
//		{
//			// Ž���� �湮 ��� �ʱ�ȭ
//			fill(&visited[0][0], &visited[0][0] + 50 * 50, 0);
//			// �����̰� �湮���� �ʾ��� �� BFS ������ 
//			if (1 == island[i][j] && 0 == visited[i][j])
//			{
//				q.push({ i,j });
//				BFS(i, j);
//			}
//		}
//	}
//
//	// ��� ���
//	cout << ret;
//
//	return 0;
//}

// �� �ٸ� Ǯ�̹�(?)
// �� Ǯ�̿� ����?
// ���� -> ������ ���� ���� �� �ִܰŸ�, ������ ���� �� �ִܰŸ��� ��������
// �ִ� �Ÿ� �� ���� Max ��
// ��� ����� BFS�� Ȱ���Ͽ� �ִܰŸ� ���ϸ� ��
//int n, m, mx, visited[54][54];
//int dy[] = { -1, 0, 1, 0 };
//int dx[] = { 0, 1, 0, -1 };
//char a[54][54];
//
//void BFS(int y, int x)
//{
//	// �湮 �ʱ�ȭ
//	fill(&visited[0][0], &visited[0][0] + 54 * 54, 0);
//	visited[y][x] = 1;
//	queue<pair<int, int>> q;
//	q.push({ y,x });
//
//	while (true != q.empty())
//	{
//		tie(y, x) = q.front();
//		q.pop();
//
//		for (int i = 0; i < 4; ++i)
//		{
//			int ny = y + dy[i];
//			int nx = x + dx[i];
//
//			if (0 > ny || 0 > nx || n <= ny || m <= nx) continue;
//			if (0 != visited[ny][nx] || 'W' == a[ny][nx]) continue;
//
//			// �ִ� �Ÿ� �迭
//			visited[ny][nx] = visited[y][x] + 1;
//			q.push({ ny, nx });
//			// �ִ� ���� ���ϱ� ���� max Ȱ��
//			mx = max(mx, visited[ny][nx]);
//		}
//	}
//}
//
//int main()
//{
//	// �Է� �ޱ�
//	cin >> n >> m;
//
//	for (int i = 0; i < n; ++i)
//	{
//		for (int j = 0; j < m; ++j)
//		{
//			cin >> a[i][j];
//		}
//	}
//
//	for (int i = 0; i < n; ++i)
//	{
//		for (int j = 0; j < m; ++j)
//		{
//			// 'L'�� ���� BFS ������('W'�� ���� ���� �ʿ�X)
//			if ('L' == a[i][j]) BFS(i, j);
//		}
//	}
//
//	cout << mx - 1;
//
//	return 0;
//}

// 3_�α� �̵�
// https://www.acmicpc.net/problem/16234
// ��� ��츦 Ž���ϸ� �ش� �Ǵ� ���� ��ġ�� ��Ƽ� ����
// DFS�� Ž���ϸ� L�� R������ �ش��ϴ� ���� ����(�� ����� ������ ��) => �ش� ������ ���� �α� �ջ� �� ���� ���� �ľ��� �����Ͽ� �α� ����
// �ݺ� ó�� �� ���̻� �̵��� �̷��� �� ���ٸ� ���ѷ��� Ż��
// ***** �������Ͽ� Ǯ�̤� *****
// N: �� ũ��
//int N, L, R, Count, sum, A[51][51], Border[51][51];
//int dy[] = { -1, 0, 1, 0 };
//int dx[] = { 0, 1, 0, -1 };
//vector<pair<int, int>> VecLocations;
//
//// �� ���� ������ ���� L�� R ���̿� �ִ��� �ľ�
//void DFS(int y, int x)
//{
//	for (int i = 0; i < 4; ++i)
//	{
//		int ny = y + dy[i];
//		int nx = x + dx[i];
//
//		if (0 > ny || 0 > nx || N <= ny || N <= nx || 0 != Border[ny][nx]) continue;
//
//		// ���漱�� �����ϴ� �� ������ �α� ���̰� L�� �̻� R�� ���϶��, �� ���� �����ϴ� ���漱�� ���� �Ϸ� ���� ��(DFS Ž��)
//		// �������ϴ� ���漱�� ��� ���ȴٸ� �α� �̵�
//		// ���漱�� �����־� ������ ĭ�� �̿��� �̵��� �� ������, �� ���� ���� �Ϸ� ���� ����
//		if (L <= abs(A[ny][nx] - A[y][x]) && R >= abs(A[ny][nx] - A[y][x]))
//		{
//			Border[ny][nx] = 1;
//			// ���漱�� ������ �̵� ������ ����� ����
//			VecLocations.push_back({ ny,nx });
//			// ���� �α��� ���ϱ�(����)
//			sum += A[ny][nx];
//			DFS(ny, nx);
//		}
//	}
//}
//
//int main()
//{
//	cin >> N >> L >> R;
//
//	for (int i = 0; i < N; ++i)
//	{
//		for (int j = 0; j < N; ++j)
//		{
//			cin >> A[i][j];
//		}
//	}
//
//	while (true)
//	{
//		bool IsMove = false;
//		fill(&Border[0][0], &Border[0][0] + 51 * 51, 0);
//
//		// ��� ������ ���� Ž��
//		for (int i = 0; i < N; ++i)
//		{
//			for (int j = 0; j < N; ++j)
//			{
//				// �湮���� �ʾҴٸ�? �ش� ��ġ�κ��� Ž�� ����
//				if (0 == Border[i][j])
//				{
//					// �α� �̵����� ���� �ľ��ϱ� ���� �ڷᱸ�� �ʱ�ȭ
//					VecLocations.clear();
//					Border[i][j] = 1;
//					VecLocations.push_back({ i,j });
//					sum = A[i][j];
//					DFS(i, j);
//
//					// ����� 1�̸� ���漱 ���� ��X, �ش� ���� �����ָ� ������ üũ�ؼ� �ð��ʰ� ����
//					if (1 == VecLocations.size()) continue;
//
//					// ���漱�� ������ �̵� ������ ����� ���� Ȯ���ؼ� ��ȭ ����
//					for (pair<int, int> Location : VecLocations)
//					{
//						// ������ �̷�� �ִ� ĭ�� �α����� ������ �α��� / ������ �̷�� �ִ� ĭ�� ��
//						A[Location.first][Location.second] = sum / VecLocations.size();
//						// �α� �̵� �Ͼ
//						IsMove = true;
//					}
//				}
//			}
//		}
//
//		// ������ ��ü�ϰ� ��� ���漱 ����
//		if (false == IsMove) break;
//		++Count;
//	}
//
//	cout << Count;
//
//	return 0;
//}

// 4_��!
// https://www.acmicpc.net/problem/4179
// �д� ������ 1ĭ ������, �� 4���� Ȯ��
// J- ���� ��ġ F- �ҳ� ���� #- �� .- �̵� ����
// R: �̷� �� ����, C: �̷� �� ����
//int R, C, cnt, FirePos[1000][1000], visited[1000][1000];
//char Maze[1000][1000];
//pair<int, int> JihoonPos;
//queue<pair<int, int>> qPosInfo;
//int dy[] = { -1, 0, 1, 0 };
//int dx[] = { 0, 1, 0, -1 };
//
//int main()
//{
//	cin >> R >> C;
//
//	for (int i = 0; i < R; ++i)
//	{
//		string str = "";
//		cin >> str;
//		for (int j = 0; j < C; ++j)
//		{
//			Maze[i][j] = str[j];
//
//			if ('J' == Maze[i][j])
//			{
//				visited[i][j] = 1;
//				JihoonPos = make_pair(i, j);
//			}
//			if ('F' == Maze[i][j])
//			{
//				FirePos[i][j] = 1;
//				qPosInfo.push({ i,j });
//			}
//		}
//	}
//	
//	// Fire: �� Ȯ�� �ð� ���� ǥ�� �̸� �ۼ��ϱ� ���� Fire ���� �� �� Jihoon �̵� Ȯ��
//	while (false == qPosInfo.empty())
//	{
//		pair<int, int> Fire = qPosInfo.front();
//		qPosInfo.pop();
//
//		for (int i = 0; i < 4; ++i)
//		{
//			int ny = Fire.first + dy[i];
//			int nx = Fire.second + dx[i];
//
//			if (0 > ny || 0 > nx || R <= ny || C <= nx) continue;
//			// ���̰ų� �� Ȯ���� ������ ���� �ƴ� ��� �ǳʶٱ�
//			if ('#' == Maze[ny][nx] || 0 != FirePos[ny][nx]) continue;
//
//			// Ȯ�� ���� ���� ǥ��
//			FirePos[ny][nx] = FirePos[Fire.first][Fire.second] + 1;
//			qPosInfo.push({ ny,nx });
//		}
//	}
//
//	qPosInfo.push(JihoonPos);
//	// Jihoon
//	while (false == qPosInfo.empty())
//	{
//		JihoonPos = qPosInfo.front();
//		qPosInfo.pop();
//
//		// Ż�� ���� ���� ���޽� �ð� ����� �޾Ƶΰ� while�� Ż��
//		if (0 == JihoonPos.first || 0 == JihoonPos.second || R - 1 == JihoonPos.first || C - 1 == JihoonPos.second)
//		{
//			cnt = visited[JihoonPos.first][JihoonPos.second];
//			break;
//		}
//
//		for (int i = 0; i < 4; ++i)
//		{
//			int ny = JihoonPos.first + dy[i];
//			int nx = JihoonPos.second + dx[i];
//
//			if (0 > ny || 0 > nx || R <= ny || C <= nx) continue;
//			// ���̰ų� �̵� ������ ���� �ƴ� ��� �ǳʶٱ�
//			if ('#' == Maze[ny][nx] || 0 != visited[ny][nx]) continue;
//			// �̸� ����� �ұ� �ð�(0�̿�, 0�� �ұ� ���� ���� �ƴ�)�� ���� �̵� ������ �ð��� ���ؼ� ������ �� ������ �ǳʶٱ�
//			if (0 != FirePos[ny][nx] && FirePos[ny][nx] <= visited[JihoonPos.first][JihoonPos.second] + 1) continue;
//
//			// �̵� �ð� ���� ǥ��
//			visited[ny][nx] = visited[JihoonPos.first][JihoonPos.second] + 1;
//			
//			// Ż�� ���� ���� ���� ������ �� �ݺ��� ���� ���� ��ġ push
//			qPosInfo.push({ ny,nx });
//		}
//	}
//
//	// Ż�� ����(0)�� IMPOSSIBLE, Ż�� �����ϸ�(cnt) Ż�� �ð�
//	string ret = 0 == cnt ? "IMPOSSIBLE" : to_string(cnt);
//	cout << ret;
//
//	return 0;
//}

// 5_��Ż����ũ
// https://www.acmicpc.net/problem/12869
// BFS ���� => ����� ���� ���� �ּ����� Ƚ���� SCV�� 0���� ����� ����(����ġ ����)
// ***** SCVVisited[61][61][61]: �� SCV�� ü���� ��Ÿ���� ���¸� �湮�ߴ��� ���θ� ����ϴ� �迭 ***** �޸������̼� ó�� ����
// N: SCV�� ��
//int N, SCV[3], SCVVisited[61][61][61];
//int Damage[6][3] =
//{
//	{9, 3, 1},
//	{9, 1, 3},
//	{3, 1, 9},
//	{3, 9 ,1},
//	{1, 3, 9},
//	{1, 9 ,3},
//};
//
//struct Attack
//{
//	int Attack1;
//	int Attack2;
//	int Attack3;
//};
//
//int BFS()
//{
//	queue<Attack> q;
//	q.push({ SCV[0], SCV[1], SCV[2] });
//	SCVVisited[SCV[0]][SCV[1]][SCV[2]] = 1;
//
//	while (false == q.empty())
//	{
//		Attack atk = q.front();
//		q.pop();
//
//		// ��� ü���� 0�� �Ǿ� �ּ����� ���� Ƚ���� �����Ѵٸ� BFS While�� Ż��
//		if (0 != SCVVisited[0][0][0]) break;
//
//		// ���� ����� ���Ͽ� ���� �ݺ�
//		for (int i = 0; i < 6; ++i)
//		{
//			// �迭�� ������ �� �� �����Ƿ� ���� ������ �������ٸ� 0���� ����
//			int na1 = max(0, atk.Attack1 - Damage[i][0]);
//			int na2 = max(0, atk.Attack2 - Damage[i][1]);
//			int na3 = max(0, atk.Attack3 - Damage[i][2]);
//			// �ش� ü�� ���¿� ���� ������ �ִٸ� �ǳʶٱ�
//			if (0 != SCVVisited[na1][na2][na3]) continue;
//
//			// ���� Ƚ�� �ľ��� ���� ���� ����
//			SCVVisited[na1][na2][na3] = SCVVisited[atk.Attack1][atk.Attack2][atk.Attack3] + 1;
//			// ���� Ž���� ���� ť�� ����
//			q.push({ na1,na2,na3 });
//		}
//	}
//
//	return SCVVisited[0][0][0] - 1;
//}
//
//int main()
//{
//	cin >> N;
//
//	for (int i = 0; i < N; ++i)
//	{
//		cin >> SCV[i];
//	}
//
//	cout << BFS();
//
//	return 0;
//}

// 6_��ȣ �߰��ϱ�
// https://www.acmicpc.net/problem/16637
// ��Ž�� ��� �ε����� ������� �������� => ���⼺�� �ְ� ����Ŭ�� ����
// ��ø ��ȣ �Ұ�, ������ �¿��� ��� �̷������
// �����հ� Index�� ������� Ž�� �ʿ�
// �����ڿ� ���ڷ� ������ �غ� ��
// �Լ������ͷ� ���� ������ ���� ������ ���ѵ� �غ� ��
// N: ���� ����
//int N, ret = -987654321;
//string Str;
//vector<int> Numbers;
//vector<char> Operations;
//
//int Add(int Left, int Right) { return Left + Right; }
//int Sub(int Left, int Right) { return Left - Right; }
//int Mul(int Left, int Right) { return Left * Right; }
//
//int Calculation(char InOperation, int InLeft, int InRight)
//{
//	int (*Oper)(int, int) = nullptr;
//	switch (InOperation)
//	{
//	case '+':
//		Oper = Add;
//		break;
//	case '-':
//		Oper = Sub;
//		break;
//	case '*':
//		Oper = Mul;
//		break;
//	}
//
//	return nullptr != Oper ? Oper(InLeft, InRight) : 0;
//}
//
//void MakeExpression(int Index, int Value)
//{
//	// ����� ��
//	if (Numbers.size() - 1 == Index)
//	{
//		// �ִ밪 ���� �۾�
//		ret = max(ret, Value);
//		return;
//	}
//
//	// ���� ����
//	MakeExpression(Index + 1, Calculation(Operations[Index], Value, Numbers[Index + 1]));
//	// ��ȣ�� �ִ� ���� ���� ����
//	if (Numbers.size() - 1 >= Index + 2)
//	{
//		int ParenthesesValue = Calculation(Operations[Index + 1], Numbers[Index + 1], Numbers[Index + 2]);
//		MakeExpression(Index + 2, Calculation(Operations[Index], Value, ParenthesesValue));
//	}
//}
//
//int main()
//{
//	cin >> N >> Str;
//	for (char ch : Str)
//	{
//		if (0 != isdigit(ch)) Numbers.push_back(ch - '0');
//		else Operations.push_back(ch);
//	}
//
//	MakeExpression(0, Numbers[0]);
//	cout << ret;
//
//	return 0;
//}

// 7_���ٲ���2(46% -> ����)
// https://www.acmicpc.net/problem/12851
// N: ���� ��ġ, K: ���� ��ġ
//int N, K, minCount, minTime = 987654321, visited[100001];
//
//void Move()
//{
//	queue<int> q;
//	q.push(N);
//	// ù ��ġ �湮 ó��
//	visited[N] = 1;
//
//	while (false == q.empty()) 
//	{
//		int curIndex = q.front();
//		q.pop();
//
//		// ���� ��ġ�� ������ ��
//		if (K == curIndex) 
//		{
//			// �ּ� �ð� ����
//			if (minTime > visited[curIndex]) 
//			{
//				minTime = visited[curIndex];
//				// ���� �ּ� �ð� ī��Ʈ �� �ʱ�ȭ
//				minCount = 1;
//			}
//			// ���� �ּ� �ð� ī��Ʈ ����
//			else if (minTime == visited[curIndex]) ++minCount;
//			
//			continue;
//		}
//
//		// ���� �̵� ��ġ Ž��
//		int nextInfo[] = { curIndex - 1, curIndex + 1, curIndex * 2 };
//		for (int i = 0; i < 3; ++i) 
//		{
//			int nextIndex = nextInfo[i];
//
//			// �̵��� ���� ��ġ�� �迭 ���� �ʰ��ϸ� ����
//			if (0 > nextIndex || 100000 < nextIndex ) continue;
//			// �湮 ���ο� �ּ� �ð����� Ž�� �ð��� �� �ɸ��ٸ� ���� �� Ž���� �ʿ� �����Ƿ� ����
//			if (0 != visited[nextIndex] || minTime < visited[curIndex] + 1) continue;
//
//			// Ž�� �ð� �ľ�
//			visited[nextIndex] = visited[curIndex] + 1;
//			q.push(nextIndex);
//		}
//	}
//}
//
//int main()
//{
//	cin >> N >> K;
//
//	Move();
//
//	cout << minTime - 1 << "\n" << minCount;
//
//	return 0;
//}

// 7_�ٸ� Ǯ��
// ���� ���� �ð�(BFS), ����� ��
//const int MaxPosition = 100000;
//int visited[MaxPosition + 1], cnt[MaxPosition + 1];
//
//int main()
//{
//	int n, k;
//	cin >> n >> k;
//	// �߰� �ݷ�(���� ��ġ�� ���), �ݷ� �߰� �����ָ� ����ó����
//	if (n == k)
//	{
//		cout << '0' << "\n" << '1';
//
//		return 0;
//	}
//
//	visited[n] = 1;
//	cnt[n] = 1;
//
//	queue<int> q;
//	q.push(n);
//
//	while (false == q.empty())
//	{
//		int curIndex = q.front();
//		q.pop();
//
//		int nextInfo[] = { curIndex - 1, curIndex + 1, curIndex * 2 };
//		for (int i = 0; i < 3; ++i)
//		{
//			// �̵� ������ ���� Ȯ��
//			if (0 <= nextInfo[i] && MaxPosition >= nextInfo[i])
//			{
//				// ù �湮
//				if (0 == visited[nextInfo[i]])
//				{
//					q.push(nextInfo[i]);
//					visited[nextInfo[i]] = visited[curIndex] + 1;
//					// ����� ���� ���ϱ� ���� ����
//					cnt[nextInfo[i]] += cnt[curIndex];
//				}
//				// ���������� �ٸ� �ִ� ��Ʈ�� ���� �� ����� �� �߰�
//				// �ش� �κ��� ��� ���ؼ� 46%���� Ʋ�ȴ��� �ƴұ� ����
//				else if (visited[nextInfo[i]] == visited[curIndex] + 1) cnt[nextInfo[i]] += cnt[curIndex];
//			}
//		}
//	}
//
//	cout << visited[k] - 1 << "\n" << cnt[k];
//
//	return 0;
//}

// 8_���ٲ���4
// https://www.acmicpc.net/problem/13913
// BFS, ***** Trace(��� ����): prev[next] = here *****
//const int MaxPosition = 100000;
//int visited[MaxPosition + 1], prevIndex[MaxPosition + 1];
//vector<int> cnt;
//
//int main()
//{
//	int n, k;
//	cin >> n >> k;
//
//	queue<int> q;
//	q.push(n);
//	visited[n] = 1;
//
//	while (false == q.empty())
//	{
//		int curIndex = q.front();
//		q.pop();
//
//		if (k == curIndex) break;
//
//		int nextInfo[] = { curIndex - 1, curIndex + 1, curIndex * 2 };
//		for (int i = 0; i < 3; ++i)
//		{
//			// �̵� ������ ���� Ȯ��
//			if (0 <= nextInfo[i] && MaxPosition >= nextInfo[i] && 0 == visited[nextInfo[i]])
//			{
//				q.push(nextInfo[i]);
//				visited[nextInfo[i]] = visited[curIndex] + 1;
//				// Index ���� ������ ���Ŀ� ��ġ�� �ľ��ؼ� ��Ž���� ����
//				prevIndex[nextInfo[i]] = curIndex;
//			}
//		}
//	}
//
//	// ������������ �����ؼ� ������������ Index�� ��Ž�� ������ ��ȸ
//	for (int i = k; i != n; i = prevIndex[i]) cnt.push_back(i);
//	// �������� ���
//	cnt.push_back(n);
//	// �����̹Ƿ� ������
//	reverse(cnt.begin(), cnt.end());
//
//	cout << visited[k] - 1 << "\n";
//	for (int i : cnt) cout << i << " ";
//
//	return 0;
//}

// 9_���ٲ���5
// https://www.acmicpc.net/problem/17071
// �����̰� �̵��ϴ� �迭, ������ �̵��ϴ� �迭 ���� �����Ϸ��� ������ 500000�̶�� ��ġ�� �ſ� ŭ(���� ���⵵�� ���)
// ������ ��� Ȧ�� ¦���� ���� �̵� ��ġ�� �ٲ�(+1, +2, +3, +4, ...)
// ������ ��� +1, -1 �̵� ���� ���� ������ 3�ʿ� �Դٰ� ���� �� ������ 1�ʿ� �̸� �����ߴٸ� �Դ� ���� �������� ���� �� ����(��, Ȧ�� ¦�� �ð��� ��ġ�� ��)
// ���� �����̿� ������ ���� ���� ���� �����̰� ���� �����ؼ� �Դٰ��ٷ� ������ �����ϴ� ��� ���
// �������� ��ġ�� Ȧ¦���� �����ϵ� ������ �̵� ��ġ�� �ľ��� �ʿ� ����
//const int MaxPosition = 500000;
//int MoveCount = 1, visited[2][MaxPosition + 1];		// visited[2][MaxPosition + 1] => [2]: Ȧ�� ¦������ �ش� ���� Ȯ�ο�, [MaxPosition + 1]: ���� ��ġ
//bool IsVisited;
//vector<int> cnt;
//
//int main()
//{
//	int n, k;
//	cin >> n >> k;
//	if (n == k)
//	{
//		cout << 0;
//		return 0;
//	}
//
//	queue<int> q;
//	q.push(n);
//	// ���� ���� ù �湮 ����
//	visited[0][n] = 1;
//
//	while (false == q.empty())
//	{
//		// �̵� ��ġ��ŭ ���� ��ġ ����
//		k += MoveCount;
//
//		if (MaxPosition < k) break;
//		// ���� ¦��(, Ȧ�� �Ͽ� ���缭)�� �� ���� ��ġ�� �̸� �湮 �ߴٸ� �Դٰ��ٷ� ���� �� �����Ƿ� IsVisited�� true
//		if (0 != visited[MoveCount % 2][k])
//		{
//			IsVisited = true;
//			break;
//		}
//
//		// Flood Fill Algorithm(�÷��� �� �˰���)
//		// Leveling ������ �ʿ��� ����?
//		// for���� q.size()�� ������� �� q�� ����� ���ϰ� �Ǹ鼭 ������ ��Ʋ���� ��
//		// ���� �� Ž�� ������ �ľ��� ���� �̸� ����� �޾Ƽ� ���
//		int Leveling = q.size();
//		for (int i = 0; i < Leveling; ++i)
//		{
//			int curIndex = q.front();
//			q.pop();
//
//			int nextInfo[] = { curIndex - 1, curIndex + 1, curIndex * 2 };
//			for (int i = 0; i < 3; ++i)
//			{
//				// �̵� ������ ���� Ȯ��
//				if (0 <= nextInfo[i] && MaxPosition >= nextInfo[i] && 0 == visited[MoveCount % 2][nextInfo[i]])
//				{
//					// + 1�� �ϴ� ����? => ¦���� �湮�ߴٸ� ������ Ȧ���� �湮
//					// ���� 2�ʿ� �湮�ߴٸ� ������ 3�ʰ� �Ǵϱ�?!
//					visited[MoveCount % 2][nextInfo[i]] = visited[(MoveCount + 1) % 2][curIndex] + 1;
//
//					// ������ ��ġ�� �����ϴٸ�
//					if (k == nextInfo[i])
//					{
//						IsVisited = true;
//						break;
//					}
//
//					q.push(nextInfo[i]);
//				}
//			}
//
//			if (true == IsVisited) break;
//		}
//
//		if (true == IsVisited) break;
//		++MoveCount;
//	}
//
//	// ���� ���� ������ -1, ������ �̵��� �� ���
//	MoveCount = true == IsVisited ? MoveCount : -1;
//	cout << MoveCount;
//
//	return 0;
//}

// 10_�ֳ��� ��(��)
// https://www.acmicpc.net/problem/14497
// *: �ֳ��� ��ġ, #: ���ڹٸ� ���� �л�
// 0: �̵�����, 1: �ð��� ���� �̵� ������ �κ�
// 0�̸� �� �����̹Ƿ� �ش� ��ġ 4�������� Ȯ��(?)�Ǿ� 1�� ������ 1�� 0���� �ٲٰ� ����
// N: ����, M: ���� ���� ũ��
//int N, M, JumpCount = 1, visited[301][301];
//pair<int, int> JPos, CPos;
//char JClass[301][301];
//int dy[] = { -1, 0, 1, 0 };
//int dx[] = { 0, 1, 0, -1 };
//
//int main()
//{
//	cin >> N >> M;
//	cin >> JPos.second >> JPos.first >> CPos.second >> CPos.first;
//
//	for (int i = 1; i <= N; ++i)
//	{
//		string str = "";
//		cin >> str;
//		for (int j = 1; j <= str.size(); ++j) JClass[i][j] = str[j - 1];
//	}
//
//	queue<pair<int, int>> q;
//	q.push({ JPos.second, JPos.first });
//	visited[JPos.second][JPos.first] = 1;
//	
//	// ��ǥ ������ '0'�� �� ������ �ݺ�
//	while ('0' != JClass[CPos.second][CPos.first])
//	{
//		// ���� Ž���� ���� ��Ƴ��� ť �ڷᱸ��
//		queue<pair<int, int>> nextq;
//
//		while (false == q.empty())
//		{
//			int y = q.front().first;
//			int x = q.front().second;
//			q.pop();
//			
//			for (int i = 0; i < 4; ++i)
//			{
//				int ny = y + dy[i];
//				int nx = x + dx[i];
//
//				if (1 > ny || 1 > nx || N < ny || M < nx || 0 != visited[ny][nx]) continue;
//
//				visited[ny][nx] = JumpCount;
//				// ���� '1'�� ģ���� �����Ѵٸ� '0'���� ����
//				// nextq�� �߰�
//				if ('0' != JClass[ny][nx])
//				{
//					JClass[ny][nx] = '0';
//					nextq.push({ ny, nx });
//				}
//				// '0'�̶�� q�� �߰�
//				else q.push({ ny, nx });
//			}
//		}
//
//		// '0' Ž�� ���� ���� jump�� Ž�� ������ ���� �ش� ������ q�� ����
//		q = nextq;
//		// ���� ī��Ʈ ����
//		++JumpCount;
//	}
//
//	cout << visited[CPos.second][CPos.first];
//
//	return 0;
//}

// 11_������ ȣ��
// https://www.acmicpc.net/problem/3197
// �Ϸ� �������� ���� ����ִ� ������ ��´�(�����¿��̸� �밢���� ���X)
// R: ��, C: ��
//const int Max_num = 1501;
//int R, C, day, Svisited[Max_num][Max_num], Wvisited[Max_num][Max_num];
//int SwanY, SwanX, CurY, CurX;
//char Lake[Max_num][Max_num];
//queue<pair<int, int>> WaterQ, SwanQ, Water_NextQ, Swan_NextQ;   // BFS, Flood Fill�� ����� �� ť 2��
//int dy[4] = { 0, 1, 0, -1 };
//int dx[4] = { 1, 0, -1, 0 };
//
//// ť�� Ŭ���� ���ִ� ����� �����Ƿ� �����Ͽ� ������ �ٲ�
//void Qclear(queue<pair<int, int>>& Inq) 
//{
//    queue<pair<int, int>> EmptyQ;
//    // �� ť�� ��ü�Ͽ� ť�� ���
//    swap(Inq, EmptyQ); 
//}
//
//void IceMelting() 
//{
//    while (false == WaterQ.empty())
//    {
//        tie(CurY, CurX) = WaterQ.front();
//        WaterQ.pop();
//
//        for (int i = 0; i < 4; ++i) 
//        {
//            int ny = CurY + dy[i];
//            int nx = CurX + dx[i];
//
//            if (0 > ny || 0 > nx || R < ny || C < nx || 0 != Wvisited[ny][nx]) continue;
//            
//            // ���� �̵��� ���϶�� ���� ����
//            if ('X' == Lake[ny][nx])
//            {
//                Wvisited[ny][nx] = 1;
//                Lake[ny][nx] = '.';
//                Water_NextQ.push({ ny, nx });
//            }
//        }
//    }
//}
//
//bool MoveAndMeet() 
//{
//    while (false == SwanQ.empty())
//    {
//        tie(CurY, CurX) = SwanQ.front();
//        SwanQ.pop();
//
//        for (int i = 0; i < 4; ++i) 
//        {
//            int ny = CurY + dy[i];
//            int nx = CurX + dx[i];
//
//            if (0 > ny || 0 > nx || R < ny || C < nx || 0 != Svisited[ny][nx]) continue;
//
//            Svisited[ny][nx] = 1;
//            // ���� �̵��� ���̶�� ����ť�� �߰�
//            if ('.' == Lake[ny][nx]) SwanQ.push({ny, nx});
//            // ���� �̵��� ���϶�� ����ť�� �߰�
//            else if ('X' == Lake[ny][nx]) Swan_NextQ.push({ny, nx});
//            // ���� �̵��� ������ �ִٸ� �������Ƿ� true
//            else if ('L' == Lake[ny][nx]) return true;
//        }
//    }
//
//    // ������� ���� ������ ���� ���
//    return false;
//}
//
//int main() 
//{
//    cin >> R >> C;
//    for (int i = 0; i < R; ++i)
//    {
//        string str = "";
//        cin >> str;
//        for (int j = 0; j < C; ++j) 
//        {
//            Lake[i][j] = str[j];
//
//            if ('L' == Lake[i][j] || '.' == Lake[i][j])
//            {
//                if ('L' == Lake[i][j])
//                {
//                    SwanY = i;
//                    SwanX = j;
//                }
//
//                Wvisited[i][j] = 1;
//                WaterQ.push({ i, j });                          // �� ť �߰�
//            }
//        }
//    }
//
//    SwanQ.push({ SwanY, SwanX });
//    Svisited[SwanY][SwanX] = 1;
//
//    while (true) 
//    {
//        // �� ������ ������ ����
//        if (true == MoveAndMeet()) break;
//        
//        // �Ϸ� ���� ���� ���̱�
//        IceMelting();
//        
//        // ť ������Ʈ(���� ��� ������, ���� �̵�)
//        WaterQ = Water_NextQ;
//        SwanQ = Swan_NextQ;
//        
//        // ť ����
//        Qclear(Water_NextQ);
//        Qclear(Swan_NextQ);
//        
//        // �Ϸ� ���
//        ++day;
//    }
//
//    cout << day;
//
//    return 0;
//}

// 12_���ĺ�
// https://www.acmicpc.net/problem/1987
// ĭ���� �빮�� ����, ���� 4���� �̵� ���� ���ݱ��� ������ ĭ�� �ٸ� ���ĺ� ĭ�� �̵� ����
// ���� ������ �»��(1,1), �ִ� �� ĭ �̵� �����Ѱ�
// ���ĺ� �湮 �迭�� �ش� ���ĺ��� �湮�ߴ��� ���θ� Ȯ���Ͽ� Ž��
// R: ����, C: ����
//int R, C, visited[30];
//char Board[21][21];
//int dy[] = { -1, 0, 1, 0 };
//int dx[] = { 0, 1, 0, -1 };
//
//int DFS(int y, int x)
//{
//	int value = 0;
//
//	for (int i = 0; i < 4; ++i)
//	{
//		int ny = y + dy[i];
//		int nx = x + dx[i];
//
//		if (0 > ny || 0 > nx || R <= ny || C <= nx) continue;
//		if (0 != visited[Board[ny][nx] - 'A']) continue;
//
//		// �湮 üũ
//		visited[Board[ny][nx] - 'A'] = 1;
//		// ��� �� ��ȯ ī��Ʈ�� ���� �ִ�� Ž���� ���� ���ϱ�
//		value = max(value, DFS(ny, nx));
//		// �湮 ����
//		visited[Board[ny][nx] - 'A'] = 0;
//	}
//
//	// ������ġ �����Ͽ� ��ȯ
//	return value + 1;
//}
//
//int main()
//{
//	cin >> R >> C;
//	for (int i = 0; i < R; ++i)
//	{
//		for (int j = 0; j < C; ++j) cin >> Board[i][j];
//	}
//
//	visited[Board[0][0]- 'A'] = 1;
//
//	cout << DFS(0, 0);
//
//	return 0;
//}

// 13_�ε�ȣ
// https://www.acmicpc.net/problem/2529
// �־��� �ε�ȣ ������ �°� ���ڰ� �����Ǵ� �͵��� ��� �ּ� �ִ�
// k: �ε�ȣ ����
//int k, number[10];
//char sign[10];
//vector<string> ret;
//
//// ��ȣ�� �ùٸ��� �Ǿ����� Ȯ���Ͽ� ��ȯ
//bool Check(char Left, char Right, char Oper)
//{
//	if (Left < Right && '<' == Oper) return true;
//	if (Left > Right && '>' == Oper) return true;
//
//	return false;
//}
//
//void Make(int Index, string strNum)
//{
//	// �ε�ȣ �� => ���� ���� ���� ������
//	if (k + 1 == Index)
//	{
//		ret.push_back(strNum);
//		return;
//	}
//
//	for (int i = 0; i < 10; ++i)
//	{
//		// �̹� ����� ���ڸ� ����
//		if (0 != number[i]) continue;
//
//		// �ε����� 0�̰ų� (���� ������) (�ε�ȣ) (�߰��� ����)�� ���� ���� ��
//		if (0 == Index || true == Check(strNum[Index - 1], i + '0', sign[Index - 1]))
//		{
//			// (�߰��� ����) ��� üũ
//			number[i] = 1;
//			// ��Ž ���� �����(�ε��� ����, ���� ���� + �߰��� ���� �ѱ��)
//			Make(Index + 1, strNum + to_string(i));
//			// (�߰��� ����) ��� ���� => ���� �۾�
//			number[i] = 0;
//		}
//	}
//}
//
//int main()
//{
//	cin >> k;
//	for (int i = 0; i < k; ++i) cin >> sign[i];
//
//	// ��Ž ���� �����(�ε��� ��� Ž��)
//	Make(0, "");
//	// ����
//	sort(ret.begin(), ret.end());
//
//	// �ִ� �ּ� ���
//	cout << ret[ret.size() - 1] << "\n" << ret[0];
//
//	return 0;
//}

// 14_���� ���� Ʈ��
// https://www.acmicpc.net/problem/9934
// 1)���� ó�� Ʈ���� ��Ʈ�� �ִ� ���� ��
// 2)���� ������ ���� �ڽĿ� �ִ� ������ ���� ���� �ʾҴٸ�, ���� �ڽ����� �̵�
// 3)���� �ִ� ��尡 ���� �ڽ��� ������ ���� �ʰų� ���� �ڽĿ� �ִ� ������ �̹� ���ٸ�, ���� ��忡 �ִ� ���� ����, ���̿� ��ȣ ���
// 4)���� ������ �̹� ���� �� �����̰�, ������ �ڽ��� ������ �ִ� ��� ������ �ڽ� �̵�
// 5)���� ������ ����, ������ �ڽĿ� �ִ� ������ ��� �湮�ߴٸ�, �θ� ���� �̵�
// ���� ��ȸ ���
// ��� ������ ��ȣ�� �ߺ�X, 1 ~ 2^K - 1, �� K�� 1 ~ 10�̹Ƿ� ���� �ִ� ���ڴ� 2^10 - 1
// K: ���� ���� Ʈ�� ����
//int K, Building[1025];
//vector<int> ret[11];			// ���� �� ���� ���� �ľ�
//
//void Go(int StartIndex, int EndIndex, int Depth)
//{
//	if (StartIndex > EndIndex) return;
//	if (StartIndex == EndIndex)
//	{
//		ret[Depth].push_back(Building[StartIndex]);
//		return;
//	}
//
//	// ������ �������� ���� �ľ�
//	int Mid = (StartIndex + EndIndex) / 2;
//	ret[Depth].push_back(Building[Mid]);
//
//	// ���� �ڽ� Ž��
//	Go(StartIndex, Mid - 1, Depth + 1);
//	// ������ �ڽ� Ž��
//	Go(Mid + 1, EndIndex, Depth + 1);
//}
//
//int main()
//{
//	cin >> K;
//	int LastBuildingNum = static_cast<int>(pow(2, K)) - 1;
//	for (int i = 0; i < LastBuildingNum; ++i) cin >> Building[i];
//
//	Go(0, LastBuildingNum, 1);
//
//	for (int i = 1; i <= K; ++i)
//	{
//		for (int j : ret[i]) cout << j << " ";
//
//		cout << "\n";
//	}
//
//	return 0;
//}

// 15_��ٸ� ����
// https://www.acmicpc.net/problem/15684
// ���� ���� ���� ���� ���� �����
// �� �� �߰��ؾ��ϴ� ���μ��� �ּ� ����
// N: ���μ�, M: ���μ�, H: ���μ����� ���μ� ���� �� �ִ� ��ġ ����
//const int inf = 987654321;
//int n, m, h, a, b, ret = inf, visited[31][31];
//
//// ���۰� ������ ���� ������ �Ǻ�
//bool check()
//{
//	for (int i = 1; i <= n; ++i)
//	{
//		// ��ġ ������ �ľ��ϱ� ���� pos ����
//		int pos = i;
//		for (int j = 1; j <= h; ++j)
//		{
//			// ��ġ�� ���� ��ٸ��� ���� ����(������ ++, ���� --)
//			if (0 != visited[j][pos]) ++pos;
//			else if (0 != visited[j][pos - 1]) --pos;
//		}
//
//		// ���� ������ �ٸ� ��� false
//		if (i != pos) return false;
//	}
//
//	return true;
//}
//
//void move(int here, int cnt)
//{
//	// 3 Ȥ�� ���� �ּҰ����� Ŭ ��� return
//	if (3 < cnt || ret <= cnt) return;
//	if (true == check())
//	{
//		ret = min(ret, cnt);
//		return;
//	}
//
//	for (int i = here; i <= h; ++i)
//	{
//		for (int j = 1; j < n; ++j)
//		{
//			// ��ٸ� ���� ���� �Ұ�(����)
//			if (0 != visited[i][j] || 0 != visited[i][j - 1] || 0 != visited[i][j + 1]) continue;
//
//			// ��ٸ� ����
//			visited[i][j] = 1;
//			move(i, cnt + 1);
//			// ��ٸ� ����
//			visited[i][j] = 0;
//		}
//	}
//}
//
//int main()
//{
//	cin >> n >> m >> h;
//
//	// ��ٸ� �����
//	for (int i = 0; i < m; ++i)
//	{
//		cin >> a >> b;
//		visited[a][b] = 1;;
//	}
//
//	// ��ٸ� ���� ����
//	move(1, 0);
//
//	cout << (inf == ret ? -1 : ret) << "\n";
//
//	return 0;
//}

// 16_�ɱ�
// https://www.acmicpc.net/problem/14620
// �����¿�� ������ �������� ��ĥ ��� ����
// 3���� ������ �ּ� ������� �� �ǿ��
// ���� Ž���ϵ� ���� �ǿ� �� �ִ��� Ȯ���ϰ� ������ �������� �ǿ��� �� ��� ���� �� ���� �۾� ó�� �ʿ�
// n: ȭ�� �� ���� ����
int n, ret = 987654321, ground[11][11];
bool bloomed[11][11];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

// �� �ǿ�� �������� Ȯ��
bool check(int y, int x)
{
	// �̹� �Ǿ��ִ� ���̸� �Ұ���
	if (true == bloomed[y][x]) return false;

	// ���� 4���� Ȯ��
	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		// ���� ��Ż �� �Ǿ� �ִ� ���̸� �Ұ���
		if (0 > ny || 0 > nx || n <= ny || n <= nx || true == bloomed[ny][nx]) return false;
	}

	return true;
}

// y, x �������� �� �ǿ��� �� ��� ����
int cost(int y, int x)
{
	// �� �ǿ� ó��
	bloomed[y][x] = true;

	// ���� �Ѹ� ���� ���
	int totalcost = ground[y][x];
	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		// ���� �ǿ� ó��
		bloomed[ny][nx] = true;
		// �ǿ��� ���� �ڸ� ��� �߰�
		totalcost += ground[ny][nx];
	}

	// ���� ��� ��ȯ
	return totalcost;
}

// �� �� �ڸ� ���� �۾� ó��
void eraseFlower(int y, int x)
{
	// �ǿ� �ڸ� ����
	bloomed[y][x] = false;

	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		// ��� ���� �ڸ� ����
		bloomed[ny][nx] = false;
	}
}

void flower(int cnt, int curcost)
{
	// ���� 3�� ��� �ѷ��� �� �ּ� ��� ����
	if (3 == cnt)
	{
		ret = min(ret, curcost);
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			// �� �Ǳ� �Ұ����� ���̸� ����
			if (false == check(i, j)) continue;
			
			// �� ī��Ʈ �� ��� ���� �� ��� �� �ǿ��
			flower(cnt + 1, curcost + cost(i, j));
			// ����
			eraseFlower(i, j);
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> ground[i][j];
		}
	}

	flower(0, 0);

	cout << ret;

	return 0;
}