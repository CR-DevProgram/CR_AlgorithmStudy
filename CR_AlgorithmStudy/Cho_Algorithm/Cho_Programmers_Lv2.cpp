// �ִ񰪰� �ּڰ�
// https://school.programmers.co.kr/learn/courses/30/lessons/12939
//#include <string>
//#include <vector>
//#include <sstream>
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//vector<int> SplitString(string& s)
//{
//    istringstream iss(s);
//    string token;
//    vector<int> tokens;
//
//    while (iss >> token)
//    {
//        tokens.push_back(stoi(token));
//    }
//
//    return tokens;
//}
//
//string solution(string s) {
//    vector<int> v = SplitString(s);
//
//    sort(v.begin(), v.end());
//
//    int minValue = v[0];
//    int maxValue = v[v.size() - 1];
//
//    string answer = "";
//    answer = to_string(minValue) + ' ' + to_string(maxValue);
//
//    return answer;
//}
//
//int main()
//{
//    string s = "1 2 3 4";
//    cout << solution(s);
//}

// �ùٸ� ��ȣ
// https://school.programmers.co.kr/learn/courses/30/lessons/12909
//#include <string>
//#include <iostream>
//#include <stack>
//
//using namespace std;
//
//bool solution(string s)
//{
//    bool answer = true;
//    stack<char> st;
//
//    int size = s.size();
//
//    for (int i = 0; i < size; i++)
//    {
//        if (s[i] == '(')
//        {
//            st.push(s[i]);
//        }
//        else
//        {
//            if (st.size() > 0)
//            {
//                st.pop();
//            }
//            else
//            {
//                answer = false;
//                return answer;
//            }
//        }
//    }
//
//    return st.size() == 0 ? answer : !answer;
//}

// �ּڰ� �����
// https://school.programmers.co.kr/learn/courses/30/lessons/12941
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int solution(vector<int> A, vector<int> B)
//{
//    sort(A.begin(), A.end());
//    sort(B.begin(), B.end(), greater<>());
//
//    int size = A.size();
//    int answer = 0;
//    for (int i = 0; i < size; i++)
//    {
//        answer += A[i] * B[i];
//    }
//
//    return answer;
//}

// JadenCase ���ڿ� �����
// https://school.programmers.co.kr/learn/courses/30/lessons/12951
//#include <string>
//#include <vector>
//
//using namespace std;
//
//string solution(string s)
//{
//    int size = s.size();
//
//    bool upper = true;
//    for (int i = 0; i < size; i++)
//    {
//        if (isdigit(s[i]))
//        {
//            upper = false;
//            continue;
//        }
//
//        if (s[i] == ' ')
//        {
//            upper = true;
//            continue;
//        }
//
//        if (upper)
//        {
//            s[i] = toupper(s[i]);
//            upper = false;
//        }
//        else
//        {
//            s[i] = tolower(s[i]);
//        }
//    }
//
//    return s;
//}

// ���� ��ȯ �ݺ��ϱ�
// https://school.programmers.co.kr/learn/courses/30/lessons/70129
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <iostream>
//
//using namespace std;
//
//vector<int> solution(string s) {
//	vector<int> answer;
//	int removeCnt = 0;
//	int playCnt = 0;
//
//	while (true)
//	{
//		// 1�� ������ ����.
//		int cnt = count(s.begin(), s.end(), '1');
//		if (s.size() == 1)
//		{
//			answer.push_back(playCnt);
//			answer.push_back(removeCnt);
//			return answer;
//		}
//
//		++playCnt;
//		removeCnt += s.size() - cnt;
//
//		// cnt�� ��Ʈ�� ��ȯ�Ѵ�.
//		s = "";
//
//		while (true)
//		{
//			s.insert(0, to_string(cnt % 2));
//			cnt /= 2;
//
//			if (cnt == 0)
//			{
//				break;
//			}
//		}
//	}
//}
//
//int main()
//{
//	string s = "110010101001";
//	solution(s);
//}

