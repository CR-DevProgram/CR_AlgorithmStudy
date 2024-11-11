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
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <set>
//
//using namespace std;
//
//int solution(vector<int> elements) {
//    set<int> s;
//    int size = elements.size();
//
//    for (int j = 0; j < size; j++)
//    {
//        int value = 0;
//
//        for (int i = 0; i < size; i++)
//        {
//            value += elements[i];
//            s.insert(value);
//        }
//
//        rotate(elements.begin(), elements.begin() + 1, elements.end());
//    }
//
//    return s.size();
//}

// ��ȣ ȸ���ϱ�
// https://school.programmers.co.kr/learn/courses/30/lessons/76502
//#include <string>
//#include <algorithm>
//#include <vector>
//#include <stack>
//
//using namespace std;
//
//int solution(string s) {
//    int size = s.size();
//    int cnt = 0;
//    for (int i = 0; i < size; i++)
//    {
//        stack<char> st;
//        for (int j = 0; j < size; j++)
//        {
//            if (st.empty())
//            {
//                st.push(s[j]);
//            }
//            else
//            {
//                if ((st.top() == '[' && s[j] == ']') ||
//                    (st.top() == '{' && s[j] == '}') ||
//                    (st.top() == '(' && s[j] == ')'))
//                {
//                    st.pop();
//                }
//                else
//                {
//                    st.push(s[j]);
//                }
//            }
//        }
//
//        if (st.empty()) ++cnt;
//
//        rotate(s.begin(), s.begin() + 1, s.end());
//    }
//    return cnt;
//}

// n^2 �迭 �ڸ���
// https://school.programmers.co.kr/learn/courses/30/lessons/87390
//#include <string>
//#include <vector>
//
//using namespace std;
//
//vector<int> solution(int n, long long left, long long right) {
//    vector<int> v;    
//    vector<int> answer;
//
//    for (long long k = left; k <= right; ++k)
//    {
//        int i = k / n;
//        int j = k % n;
//
//        answer.push_back(max(i, j) + 1);
//    }
//
//    return answer;
//}
//
//int main()
//{
//    solution(3, 2, 5);
//}

// ���� ���
// https://school.programmers.co.kr/learn/courses/30/lessons/131127
//#include <string>
//#include <vector>
//#include <map>
//#include <iostream>
//
//using namespace std;
//
//int solution(vector<string> want, vector<int> number, vector<string> discount) {
//
//    map<string, int> m;
//    int size = want.size();
//
//    for (int i = 0; i < size; i++)
//    {
//        m.insert(make_pair(want[i], number[i]));
//    }
//
//    size = discount.size();
//
//    int cnt = 0;
//    int answer = 0;
//    for (int i = 0; i < size; i++)
//    {
//        ++cnt;
//        if (m.find(discount[i]) != m.end())
//        {
//            --m[discount[i]];
//        }
//        if(cnt >= 10)
//        {
//            bool isTrue = true;
//            for (auto& j : m)
//            {
//                if (j.second > 0)
//                {
//                    isTrue = false;
//                    break;
//                }
//            }
//
//            if (isTrue) ++answer;
//            if (m.find(discount[i - 9]) != m.end())
//            {
//                ++m[discount[i - 9]];
//            }
//        }
//    }
//
//    return answer;
//}
//
//int main()
//{
//    solution({ "banana", "apple", "rice", "pork", "pot" }, { 3, 2, 2, 2, 1 }, { "chicken", "apple", "apple", "banana", "rice", "apple", "pork", "banana", "pork", "rice", "pot", "banana", "apple", "banana" });
//}

// ����� ����
// https://school.programmers.co.kr/learn/courses/30/lessons/12949
//#include <string>
//#include <vector>
//
//using namespace std;
//
//vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
//    int arr1Row = arr1.size();
//    int arr1Col = arr1[0].size();
//    int arr2Row = arr2.size();
//    int arr2Col = arr2[0].size();
//    vector<vector<int>> arr3(arr1Row, vector<int>(arr2Col));
//
//    for (int i = 0; i < arr1Row; i++)
//    {
//        for (int j = 0; j < arr2Col; j++)
//        {
//            for (int k = 0; k < arr1Col; k++)
//            {
//                arr3[i][j] += arr1[i][k] * arr2[k][j];
//            }
//        }
//    }
//
//    return arr3;
//}
//
//int main()
//{
//    solution({ {1, 4} ,{3, 2},{4, 1} }, { {3, 3}, {3, 3} });
//}

// �ǻ�
// https://school.programmers.co.kr/learn/courses/30/lessons/42578
//#include <string>
//#include <vector>
//#include <map>
//
//using namespace std;
//
//int solution(vector<vector<string>> clothes)
//{
//    map<string, int> m;
//    int size = clothes.size();
//    int answer = 1;
//
//    for (int i = 0; i < size; i++)
//    {
//        ++m[clothes[i][1]];
//    }
//
//    for (auto it = m.begin(); it != m.end(); it++)
//    {
//        answer *= (it->second + 1);
//    }
//
//
//    return answer - 1;
//}

