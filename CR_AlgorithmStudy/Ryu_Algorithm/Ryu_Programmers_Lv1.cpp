#include <iostream>
#include <vector>
#include <set>

using namespace std;

// 해시_L1 폰켓몬
int solution(vector<int> nums)
{
    int answer = 0;
    // 가져갈 수 있는 최대 폰켓몬 수
    int iMaxPokemon = nums.size() / 2;
    // 중복된 폰켓몬을 없애기 위한 set 해시
    set<int> sPokemon;

    for (int i = 0; i < nums.size(); ++i)
    {
        sPokemon.insert(nums[i]);
    }

    // 얻을 수 있는 최대 폰켓몬 수
    int iGetablePokemon = sPokemon.size();

    // 얻을 수 있는 최대 폰켓몬 수가 가져갈 수 있는 최대 폰켓몬 수보다 작으면,
    // 얻을 수 있는 최대 폰켓몬 수
    // 얻을 수 있는 최대 폰켓몬 수가 가져갈 수 있는 최대 폰켓몬 수보다 크거나 같으면,
    // 최대 폰켓몬 수
    answer = iGetablePokemon < iMaxPokemon ? iGetablePokemon : iMaxPokemon;

    cout << answer << endl;

    return answer;
}

//int main(void)
//{
//    // 해시_L1 폰켓몬
//    solution({ 3, 1, 2, 3 });           // 2
//    solution({ 3, 3, 3, 2, 2, 4 });     // 3
//    solution({ 3, 3, 3, 2, 2, 2 });     // 2
//
//    return 0;
//}