#include <bits/stdc++.h>

using namespace std;

// 1_�ϰ� ������
// https://www.acmicpc.net/problem/2309
//// 9�� �� 7���� ���� 100
//// ������ ������� ���Ͽ� 100�̹Ƿ� ����
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
//		// return�� ���� �� ������ ������ ���������� ��� ��� ȣ��Ǳ� ������ �������� ó����
//		// ���� �ش� ��͸� �ƿ� Ż���� �� �ְ� exit(0)���� ����� ��
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

// �� �ٸ� Ǯ�̹�(����)
// 9�� �� 7�� �̴´�, ������ ����� ���� 9C7
// �׷��� �� ������ 9P7�ε� ���� �� �ִ� Permutation�� ������ ��������� n(== 9)�� �� ��ü�� �۱� ������ ����
// 9P7 => 9! / 2! => 9 * 8 * 7 * 6 * 5 * 4 * 3 => 181440
//int arr[9];
//
//int main()
//{
//	// ��ȩ �������� Ű �Է� �ޱ�
//	for (int i = 0; i < 9; ++i)
//	{
//		cin >> arr[i];
//	}
//
//	// ������ �� ���� �׻� ����. ������������ ����� ��
//	sort(arr, arr + 9);
//
//	do
//	{
//		// ����� �ڵ�
//		for (int i : arr) cout << i << " ";
//		cout << "\n";
//
//		// ����
//		// Sum�� 0���� ��� �ʱ�ȭ
//		int Sum = 0;
//		// �ϰ� �������� ��
//		for (int i = 0; i < 7; ++i) Sum += arr[i];
//		// ���� 100�� �� ����
//		if (100 == Sum) break;
//	} while (next_permutation(arr, arr + 9));
//
//	for (int i = 0; i < 7; ++i) cout << arr[i] << "\n";
//
//	return 0;
//}

// �� �ٸ� Ǯ�̹�(����)
// 9C7�� 9C2�� ����
// �������� �ϰ� �����̸� �̴� �Ͱ� ���������� �� �����̸� �̾Ƴ��� ���� �ᱹ ���� �����̳� �ٸ�����
// 100 + A + B�� ��ȩ �������� ���� ��. �� �� A�� B�� ã�Ƴ��ٴ� ���� 100 == ��ü - (A + B)

// 2�� ���̶� pair ���
//pair<int, int> ret;
//vector<int> vec;
//int arr[9];
//int Sum;
//
//void Solve()
//{
//	// 9C2�̴ϱ� ��øfor���� 2����
//	for (int i = 0; i < 9; ++i)
//	{
//		for (int j = 0; j < i; ++j)
//		{
//			// ����
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
//		// �Է� �ޱ�
//		cin >> arr[i];
//		// ��ü �� ���ϱ�
//		Sum += arr[i];
//	}
//	
//	Solve();
//
//	for (int i = 0; i < 9; ++i)
//	{
//		// ��¥ ������ �� �� �ϳ��� �ش� �� ��� �ǳ� �ڴ� == continue
//		if (ret.first == i || ret.second == i) continue;
//		// ��¥ ������ �ϰ��� ���Ϳ� �־���
//		vec.push_back(arr[i]);
//	}
//
//	// �������� ����� ���� ����
//	sort(vec.begin(), vec.end());
//	for (int i : vec) cout << i << "\n";
//
//	return 0;
//}

// �� �ٸ� Ǯ�̹�(��ͼ���)
//int arr[9];
//int n = 9, r = 7;
//
//void Solve()
//{
//	// �ջ� 0���� �ʱ�ȭ �۾�
//	int Sum = 0;;
//
//	// �ջ� �۾�
//	for (int i = 0; i < r; ++i) Sum += arr[i];
//	// �ջ��� 100�� ���
//	if (100 == Sum)
//	{
//		// ��������
//		sort(arr, arr + 7);
//		for (int i = 0; i < r; ++i) cout << arr[i] << "\n";
//		// main �Լ� ��ü�� ����
//		// retunr�� �ϰ� �Ǹ� �ش� �Լ��� ����
//		exit(0);
//	}
//}
//
//void MakePermutation(int n, int r, int depth)
//{
//	// 7�� �̱�
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
//	// �Է� �ޱ�
//	for (int i = 0; i < 9; ++i)
//	{
//		cin >> arr[i];
//	}
//
//	MakePermutation(n, r, 0);
//
//	return 0;
//}

