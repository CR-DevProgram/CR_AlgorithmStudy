// 01_�ϰ� ������
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//    // ��ȩ �������� Ű�� �Է¹޾� �����Ѵ�.
//    // ��ȩ ������ Ű�� ���� ���Ѵ�.
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
//    // �������� Ű�� ������������ �����Ѵ�.
//    sort(talls.begin(), talls.end());
//
//    // 2���� �����̸� ��� ��ü Ű���� ����.
//    // �� ���� 100�̸� ����Ѵ�.
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

// 02_���ĺ� ����
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//int main()
//{
//    // ù°�ٿ� �ܾ� s�� �־�����.
//    string s;
//    cin >> s;
//
//    // �ܾ��� ������ ������ �迭�� �����.
//    vector<int> cnt(26);
//
//    // �ܾ ������ cnt�� ������Ų��.
//    for (const auto& i : s)
//    {
//        ++cnt[i - 'a'];
//    }
//
//    // ����Ѵ�.
//    for (const auto& i : cnt)
//    {
//        cout << i << ' ';
//    }
//}

// 03_Ʈ�� ����
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//    // ����̴� Ʈ���� �� �� �� ������ �ִ� ���ڴ�.
//    // ���� ��� A, B, C�� �־�����.
//
//    int a, b, c;
//    cin >> a >> b >> c;
//
//    // ������ ����� ������ �迭�� �����.
//    vector<int> v(101, 0);
//
//    // �� �� �ٿ��� �� ������ �־�����.
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

// 04_�Ӹ�������� Ȯ���ϱ�
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

// 01_�ϰ� ������
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//    // ��ȩ �������� Ű�� �Է¹޾� �����Ѵ�.
//    // ��ȩ ������ Ű�� ���� ���Ѵ�.
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
//    // �������� Ű�� ������������ �����Ѵ�.
//    sort(talls.begin(), talls.end());
//
//    // 2���� �����̸� ��� ��ü Ű���� ����.
//    // �� ���� 100�̸� ����Ѵ�.
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

// 02_���ĺ� ����
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//int main()
//{
//    // ù°�ٿ� �ܾ� s�� �־�����.
//    string s;
//    cin >> s;
//
//    // �ܾ��� ������ ������ �迭�� �����.
//    vector<int> cnt(26);
//
//    // �ܾ ������ cnt�� ������Ų��.
//    for (const auto& i : s)
//    {
//        ++cnt[i - 'a'];
//    }
//
//    // ����Ѵ�.
//    for (const auto& i : cnt)
//    {
//        cout << i << ' ';
//    }
//}

// 03_Ʈ�� ����
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//    // ����̴� Ʈ���� �� �� �� ������ �ִ� ���ڴ�.
//    // ���� ��� A, B, C�� �־�����.
//
//    int a, b, c;
//    cin >> a >> b >> c;
//
//    // ������ ����� ������ �迭�� �����.
//    vector<int> v(101, 0);
//
//    // �� �� �ٿ��� �� ������ �־�����.
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

// 04_�Ӹ�������� Ȯ���ϱ�
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

// 05_�� ���
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//int main()
//{
//    // ���� ���� �Է� �޴´�.
//    int n;
//    cin >> n;
//
//    // ���� �̸� ������ ���� �迭�� �����.
//    vector<int> cnt(26);
//
//    // ���� �̸� ù ������ ������ ���Ѵ�.
//    for (int i = 0; i < n; i++)
//    {
//        string s;
//        cin >> s;
//
//        cnt[s[0] - 'a']++;
//    }
//
//    bool isTrue = false;
//    for (int i = 0; i < 26; i++)
//    {
//        if (cnt[i] >= 5)
//        {
//            char curWord = i + 'a';
//            cout << curWord;
//            isTrue = true;
//        }
//    }
//
//    if (!isTrue)
//    {
//        cout << "PREDAJA";
//    }
//}

