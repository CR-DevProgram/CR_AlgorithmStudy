#include <iostream>
#include <vector>
#include <set>

using namespace std;

// �ؽ�_L1 ���ϸ�
int solution(vector<int> nums)
{
    int answer = 0;
    // ������ �� �ִ� �ִ� ���ϸ� ��
    int iMaxPokemon = nums.size() / 2;
    // �ߺ��� ���ϸ��� ���ֱ� ���� set �ؽ�
    set<int> sPokemon;

    for (int i = 0; i < nums.size(); ++i)
    {
        sPokemon.insert(nums[i]);
    }

    // ���� �� �ִ� �ִ� ���ϸ� ��
    int iGetablePokemon = sPokemon.size();

    // ���� �� �ִ� �ִ� ���ϸ� ���� ������ �� �ִ� �ִ� ���ϸ� ������ ������,
    // ���� �� �ִ� �ִ� ���ϸ� ��
    // ���� �� �ִ� �ִ� ���ϸ� ���� ������ �� �ִ� �ִ� ���ϸ� ������ ũ�ų� ������,
    // �ִ� ���ϸ� ��
    answer = iGetablePokemon < iMaxPokemon ? iGetablePokemon : iMaxPokemon;

    cout << answer << endl;

    return answer;
}

//int main(void)
//{
//    // �ؽ�_L1 ���ϸ�
//    solution({ 3, 1, 2, 3 });           // 2
//    solution({ 3, 3, 3, 2, 2, 4 });     // 3
//    solution({ 3, 3, 3, 2, 2, 2 });     // 2
//
//    return 0;
//}