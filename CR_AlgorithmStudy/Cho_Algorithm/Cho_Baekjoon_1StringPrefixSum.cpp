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