// 2_���ĺ� ����
// https://www.acmicpc.net/problem/10808
// �Է����� ������ ���ڿ����� �� ���ĺ� �ܾ �� ������ a~z���� ǥ���ϴ� ������ ���� ī����
//int AlphabetArr[26];
//
//int main()
//{
//	string m_str = "";
//	cin >> m_str;
//
//	for (int i = 0; i < m_str.size(); ++i)
//	{
//		// �ƽ�Ű�ڵ� �����Ͽ� �ε��� ���� ���� ���ĺ� �� ����
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

// �� �ٸ� Ǯ�̹�(Counting Star - map, array)
// map�� key-value => char(key)-int(value)
// map�� ���� string�� ������� ���� �� ���
// array�� ��Ƽ���� �迭 �ε����� �����Ͽ� ���������ڷ� ī����
// array�� ���� int�� ������� ���� �� ���. ��, 10�� 100�� 1000���� ū ���� ���� ��쿡�� map�� ��õ
// �ٸ� �ش� ������ ���ڸ� ī�����ϴ� ��. ���� �迭�� ���� ���� ��������..?
// �ƽ�Ű�ڵ� - A(65), a(97) / �ƽ�Ű�ڵ�� ���ڰ� ���ڷ� ���εǾ� �ִ� ��
// cnt['a'] == cnt[97]

// * ���������� ����ϰ� �Ǹ� 0���� �ʱ�ȭ �۾��� �� => �����Ͽ��� ����ȭ�� ��Ű�� ����
// * ���������� ���Ե� ��� �׻� ������ ���� ���� ������ �ڵ� �׽�Ʈ�� �Ѵ� ���� �� �������� ����� ���� 
//int cnt[26];
//string str;
//
//int main()
//{
//	cin >> str;
//
//	for (char a : str)
//	{
//		// ��ǥ�̵��� �̿��� �迭�� a(97)��ŭ�� ����Ŵϱ� ������ ���ĺ� - a
//		++cnt[a - 'a'];
//	}
//
//	for (int i : cnt) cout << i << " ";
//
//	return 0;
//}

// 3_Ʈ�� ����
// https://www.acmicpc.net/problem/2979
// �ð��� �迭�� ��� ī�����ϰ� ����
// �ð��� 1�� 100 �����̹Ƿ� array[100]
//int TimeCnt[100];
//int A, B, C, Sum;
//
//int main()
//{
//	// ���� ���� ���� ��� �Է� �ޱ�
//	cin >> A >> B >> C;
//
//	// 3���� ���� ���� �ð�
//	for (int i = 0; i < 3; ++i)
//	{
//		int In, Out = 0;
//		cin >> In >> Out;
//
//		// �ð��� �� ���� �� ī����
//		for (int j = In; j < Out; ++j)
//		{
//			++TimeCnt[j];
//		}
//	}
//
//	// �ð��� ���� ���� ���� ��� ���� ����
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

// �� �ٸ� Ǯ�̹�(Counting)
// �ð��� �̻� �̸��̴�
// Ǯ�̴� �� Ǯ�̶� ����
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
//		// �ð��� �̻� �̸��� ǥ��. a�� ���ԵǾ� �ְ� b�� ���ԵǾ����� ����
//		for (int j = a; j < b; ++j) ++cnt[j];
//	}
//
//	// ������ �ִ� ������ 100�̱� ������ 100������ Ȯ��
//	for (int j = 1; j < 100; ++j)
//	{
//		// Ʈ���� �ִٸ�
//		if (0 != cnt[j])
//		{
//			if (1 == cnt[j]) ret += A;
//			// ������ �δ�ϱ� ���ϱ� 2(�Ѵ�� ����� B)
//			else if (2 == cnt[j]) ret += B * 2;
//			// ������ ����ϱ� ���ϱ� 3(�Ѵ�� ����� C)
//			else if (3 == cnt[j]) ret += C * 3;
//		}
//	}
//
//	cout << ret << "\n";
//
//	return 0;
//}