// ������ ǥ��
// https://school.programmers.co.kr/learn/courses/30/lessons/12924
//#include <string>
//#include <vector>
//
//using namespace std;
//
//int solution(int n) {
//    int answer = 1;
//
//    for (int i = 1; i <= n; i++)
//    {
//        int temp = i;
//
//        for (int j = i + 1; j <= n; j++)
//        {
//            temp += j;
//
//            if (temp > n) break;
//            if (temp == n)
//            {
//                ++answer;
//                break;
//            }
//        }
//    }
//
//    return answer;
//}

// ���� ū ����
// https://school.programmers.co.kr/learn/courses/30/lessons/12911
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int getCount(int n)
//{
//    string s = "";
//    while (true)
//    {
//        s.insert(0, to_string(n % 2));
//        n /= 2;
//
//        if (n == 0)
//        {
//            break;
//        }
//    }
//
//    return count(s.begin(), s.end(), '1');
//}
//
//int solution(int n) {
//    int originCnt = getCount(n);
//
//    while (true)
//    {
//        int cnt = getCount(++n);
//        if (originCnt == cnt)
//        {
//            return n;
//        }
//    }
//}

// �Ǻ���ġ ��
// https://school.programmers.co.kr/learn/courses/30/lessons/12945
// �޸������̼� �� �ϸ� �ð� �ʰ� ��
//#include <string>
//#include <vector>
//
//using namespace std;
//
//vector<int> memo(100001, -1);
//int divideNum = 1234567;
//
//int fibo(int n)
//{
//    if (n == 0) return 0;
//    if (n == 1) return 1;
//
//    if (memo[n] != -1) return memo[n];
//
//    memo[n] = (fibo(n - 1) % divideNum + fibo(n - 2) % divideNum) % divideNum;
//
//    return memo[n];
//}
//
//int solution(int n) {
//    return fibo(n);
//}

// ¦���� �����ϱ�
// https://school.programmers.co.kr/learn/courses/30/lessons/12973
//#include <iostream>
//#include <string>
//#include <stack>
//using namespace std;
//
//int solution(string s)
//{
//    int size = s.size();
//    stack<char> st;
//
//    for (int i = 0; i < size; i++)
//    {
//        if (st.size() == 0)
//        {
//            st.push(s[i]);
//        }
//        else if (st.top() == s[i])
//        {
//            st.pop();
//        }
//        else
//        {
//            st.push(s[i]);
//        }
//    }
//
//    return st.size() > 0 ? 0 : 1;
//}

// ī��
// https://school.programmers.co.kr/learn/courses/30/lessons/42842
//#include <string>
//#include <vector>
//
//using namespace std;
//
//vector<int> solution(int brown, int yellow) {
//    vector<int> answer;
//
//    // ���� ���̴� ���� ���̿� ���ų� ���
//    for (int i = 1; i <= yellow; i++)
//    {
//        if (yellow % i == 0)
//        {
//            int h = i;
//            int w = yellow / i + 2;
//            if (brown == h * 2 + w * 2)
//            {
//                answer.push_back(w);
//                answer.push_back(h + 2);
//                return answer;
//            }
//        }
//    }
//
//    return answer;
//}
//
//int main()
//{
//    int brown = 8;
//    int yellow = 1;
//    solution(brown, yellow);
//}

// ������ ���� �̵�
// https://school.programmers.co.kr/learn/courses/30/lessons/12980
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <string>
//
//using namespace std;
//
//int solution(int n)
//{
//    string s = "";
//    while (true)
//    {
//        s.insert(0, to_string(n % 2));
//        n /= 2;
//
//        if (n == 0)
//            break;
//    }
//
//    return count(s.begin(), s.end(), '1');
//}