// H-Index
// https://school.programmers.co.kr/learn/courses/30/lessons/42747
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <iostream>
//
//using namespace std;
//
//int solution(vector<int> citations) {
//    sort(citations.begin(), citations.end(), greater<>());
//
//    for (int i = 0; i < citations.size(); ++i) {
//        if (citations[i] < i + 1) {
//            return i;
//        }
//    }
//}
//
//int main()
//{
//    cout << solution({ 3,0,6,1,5 });
//}

// ĳ��
// https://school.programmers.co.kr/learn/courses/30/lessons/17680
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <iostream>
//
//using namespace std;
//
//int solution(int cacheSize, vector<string> cities) {
//    int size = cities.size();
//    vector<string> v;
//    int answer = 0;
//
//    if (cacheSize == 0)
//    {
//        return size * 5;
//    }
//
//    for (int i = 0; i < size; i++)
//    {
//        string city = "";
//
//        for (int j = 0; j < cities[i].size(); j++)
//        {
//            city += tolower(cities[i][j]);
//        }
//
//        if (v.size() < cacheSize)
//        {
//            if (v.end() == find(v.begin(), v.end(), city))
//            {
//                v.push_back(city);
//                answer += 5;
//            }
//            else
//            {
//                v.erase(remove(v.begin(), v.end(), city), v.end());
//                v.push_back(city);
//                answer += 1;
//            }
//        }
//        else
//        {
//            if (v.end() == find(v.begin(), v.end(), city))
//            {
//                v.erase(v.begin(), v.begin() + 1);
//                v.push_back(city);
//                answer += 5;
//            }
//            else
//            {
//                v.erase(remove(v.begin(), v.end(), city), v.end());
//                v.push_back(city);
//                answer += 1;
//            }
//        }
//    }
//
//    return answer;
//}
//
//int main()
//{
//    cout << solution(3, { "a", "b", "c", "b"});
//}

// ��ɰ���
// https://school.programmers.co.kr/learn/courses/30/lessons/42586
//#include <string>
//#include <vector>
//
//using namespace std;
//
//vector<int> solution(vector<int> progresses, vector<int> speeds) {
//    vector<vector<int>> v;
//    int size = progresses.size();
//    for (int i = 0; i < size; i++)
//    {
//        v.push_back({ progresses[i], speeds[i] });
//    }
//
//    vector<int> answer;
//    while (!v.empty())
//    {
//        int cnt = 0;
//        while (!v.empty() && v[0][0] >= 100)
//        {
//            v.erase(v.begin());
//            ++cnt;
//        }
//
//        if (cnt > 0)
//            answer.push_back(cnt);
//
//        if (!v.empty())
//        {
//            for (int i = 0; i < v.size(); i++)
//            {
//                v[i][0] += v[i][1];
//            }
//        }
//    }
//
//    return answer;
//}
//
//int main()
//{
//    solution({ 93, 30, 55 }, { 1, 30, 5 });
//}

// ���μ���
// https://school.programmers.co.kr/learn/courses/30/lessons/42587
//#include <string>
//#include <vector>
//#include <queue>
//#include <iostream>
//
//using namespace std;
//
//int solution(vector<int> priorities, int location) {
//    queue<pair<int, int>> q;
//    priority_queue<int> pq;
//    int size = priorities.size();
//
//    for (int i = 0; i < size; i++)
//    {
//        q.push({ priorities[i], i });
//        pq.push(priorities[i]);
//    }
//
//    int cnt = 0;
//    while (true)
//    {
//        if (pq.top() != q.front().first)
//        {
//            int f = q.front().first;
//            int s = q.front().second;
//            q.pop();
//            q.push({f, s});
//        }
//        else
//        {
//            ++cnt;
//            // location�� ��ġ�ϴ��� Ȯ���Ѵ�.
//            if (q.front().second == location)
//            {
//                return cnt;
//            }
//            else
//            {
//                pq.pop();
//                q.pop();
//            }
//        }
//    }
//}
//
//int main()
//{
//    cout << solution({ 1,1,9,1,1,1 },0);
//}

// ��ȭ��ȣ ���
// https://school.programmers.co.kr/learn/courses/30/lessons/42577
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//bool solution(vector<string> phone_book) {
//    int size = phone_book.size();
//
//    sort(phone_book.begin(), phone_book.end());
//
//    for (int i = 0; i < size - 1; i++)
//    {
//        if (phone_book[i + 1].find(phone_book[i]) == 0)
//        {
//            return false;
//        }
//    }
//
//    return true;
//}

//�޴� ������
// https://school.programmers.co.kr/learn/courses/30/lessons/72411
//#include <string>
//#include <vector>
//#include <map>
//#include <algorithm>
//
//using namespace std;
//
//map<string, int> newCourse;
//vector<int> maxCnt(11, 0);
//
//void combination(string src, string dst, int depth)
//{
//    if (dst.size() == depth)
//    {
//        newCourse[dst]++;
//        maxCnt[depth] = max(maxCnt[depth], newCourse[dst]);
//    }
//    else
//    {
//        for (int i = 0; i < src.size(); i++)
//        {
//            combination(src.substr(i + 1), dst + src[i], depth);
//        }
//    }
//}
//
//vector<string> solution(vector<string> orders, vector<int> course) {
//    for (auto& s : orders)
//    {
//        sort(s.begin(), s.end());
//    }
//
//    for (auto& i : course)
//    {
//        for (auto& s : orders)
//        {
//            combination(s, "", i);
//        }
//    }
//
//    vector<string> answer;
//    for (auto& [course, cnt] : newCourse)
//    {
//        if (maxCnt[course.size()] >= 2 && maxCnt[course.size()] == cnt)
//        {
//            answer.push_back(course);
//        }
//    }
//
//    return answer;
//}