// 4_�Ӹ�������� Ȯ���ϱ�
// https://www.acmicpc.net/problem/10988
// �Ӹ�����̶� �յڷ� ���� �� ������ �ܾ�
// ����� ���� ���ڶ� ������ Ȯ���ϸ� ���� ������? 
//string str, revstr;
//bool ret;
//
//int main()
//{
//	cin >> str;
//
//	// ���ڿ� ����
//	revstr = str;
//	// ������ ���ڿ� ������
//	reverse(revstr.begin(), revstr.end());
//
//	// compare �Լ��� �̿��Ͽ� ���� ���ڿ� ������ ���ڰ� ���ٴ� 0�� ��� true 0�� �ƴ� ��� false
//	ret = 0 == str.compare(revstr) ? true : false;
//
//	cout << ret << "\n";
//
//	return 0;
//}

// �� �ٸ� Ǯ�̹�(reverse)
// �Ӹ������ ȸ��, ��� ���ڿ��� ȸ�������� Ȯ���ϴ� ������ �����ϸ� ��
// Ǯ�̴� �� Ǯ�̿� ����
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

// 5_�� ���
// https://www.acmicpc.net/problem/1159
// ���� ù ���ڰ� ���� ���� 5�� => ������ ������� ����
// �����̶�� ���������� ���� ���̽� �� ���� ��Ȳ�� ���� �� ī���ù迭 ������ ����
// n: �ο���
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

// �� �ٸ� Ǯ�̹�(countingarray)
// �� Ǯ�̿� ����
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
//		// ù ���ڿ� ���� ī����
//		// ���ڸ� ����ȭ ��Ŵ
//		++cnt[s[0] - 'a'];
//	}
//
//	for (int i = 0; i < 26; ++i)
//	{
//		if (5 <= cnt[i])
//		{
//			// �ƽ�Ű�ڵ带 Ȱ���Ͽ� 5 �̻��� ���ĺ� ���
//			// ���ڸ� ����ȭ ��Ŵ
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
// ���ڿ��� �޾Ƽ� ��ҹ����� ��쿡�� 13�ڸ� �̷��?
//string str;
//
//int main()
//{
//    // getline�� �̿��Ͽ� ���ڿ� �ޱ�
//    getline(cin, str);
//
//    for (int i = 0; i < str.size(); ++i)
//    {
//        // �빮���ΰ��
//        if (65 <= str[i] && 90 >= str[i])
//        {
//            // �ƽ�Ű�ڵ� 90�� �ʰ��� ��� Z�� �Ѿ��� ���
//            if (90 < str[i] + 13) str[i] -= 13;
//            else str[i] += 13;
//        }
//        // �ҹ����ΰ��
//        else if (97 <= str[i] && 122 >= str[i])
//        {
//            // �ƽ�Ű�ڵ� 122�� �ʰ��� ��� z�� �Ѿ��� ���
//            if (122 < str[i] + 13) str[i] -= 13;
//            else str[i] += 13;
//        }
//
//        cout << str[i];
//    }
//
//    return 0;
//}

// �� �ٸ� Ǯ�̹�(?)
// �ƽ�Ű�ڵ� �ϱ��� �� 2�� => A - 65, a - 97
// �� Ǯ�̿� ����
//string s;
//
//int main()
//{
//	getline(cin, s);
//
//	for (int i = 0; i < s.size(); ++i)
//	{
//		// �빮��
//		if (65 <= s[i] && 97 > s[i])
//		{
//			if (90 < s[i] + 13) s[i] = s[i] + 13 - 26;
//			else s[i] = s[i] + 13;
//		}
//		// �ҹ���
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