// ����Ʈ
// https://school.programmers.co.kr/learn/courses/30/lessons/42885
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int solution(vector<int> people, int limit) {
//    sort(people.begin(), people.end());
//    int size = people.size();
//
//    int i = 0;
//    int j = size - 1;
//    int cnt = 0;
//
//    while (i <= j)
//    {
//        if (people[i] + people[j] <= limit)
//        {
//            ++i;
//        }
//        ++cnt;
//        --j;
//    }
//
//    return cnt;
//}

// �ָ��ٱ�
// https://school.programmers.co.kr/learn/courses/30/lessons/12914
#include <string>
//#include <vector>
//
//using namespace std;
//
//long long solution(int n) {
//    int value = 1234567;
//    vector<long long> v(2001, 0);
//    v[0] = 1;
//    v[1] = 1;
//
//    for (int i = 2; i <= n; i++)
//    {
//        v[i] = ((v[i - 1] % value) + (v[i - 2] % value)) % value;
//    }
//
//    return v[n];
//}

// N���� �ּҰ����
// https://school.programmers.co.kr/learn/courses/30/lessons/12953
//#include <string>
//#include <vector>
//#include <math.h>
//
//using namespace std;
//
//int gcd(int a, int b) {
//    while (b != 0) {
//        int temp = b;
//        b = a % b;
//        a = temp;
//    }
//    return a;
//}
//
//int lcm(int a, int b) {
//    return abs(a * b) / gcd(a, b);
//}
//
//int solution(vector<int> arr) {
//    int size = arr.size();
//    int value = arr[0];
//    for (int i = 1; i < size; i++)
//    {
//        value = lcm(value, arr[i]);
//    }
//
//    return value;
//}

// ���� �����ձ�
// https://school.programmers.co.kr/learn/courses/30/lessons/12981
//#include <string>
//#include <vector>
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//vector<int> solution(int n, vector<string> words) {
//    vector<int> answer;
//    int size = words.size();
//    vector<string> v;
//
//    for (int i = 0; i < size; i++)
//    {
//        // �ߺ� üũ�� �Ѵ�.
//        int cnt = count(v.begin(), v.end(), words[i]);
//        if (cnt == 0)
//        {
//            // �� ����� �� ���ڿ� ���� ù ���ڸ� ���Ѵ�.
//            if (v.size() > 0)
//            {
//                if (v[i - 1].back() != words[i].front())
//                {
//                    answer.push_back(i % n + 1);
//                    answer.push_back(i / n + 1);
//                    break;
//                }
//                else
//                {
//                    v.push_back(words[i]);
//                }
//            }
//            else
//            {
//                v.push_back(words[i]);
//            }
//        }
//        else
//        {
//            answer.push_back(i % n + 1);
//            answer.push_back(i / n + 1);
//            break;
//        }
//    }
//
//    if (answer.empty())
//    {
//        answer.push_back(0);
//        answer.push_back(0);
//    }
//
//    return answer;
//}
//
//int main()
//{
//    solution(2, { "hello", "one", "even", "never", "now", "world", "draw" });
//}

// ���� ����ǥ
// https://school.programmers.co.kr/learn/courses/30/lessons/12985
//#include <iostream>
//
//using namespace std;
//
//int solution(int n, int a, int b)
//{
//    int cnt = 0;
//    --a;
//    --b;
//
//    while (a != b)
//    {
//        a /= 2;
//        b /= 2;
//        ++cnt;
//    }
//
//    return cnt;
//}

// �� ����
// https://school.programmers.co.kr/learn/courses/30/lessons/138476
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int solution(int k, vector<int> tangerine) {
//    // �� �迭�� ������ ���Ѵ�.
//    int size = tangerine.size();
//
//    // vector�� �� ���� ��ȣ�� ������ �ִ´�.
//    vector<int> v(10000001, 0);
//    for (int i = 0; i < size; i++)
//    {
//        ++v[tangerine[i]];
//    }
//
//    // �����Ѵ�.
//    sort(v.begin(), v.end(), greater<>());
//
//    int cnt = 0;
//    for (int i = 0; i < size; i++)
//    {
//        cnt += v[i];
//
//        if (cnt >= k)
//            return i + 1;
//    }
//}

// ���� �κ� ���� ���� ����
// https://school.programmers.co.kr/learn/courses/30/lessons/131701
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    set<int> s;
    int size = elements.size();

    for (int j = 0; j < size; j++)
    {
        int value = 0;

        for (int i = 0; i < size; i++)
        {
            value += elements[i];
            s.insert(value);
        }

        rotate(elements.begin(), elements.begin() + 1, elements.end());
    }

    return s.size();
}