// 06_ROT13 
//#include <iostream>
//#include <string>
//using namespace std;
//
//int main()
//{
//    // ���ڿ��� �Է� �޴´�.
//    string s;
//    getline(cin, s);
//
//    // 13���ھ� �δ�
//    for (auto& i : s)
//	{
//		if (isdigit(i) || i == ' ') continue;
//
//		// i�� ���ڷ� �ٲ۴�
//		int temp = i + 13;
//
//		if (i <= 'Z')
//		{
//			int standard = 'Z' + 1;
//			if (temp >= standard) i = 'A' + (temp % standard);
//			else {
//				i = temp;
//			}
//		}
//		else if (i <= 'z')
//		{
//			int standard = 'z' + 1;
//			if (temp >= standard) i = 'a' + (temp % standard);
//			else
//            {
//                i = temp;
//            }
//        }
//    }
//
//    cout << s;
//}

// �ѱ��� �׸��� �� ������ ��������
// https://www.acmicpc.net/problem/9996
//#include <iostream>
//#include <vector>
//#include <sstream>
//using namespace std;
//
//vector<string> splitString(string& s, char d)
//{
//    istringstream iss(s);
//    string token;
//    vector<string> tokens;
//
//    while (getline(iss, token, d))
//    {
//        tokens.push_back(token);
//    }
//
//    return tokens;
//}
//
//int main()
//{
//    int cnt;
//    cin >> cnt;
//
//    string s;
//    cin >> s;
//    vector<string> v = splitString(s, '*');
//
//    for (int i = 0; i < cnt; i++)
//    {
//        string temp;
//        cin >> temp;
//
//        if (temp.size() < v[0].size() + v[1].size())
//        {
//            cout << "NE" << '\n';
//            continue;
//        }
//
//        string start = temp.substr(0, v[0].size());
//        string end = temp.substr(temp.size() - v[1].size(), temp.size());
//        if (start == v[0] && end == v[1])
//        {
//            cout << "DA" << '\n';
//        }
//        else
//        {
//            cout << "NE" << '\n';
//        }
//    }
//}

// ����
// https://www.acmicpc.net/problem/2559
//#include <iostream>
//#include <queue>
//#include <math.h>
//using namespace std;
//
//int main()
//{
//    int n, m;
//    cin >> n >> m;
//
//    queue<int> q;
//    int sum = 0;
//    int maxValue = -100 * n;
//    for (int i = 0; i < n; i++)
//    {
//        int temp;
//        cin >> temp;
//
//        q.push(temp);
//        sum += temp;
//
//        if (q.size() == m)
//        {
//            maxValue = max(maxValue, sum);
//            sum -= q.front();
//            q.pop();
//        }
//    }
//
//    cout << maxValue;
//}

// ���¾� ���ϸ� ������ �̴ټ�
// https://www.acmicpc.net/problem/1620
//#include <iostream>
//#include <map>
//#include <string>
//using namespace std;
//
//int main()
//{
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);
//
//    // ������ ���ϵǾ� �ִ� ���ϸ��� ���� N
//    // ����� �ϴ� ������ ���� M
//    int n, m;
//    cin >> n >> m;
//
//    map<int, string> m1;
//    map<string, int> m2;
//
//    for (int i = 1; i <= n; i++)
//    {
//        string temp;
//        cin >> temp;
//        m1[i] = temp;
//        m2[temp] = i;
//    }
//
//    for (int i = 0; i < m; i++)
//    {
//        string temp;
//        cin >> temp;
//
//        if (isdigit(temp[0]))
//        {
//            cout << m1[stoi(temp)] << '\n';
//        }
//        else
//        {
//            cout << m2[temp] << '\n';
//        }
//    }
//}