// ����ä�ù�
// https://school.programmers.co.kr/learn/courses/30/lessons/42888
//#include <string>
//#include <vector>
//#include <sstream>
//#include <map>
//
//using namespace std;
//
//vector<string> solution(vector<string> record) {
//    map<string/*id*/, string/*name*/> m;
//
//    vector<string> answer;
//    vector<string> ids;
//    for (auto& r : record)
//    {
//        stringstream s(r);
//        string cmd, id, name;
//        s >> cmd;
//
//        if (cmd == "Enter" || cmd == "Change")
//        {
//            s >> id >> name;
//            m[id] = name;
//            if (cmd == "Enter")
//            {
//                answer.push_back("���� ���Խ��ϴ�.");
//                ids.push_back(id);
//            }
//        }
//        else
//        {
//            s >> id;
//            answer.push_back("���� �������ϴ�.");
//            ids.push_back(id);
//        }
//    }
//
//    int size = ids.size();
//
//    for (int i = 0; i < size; i++)
//    {
//        string name = m[ids[i]];
//
//        answer[i] = name + answer[i];
//    }
//
//    return answer;
//}

// ���� �� �ִܰŸ�
// https://school.programmers.co.kr/learn/courses/30/lessons/1844
//#include <vector>
//#include <queue>
//using namespace std;
//
//int dx[] = { -1, 1, 0, 0 };
//int dy[] = { 0, 0, -1, 1 };
//
//int bfs(vector<vector<int>>& maps, int x, int y)
//{
//    int h = maps[0].size();
//    int w = maps.size();
//
//    vector<vector<bool>> isVisited(w, vector<bool>(h, false));
//    vector<vector<int>> visitedCnt(w, vector<int>(h, 0));
//    isVisited[0][0] = true;
//    visitedCnt[0][0] = 1;
//
//    queue<pair<int, int>> q;
//
//    q.push({ x, y });
//
//    while (!q.empty())
//    {
//        int cx = q.front().first;
//        int cy = q.front().second;
//        q.pop();
//
//        for (int i = 0; i < 4; i++)
//        {
//            int nx = cx + dx[i];
//            int ny = cy + dy[i];
//
//            if (nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
//            if (isVisited[nx][ny]) continue;
//            if (maps[nx][ny] == 0) continue;
//
//            isVisited[nx][ny] = true;
//            visitedCnt[nx][ny] = visitedCnt[cx][cy] + 1;
//
//            if (nx == w - 1 && ny == h - 1)
//            {
//                return visitedCnt[nx][ny];
//            }
//
//            q.push({ nx, ny });
//        }
//    }
//
//    return -1;
//}
//
//int solution(vector<vector<int> > maps)
//{
//    return bfs(maps, 0, 0);
//}
//
//int main()
//{
//    solution({ { 1, 1 } });
//}

// 124 ������ ����
// https://school.programmers.co.kr/learn/courses/30/lessons/12899
//#include <string>
//#include <vector>
//
//using namespace std;
//
//string solution(int n) {
//
//    string answer = "";
//    int t = 0;
//    while (n != 0) // ���ڰ� 0�� �ƴϸ�
//    {
//        t = n % 3; // ���ڸ� 3���� ���� �������� ���Ѵ�. �������� �� �� �ִ� ���ڴ� 0 ~ 2 �̹Ƿ� 0�� ������ ��� 4�� ��ȯ�Ѵ�.
//        n /= 3;    // ���ڸ� 3���� ���� ���� ���Ѵ�.
//
//        if (t == 0) // ���� �������� 0�̸� 4�� ��ȯ�ϰ�, ���ڿ� 1�� ���δ�.
//        {
//            t = 4;
//            --n;
//        }
//
//        answer = to_string(t) + answer;
//    }
//
//    return answer;
//}

// ���
// https://school.programmers.co.kr/learn/courses/30/lessons/12978
//#include <iostream>
//#include <vector>
//#include <queue>
//using namespace std;
//
//const int INF = 10000001;
//
//vector<int> dijkstra(const vector<vector<int>>& graph, int start)
//{
//    int size = graph.size();
//    vector<int> distances(size, INF);
//    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
//
//    distances[start] = 0;
//    pq.push({ 0, start });
//
//    while (!pq.empty()) {
//        int current_dist = pq.top().first;
//        int u = pq.top().second;
//        pq.pop();
//
//        if (current_dist > distances[u]) continue;
//
//        for (int v = 0; v < size; ++v) {
//            if (graph[u][v] != INF) {
//                int weight = graph[u][v];
//                if (distances[u] + weight < distances[v]) {
//                    distances[v] = distances[u] + weight;
//                    pq.push({ distances[v], v });
//                }
//            }
//        }
//    }
//
//    return distances;
//}
//
//int solution(int N, vector<vector<int> > road, int K) {
//    vector<vector<int>> v(N + 1, vector<int>(N + 1, INF));
//
//    for (int i = 0; i < road.size(); i++)
//    {
//        int from = road[i][0];
//        int to = road[i][1];
//        int time = road[i][2];
//
//        v[from][to] = min(v[from][to], time);
//        v[to][from] = min(v[from][to], time);
//    }
//
//    vector<int> distances = dijkstra(v, 1); // 1�� �������� ���� �Ÿ� ���
//
//    int answer = 0;
//    for (int i = 1; i < distances.size(); i++)
//    {
//        if (distances[i] <= K)
//        {
//            ++answer;
//        }
//    }
//
//    return answer;
//}