// 7_�ѱ��� �׸��� �� ������ ��������
// https://www.acmicpc.net/problem/9996
// ������ �յ� ���ڸ� ���Ͽ� �ջ�� ���� ������ ���ϴ� ������ ���ϸ��� �յ� ���ڸ� ����� ���� ����
// *�� �������� �յ� ���ڿ��� ���̴� �� �� ���� ��... �ϳ���� �������� �������� �� ����ó�� ����
// ���� *�� �������� �� �� ���ڿ��� ���ؼ� ���Ͽ� ����ϴ� �������� ����
// �յ� ���ڿ��� �� ũ��� ���ϸ��� ũ�⸦ �����ؾ��� ���ʿ� ���ڰ� ���ں��� Ŭ ��� ���ڴ� NE�̹Ƿ� �̸� �ɷ����� ������ �ʿ�(�� �κ� �����༭ ����ó�� ����)
// n: ���� ����
//int n, pos;
//string filepattern, filename;
//
//int main()
//{
//	cin >> n;
//	cin >> filepattern;
//
//	pos = filepattern.find('*');
//	// *ǥ �� ���ڿ�
//	string frontpat = filepattern.substr(0, pos);
//	// *ǥ �� ���ڿ�
//	string backpat = filepattern.substr(pos + 1);
//
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> filename;
//
//		// *ǥ �յ� ���ڿ����� ���ϸ��� ����� ������ ������ �Ѿ�� �ǹǷ� ���� ����� ���� ó�� �ʿ�
//		if (filename.size() < frontpat.size() + backpat.size()) cout << "NE" << "\n";
//		// *ǥ �յ� ���ڿ����� ���ϸ��� ����� ū ��� ���ϸ� �� �۾�
//		else
//		{
//			if (0 == frontpat.compare(filename.substr(0, frontpat.size())) && 0 == backpat.compare(filename.substr(filename.size() - backpat.size()))) cout << "DA" << "\n";
//			else cout << "NE" << "\n";
//		}
//	}
//
//	return 0;
//}

// �� �ٸ� Ǯ�̹�(?)
// �� Ǯ�̿� ����? ����?
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
//		// �ݷʸ� ���� �ڵ�
//		// ���� ab*ab�� �� ���ϴ� ���ϸ��� ab�� ���� ��� �´ٰ� ó���� ��
//		// ���� ���λ�� ���̻縦 ���� ������� ū ����� �;� �� ��
//		if (s.size() < pre.size() + suf.size())
//		{
//			cout << "NE\n";
//		}
//		else
//		{
//			// ���� ����
//			if (pre == s.substr(0, pre.size()) && suf == s.substr(s.size() - suf.size())) cout << "DA\n";
//			else cout << "NE\n";
//		}
//	}
//
//	return 0;
//}

// 8_����
// https://www.acmicpc.net/problem/2559
// �������� �̿��ؼ� �ϴ� �� ������ �������� �ؼ� �׷��� VS�� ������ ���� ����ǰ� ������
// �������� �����ϸ� �ڲ� ������� ���� Ȥ�� �� �����̳� ���� �߻�(��ü ����?)
// ������ ���� �ΰ��� �̿��ؼ� �ϳ��� sort�Լ� �̿��� �� ���� ū ���� ������ ���������
// ���� ���� ������ max�Լ��� ���� ���ؼ� ���� ū ���� ����ϰ� ����
// n: ��ü ��¥ �� 2�̻� 100000����
// k: �������� ��¥ �� 1�� n����
//int n, k, num, ret = -1000000;
//vector<int> perfixsum;
//
//int main()
//{
//	cin >> n >> k;
//	// ���� ���Ҵ� 
//	perfixsum.resize(n);
//
//	// �ε��� 1������ �Է¹��� ���� ���� �־���
//	for (int i = 1; i < n + 1; ++i)
//	{
//		int temp = 0;
//		cin >> temp;
//		num += temp;
//		perfixsum[i] = num;
//	}
//
//	// k��ŭ�� �ջ��� ���ϱ� ���� �ݺ���
//	// �ش� �������� �ִ밪 �̾Ƴ���
//	for (int i = k; i < perfixsum.size(); ++i)
//	{
//		ret = max(ret, perfixsum[i] - perfixsum[i - k]);
//	}
//
//	cout << ret << "\n";
//
//	return 0;
//}

// �� �ٸ� Ǯ�̹�(?)
// �� Ǯ�̿� ����
// k�� ������ 1~n ���̰��̹Ƿ� 1~10��-1
// �ִ밪 �ּڰ��� ���϶��ϸ� �������� ���÷���
// �ִ��� ���϶� => �ּڰ� ������ ��ƶ�(max�� ���Ŵϱ�)
// �ּڰ��� ���϶� => �ִ� ������ ��ƶ�(min�� ���Ŵϱ�)
// �׷��ٸ� �� ������ �ּڰ���? => �־��� ��츦 ����Ͽ� -100 * 10���� => -1000��
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

