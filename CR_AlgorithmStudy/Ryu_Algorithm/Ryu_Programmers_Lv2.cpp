#include <bits/stdc++.h>

using namespace std;

// 완전탐색_Lv2 피로도
//bool visited[10];
//int cnt = -1;
//
//void Enter(int energy, int count, const vector<vector<int>>& dungeons)
//{
//    // 던전 최대 방문수 업데이트
//    cnt = max(cnt, count);
//
//    for (int i = 0; i < dungeons.size(); ++i)
//    {
//        // 방문 했으면 무시
//        if (true == visited[i]) continue;
//
//        // 최소 필요 피로도가 되는 경우
//        if (dungeons[i][0] <= energy)
//        {
//            // 방문 기록
//            visited[i] = true;
//            // 던전 탐사
//            Enter(energy - dungeons[i][1], count + 1, dungeons);
//            // 방문 복원
//            visited[i] = false;
//        }
//    }
//}
//
//int solution(int k, vector<vector<int>> dungeons)
//{
//    Enter(k, 0, dungeons);
//
//    return cnt;
//}

// 완전탐색_Lv2 모음 사전
// 이렇게 푸는게 아닌거 같기도.. 시간이 에법 오래 걸림
//char ch[5] = { 'A', 'E', 'I', 'O', 'U' };
//int cnt;
//bool bIsFind = false;
//
//void check(const string& word, string str, int depth)
//{
//    // 길이 확인
//    if (5 < depth) return;
//    // 동일 문자 확인
//    if (word == str)
//    {
//        bIsFind = true;
//        return;
//    }
//
//    ++cnt;
//
//    for (int i = 0; i < 5; ++i)
//    {
//        // 동일 문자 찾았을 시 순회 탈출
//        if (true == bIsFind) break;
//
//        check(word, str + ch[i], depth + 1);
//    }
//}
//
//int solution(string word)
//{
//    check(word, "", 0);
//
//    return cnt;
//}

// 완전탐색_Lv2 카펫
//vector<int> solution(int brown, int yellow)
//{
//    vector<int> answer;
//
//    // 내부 사각형인 yellow 수만큼 반복
//    for (int i = 1; i <= yellow; ++i)
//    {
//        // 나누어 떨어지지 않으면 무시
//        if (0 != yellow % i) continue;
//
//        // 가로(가로가 더 긴 사각형이므로 몫 값)
//        int x = yellow / i;
//        // 세로
//        int y = i;
//        // 테두리 수가 brown과 같은 경우
//        if (brown == (((x + 2) * 2) + (y * 2)))
//        {
//            answer.push_back(x + 2);
//            answer.push_back(y + 2);
//
//            break;
//        }
//    }
//
//    return answer;
//}

// 완전탐색_Lv2 소수 찾기
//bool visited[8];
//// 중복 방지 위해 set 사용
//set<int> ret;
//
//// 소수 판별
//bool check(int n)
//{
//    if (1 >= n) return false;
//    if (2 == n) return true;
//    if (0 == n % 2) return false;
//
//    for (int i = 2; i * i <= n; ++i)
//    {
//        if (0 == n % i) return false;
//    }
//
//    return true;
//}
//
//void make(const string& numbers, string str)
//{
//    // 판별 문자가 비어있지 않고 소수인 경우
//    if (false == str.empty() && true == check(stoi(str)))
//    {
//        ret.insert(stoi(str));
//    }
//
//    for (int i = 0; i < numbers.size(); ++i)
//    {
//        if (true == visited[i]) continue;
//
//        visited[i] = true;
//        make(numbers, str + numbers[i]);
//        visited[i] = false;
//    }
//}
//
//int solution(string numbers)
//{
//    make(numbers, "");
//
//    return ret.size();
//}

