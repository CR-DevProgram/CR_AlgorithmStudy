#include <bits/stdc++.h>

using namespace std;

// 완전탐색_Lv2 피로도
bool visited[10];
int cnt = -1;

void Enter(int energy, int count, const vector<vector<int>>& dungeons)
{
    // 던전 최대 방문수 업데이트
    cnt = max(cnt, count);

    for (int i = 0; i < dungeons.size(); ++i)
    {
        // 방문 했으면 무시
        if (true == visited[i]) continue;

        // 최소 필요 피로도가 되는 경우
        if (dungeons[i][0] <= energy)
        {
            // 방문 기록
            visited[i] = true;
            // 던전 탐사
            Enter(energy - dungeons[i][1], count + 1, dungeons);
            // 방문 복원
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons)
{
    Enter(k, 0, dungeons);

    return cnt;
}

int main(void)
{
    // 완전탐색_Lv2 피로도
    solution(80, { {80, 20},{50, 40},{30, 10} });                                   // 3
    solution(40, { {40, 20},{10, 10},{10, 10},{10, 10},{10, 10} });                 // 4
    solution(100, { {100, 1},{99, 1},{99, 1},{99, 1},{99, 1},{99, 1},{99, 1} });    // 2

    return 0;
}