// 9_���¾� ���ϸ� ������ �̴ټ�
// https://www.acmicpc.net/problem/1620
// �ܼ��ϰ� ���� �����̳� �ϳ��� �����鼭 find ����ϸ� �ǰڴ� �;�����
// ����� �ð��ʰ�!
// ���� ���� ������༭ �� �� �� �˾����� ��.. �ð� �ʰ��� ���۸� ���ð� ��
// cout�� cin�� ��������� ���� �ְ� �Է� ��û�� ������ ��� ���۸� ��� ����ϰ� �Ǵµ�
// �� �۾��� �ݺ��Ǹ� ���۸� ����ٰ� ���� �ɸ��ٰ� ��
// ���� �����ִ� �۾����� cin.tie(NULL);�� ����� �ȴٰ� ��
// n: ������ ��ϵǾ� �ִ� ���ϸ� ����
// m: ����� �ϴ� ���� ����
//int n, m;
////vector<string> pocketmon;
//map<int, string> mapNumberkey;
//map<string, int> mapNamekey;
//
//int main()
//{
//	// �Ʒ� �ڵ� �߰� ���ϸ� �ð��ʰ�
//	// �� �ð�����... �� �ð� �ʰ��� ���� ������ �˻� ������ �Ԥ�
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
//	// �ð� �ʰ�(find �Լ� ����ؼ� �׷��� ����)
//	//for (int i = 0; i < m; ++i)
//	//{
//	//	string quiz = "";
//	//	cin >> quiz;
//
//	//	// 0�̸� ���� 0�� �ƴϸ� ����
//	//	// ����
//	//	if (0 == isdigit(quiz[0]))
//	//	{
//	//		int idx = find(pocketmon.begin(), pocketmon.end(), quiz) - pocketmon.begin();
//	//		cout << idx << "\n";
//	//	}
//	//	// ����
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

// �� �ٸ� Ǯ�̹�(?)
// �� Ǯ�̿� ����
// ���ڿ��� int�� �ٲ� �� atoi(���ڿ�.c_str())
// �迭�� find �Լ��� �ð����⵵�� O(n)
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

// 10_�мǿ� ���غ�
// https://www.acmicpc.net/problem/9375
// ���� ���������� �����ϰ� �������� Ǯ�� ����
// �ٵ� �� 25%���� ��� �ȵǴ°ɱ�.. �ݷ� �����ؼ� Ȯ���ߴµ� ��� ����ǰ�
// ����� ��Ȱ��� ���̵� ũ�� ����̴µ� ������ �� �� ����
// ���߿� ������ Ǯ����� �� ��
// n: ���� �ǻ��� ��
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
//			// �� �Դ� ��쵵 ����Ͽ� ����� �� �ϳ� �� �߰�
//			count *= matchtype.second.size() + 1;
//		}
//
//		// �ƿ� �� �Դ� ����� �����Ƿ� -1
//		cout << count - 1 << "\n";
//	}
//
//	return 0;
//}

// �� �ٸ� Ǯ�̹�(?)
// �� Ǯ�̿� ����
// ���� ���ڿ��� ���� �ʿ� ���� Ÿ�Կ� ���� �������� �̿��� ����
// ����Բ��� �Ǵµ� ���� �� �ȵ�?!!!!!!!!!
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

