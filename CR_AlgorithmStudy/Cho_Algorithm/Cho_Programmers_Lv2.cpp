// 최댓값과 최솟값
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

// 올바른 괄호
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

// 최솟값 만들기
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

// JadenCase 문자열 만들기
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

// 이진 변환 반복하기
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
//		// 1의 개수를 센다.
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
//		// cnt를 비트로 변환한다.
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

// 숫자의 표현
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

// 다음 큰 숫자
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

// 피보나치 수
// https://school.programmers.co.kr/learn/courses/30/lessons/12945
// 메모이제이션 안 하면 시간 초과 남
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

// 짝지어 제거하기
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

// 카펫
// https://school.programmers.co.kr/learn/courses/30/lessons/42842
//#include <string>
//#include <vector>
//
//using namespace std;
//
//vector<int> solution(int brown, int yellow) {
//    vector<int> answer;
//
//    // 가로 길이는 세로 길이와 같거나 길다
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

// 점프와 순간 이동
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

// 구명보트
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

// 멀리뛰기
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

// N개의 최소공배수
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

// 영어 끝말잇기
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
//        // 중복 체크를 한다.
//        int cnt = count(v.begin(), v.end(), words[i]);
//        if (cnt == 0)
//        {
//            // 앞 사람의 끝 글자와 현재 첫 글자를 비교한다.
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

// 예상 대진표
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

// 귤 고르기
// https://school.programmers.co.kr/learn/courses/30/lessons/138476
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int solution(int k, vector<int> tangerine) {
//    // 귤 배열의 개수를 구한다.
//    int size = tangerine.size();
//
//    // vector에 각 귤의 번호와 개수를 넣는다.
//    vector<int> v(10000001, 0);
//    for (int i = 0; i < size; i++)
//    {
//        ++v[tangerine[i]];
//    }
//
//    // 정렬한다.
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

// 연속 부분 수열 합의 개수
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

// 괄호 회전하기
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

// n^2 배열 자르기
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

// 할인 행사
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

// 행렬의 곱셈
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

// 의상
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

// 캐시
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

// 기능개발
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

// 프로세스
// https://school.programmers.co.kr/learn/courses/30/lessons/42587
#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    queue<pair<int, int>> q;
    priority_queue<int> pq;
    int size = priorities.size();

    for (int i = 0; i < size; i++)
    {
        q.push({ priorities[i], i });
        pq.push(priorities[i]);
    }

    int cnt = 0;
    while (true)
    {
        if (pq.top() != q.front().first)
        {
            int f = q.front().first;
            int s = q.front().second;
            q.pop();
            q.push({f, s});
        }
        else
        {
            ++cnt;
            // location이 일치하는지 확인한다.
            if (q.front().second == location)
            {
                return cnt;
            }
            else
            {
                pq.pop();
                q.pop();
            }
        }
    }
}

int main()
{
    cout << solution({ 1,1,9,1,1,1 },0);
}