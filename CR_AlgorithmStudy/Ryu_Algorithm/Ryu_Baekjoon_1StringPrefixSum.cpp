#include <bits/stdc++.h>

using namespace std;

// 1_일곱 난쟁이
// https://www.acmicpc.net/problem/2309
//// 9명 중 7명의 합이 100
//// 순서와 상관없이 합하여 100이므로 조합
//vector<int> vecN(9);
//int Sum;
//
//void Combi(int start, vector<int> vec)
//{
//	if (7 == vec.size() && 100 == Sum)
//	{
//		sort(vec.begin(), vec.end());
//		for (int i : vec) cout << i << "\n";
//
//		// return을 했을 때 가능한 정답이 여러가지인 경우 모두 호출되기 때문에 오답으로 처리됨
//		// 따라서 해당 재귀를 아예 탈출할 수 있게 exit(0)으로 해줘야 함
//		exit(0);
//	}
//
//	for (int i = start + 1; i < vecN.size(); ++i)
//	{
//		vec.push_back(vecN[i]);
//		Sum += vecN[i];
//		Combi(i, vec);
//		vec.pop_back();
//		Sum -= vecN[i];
//	}
//
//	return;
//}
//
//int main()
//{
//	for (int i = 0; i < vecN.size(); ++i)
//	{
//		cin >> vecN[i];
//	}
//
//	vector<int> m_vector;
//
//	Combi(-1, m_vector);
//
//	return 0;
//}

// 또 다른 풀이법(순열)
// 9개 중 7개 뽑는다, 순서와 상관이 없다 9C7
// 그런데 이 문제는 9P7로도 뽑을 수 있다 Permutation은 순서와 상관있지만 n(== 9)의 수 자체가 작기 때문에 가능
// 9P7 => 9! / 2! => 9 * 8 * 7 * 6 * 5 * 4 * 3 => 181440
//int arr[9];
//
//int main()
//{
//	// 아홉 난쟁이의 키 입력 받기
//	for (int i = 0; i < 9; ++i)
//	{
//		cin >> arr[i];
//	}
//
//	// 순열을 할 때는 항상 정렬. 오름차순으로 해줘야 함
//	sort(arr, arr + 9);
//
//	do
//	{
//		// 디버깅 코드
//		for (int i : arr) cout << i << " ";
//		cout << "\n";
//
//		// 로직
//		// Sum을 0으로 계속 초기화
//		int Sum = 0;
//		// 일곱 난쟁이의 합
//		for (int i = 0; i < 7; ++i) Sum += arr[i];
//		// 합이 100일 때 멈춤
//		if (100 == Sum) break;
//	} while (next_permutation(arr, arr + 9));
//
//	for (int i = 0; i < 7; ++i) cout << arr[i] << "\n";
//
//	return 0;
//}

// 또 다른 풀이법(조합)
// 9C7은 9C2와 같다
// 정상적인 일곱 난쟁이를 뽑는 것과 비정상적인 두 난쟁이를 뽑아내는 것은 결국 같은 로직이나 다름없다
// 100 + A + B가 아홉 난쟁이의 합일 것. 그 중 A와 B를 찾아낸다는 것은 100 == 전체 - (A + B)

// 2개 뽑이라 pair 사용
//pair<int, int> ret;
//vector<int> vec;
//int arr[9];
//int Sum;
//
//void Solve()
//{
//	// 9C2이니까 중첩for문은 2번만
//	for (int i = 0; i < 9; ++i)
//	{
//		for (int j = 0; j < i; ++j)
//		{
//			// 로직
//			if (100 == Sum - (arr[i] + arr[j]))
//			{
//				ret = { i, j };
//				return;
//			}
//		}
//	}
//}
//
//int main()
//{
//	for (int i = 0; i < 9; ++i)
//	{
//		// 입력 받기
//		cin >> arr[i];
//		// 전체 합 구하기
//		Sum += arr[i];
//	}
//	
//	Solve();
//
//	for (int i = 0; i < 9; ++i)
//	{
//		// 가짜 난쟁이 둘 중 하나에 해당 할 경우 건너 뛴다 == continue
//		if (ret.first == i || ret.second == i) continue;
//		// 진짜 난쟁이 일곱만 벡터에 넣어줌
//		vec.push_back(arr[i]);
//	}
//
//	// 오름차순 출력을 위한 정렬
//	sort(vec.begin(), vec.end());
//	for (int i : vec) cout << i << "\n";
//
//	return 0;
//}