// 11_�Ӹ���� �����
// https://www.acmicpc.net/problem/1213
// �߾��� �������� ����� ������ ���ڷ� �����ؾ� �ϴ� �����ϱ� �߰����� ���� ���� �� �������� ���̸� ������ ��
// �� ���ڰ� Ȧ���� ���·� ������ ������ �κе� ����ؾ� ��
//string name, ret;
//int midcount;				// Ȧ���� �� �� ������ Ȯ�� �뵵(2�� �Ѱ� ���� ��Ī ���� ���� �Ұ�)
////pair<char, int> midinfo;	// Ȧ���� ���� �� ��� �߾� ��ġ�� �� ����
//char midchar;
//int namecount[26];			// ���ں� Ƚ�� ���� ī����
//
//int main()
//{
//	cin >> name;
//
//	for (int i = 0; i < name.size(); ++i)
//	{
//		// �Էµ� ���ں� Ƚ�� ����
//		++namecount[name[i] - 'A'];
//	}
//
//	for (int i = 0; i < 26; ++i)
//	{
//		// ���ں� ���� ī��Ʈ�� Ȧ���� �� ����
//		if (1 == namecount[i] % 2)
//		{
//			++midcount;
//			//midinfo = { i + 'A', --namecount[i] };
//			midchar = i + 'A';
//			--namecount[i];
//		}
//
//		// Ȧ�� üũ�� 2�� �̻�(1�ʰ��� ���) ������ ���ڿ� ���� �� �ݺ��� Ż��
//		// �ش� ���� üũ�� ���� �θ� ������ Z üũ �� midcount�� ���� ���� ��
//		// ���ǿ� ������ �ʾƼ� ret�� �� ������ ��µǴ� ���� �߻�, ���� ������ Ȯ���� ���� �ϴܿ��� ���� Ȯ��
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
//			// ���ݸ� �����ϴ� �۾��� ���� ���� ī��Ʈ�� ���ݸ� �ݺ��ؼ� ���� �߰�
//			for (int j = 0; j < namecount[i] * 0.5f; ++j)
//			{
//				ret += (i + 'A');
//			}
//		}
//
//		// ���� �� ���� ��� �۾�
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

// �� �ٸ� Ǯ�̹�(��Ʈ������, ���� �ƽ�Ű�ڵ���� �����̱� �̿�)
// �Ұ����� ���: Ȧ���� 2�� �̻�
// �ƽ�Ű�ڵ� �� ���� ���� �ִ� ���� ����
//string s, ret;
//int cnt[200], flag;
//char mid;
//
//int main()
//{
//	cin >> s;
//
//	// ī���ù迭 �̿�
//	for (char a : s) ++cnt[a];
//
//	// Z���� ���̱�
//	for (int i = 'Z'; i >= 'A'; --i)
//	{
//		// ī���� �迭�� �����Ǿ� �ִٸ� 
//		if (0 != cnt[i])
//		{
//			// & 1: Ȧ���� ����
//			// Ȧ���� ��� �������� ��Ÿ���� ������ ��Ʈ���� 1
//			// ¦���� ��� �������� ��Ÿ���� ������ ��Ʈ���� 0
//			// ���� �ش� cnt[i] & 1 �ڵ�� 'Ȧ���� ���'��� ��
//			if (cnt[i] & 1)
//			{
//				// Ȧ�� �ϳ��� ������ �� �߰��� �ֱ� ���� �۾�
//				mid = char(i);
//				++flag;
//				--cnt[i];
//			}
//
//			// flag �� Ȧ���� 2�� �̻��̸� break
//			if (2 == flag) break;
//
//			// ���� ���̱�
//			// j += 2�� ������ �յڷ� ���̸鼭 ī��Ʈ 2���� �Ҹ�Ǳ� ����
//			for (int j = 0; j < cnt[i]; j += 2)
//			{
//				ret = char(i) + ret;	// �տ� ���̱�
//				ret += char(i);			// �ڿ� ���̱�
//			}
//		}
//	}
//
//	// �߾ӿ� mid ����
//	if (mid) ret.insert(ret.begin() + ret.size() / 2, mid);
//	if (2 == flag) cout << "I'm Sorry Hansoo\n";
//	else cout << ret << "\n";
//
//	return 0;
//}

// 12_�ָ�
// https://www.acmicpc.net/problem/1940
// �� ����� �ջ��� ���� �� ���� ��� ���� �� �ִ� ������ ������ ��� ���� ����
// ��� 2���� �����̹Ƿ� �޺� ��� �Լ� ���� ���� �������� �ذ� ����
// n: ��� ����
// m: ������ ����µ� �ʿ��� ��
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

// �� �ٸ� Ǯ�̹�(?)
// �� Ǯ�̿� ����
// 15000�� ������ ��� �� ����, ���� ���� ��ȣ ����
// ��� �ΰ��� �� ī����
// ��Ḧ �� �� ���� ���X ���� ����
int n, m, a[15001], cnt;

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; ++i) cin >> a[i];

	// �������� �ٸ����� �ð� �ʰ��� ����� ������ ����� ���� ���
	// ����ó���� ���� �ð��ʰ��� ���̴� ��
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