// ������ �κ�
// https://school.programmers.co.kr/learn/courses/30/lessons/169199
//#include <string>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//// �� �� �Ʒ� ��
//int dx[4] = { 1,-1,0,0 };
//int dy[4] = { 0,0,1,-1 };
//
//int bfs(vector<vector<char>>& v, int x, int y)
//{
//    int w = v.size();
//    int h = v[0].size();
//    vector<vector<bool>> isVisited(w, vector<bool>(h));
//    vector<vector<int>> visitedCnt(w, vector<int>(h));
//    queue<pair<int, int>> q;
//    q.push({ x, y });
//    isVisited[x][y] = true;
//
//    while (!q.empty())
//    {
//        int cx = q.front().first;
//        int cy = q.front().second;
//
//        q.pop();
//
//        int idx = 0;
//        for (int i = 0; i < 4; i++)
//        {
//            int nx = cx;
//            int ny = cy;
//            while (true)
//            {
//                nx += dx[i];
//                ny += dy[i];
//
//                // ��ֹ��� ��ų� �ٱ����� ������ ���� ��ġ�� �湮�ߴ��� Ȯ���Ѵ�.
//                if (nx < 0 || ny < 0 ||
//                    nx >= w || ny >= h ||
//                    v[nx][ny] == 'D')
//                {
//                    // �湮���� �ʾ����� ���� ��ġ�� �湮�ߴٰ� �ϰ�
//                    int px = nx - dx[i];
//                    int py = ny - dy[i];
//                    if (!isVisited[px][py])
//                    {
//                        // q�� �ִ´�.
//                        isVisited[px][py] = true;
//                        visitedCnt[px][py] = visitedCnt[cx][cy] + 1;
//                        q.push({ px, py });
//
//                        if (v[px][py] == 'G')
//                        {
//                            return visitedCnt[px][py];
//                        }
//                    }
//
//                    break;
//                }
//            }
//        }
//    }
//
//    return -1;
//}
//
//int solution(vector<string> board) {
//    // ������ �̵��ؾ� �� ���̴�.
//    int w = board.size();
//    int h = board[0].size();
//    vector<vector<char>> v(w, vector<char>(h));
//    int x = 0;
//    int y = 0;
//    for (int i = 0; i < w; i++)
//    {
//        for (int j = 0; j < h; j++)
//        {
//            if (board[i][j] == 'R')
//            {
//                x = i;
//                y = j;
//            }
//
//            v[i][j] = board[i][j];
//        }
//    }
//
//    int answer = bfs(v, x, y);
//    return answer;
//}
//
//int main()
//{
//    solution({ "...D..R", ".D.G...", "....D.D", "D....D.", "..D...." });
//}

//���ڿ� ����
// https://school.programmers.co.kr/learn/courses/30/lessons/60057
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//string compress(const string& s, int size)
//{
//    // ó������ ��������� �ڸ� �迭�� �����.
//    string prev = s.substr(0, size);
//    string compressed = "";
//    int count = 1;
//    for (int i = size; i < s.size(); i += size)
//    {
//        // ���� ���ڸ� ���Ѵ�.
//        string cur = s.substr(i, size);
//
//        // ��ġ�ϸ� count�� ���Ѵ�.
//        if (prev == cur)
//            ++count;
//        else
//        {
//            // ��������� ���ڸ� ǥ���ϰ�
//            if (count > 1)
//            {
//                compressed += to_string(count);
//                count = 1;
//            }
//
//            // ���ڸ� ���δ�
//            compressed += prev;
//            prev = cur;
//        }
//    }
//
//    if (count > 1)
//    {
//        compressed += to_string(count);
//    }
//
//    compressed += prev;
//
//    return compressed;
//}
//
//
//int solution(string s) {
//    int size = s.size();
//    int minSize = size;
//
//    for (int i = 1; i <= size / 2; i++)
//    {
//        string compressed = compress(s, i);
//        int newSize = compressed.size();
//        minSize = min(minSize, newSize);
//    }
//
//    return minSize;
//}

