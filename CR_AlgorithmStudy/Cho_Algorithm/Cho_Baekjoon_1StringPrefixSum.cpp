// 01_일곱 난쟁이
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//    // 아홉 난쟁이의 키를 입력받아 저장한다.
//    // 아홉 난쟁이 키의 합을 구한다.
//    int cnt = 9;
//    int sum = 0;
//    vector<int> talls(cnt);
//
//    for (int i = 0; i < cnt; i++)
//    {
//        cin >> talls[i];
//        sum += talls[i];
//    }
//
//    // 난쟁이의 키를 오름차순으로 정렬한다.
//    sort(talls.begin(), talls.end());
//
//    // 2명의 난쟁이를 골라 전체 키에서 뺀다.
//    // 그 값이 100이면 출력한다.
//
//    for (int i = 0; i < cnt; i++)
//    {
//        for (int j = 0; j < cnt; j++)
//        {
//            if (i == j) continue;
//
//            int temp = talls[i] + talls[j];
//
//            if (sum - temp == 100)
//            {
//                for (int k = 0; k < cnt; k++)
//                {
//                    if (k != i && k != j)
//                    {
//                        cout << talls[k] << '\n';
//                    }
//                }
//                return 0;
//            }
//        }
//    }
//}

// 02_알파벳 개수
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//int main()
//{
//    // 첫째줄에 단어 s가 주어진다.
//    string s;
//    cin >> s;
//
//    // 단어의 개수를 저장할 배열을 만든다.
//    vector<int> cnt(26);
//
//    // 단어가 나오면 cnt를 증가시킨다.
//    for (const auto& i : s)
//    {
//        ++cnt[i - 'a'];
//    }
//
//    // 출력한다.
//    for (const auto& i : cnt)
//    {
//        cout << i << ' ';
//    }
//}