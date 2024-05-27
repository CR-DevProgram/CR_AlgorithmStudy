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
//string s;
//
//int main()
//{
//	getline(cin, s);
//
//	for (int i = 0; i < s.size(); ++i)
//	{
//		// 대문자
//		if (65 <= s[i] && 97 > s[i])
//		{
//			if (90 < s[i] + 13) s[i] = s[i] + 13 - 26;
//			else s[i] = s[i] + 13;
//		}
//		// 소문자
//		else if (97 <= s[i] && 122 >= s[i])
//		{
//			if (122 < s[i] + 13) s[i] = s[i] + 13 - 26;
//			else s[i] = s[i] + 13;
//		}
//
//		cout << s[i];
//	}
//
//	return 0;
//}

// 7_한국이 그리울 땐 서버에 접속하지
// https://www.acmicpc.net/problem/9996
// 파일의 앞뒤 문자를 통하여 손상된 파일 패턴을 구하는 문제로 파일명의 앞뒤 문자를 얻오는 것이 중점
// *를 기준으로 앞뒤 문자열의 길이는 알 수 없는 듯... 하나라는 가정으로 구현했을 때 오답처리 받음
// 따라서 *를 기준으로 앞 뒤 문자열을 구해서 비교하여 출력하는 형식으로 변경
// 앞뒤 문자열의 총 크기와 파일명의 크기를 유의해야함 애초에 전자가 후자보다 클 경우 후자는 NE이므로 미리 걸러내는 과정이 필요(이 부분 안해줘서 오답처리 받음)
// n: 파일 개수
//int n, pos;
//string filepattern, filename;
//
//int main()
//{
//	cin >> n;
//	cin >> filepattern;
//
//	pos = filepattern.find('*');
//	// *표 앞 문자열
//	string frontpat = filepattern.substr(0, pos);
//	// *표 뒷 문자열
//	string backpat = filepattern.substr(pos + 1);
//
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> filename;
//
//		// *표 앞뒤 문자열보다 파일명의 사이즈가 작으면 범위를 넘어서게 되므로 작을 경우의 별도 처리 필요
//		if (filename.size() < frontpat.size() + backpat.size()) cout << "NE" << "\n";
//		// *표 앞뒤 문자열보다 파일명의 사이즈가 큰 경우 파일명 비교 작업
//		else
//		{
//			if (0 == frontpat.compare(filename.substr(0, frontpat.size())) && 0 == backpat.compare(filename.substr(filename.size() - backpat.size()))) cout << "DA" << "\n";
//			else cout << "NE" << "\n";
//		}
//	}
//
//	return 0;
//}

// 또 다른 풀이법(?)
// 내 풀이와 유사? 동일?
//int n;
//string s, ori_s, pre, suf;
//
//int main()
//{
//	cin >> n;
//	cin >> ori_s;
//
//	int pos = ori_s.find('*');
//	pre = ori_s.substr(0, pos);
//	suf = ori_s.substr(pos + 1);
//
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> s;
//
//		// 반례를 위한 코드
//		// 만약 ab*ab일 때 비교하는 파일명이 ab로 들어올 경우 맞다고 처리가 됨
//		// 따라서 접두사와 접미사를 더한 사이즈보다 큰 사이즈가 와야 될 것
//		if (s.size() < pre.size() + suf.size())
//		{
//			cout << "NE\n";
//		}
//		else
//		{
//			// 메인 로직
//			if (pre == s.substr(0, pre.size()) && suf == s.substr(s.size() - suf.size())) cout << "DA\n";
//			else cout << "NE\n";
//		}
//	}
//
//	return 0;
//}

// 8_수열
// https://www.acmicpc.net/problem/2559
// 누적합을 이용해서 하는 것 같은데 오랜만에 해서 그런가 VS로 돌리면 테케 통과되고 했지만
// 백준으로 제출하면 자꾸 범위기반 오류 혹은 빈 컨테이너 오류 발생(대체 왜지?)
// 원래는 벡터 두개를 이용해서 하나는 sort함수 이용한 후 제일 큰 값을 꺼내서 출력했지만
// 오류 사항 때문에 max함수로 값을 비교해서 제일 큰 값을 출력하게 변경
// n: 전체 날짜 수 2이상 100000이하
// k: 연속적인 날짜 수 1과 n사이
//int n, k, num, ret = -1000000;
//vector<int> perfixsum;
//
//int main()
//{
//	cin >> n >> k;
//	// 공간 재할당 
//	perfixsum.resize(n);
//
//	// 인덱스 1번부터 입력받은 누적 값을 넣어줌
//	for (int i = 1; i < n + 1; ++i)
//	{
//		int temp = 0;
//		cin >> temp;
//		num += temp;
//		perfixsum[i] = num;
//	}
//
//	// k만큼의 합산을 구하기 위한 반복문
//	// 해당 과정에서 최대값 뽑아내기
//	for (int i = k; i < perfixsum.size(); ++i)
//	{
//		ret = max(ret, perfixsum[i] - perfixsum[i - k]);
//	}
//
//	cout << ret << "\n";
//
//	return 0;
//}