// ���� Ŭ�����͸�
// https://school.programmers.co.kr/learn/courses/30/lessons/17677
//#include <string>
//#include <map>
//#include <algorithm>
//
//using namespace std;
//
//int solution(string str1, string str2)
//{
//    map<string, int> m1;
//    map<string, int> m2;
//
//    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
//    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
//
//    for (int i = 0; i < str1.size() - 1; i++)
//    {
//        string temp = str1.substr(i, 2);
//        if (isalpha(temp[0]) && isalpha(temp[1]))
//        {
//            ++m1[temp];
//        }
//    }
//
//    for (int i = 0; i < str2.size() - 1; i++)
//    {
//        string temp = str2.substr(i, 2);
//        if (isalpha(temp[0]) && isalpha(temp[1]))
//        {
//            ++m2[temp];
//        }
//    }
//
//    int intersection_size = 0;
//    int union_size = 0;
//
//    for (auto it : m1)
//    {
//        if (m2.end() != m2.find(it.first))
//            intersection_size += min(it.second, m2[it.first]);
//    }
//
//    for (auto it : m1)
//    {
//        union_size += it.second;
//    }
//
//    for (auto it : m2)
//    {
//        union_size += it.second;
//    }
//
//    union_size -= intersection_size;
//
//    int mul = 65536;
//    if (union_size == 0)
//    {
//        return mul;
//    }
//
//    int answer = ((double)intersection_size / union_size) * mul;
//    return answer;
//}

// ����
// https://school.programmers.co.kr/learn/courses/30/lessons/17684
//#include <string>
//#include <vector>
//#include <map>
//#include <queue>
//#include <iostream>
//
//using namespace std;
//
//vector<int> solution(string msg) {
//    // �⺻ ������ �����.
//    map<string, int> m1;
//    queue<string> q;
//    vector<int> answer;
//
//    for (int i = 0; i < msg.size(); i++)
//    {
//        string temp;
//        temp += msg[i];
//        q.push(temp);
//    }
//
//    for (int i = 0; i < 26; i++)
//    {
//        string temp;
//        temp += i + 65;
//        m1[temp] = i + 1;
//    }
//
//    int idx = 27;
//    string w;
//    for (int i = 0; i < msg.size(); i++)
//    {
//        w += msg[i];
//
//        if (m1.end() != m1.find(w)) continue;
//        else
//        {
//            string nw = w.substr(0, w.size() - 1);
//            answer.push_back(m1[nw]);
//
//            // �� ���ڸ� �־��ش�.
//            m1[w] = idx++;
//
//            w = msg[i];
//        }
//    }
//
//    if (w != "")
//    {
//        answer.push_back(m1[w]);
//    }
//
//    return answer;
//}
//
//int main()
//{
//    solution("ABABABABABABABAB");
//}

//#include <string>
//#include <vector>
//#include <algorithm>
//#include <iostream>
//#include <stack>
//#include <sstream>
//
//using namespace std;
//
//vector<string> splitString(string s)
//{
//    istringstream iss(s);
//    string temp;
//    vector<string> answer;
//    while (getline(iss, temp, ':'))
//    {
//        answer.push_back(temp);
//    }
//
//    return answer;
//}
//
//int getMinutes(string time)
//{
//    vector<string> value = splitString(time);
//
//    int hour = stoi(value[0]);
//    return hour * 60 + stoi(value[1]);
//}
//
//string getTime(string a, string b)
//{
//    int temp = getMinutes(a) + stoi(b);
//    string hour = temp / 60 < 10 ? "0" + to_string(temp / 60) : to_string(temp / 60);
//    string min = temp % 60 < 10 ? "0" + to_string(temp % 60) : to_string(temp % 60);
//    return hour + ":" + min;
//}
//
//vector<string> solution(vector<vector<string>> plans) {
//    sort(plans.begin(), plans.end(), [](vector<string>& a, vector<string>& b) { return a[1] < b[1]; });
//
//    stack<pair<string, int>> remainPlans;
//    vector<string> answer;
//
//    string curTime = plans[0][1];
//    for (int i = 0; i < plans.size(); i++)
//    {
//        if (curTime > plans[i][1])
//        {
//            int time = getMinutes(curTime) - getMinutes(plans[i][1]);
//            remainPlans.push({ plans[i - 1][0], time });
//            answer.pop_back();
//        }
//        else if (curTime < plans[i][1])
//        {
//            int workTime = getMinutes(plans[i][1]) - getMinutes(curTime);
//            while (workTime > 0 && !remainPlans.empty())
//            {
//                auto& curPlan = remainPlans.top();
//                if (curPlan.second - workTime <= 0)
//                {
//                    answer.push_back(curPlan.first);
//                    workTime -= curPlan.second;
//                    remainPlans.pop();
//                }
//                else
//                {
//                    curPlan.second -= workTime;
//                    workTime = 0;
//                }
//            }
//        }
//        curTime = getTime(plans[i][1], plans[i][2]);
//        answer.push_back(plans[i][0]);
//    }
//
//    while (!remainPlans.empty())
//    {
//        answer.push_back(remainPlans.top().first);
//        remainPlans.pop();
//    }
//
//    return answer;
//}

