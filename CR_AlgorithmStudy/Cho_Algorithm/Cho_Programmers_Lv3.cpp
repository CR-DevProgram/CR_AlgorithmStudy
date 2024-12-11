// 징검다리 건너기
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int solution(vector<int> stones, int k)
//{
//    int left = 1, right = *max_element(stones.begin(), stones.end());
//
//    while (left <= right)
//    {
//        int mid = (left + right) / 2;
//        int zeroCnt = 0;
//        bool canCross = true;
//
//        for (int stone : stones)
//        {
//            if (stone - mid <= 0)
//            {
//                ++zeroCnt;
//                if (zeroCnt >= k)
//                {
//                    canCross = false;
//                    break;
//                }
//            }
//            else zeroCnt = 0;
//        }
//
//        if (canCross)
//        {
//            left = mid + 1;
//        }
//        else
//        {
//            right = mid - 1;
//        }
//    }
//
//    return left;
//}

//#include <string>
//#include <vector>
//#include <iostream>
//
//using namespace std;
//
//// 오 -> 아 -> 왼 -> 위
//int dx[4] = { 0, 1, 0, -1 };
//int dy[4] = { 1, 0, -1, 0 };
//
//vector<vector<int>> rotate(vector<vector<int>>& v, const vector<int>& query)
//{
//    int x1 = query[0], y1 = query[1], x2 = query[2], y2 = query[3];
//    int idx = 0;
//    int cx = x1;
//    int cy = y1;
//    while (true)
//    {
//        int nx = cx + dx[idx];
//        int ny = cy + dy[idx];
//        if (nx > x2 || ny > y2 || nx < x1 || ny < y1)
//        {
//            idx = (idx + 1) % 4;
//            nx = cx + dx[idx];
//            ny = cy + dy[idx];
//        }
//
//        cout << idx << ' ' << nx << ' ' << ny << '\n';
//
//        cx = nx;
//        cy = ny;
//
//        if (cx == x1 && cy == y1) break;
//    }
//
//    return v;
//}
//
//vector<int> solution(int rows, int columns, vector<vector<int>> queries)
//{
//    // 모든 숫자를 넣는다.
//    vector<vector<int>> v(rows + 1, vector<int>(columns + 1, 0));
//    int num = 1;
//    for (int i = 1; i <= rows; i++)
//    {
//        for (int j = 1; j <= columns; j++)
//        {
//            v[i][j] = num++;
//        }
//    }
//
//    for (auto query : queries)
//    {
//        rotate(v, query);
//    }
//
//    vector<int> answer;
//    return answer;
//}
//
//int main()
//{
//    solution(6, 6, { {2, 2, 5, 4} });
//}

// [카카오 인턴] 경주로 건설
// https://school.programmers.co.kr/learn/courses/30/lessons/67259

#include <string>
#include <vector>
#include <queue>
#include <limits.h>
#include <iostream>

using namespace std;

int dx[4] = { 0, 1, -1, 0 };
int dy[4] = { 1, 0, 0, -1 };

struct Node
{
    int x, y, direction, cost;
};

int solution(vector<vector<int>> board) 
{
    vector<vector<vector<int>>> cost(board.size(), vector<vector<int>>(board.size(), vector<int>(4, INT_MAX)));
    queue<Node> q;
    q.push({ 0, 0, -1, 0 });

    for (int i = 0; i < 4; i++)
    {
        cost[0][0][i] = 0;
    }

    while (!q.empty())
    {
        Node curNode = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = curNode.x + dx[i];
            int ny = curNode.y + dy[i];
            int newCost = curNode.cost;

            if (nx < 0 || ny < 0 || nx >= board.size() || ny >= board.size() || board[nx][ny] == 1) continue;

            if (curNode.direction == -1 || curNode.direction == i) newCost += 100;
            else newCost += 600;

            if (newCost < cost[nx][ny][i])
            {
                cost[nx][ny][i] = newCost;
                q.push({ nx, ny, i, newCost });
            }
        }
    }

    int answer = INT_MAX;
    for (int i = 0; i < 4; i++)
    {
        answer = min(answer, cost[board.size() - 1][board.size() - 1][i]);
    }

    return answer;
}