// 또 다른 풀이법(?)
// 내 풀이와 유사
// k의 범위는 1~n 사이값이므로 1~10만-1
// 최대값 최솟값을 구하라하면 구간합을 떠올려라
// 최댓값을 구하라 => 최솟값 기준을 잡아라(max를 쓸거니까)
// 최솟값을 구하라 => 최댓값 기준을 잡아라(min을 쓸거니까)
// 그렇다면 이 문제의 최솟값은? => 최악의 경우를 고려하여 -100 * 10만번 => -1000만
//int n, k, temp, ret = -1000000, perfixsum[100000];
//
//int main()
//{
//	cin >> n >> k;
//
//	for (int i = 1; i <= n; ++i)
//	{
//		cin >> temp; 
//		perfixsum[i] = perfixsum[i - 1] + temp;
//	}
//
//	for (int i = k; i <= n; ++i)
//	{
//		ret = max(ret, perfixsum[i] - perfixsum[i - k]);
//	}
//
//	cout << ret << "\n";
//	
//	return 0;
//}

// 9_나는야 포켓몬 마스터 이다솜
// https://www.acmicpc.net/problem/1620
// 단순하게 벡터 컨테이너 하나로 돌리면서 find 사용하면 되겠다 싶었지만
// 어림없지 시간초과!
// 따라서 맵을 사용해줘서 잘 될 줄 알았으나 또.. 시간 초과ㅠ 구글링 빡시게 함
// cout과 cin은 입출력으로 묶여 있고 입력 요청이 들어오면 출력 버퍼를 비워 출력하게 되는데
// 이 작업이 반복되면 버퍼를 지운다고 오래 걸린다고 함
// 따라서 끊어주는 작업으로 cin.tie(NULL);을 써줘야 된다고 함
// n: 도감에 등록되어 있는 포켓몬 개수
// m: 맞춰야 하는 문제 개수
//int n, m;
////vector<string> pocketmon;
//map<int, string> mapNumberkey;
//map<string, int> mapNamekey;
//
//int main()
//{
//	// 아래 코드 추가 안하면 시간초과
//	// 몇 시간동안... 왜 시간 초과가 나는 것인지 검색 열심히 함ㅠ
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//	
//	cin >> n >> m;
//	//pocketmon.resize(n + 1);
//
//	for (int i = 1; i <= n; ++i)
//	{
//		string name = "";
//		cin >> name;
//
//		//pocketmon[i] = name;
//		mapNamekey[name] = i;
//		mapNumberkey[i] = name;
//	}
//
//	// 시간 초과(find 함수 사용해서 그런거 같음)
//	//for (int i = 0; i < m; ++i)
//	//{
//	//	string quiz = "";
//	//	cin >> quiz;
//
//	//	// 0이면 문자 0이 아니면 숫자
//	//	// 문자
//	//	if (0 == isdigit(quiz[0]))
//	//	{
//	//		int idx = find(pocketmon.begin(), pocketmon.end(), quiz) - pocketmon.begin();
//	//		cout << idx << "\n";
//	//	}
//	//	// 숫자
//	//	else
//	//	{
//	//		cout << pocketmon[stoi(quiz)] << "\n";
//	//	}
//	//}
//
//	for (int i = 0; i < m; ++i)
//	{
//		string quiz = "";
//		cin >> quiz;
//
//		if (0 == isdigit(quiz[0]))
//		{
//			cout << mapNamekey[quiz] << "\n";
//		}
//		else
//		{
//			cout << mapNumberkey[stoi(quiz)] << "\n";
//		}
//	}
//
//	return 0;
//}