//#include <string>
//#include <vector>
//#include <iostream>
//
//using namespace std;
//
//vector<int> discounts = { 10, 20, 30, 40 };
//
//void func(vector<vector<int>>& users, vector<int>& emoticons, vector<int>& discount, int& maxJoinPlus, int& maxAllPaid)
//{
//    int joinPlus = 0, allPaid = 0;
//    if (discount.size() == emoticons.size())
//    {
//        for (int i = 0; i < users.size(); i++)
//        {
//            int total = 0;
//            for (int j = 0; j < discount.size(); j++)
//                if (discount[j] >= users[i][0]) total += emoticons[j] - emoticons[j] * discount[j] / 100;
//
//            if (total >= users[i][1]) ++joinPlus;
//            else  allPaid += total;
//        }
//
//        if (joinPlus > maxJoinPlus || (joinPlus == maxJoinPlus && allPaid > maxAllPaid))
//        {
//            maxJoinPlus = joinPlus;
//            maxAllPaid = allPaid;
//        }
//
//        return;
//    }
//
//    for (int i = 0; i < 4; i++)
//    {
//        discount.push_back(discounts[i]);
//        func(users, emoticons, discount, maxJoinPlus, maxAllPaid);
//        discount.pop_back();
//    }
//
//    return;
//}
//
//
//vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
//    vector<int> discount;
//    int maxJoinPlus = 0, maxAllPaid = 0;
//    func(users, emoticons, discount, maxJoinPlus, maxAllPaid);
//    return { maxJoinPlus, maxAllPaid };
//}

// ��ȣ ��ȯ
//#include <string>
//#include <vector>
//#include <stack>
//#include <iostream>
//
//using namespace std;
//
//bool isBalance(const string& s)
//{
//    int left = 0, right = 0;
//    for (const char c : s)
//    {
//        if (c == '(') ++left;
//        else ++right;
//    }
//
//    return left == right;
//}
//
//bool isRight(const string& s)
//{
//    stack<char> se;
//    for (const char c : s)
//    {
//        if (c == '(') se.push(c);
//        else
//        {
//            if (se.empty()) return false;
//            se.pop();
//        }
//    }
//
//    return true;
//}
//
//int getSplitIndex(const string& p)
//{
//    int maxSize = p.size() / 2; // 5�� 2��, 6�̸� 3��
//    for (int i = 1; i <= maxSize; i++)
//    {
//        if (isBalance(p.substr(0, 2 * i))) return i * 2;
//    }
//
//    return -1;
//}
//
//string reserve(const string& p)
//{
//    string result = p;
//    for (char& c : result)
//    {
//        if (c == '(') c = ')';
//        else c = '(';
//    }
//
//    return result;
//}
//
//string recursive(string& p)
//{
//    if (p.empty()) return "";
//
//    int idx = getSplitIndex(p);
//    string u = p.substr(0, idx);
//    string v = p.substr(idx);
//
//    if (isRight(u)) return u + recursive(v);
//    else
//    {
//        string temp = "(" + recursive(v) + ")";
//        u = u.substr(1, u.size() - 2);
//        temp += reserve(u);
//        return temp;
//    }
//}
//
//string solution(string p) {
//    return recursive(p);
//}

// ��� �׵θ� ȸ���ϱ�
//#include <string>
//#include <vector>
//#include <iostream>
//#include <set>
//
//using namespace std;
//
//// �� -> �� -> �� -> ��
//int dx[4] = { 0, 1, 0, -1 };
//int dy[4] = { 1, 0, -1, 0 };
//
//int roateAndgetMinNum(vector<vector<int>>& v, const vector<int>& query)
//{
//    int x1 = query[0], y1 = query[1], x2 = query[2], y2 = query[3];
//    int idx = 0;
//    int cx = x1;
//    int cy = y1;
//    int temp = v[cx][cy];
//    set<int> s;
//
//    while (true)
//    {
//        int nx = cx + dx[idx];
//        int ny = cy + dy[idx];
//        if (nx > x2 || ny > y2 || nx < x1 || ny < y1)
//        {
//            idx = (idx + 1) % 4;
//            nx = cx + dx[idx];
//            ny = cy + dy[idx];
//        }
//
//        int curNum = v[nx][ny];
//        v[nx][ny] = temp;
//        temp = curNum;
//        s.insert(v[nx][ny]);
//
//        cx = nx;
//        cy = ny;
//
//        if (cx == x1 && cy == y1) break;
//    }
//
//    return *s.begin();
//}
//
//vector<int> solution(int rows, int columns, vector<vector<int>> queries)
//{
//    vector<vector<int>> v(rows + 1, vector<int>(columns + 1, 0));
//    int num = 1;
//    for (int i = 1; i <= rows; i++)
//    {
//        for (int j = 1; j <= columns; j++) v[i][j] = num++;
//    }
//
//    vector<int> answer;
//    for (auto query : queries)  answer.push_back(roateAndgetMinNum(v, query));
//
//    return answer;
//}

//#include <vector>
//#include <iostream>
//
//using namespace std;
//
//void hanoi(int n, int start, int end, int via, vector<vector<int>>& result) {
//    if (n == 1) {
//        cout << start << ' ' << end << '\n';
//        result.push_back({ start, end });
//        return;
//    }
//    hanoi(n - 1, start, via, end, result);
//    result.push_back({ start, end });
//	cout << start << ' ' << end << '\n';
//    hanoi(n - 1, via, end, start, result);
//}
//
//vector<vector<int>> solution(int n) {
//    vector<vector<int>> result;
//    hanoi(n, 1, 3, 2, result);
//    return result;
//}
//
//int main()
//{
//    solution(2);
//}

