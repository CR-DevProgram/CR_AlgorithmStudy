#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

// 해시_L1 폰켓몬
//int solution(vector<int> nums)
//{
//    int answer = 0;
//    // 가져갈 수 있는 최대 폰켓몬 수
//    int iMaxPokemon = nums.size() / 2;
//    // 중복된 폰켓몬을 없애기 위한 set 해시
//    set<int> sPokemon;
//
//    for (int i = 0; i < nums.size(); ++i)
//    {
//        sPokemon.insert(nums[i]);
//    }
//
//    // 얻을 수 있는 최대 폰켓몬 수
//    int iGetablePokemon = sPokemon.size();
//
//    // 얻을 수 있는 최대 폰켓몬 수가 가져갈 수 있는 최대 폰켓몬 수보다 작으면,
//    // 얻을 수 있는 최대 폰켓몬 수
//    // 얻을 수 있는 최대 폰켓몬 수가 가져갈 수 있는 최대 폰켓몬 수보다 크거나 같으면,
//    // 최대 폰켓몬 수
//    answer = iGetablePokemon < iMaxPokemon ? iGetablePokemon : iMaxPokemon;
//
//    cout << answer << endl;
//
//    return answer;
//}

// 완전탐색_L1 모의고사
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
//        // 학생별 답안 반복체크 할 수 있게 % 사용 및 정답시 각 카운트 증가
//        if (answers[i] == num1[i % 5]) ++cnt[0];
//        if (answers[i] == num2[i % 8]) ++cnt[1];
//        if (answers[i] == num3[i % 10]) ++cnt[2];
//    }
//
//    // 최종적으로 제일 높은 점수 찾기
//    int imax = *max_element(cnt, cnt + 3);
//
//    for (int i = 0; i < 3; ++i)
//    {
//        // 높은 점수와 동일하면 추가
//        if (imax == cnt[i]) answer.push_back(i + 1);
//    }
//
//    return answer;
//}

//int main(void)
//{
//    // 해시_L1 폰켓몬
//    //solution({ 3, 1, 2, 3 });           // 2
//    //solution({ 3, 3, 3, 2, 2, 4 });     // 3
//    //solution({ 3, 3, 3, 2, 2, 2 });     // 2
//
//    // 완전탐색_L1 모의고사
//    //solution({ 1,2,3,4,5 });        // 1
//    //solution({ 1,3,2,4,2 });        // 1, 2, 3
//
//    return 0;
//}