// DFS/BFS_Lv2 타겟 넘버
//int cnt;
//
//void cal(const vector<int>& numbers, const int& target, int num, int index)
//{
//    // 기저사례(마지막 확인)
//    if (numbers.size() == index)
//    {
//        // 타겟과 동일하면 카운트 증가
//        if (target == num) ++cnt;
//        return;
//    }
//
//    // 양수
//    cal(numbers, target, num + numbers[index], index + 1);
//    // 음수
//    cal(numbers, target, num - numbers[index], index + 1);
//}
//
//int solution(vector<int> numbers, int target)
//{
//    cal(numbers, target, 0, 0);
//
//    return cnt;
//}

// PCCP_Lv2 석유 시추
// 정확성 모두 통과, 효율성 모두 시간초과
// DFS로 사용하여 재귀 호출로 인한 시간 초과가 발생되는 것으로 추측 중
//int cnt = -1;
//int dy[] = { -1, 0, 1, 0 };
//int dx[] = { 0, 1, 0, -1 };
//
//int go(vector<vector<int>>& visited, const vector<vector<int>>& land, int y, int x)
//{
//    // 방문 기록
//    visited[y][x] = 1;
//    int scale = 0;
//
//    for (int i = 0; i < 4; ++i)
//    {
//        int ny = y + dy[i];
//        int nx = x + dx[i];
//
//        if (0 > ny || 0 > nx || land.size() <= ny || land[0].size() <= nx) continue;
//        if (0 == land[ny][nx] || 0 != visited[ny][nx]) continue;
//
//        // 커넥티드 컴포넌트 수 연산
//        scale += go(visited, land, ny, nx);
//    }
//
//    return scale + 1;
//}
//
//int solution(vector<vector<int>> land)
//{
//    for (int i = 0; i < land[0].size(); ++i)
//    {
//        // 방문 기록 변수 생성(초기화 작업을 위해 for문 내에서 생성)
//        vector<vector<int>> visited(land.size(), vector<int>(land[0].size()));
//        // i번째 땅을 시추해서 나오는 석유의 합을 위한 변수
//        int maxCheck = 0;
//
//        for (int j = 0; j < land.size(); ++j)
//        {
//            if (0 != land[j][i] && 0 == visited[j][i])
//            {
//                maxCheck += go(visited, land, j, i);
//            }
//        }
//
//        // 최대 갱신
//        cnt = max(cnt, maxCheck);
//    }
//
//    return cnt;
//}

//int main(void)
//{
//    // 완전탐색_Lv2 피로도
//    //solution(80, { {80, 20},{50, 40},{30, 10} });                                   // 3
//    //solution(40, { {40, 20},{10, 10},{10, 10},{10, 10},{10, 10} });                 // 4
//    //solution(100, { {100, 1},{99, 1},{99, 1},{99, 1},{99, 1},{99, 1},{99, 1} });    // 2
//
//    // 완전탐색_Lv2 모음 사전
//    //solution("AAAAE");      // 6
//    //solution("AAAE");       // 10
//    //solution("I");          // 1563
//    //solution("EIO");        // 1189
//
//    // 완전탐색_Lv2 카펫
//    //solution(10, 2);        // 4, 3
//    //solution(8, 1);         // 3, 3
//    //solution(24, 24);       // 8, 6
//
//    // 완전탐색_Lv2 소수 찾기
//    //solution("17");         // 3
//    //solution("011");        // 2
//
//    // DFS/BFS_Lv2 타겟 넘버
//    //solution({ 1, 1, 1, 1, 1 }, 3);     // 5
//    //solution({ 4, 1, 2, 1 }, 4);        // 2
//
//    // PCCP_Lv2 석유 시추
//    solution({ {0, 0, 0, 1, 1, 1, 0, 0},{0, 0, 0, 0, 1, 1, 0, 0},{1, 1, 0, 0, 0, 1, 1, 0},{1, 1, 1, 0, 0, 0, 0, 0},{1, 1, 1, 0, 0, 0, 1, 1} });             // 9
//    solution({ {1, 0, 1, 0, 1, 1},{1, 0, 1, 0, 0, 0},{1, 0, 1, 0, 0, 1},{1, 0, 0, 1, 0, 0},{1, 0, 0, 1, 0, 1},{1, 0, 0, 0, 0, 0},{1, 1, 1, 1, 1, 1} });     // 16
//
//    return 0;
//}