//#define M_PI 3.14159265358979323846
//
//#include <iostream>
//#include <cmath>
//
//class Vector3 {
//private :
//    float x, y, z;
//
//public:
//    Vector3(float x, float y, float z) : x(x), y(y), z(z) {}
//
//    // ���� ���� ���� ���� (�� �� ������ ���� ����)
//    Vector3 operator-(const Vector3& other) const {
//        return Vector3(x - other.x, y - other.y, z - other.z);
//    }
//
//    // ���� ����ȭ �Լ� (���̰� 1�� ���� ���ͷ� ��ȯ)
//    Vector3 normalize() const {
//        float magnitude = std::sqrt(x * x + y * y + z * z);
//        return Vector3(x / magnitude, y / magnitude, z / magnitude);
//    }
//
//    // ���� ���� �Լ�
//    float dot(const Vector3& other) const {
//        return x * other.x + y * other.y + z * other.z;
//    }
//};
//
//// �þ� �� ���� ���θ� �Ǻ��ϴ� �Լ�
//bool isInSight(const Vector3& myPosition, const Vector3& monsterPosition,
//    const Vector3& myViewDirection, float myFOV) {
//    // �� ��ġ���� ���� ��ġ���� ���� ���� ���
//    Vector3 monsterDirection = (monsterPosition - myPosition).normalize();
//
//    // �þ� �߽� ���͸� ����ȭ
//    Vector3 viewDirection = myViewDirection.normalize();
//
//    // FOV�� ������ ���� ������ ���� �ڻ��� ��
//    float cosAngle = std::cos(myFOV * 0.5f * (M_PI / 180.0f));  // ������ �������� ��ȯ
//
//    // �þ� ���Ϳ� ���� ���� ���� ���� ���� ���
//    float dotProduct = viewDirection.dot(monsterDirection);
//
//    // ���� ���� �ڻ��� �� �̻��̸� �þ� �ȿ� ����
//    return dotProduct >= cosAngle;
//}
//
//int main() {
//    // ���� ��ġ�� �þ� ����, �þ߰�
//    Vector3 myPosition(0, 0, 0);
//    Vector3 monsterPosition(1, 1, 0);
//    Vector3 myViewDirection(0, 1, 0); // x�� ������ ���� �ִٰ� ����
//    float myFOV = 10.0f;  // �þ߰� 90��`
//
//    if (isInSight(myPosition, monsterPosition, myViewDirection, myFOV)) {
//        std::cout << "���Ͱ� �þ� �ȿ� �ֽ��ϴ�." << std::endl;
//    }
//    else {
//        std::cout << "���Ͱ� �þ� �ۿ� �ֽ��ϴ�." << std::endl;
//    }
//
//    return 0;
//}

//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//#define M_PI 3.141592f
//
//class Vector3
//{
//	// (1) ������
//public:
//	Vector3(float x, float y, float z) : x(x), y(y), z(z) {}
//
//	// ���� ����
//	Vector3 operator-(const Vector3& other) const
//	{
//		return Vector3(x - other.x, y - other.y, z - other.z);
//	}
//
//	Vector3 normalize() const
//	{
//		float magnitue = sqrt(x * x + y * y + z * z);
//		return Vector3(x / magnitue, y / magnitue, z / magnitue);
//	}
//
//	float dot(const Vector3& other) const
//	{
//		return x * other.x + y * other.y + z * other.z;
//	}
//
//private:
//	float x;
//	float y;
//	float z;
//};
//
//void solution(vector<vector<float>> v, float fov)
//{
//	Vector3 myPos(v[0][0], v[0][1], v[0][2]);
//	Vector3 monPos(v[1][0], v[1][1], v[1][2]);
//	Vector3 viewDirection(v[2][0], v[2][1], v[2][2]);
//	
//	Vector3 monDir = (monPos - myPos).normalize();
//	Vector3 viewDir = viewDirection.normalize();
//
//	// �þ߰��� ���� �������� �ٲ۴�.
//	float cosAngle = cos(fov * 0.5 * (M_PI / 180.f));
//	float dotProduct = viewDir.dot(monDir);
//
//	if (dotProduct >= cosAngle)
//	{
//		cout << "�þ߰� ���� �ִ�";
//	}
//	else
//	{
//		cout << "�þ߰� ���� ����.";
//	}
//}


//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//#define M_PI 3.14159265358979323846
//
//class Vector3
//{
//public:
//	Vector3(float x, float y, float z) : x(x), y(y), z(z) {}
//
//	Vector3 operator-(const Vector3 other) const
//	{
//		return { x - other.x, y - other.y, z - other.z };
//	}
//
//	Vector3 normalize()
//	{
//		float mag = sqrt(x * x + y * y + z * z);
//		return { x / mag, y / mag, z / mag };
//	}
//
//	float dot(const Vector3 other) const
//	{
//		return { x * other.x + y * other.y + z * other.z };
//	}
//
//private:
//	float x;
//	float y;
//	float z;
//};
//
//bool solution(vector<vector<float>> v, float myFov)
//{
//	// (1) myPos, monPos, viewDirection Vector3�� �����.
//	Vector3 myPos(v[0][0], v[0][1], v[0][2]);
//	Vector3 monPos(v[1][0], v[1][1], v[1][2]);
//	Vector3 viewDir(v[2][0], v[2][1], v[2][2]);
//
//	Vector3 monDirection = (monPos - myPos).normalize();
//	Vector3 viewDirection = viewDir.normalize();
//
//	float cosAngle = cos(myFov * 0.5 * (M_PI / 180.0));
//	cout << cosAngle;
//	float dotProduct = viewDirection.dot(monDirection);
//
//	return dotProduct >= cosAngle;
//}
//
//int main()
//{
//	vector<vector<float>> v;
//	v.push_back({ 0, 0, 0 }); // myPos
//	v.push_back({ 1, 1, 0 }); // monPos
//	v.push_back({ 0, 1, 0 }); // view
//	float myFov = 90.f;
//
//	if (solution(v, myFov))
//	{
//		cout << "���δ�.";
//	}
//	else
//	{
//		cout << "�Ⱥ��δ�.";
//	}
//
//	return 0;
//}