// 또 다른 풀이법(?)
// 내 풀이와 유사
// 문자열을 int로 바꿀 때 atoi(문자열.c_str())
// 배열의 find 함수의 시간복잡도는 O(n)
//int n, m;
//string s;
//string a[100004];
//map<string, int> mp;
//map<int, string> mp2;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	cin >> n >> m;
//
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> s;
//
//		mp[s] = i + 1;
//		mp2[i + 1] = s;
//		a[i + 1] = s;
//	}
//
//	for (int i = 0; i < m; ++i)
//	{
//		cin >> s;
//
//		if (0 == atoi(s.c_str()))
//		{
//			cout << mp[s] << "\n";
//		}
//		else
//		{
//			cout << a[atoi(s.c_str())] << "\n";
//			//cout << mp2[atoi(s.c_str())] << "\n";
//		}
//	}
//
//	return 0;
//}

// 10_패션왕 신해빈
// https://www.acmicpc.net/problem/9375
// 조합 관련이지만 간단하게 곱셈으로 풀이 가능
// 근데 왜 25%에서 계속 안되는걸까.. 반례 수집해서 확인했는데 모두 통과되고
// 강사님 답안과의 차이도 크게 없어보이는데 이유를 알 수 없음
// 나중에 별도로 풀어봐야 될 듯
// n: 가진 의상의 수
//int m, n;
//string name, type;
//map<string, vector<string>> match;
//
//int main()
//{
//	cin >> m;
//
//	while (0 < m)
//	{
//		--m;
//		cin >> n;
//
//		for (int i = 0; i < n; ++i)
//		{
//			cin >> name >> type;
//
//			match[type].push_back(name);
//		}
//
//		int count = 1;
//		for (auto matchtype : match)
//		{
//			// 안 입는 경우도 고려하여 경우의 수 하나 더 추가
//			count *= matchtype.second.size() + 1;
//		}
//
//		// 아예 안 입는 방법은 없으므로 -1
//		cout << count - 1 << "\n";
//	}
//
//	return 0;
//}

// 또 다른 풀이법(?)
// 내 풀이와 유사
// 굳이 문자열로 담을 필요 없이 타입에 따른 가짓수를 이용해 연산
// 강사님꺼는 되는데 내껀 왜 안돼?!!!!!!!!!
//int Type, Count;
//string a, b;
//
//int main()
//{
//    cin >> Type;
//
//    while (0 < Type)
//    {
//        map<string, int> map_Match;
//        cin >> Count;
//        for (int i = 0; i < Count; ++i)
//        {
//            cin >> a >> b;
//            ++map_Match[b];
//        }
//
//        long long ret = 1;
//        for (auto tmp : map_Match)
//        {
//            ret *= ((long long)tmp.second + 1);
//        }
//        --ret;
//
//        cout << ret << "\n";
//
//        --Type;
//    }
//
//    return 0;
//}

// 11_팰린드롬 만들기
// https://www.acmicpc.net/problem/1213
// 중앙을 기점으로 뒤집어서 동일한 문자로 생성해야 하는 문제니까 중간까지 문자 정리 후 뒤집은거 붙이면 가능할 듯
// 단 문자가 홀수의 형태로 반전이 가능한 부분도 고려해야 함
//string name, ret;
//int midcount;				// 홀수가 몇 번 오는지 확인 용도(2번 넘게 오면 대칭 문자 생성 불가)
////pair<char, int> midinfo;	// 홀수로 오게 될 경우 중앙 위치에 들어갈 정보
//char midchar;
//int namecount[26];			// 문자별 횟수 누적 카운팅
//
//int main()
//{
//	cin >> name;
//
//	for (int i = 0; i < name.size(); ++i)
//	{
//		// 입력된 문자별 횟수 관리
//		++namecount[name[i] - 'A'];
//	}
//
//	for (int i = 0; i < 26; ++i)
//	{
//		// 문자별 누적 카운트가 홀수일 때 로직
//		if (1 == namecount[i] % 2)
//		{
//			++midcount;
//			//midinfo = { i + 'A', --namecount[i] };
//			midchar = i + 'A';
//			--namecount[i];
//		}
//
//		// 홀수 체크가 2번 이상(1초과일 경우) 지정된 문자열 담은 후 반복문 탈출
//		// 해당 조건 체크를 위로 두면 마지막 Z 체크 시 midcount가 증가 됐을 때
//		// 조건에 들어오지 않아서 ret이 빈 값으로 출력되는 문제 발생, 따라서 최종적 확인을 위해 하단에서 조건 확인
//		if (2 <= midcount)
//		{
//			ret = "I'm Sorry Hansoo";
//
//			break;
//		}
//	}
//
//	if (1 >= midcount)
//	{
//		for (int i = 0; i < 26; ++i)
//		{
//			// 절반만 생성하는 작업을 위해 누적 카운트의 절반만 반복해서 문자 추가
//			for (int j = 0; j < namecount[i] * 0.5f; ++j)
//			{
//				ret += (i + 'A');
//			}
//		}
//
//		// 반전 및 최종 출력 작업
//		string reverseret = ret;
//		reverse(reverseret.begin(), reverseret.end());
//		//ret = 0 == midinfo.first ? ret + reverseret : ret + midinfo.first + reverseret;
//		ret = '\0' == midchar ? ret + reverseret : ret + midchar + reverseret;
//	}
//
//	cout << ret << "\n";
//
//	return 0;
//}