// �мǿ� ���غ�
// https://www.acmicpc.net/problem/9375
//#include <iostream>
//#include <map>
//#include <vector>
//#include <string>
//
//using namespace std;
//
//int main()
//{
//    int n;
//    cin >> n;
//    for (int i = 0; i < n; i++)
//    {
//        int c;
//        cin >> c;
//        map<string, vector<string>> m;
//        for (int j = 0; j < c; j++)
//        {
//            string temp1, temp2;
//            cin >> temp1 >> temp2;
//            m[temp2].push_back(temp1);
//        }
//
//        int sum = 1;
//        for (auto& j : m)
//        {
//            sum *= (j.second.size() + 1);
//        }
//
//        cout << sum - 1 << '\n';
//    }
//}

// �Ӹ���� �����
// https://www.acmicpc.net/problem/1213
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <string>
//using namespace std;
//
//int main()
//{
//    string s;
//    cin >> s;
//
//    vector<int> v(26, 0);
//
//    int size = s.size();
//
//    for (int i = 0; i < size; i++)
//    {
//        ++v[s[i] - 'A'];
//    }
//
//    bool isOdd = false;
//    char oddAlpha;
//    string answer = "";
//    for (int i = 0; i < 26; i++)
//    {
//        if (v[i] % 2 != 0)
//        {
//            if (isOdd)
//            {
//                cout << "I'm Sorry Hansoo";
//                return 0;
//            }
//            else
//            {
//                isOdd = true;
//                oddAlpha = i + 'A';
//            }
//        }
//
//        int cnt = v[i] / 2;
//        while (cnt > 0)
//        {
//            answer += i + 'A';
//            cnt--;
//        }
//    }
//
//    string temp = answer;
//
//    reverse(answer.begin(), answer.end());
//
//    if (isOdd)
//    {
//        answer = oddAlpha + answer;
//    }
//
//    cout << temp + answer;
//}

// �ָ�
// https://www.acmicpc.net/problem/1940
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//    int n, m;
//    cin >> n >> m;
//
//    vector<int> ingredients(n);
//
//    for (int i = 0; i < n; i++)
//    {
//        cin >> ingredients[i];
//    }
//
//    sort(ingredients.begin(), ingredients.end());
//
//    int s = 0;
//    int l = n - 1;
//    int cnt = 0;
//
//    while (s < l)
//    {
//        int value = ingredients[s] + ingredients[l];
//        if (value == m)
//        {
//            ++cnt;
//            ++s;
//            --l;
//        }
//        else if (value < m)
//            ++s;
//        else if (value > m)
//            --l;
//    }
//
//    cout << cnt;
//}

// ���� �ܾ�
// https://www.acmicpc.net/problem/3986
//#include <iostream>
//#include <stack>
//using namespace std;
//
//int main()
//{
//    int n;
//    cin >> n;
//    int cnt = 0;
//    for (int i = 0; i < n; i++)
//    {
//        string temp;
//        cin >> temp;
//
//        int size = temp.size();
//        stack<char> s;
//        for (int j = 0; j < size; j++)
//        {
//            if (!s.empty() && s.top() == temp[j])
//            {
//                s.pop();
//            }
//            else
//            {
//                s.push(temp[j]);
//            }
//        }
//
//        if (s.empty()) ++cnt;
//    }
//
//    cout << cnt;
//}

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<int> value;
    int origin = k;
    while (k > 1)
    {
        value.push_back(k);

        if (k % 2 == 0)
            k /= 2;
        else
        {
            k = k * 3 + 1;
        }
    }

    value.push_back(1);
    int size = value.size();
    vector<double> tempValue;

    for (int i = 1; i < size; i++)
    {
        int w1 = value[i - 1];
        int w2 = value[i];
        double temp = ((double)w1 + w2) / 2;
        tempValue.push_back(temp);
    }

    vector<double> answer;
    for (auto i : ranges)
    {
        int start = i[0];
        int end = tempValue.size() + i[1];

        if (start > end)
        {
            answer.push_back(-1);
            continue;
        }

        double sum = 0;
        for (int j = start; j < end; j++)
        {
            sum += tempValue[j];
        }

        answer.push_back(sum);
    }

    return answer;
}

int main()
{
    solution(5, { {0,0},{0,-1},{2,-3},{3,-3} });
}