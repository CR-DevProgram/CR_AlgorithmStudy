#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

// �ؽ�_L1 ���ϸ�
//int solution(vector<int> nums)
//{
//    int answer = 0;
//    // ������ �� �ִ� �ִ� ���ϸ� ��
//    int iMaxPokemon = nums.size() / 2;
//    // �ߺ��� ���ϸ��� ���ֱ� ���� set �ؽ�
//    set<int> sPokemon;
//
//    for (int i = 0; i < nums.size(); ++i)
//    {
//        sPokemon.insert(nums[i]);
//    }
//
//    // ���� �� �ִ� �ִ� ���ϸ� ��
//    int iGetablePokemon = sPokemon.size();
//
//    // ���� �� �ִ� �ִ� ���ϸ� ���� ������ �� �ִ� �ִ� ���ϸ� ������ ������,
//    // ���� �� �ִ� �ִ� ���ϸ� ��
//    // ���� �� �ִ� �ִ� ���ϸ� ���� ������ �� �ִ� �ִ� ���ϸ� ������ ũ�ų� ������,
//    // �ִ� ���ϸ� ��
//    answer = iGetablePokemon < iMaxPokemon ? iGetablePokemon : iMaxPokemon;
//
//    cout << answer << endl;
//
//    return answer;
//}

// ����Ž��_L1 ���ǰ��
//int num1[] = { 1,2,3,4,5 };
//int num2[] = { 2,1,2,3,2,4,2,5 };
//int num3[] = { 3,3,1,1,2,2,4,4,5,5 };
//int cnt[3] = { 0,0,0 };
//
//vector<int> solution(vector<int> answers)
//{
//    vector<int> answer;
//
//    for (int i = 0; i < answers.size(); ++i)
//    {
//        // �л��� ��� �ݺ�üũ �� �� �ְ� % ��� �� ����� �� ī��Ʈ ����
//        if (answers[i] == num1[i % 5]) ++cnt[0];
//        if (answers[i] == num2[i % 8]) ++cnt[1];
//        if (answers[i] == num3[i % 10]) ++cnt[2];
//    }
//
//    // ���������� ���� ���� ���� ã��
//    int imax = *max_element(cnt, cnt + 3);
//
//    for (int i = 0; i < 3; ++i)
//    {
//        // ���� ������ �����ϸ� �߰�
//        if (imax == cnt[i]) answer.push_back(i + 1);
//    }
//
//    return answer;
//}

//int main(void)
//{
//    // �ؽ�_L1 ���ϸ�
//    //solution({ 3, 1, 2, 3 });           // 2
//    //solution({ 3, 3, 3, 2, 2, 4 });     // 3
//    //solution({ 3, 3, 3, 2, 2, 2 });     // 2
//
//    // ����Ž��_L1 ���ǰ��
//    //solution({ 1,2,3,4,5 });        // 1
//    //solution({ 1,3,2,4,2 });        // 1, 2, 3
//
//    return 0;
//}