//#include <iostream>
//#include <cmath>
//
//struct Vector3 {
//    float x, y, z;
//    Vector3(float x, float y, float z) : x(x), y(y), z(z) {}
//
//    // ���� ���� ������
//    Vector3 operator-(const Vector3& other) const {
//        return Vector3(x - other.x, y - other.y, z - other.z);
//    }
//
//    // ���� �Լ�
//    Vector3 cross(const Vector3& other) const {
//        return Vector3(
//            y * other.z - z * other.y,
//            z * other.x - x * other.z,
//            x * other.y - y * other.x
//        );
//    }
//
//    // ���� ũ�� ���
//    float magnitude() const {
//        return std::sqrt(x * x + y * y + z * z);
//    }
//};
//
//float triangleArea(const Vector3& A, const Vector3& B, const Vector3& C) {
//    Vector3 AB = B - A;
//    Vector3 AC = C - A;
//    Vector3 crossProduct = AB.cross(AC);
//    return crossProduct.magnitude() / 2.0f;
//}

//#include <iostream>
//
//using namespace std;
//
//class Vector3
//{
//public:
//    Vector3(int x, int y, int z) : x(x), y(y), z(z) {}
//    Vector3 operator-(Vector3 other) const
//    {
//        return Vector3(x - other.x, y - other.y, z - other.z);
//    }
//
//    Vector3 cross(Vector3 other) const
//    {
//        return Vector3(
//            y * other.z - z * other.y,
//            z * other.x - x * other.z,
//            x * other.y - y * other.x
//        );
//    }
//
//    float mag() 
//    {
//        return sqrt(x * x + y * y + z * z);
//    }
//
//private:
//    int x;
//    int y;
//    int z;
//};
//
//int triangleArea(Vector3 A, Vector3 B, Vector3 C)
//{
//    Vector3 AB = B - A;
//    Vector3 AC = C - A;
//    Vector3 crossProduct = AB.cross(AC);
//    return crossProduct.mag() / 2.f;
//}
//
//int main() {
//    Vector3 A(0, 0, 0);
//    Vector3 B(4, 0, 0);
//    Vector3 C(0, 4, 0);
//    std::cout << "�ﰢ���� ����: " << triangleArea(A, B, C) << std::endl;
//    return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//struct pos {
//    int x, y;
//};
//
//int main(int argc, const char* argv[])
//{
//    pos a, b, c;
//    cin >> a.x >> a.y;
//    cin >> b.x >> b.y;
//    cin >> c.x >> c.y;
//
//    long long temp = a.x * b.y + b.x * c.y + c.x * a.y - (b.x * a.y + c.x * b.y + a.x * c.y);
//
//    if (temp < 0)
//        cout << "-1";
//    else if (temp > 0)
//        cout << "1";
//    else
//        cout << "0";
//
//    return 0;
//}

// ���� ǥ����
//#include <iostream>
//#include <regex>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//	vector<string> file_names = { "db-123-log.txt", "db-124-log.txt",
//								 "not-db-log.txt", "db-12-log.txt",
//								 "db-12-log.jpg" };
//
//	regex re("db-\\d*-log\\.txt");
//
//	for (const auto& file_name : file_names)
//	{
//		// regex_match : ù ��° ���ڷ� ���޵� ���ڿ���
//		//               �� ��° ���ڷ� ���޵� ���� ǥ���� ��ü��
//		//               ������ ��Ī�Ǵ� ��� true ����
//		cout << file_name << ": " << std::boolalpha << std::regex_match(file_name, re) << '\n';
//	}
//}

// �ٸ��� ������ Ʈ��
// https://school.programmers.co.kr/learn/courses/30/lessons/42583

#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int max_weight, vector<int> truck_weights)
{
    int length = 0, weight = 0, idx = 0;
    queue<pair<int, int>> q;

    for (int time = 1; ; time++)
    {
        if (!q.empty() && time - q.front().first >= bridge_length)
        {
            --length;
            weight -= q.front().second;
            q.pop();
        }

        if (length + 1 <= bridge_length && idx < truck_weights.size() && max_weight >= weight + truck_weights[idx])
        {
            ++length;
            weight += truck_weights[idx];
            q.push({ time, truck_weights[idx] });
            ++idx;
        }

        if (idx >= truck_weights.size() && q.empty()) return time;
    }

    return -1;
}