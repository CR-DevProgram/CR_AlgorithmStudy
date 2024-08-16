#include <bits/stdc++.h>

using namespace std;

// ����Ž��_Lv2 �Ƿε�
//bool visited[10];
//int cnt = -1;
//
//void Enter(int energy, int count, const vector<vector<int>>& dungeons)
//{
//    // ���� �ִ� �湮�� ������Ʈ
//    cnt = max(cnt, count);
//
//    for (int i = 0; i < dungeons.size(); ++i)
//    {
//        // �湮 ������ ����
//        if (true == visited[i]) continue;
//
//        // �ּ� �ʿ� �Ƿε��� �Ǵ� ���
//        if (dungeons[i][0] <= energy)
//        {
//            // �湮 ���
//            visited[i] = true;
//            // ���� Ž��
//            Enter(energy - dungeons[i][1], count + 1, dungeons);
//            // �湮 ����
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

// ����Ž��_Lv2 ���� ����
// �̷��� Ǫ�°� �ƴѰ� ���⵵.. �ð��� ���� ���� �ɸ�
//char ch[5] = { 'A', 'E', 'I', 'O', 'U' };
//int cnt;
//bool bIsFind = false;
//
//void check(const string& word, string str, int depth)
//{
//    // ���� Ȯ��
//    if (5 < depth) return;
//    // ���� ���� Ȯ��
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
//        // ���� ���� ã���� �� ��ȸ Ż��
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

// ����Ž��_Lv2 ī��
//vector<int> solution(int brown, int yellow)
//{
//    vector<int> answer;
//
//    // ���� �簢���� yellow ����ŭ �ݺ�
//    for (int i = 1; i <= yellow; ++i)
//    {
//        // ������ �������� ������ ����
//        if (0 != yellow % i) continue;
//
//        // ����(���ΰ� �� �� �簢���̹Ƿ� �� ��)
//        int x = yellow / i;
//        // ����
//        int y = i;
//        // �׵θ� ���� brown�� ���� ���
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

// ����Ž��_Lv2 �Ҽ� ã��
bool visited[8];
// �ߺ� ���� ���� set ���
set<int> ret;

// �Ҽ� �Ǻ�
bool check(int n)
{
    if (1 >= n) return false;
    if (2 == n) return true;
    if (0 == n % 2) return false;

    for (int i = 2; i * i <= n; ++i)
    {
        if (0 == n % i) return false;
    }

    return true;
}

void make(const string& numbers, string str)
{
    // �Ǻ� ���ڰ� ������� �ʰ� �Ҽ��� ���
    if (false == str.empty() && true == check(stoi(str)))
    {
        ret.insert(stoi(str));
    }

    for (int i = 0; i < numbers.size(); ++i)
    {
        if (true == visited[i]) continue;

        visited[i] = true;
        make(numbers, str + numbers[i]);
        visited[i] = false;
    }
}

int solution(string numbers)
{
    make(numbers, "");

    return ret.size();
}

// DFS/BFS_Lv2 Ÿ�� �ѹ�
//int cnt;
//
//void cal(const vector<int>& numbers, const int& target, int num, int index)
//{
//    // �������(������ Ȯ��)
//    if (numbers.size() == index)
//    {
//        // Ÿ�ٰ� �����ϸ� ī��Ʈ ����
//        if (target == num) ++cnt;
//        return;
//    }
//
//    // ���
//    cal(numbers, target, num + numbers[index], index + 1);
//    // ����
//    cal(numbers, target, num - numbers[index], index + 1);
//}
//
//int solution(vector<int> numbers, int target)
//{
//    cal(numbers, target, 0, 0);
//
//    return cnt;
//}

int main(void)
{
    // ����Ž��_Lv2 �Ƿε�
    //solution(80, { {80, 20},{50, 40},{30, 10} });                                   // 3
    //solution(40, { {40, 20},{10, 10},{10, 10},{10, 10},{10, 10} });                 // 4
    //solution(100, { {100, 1},{99, 1},{99, 1},{99, 1},{99, 1},{99, 1},{99, 1} });    // 2

    // ����Ž��_Lv2 ���� ����
    //solution("AAAAE");      // 6
    //solution("AAAE");       // 10
    //solution("I");          // 1563
    //solution("EIO");        // 1189

    // ����Ž��_Lv2 ī��
    //solution(10, 2);        // 4, 3
    //solution(8, 1);         // 3, 3
    //solution(24, 24);       // 8, 6

    // ����Ž��_Lv2 �Ҽ� ã��
    solution("17");         // 3
    solution("011");        // 2

    // DFS/BFS_Lv2 Ÿ�� �ѹ�
    //solution({ 1, 1, 1, 1, 1 }, 3);     // 5
    //solution({ 4, 1, 2, 1 }, 4);        // 2

    return 0;
}