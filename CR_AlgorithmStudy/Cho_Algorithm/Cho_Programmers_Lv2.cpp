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
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(string s) {
	vector<int> answer;
	int removeCnt = 0;
	int playCnt = 0;

	while (true)
	{
		// 1의 개수를 센다.
		int cnt = count(s.begin(), s.end(), '1');
		if (s.size() == 1)
		{
			answer.push_back(playCnt);
			answer.push_back(removeCnt);
			return answer;
		}

		++playCnt;
		removeCnt += s.size() - cnt;

		// cnt를 비트로 변환한다.
		s = "";

		while (true)
		{
			s.insert(0, to_string(cnt % 2));
			cnt /= 2;

			if (cnt == 0)
			{
				break;
			}
		}
	}
}

int main()
{
	string s = "110010101001";
	solution(s);
}