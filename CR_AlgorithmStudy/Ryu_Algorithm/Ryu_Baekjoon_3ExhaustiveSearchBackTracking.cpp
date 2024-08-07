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
const int MaxPosition = 100000;
int visited[MaxPosition + 1], prevIndex[MaxPosition + 1];
vector<int> cnt;

int main()
{
	int n, k;
	cin >> n >> k;

	queue<int> q;
	q.push(n);
	visited[n] = 1;

	while (false == q.empty())
	{
		int curIndex = q.front();
		q.pop();

		if (k == curIndex) break;

		int nextInfo[] = { curIndex - 1, curIndex + 1, curIndex * 2 };
		for (int i = 0; i < 3; ++i)
		{
			// �̵� ������ ���� Ȯ��
			if (0 <= nextInfo[i] && MaxPosition >= nextInfo[i] && 0 == visited[nextInfo[i]])
			{
				q.push(nextInfo[i]);
				visited[nextInfo[i]] = visited[curIndex] + 1;
				// Index ���� ������ ���Ŀ� ��ġ�� �ľ��ؼ� ��Ž���� ����
				prevIndex[nextInfo[i]] = curIndex;
			}
		}
	}

	// ������������ �����ؼ� ������������ Index�� ��Ž�� ������ ��ȸ
	for (int i = k; i != n; i = prevIndex[i]) cnt.push_back(i);
	// �������� ���
	cnt.push_back(n);
	// �����̹Ƿ� ������
	reverse(cnt.begin(), cnt.end());

	cout << visited[k] - 1 << "\n";
	for (int i : cnt) cout << i << " ";

	return 0;
}