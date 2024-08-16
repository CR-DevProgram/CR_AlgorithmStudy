#include <bits/stdc++.h>

using namespace std;

// ����Ž��_Lv2 �Ƿε�
bool visited[10];
int cnt = -1;

void Enter(int energy, int count, const vector<vector<int>>& dungeons)
{
    // ���� �ִ� �湮�� ������Ʈ
    cnt = max(cnt, count);

    for (int i = 0; i < dungeons.size(); ++i)
    {
        // �湮 ������ ����
        if (true == visited[i]) continue;

        // �ּ� �ʿ� �Ƿε��� �Ǵ� ���
        if (dungeons[i][0] <= energy)
        {
            // �湮 ���
            visited[i] = true;
            // ���� Ž��
            Enter(energy - dungeons[i][1], count + 1, dungeons);
            // �湮 ����
            visited[i] = false;
        }
    }
}

//int solution(int k, vector<vector<int>> dungeons)
//{
//    Enter(k, 0, dungeons);
//
//    return cnt;
//}

// ����Ž��_Lv2 ���� ����
// �̷��� Ǫ�°� �ƴѰ� ���⵵.. �ð��� ���� ���� �ɸ�
char ch[5] = { 'A', 'E', 'I', 'O', 'U' };
int cnt;
bool bIsFind = false;

void check(const string& word, string str, int depth)
{
    // ���� Ȯ��
    if (5 < depth) return;
    // ���� ���� Ȯ��
    if (word == str)
    {
        bIsFind = true;
        return;
    }

    ++cnt;

    for (int i = 0; i < 5; ++i)
    {
        // ���� ���� ã���� �� ��ȸ Ż��
        if (true == bIsFind) break;

        check(word, str + ch[i], depth + 1);
    }
}

int solution(string word)
{
    check(word, "", 0);

    return cnt;
}

int main(void)
{
    // ����Ž��_Lv2 �Ƿε�
    //solution(80, { {80, 20},{50, 40},{30, 10} });                                   // 3
    //solution(40, { {40, 20},{10, 10},{10, 10},{10, 10},{10, 10} });                 // 4
    //solution(100, { {100, 1},{99, 1},{99, 1},{99, 1},{99, 1},{99, 1},{99, 1} });    // 2

    // ����Ž��_Lv2 ���� ����
    solution("AAAAE");      // 6
    solution("AAAE");       // 10
    solution("I");          // 1563
    solution("EIO");        // 1189

    return 0;
}