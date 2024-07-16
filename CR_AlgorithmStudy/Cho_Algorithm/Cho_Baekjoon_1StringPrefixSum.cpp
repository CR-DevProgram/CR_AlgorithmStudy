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

// 03_트럭 주차
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//    // 상근이는 트럭을 총 세 대 가지고 있는 부자다.
//    // 주차 요금 A, B, C가 주어진다.
//
//    int a, b, c;
//    cin >> a >> b >> c;
//
//    // 주차한 대수를 저장할 배열을 만든다.
//    vector<int> v(101, 0);
//
//    // 세 개 줄에는 두 정수가 주어진다.
//    int cnt = 3;
//    int maxIdx = 0;
//    for (int i = 0; i < cnt; i++)
//    {
//        int t1, t2;
//        cin >> t1 >> t2;
//
//        for (int j = t1; j < t2; j++)
//        {
//            ++v[j];
//            maxIdx = max(maxIdx, j);
//        }
//    }
//
//    int sum = 0;
//    for (int i = 1; i <= maxIdx; i++)
//    {
//        if (v[i] == 0) continue;
//
//        if (v[i] == 1)
//        {
//            sum += a;
//        }
//        else if (v[i] == 2)
//        {
//            sum += b * 2;
//        }
//        else
//        {
//            sum += c * 3;
//        }
//    }
//
//    cout << sum;
//}

// 04_팰린드롬인지 확인하기
//#include <iostream>
//#include <string>
//using namespace std;
//
//int main()
//{
//    string s;
//    cin >> s;
//
//    int size = s.size();
//
//    for (int i = 0; i < size / 2; i++)
//    {
//        if (s[i] != s[size - i - 1])
//        {
//            cout << 0;
//            return 0;
//        }
//    }
//
//    cout << 1;
//}

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

// 03_트럭 주차
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//    // 상근이는 트럭을 총 세 대 가지고 있는 부자다.
//    // 주차 요금 A, B, C가 주어진다.
//
//    int a, b, c;
//    cin >> a >> b >> c;
//
//    // 주차한 대수를 저장할 배열을 만든다.
//    vector<int> v(101, 0);
//
//    // 세 개 줄에는 두 정수가 주어진다.
//    int cnt = 3;
//    int maxIdx = 0;
//    for (int i = 0; i < cnt; i++)
//    {
//        int t1, t2;
//        cin >> t1 >> t2;
//
//        for (int j = t1; j < t2; j++)
//        {
//            ++v[j];
//            maxIdx = max(maxIdx, j);
//        }
//    }
//
//    int sum = 0;
//    for (int i = 1; i <= maxIdx; i++)
//    {
//        if (v[i] == 0) continue;
//
//        if (v[i] == 1)
//        {
//            sum += a;
//        }
//        else if (v[i] == 2)
//        {
//            sum += b * 2;
//        }
//        else
//        {
//            sum += c * 3;
//        }
//    }
//
//    cout << sum;
//}

// 04_팰린드롬인지 확인하기
//#include <iostream>
//#include <string>
//using namespace std;
//
//int main()
//{
//    string s;
//    cin >> s;
//
//    int size = s.size();
//
//    for (int i = 0; i < size / 2; i++)
//    {
//        if (s[i] != s[size - i - 1])
//        {
//            cout << 0;
//            return 0;
//        }
//    }
//
//    cout << 1;
//}

// 05_농구 경기
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    // 선수 수를 입력 받는다.
    int n;
    cin >> n;

    // 선수 이름 개수를 담을 배열을 만든다.
    vector<int> cnt(26);

    // 선수 이름 첫 글자의 개수를 구한다.
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        cnt[s[0] - 'a']++;
    }

    bool isTrue = false;
    for (int i = 0; i < 26; i++)
    {
        if (cnt[i] >= 5)
        {
            char curWord = i + 'a';
            cout << curWord;
            isTrue = true;
        }
    }

    if (!isTrue)
    {
        cout << "PREDAJA";
    }
}