// 또 다른 풀이법(재귀순열)
//int arr[9];
//int n = 9, r = 7;
//
//void Solve()
//{
//	// 합산 0으로 초기화 작업
//	int Sum = 0;;
//
//	// 합산 작업
//	for (int i = 0; i < r; ++i) Sum += arr[i];
//	// 합산이 100일 경우
//	if (100 == Sum)
//	{
//		// 오름차순
//		sort(arr, arr + 7);
//		for (int i = 0; i < r; ++i) cout << arr[i] << "\n";
//		// main 함수 자체가 종료
//		// retunr을 하게 되면 해당 함수만 종료
//		exit(0);
//	}
//}
//
//void MakePermutation(int n, int r, int depth)
//{
//	// 7개 뽑기
//	if (r == depth)
//	{
//		Solve();
//
//		return;
//	}
//
//	for (int i = depth; i < n; ++i)
//	{
//		swap(arr[i], arr[depth]);
//		MakePermutation(n, r, depth + 1);
//		swap(arr[i], arr[depth]);
//	}
//
//	return;
//}
//
//int main()
//{
//	// 입력 받기
//	for (int i = 0; i < 9; ++i)
//	{
//		cin >> arr[i];
//	}
//
//	MakePermutation(n, r, 0);
//
//	return 0;
//}

// 2_알파벳 개수
// https://www.acmicpc.net/problem/10808
// 입력으로 들어오는 문자열에서 각 알파벳 단어가 몇 개인지 a~z까지 표현하는 것으로 개별 카운팅
//int AlphabetArr[26];
//
//int main()
//{
//	string m_str = "";
//	cin >> m_str;
//
//	for (int i = 0; i < m_str.size(); ++i)
//	{
//		// 아스키코드 생각하여 인덱스 별로 동일 알파벳 수 누적
//		++AlphabetArr[m_str[i] - 97];
//	}
//
//	for (int i = 0; i < 26; ++i)
//	{
//		cout << AlphabetArr[i] << " ";
//	}
//
//	cout << "\n";
//
//	return 0;
//}

// 또 다른 풀이법(Counting Star - map, array)
// map은 key-value => char(key)-int(value)
// map은 보통 string을 기반으로 했을 때 사용
// array는 인티저형 배열 인덱스로 접근하여 증감연산자로 카운팅
// array는 보통 int를 기반으로 했을 때 사용. 단, 10만 100만 1000만의 큰 수가 들어올 경우에는 map을 추천
// 다만 해당 문제는 문자를 카운팅하는 것. 따라서 배열로 쓰는 것이 좋을지도..?
// 아스키코드 - A(65), a(97) / 아스키코드는 문자가 숫자로 맵핑되어 있는 것
// cnt['a'] == cnt[97]

// * 전역변수로 사용하게 되면 0으로 초기화 작업이 됨 => 컴파일에서 최적화를 시키기 때문
// * 지역변수로 쓰게될 경우 항상 쓰레기 값이 들어가기 때문에 코딩 테스트를 한다 했을 때 전역변수 사용이 좋음 
//int cnt[26];
//string str;
//
//int main()
//{
//	cin >> str;
//
//	for (char a : str)
//	{
//		// 좌표이동을 이용한 배열로 a(97)만큼을 땡길거니까 들어오는 알파벳 - a
//		++cnt[a - 'a'];
//	}
//
//	for (int i : cnt) cout << i << " ";
//
//	return 0;
//}

// 3_트럭 주차
// https://www.acmicpc.net/problem/2979
// 시간을 배열로 잡아 카운팅하고 연산
// 시간은 1과 100 사이이므로 array[100]
//int TimeCnt[100];
//int A, B, C, Sum;
//
//int main()
//{
//	// 차량 수에 따른 요금 입력 받기
//	cin >> A >> B >> C;
//
//	// 3대의 차량 출입 시간
//	for (int i = 0; i < 3; ++i)
//	{
//		int In, Out = 0;
//		cin >> In >> Out;
//
//		// 시간대 별 차량 수 카운팅
//		for (int j = In; j < Out; ++j)
//		{
//			++TimeCnt[j];
//		}
//	}
//
//	// 시간에 따른 차량 주차 요금 정산 로직
//	for (int i : TimeCnt)
//	{
//		if (1 == i) Sum += i * A;
//		else if (2 == i) Sum += i * B;
//		else if (3 == i) Sum += i * C;
//	}
//
//	cout << Sum << "\n";
//
//	return 0;
//}

// 또 다른 풀이법(Counting)
// 시간은 이상 미만이다
// 풀이는 내 풀이랑 유사
//int A, B, C, a, b, cnt[104], ret;
//
//int main()
//{
//	cin >> A >> B >> C;
//
//	for (int i = 0; i < 3; ++i)
//	{
//		cin >> a >> b;
//
//		// 시간의 이상 미만을 표현. a는 포함되어 있고 b는 포함되어있지 않음
//		for (int j = a; j < b; ++j) ++cnt[j];
//	}
//
//	// 문제의 최대 범위가 100이기 때문에 100까지만 확인
//	for (int j = 1; j < 100; ++j)
//	{
//		// 트럭이 있다면
//		if (0 != cnt[j])
//		{
//			if (1 == cnt[j]) ret += A;
//			// 차량이 두대니까 곱하기 2(한대당 요금이 B)
//			else if (2 == cnt[j]) ret += B * 2;
//			// 차량이 세대니까 곱하기 3(한대당 요금이 C)
//			else if (3 == cnt[j]) ret += C * 3;
//		}
//	}
//
//	cout << ret << "\n";
//
//	return 0;
//}

