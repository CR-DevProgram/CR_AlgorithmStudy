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