// 또 다른 풀이법(비트연산자, 높은 아스키코드부터 덧붙이기 이용)
// 불가능한 경우: 홀수가 2개 이상
// 아스키코드 상 가장 위에 있는 것을 먼저
//string s, ret;
//int cnt[200], flag;
//char mid;
//
//int main()
//{
//	cin >> s;
//
//	// 카운팅배열 이용
//	for (char a : s) ++cnt[a];
//
//	// Z부터 붙이기
//	for (int i = 'Z'; i >= 'A'; --i)
//	{
//		// 카운팅 배열에 누적되어 있다면 
//		if (0 != cnt[i])
//		{
//			// & 1: 홀수를 뜻함
//			// 홀수의 경우 이진수로 나타내면 마지막 비트값이 1
//			// 짝수의 경우 이진수로 나타내면 마지막 비트값이 0
//			// 따라서 해당 cnt[i] & 1 코드는 '홀수일 경우'라는 뜻
//			if (cnt[i] & 1)
//			{
//				// 홀수 하나가 들어왔을 때 중간에 넣기 위한 작업
//				mid = char(i);
//				++flag;
//				--cnt[i];
//			}
//
//			// flag 즉 홀수가 2개 이상이면 break
//			if (2 == flag) break;
//
//			// 문자 붙이기
//			// j += 2인 이유는 앞뒤로 붙이면서 카운트 2개가 소모되기 때문
//			for (int j = 0; j < cnt[i]; j += 2)
//			{
//				ret = char(i) + ret;	// 앞에 붙이기
//				ret += char(i);			// 뒤에 붙이기
//			}
//		}
//	}
//
//	// 중앙에 mid 삽입
//	if (mid) ret.insert(ret.begin() + ret.size() / 2, mid);
//	if (2 == flag) cout << "I'm Sorry Hansoo\n";
//	else cout << ret << "\n";
//
//	return 0;
//}

// 12_주몽
// https://www.acmicpc.net/problem/1940
// 두 재료의 합산을 통해 몇 개의 장비를 만들 수 있는 것으로 순서와 상관 없는 조합
// 대신 2개의 조합이므로 콤비 재귀 함수 없이 이중 포문으로 해결 가능
// n: 재료 개수
// m: 갑옷을 만드는데 필요한 수
//int n, m, ret;
//int materialnumbers[15000];
//
//int main()
//{
//	cin >> n >> m;
//
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> materialnumbers[i];
//	}
//
//	for (int i = 0; i < n; ++i)
//	{
//		for (int j = i + 1; j < n; ++j)
//		{
//			if (m == materialnumbers[i] + materialnumbers[j])
//			{
//				++ret;
//			}
//		}
//	}
//
//	cout << ret << "\n";
//
//	return 0;
//}

// 또 다른 풀이법(?)
// 내 풀이와 유사
// 15000개 이하의 재료 두 가지, 재료는 고유 번호 존재
// 재료 두개의 합 카운팅
// 재료를 고를 때 순서 상관X 따라서 조합
int n, m, a[15001], cnt;

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; ++i) cin >> a[i];

	// 문제마다 다르지만 시간 초과가 생기는 빠듯한 경우일 때를 대비
	// 예외처리를 통해 시간초과를 줄이는 법
	if (200000 < m) cout << 0 << "\n";
	else
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				if (m == a[i] + a[j]) ++cnt;
			}
		}
	}

	cout << cnt << "\n";

	return 0;
}