// 4_팰린드롬인지 확인하기
// https://www.acmicpc.net/problem/10988
// 팰린드롬이란 앞뒤로 읽을 때 동일한 단어
// 뒤집어서 현재 문자랑 같은지 확인하면 되지 않을까? 
//string str, revstr;
//bool ret;
//
//int main()
//{
//	cin >> str;
//
//	// 문자열 복사
//	revstr = str;
//	// 복사한 문자열 뒤집기
//	reverse(revstr.begin(), revstr.end());
//
//	// compare 함수를 이용하여 원본 문자와 뒤집은 문자가 같다는 0일 경우 true 0이 아닐 경우 false
//	ret = 0 == str.compare(revstr) ? true : false;
//
//	cout << ret << "\n";
//
//	return 0;
//}

// 또 다른 풀이법(reverse)
// 팰린드롬은 회문, 어떠한 문자열이 회문인지를 확인하는 로직을 구현하면 됨
// 풀이는 내 풀이와 유사
//string s, temp;
//
//int main()
//{
//	cin >> s;
//
//	temp = s;
//	reverse(temp.begin(), temp.end());
//
//	if (temp == s) cout << 1 << "\n";
//	else cout << 0 << "\n";
//
//	return 0;
//}

// 5_농구 경기
// https://www.acmicpc.net/problem/1159
// 성의 첫 글자가 같은 선수 5명 => 순서가 상관없는 조합
// 조합이라고 생각했으나 예제 케이스 및 문제 상황을 봤을 때 카운팅배열 문제로 추정
// n: 인원수
//vector<int> namecnt(26);
//string str, ret;
//int n;
//
//int main()
//{
//	cin >> n;
//
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> str;
//		++namecnt[str[0] - 97];
//	}
//
//	for (int i = 0; i < namecnt.size(); ++i)
//	{
//		if (5 <= namecnt[i])
//		{
//			ret += i + 'a';
//		}
//	}
//
//	if (true == ret.empty()) ret = "PREDAJA";
//
//	cout << ret << "\n";
//
//	return 0;
//}

// 또 다른 풀이법(countingarray)
// 내 풀이와 유사
//int n, cnt[26];
//string s, ret;
//
//int main()
//{
//	cin >> n;
//
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> s;
//		// 첫 글자에 대한 카운팅
//		// 문자를 숫자화 시킴
//		++cnt[s[0] - 'a'];
//	}
//
//	for (int i = 0; i < 26; ++i)
//	{
//		if (5 <= cnt[i])
//		{
//			// 아스키코드를 활용하여 5 이상의 알파벳 담기
//			// 숫자를 문자화 시킴
//			ret += (i + 'a');
//		}
//	}
//
//	if (0 != ret.size()) cout << ret << "\n";
//	else cout << "PREDAJA" << "\n";
//
//	return 0;
//}

// 6_ROT13
// https://www.acmicpc.net/problem/11655
// 문자열을 받아서 대소문자인 경우에만 13자를 미루기?
//string str;
//
//int main()
//{
//    // getline을 이용하여 문자열 받기
//    getline(cin, str);
//
//    for (int i = 0; i < str.size(); ++i)
//    {
//        // 대문자인경우
//        if (65 <= str[i] && 90 >= str[i])
//        {
//            // 아스키코드 90을 초과한 경우 Z를 넘었을 경우
//            if (90 < str[i] + 13) str[i] -= 13;
//            else str[i] += 13;
//        }
//        // 소문자인경우
//        else if (97 <= str[i] && 122 >= str[i])
//        {
//            // 아스키코드 122를 초과한 경우 z를 넘었을 경우
//            if (122 < str[i] + 13) str[i] -= 13;
//            else str[i] += 13;
//        }
//
//        cout << str[i];
//    }
//
//    return 0;
//}

// 또 다른 풀이법(?)
// 아스키코드 암기할 건 2개 => A - 65, a - 97
// 내 풀이와 동일
string s;

int main()
{
	getline(cin, s);

	for (int i = 0; i < s.size(); ++i)
	{
		// 대문자
		if (65 <= s[i] && 97 > s[i])
		{
			if (90 < s[i] + 13) s[i] = s[i] + 13 - 26;
			else s[i] = s[i] + 13;
		}
		// 소문자
		else if (97 <= s[i] && 122 >= s[i])
		{
			if (122 < s[i] + 13) s[i] = s[i] + 13 - 26;
			else s[i] = s[i] + 13;
		}

		cout << s[i];
	}

	return 0;
}