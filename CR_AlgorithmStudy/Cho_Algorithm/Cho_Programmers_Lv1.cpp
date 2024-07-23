// �Ű� ��� �ޱ�
// https://school.programmers.co.kr/learn/courses/30/lessons/92334
//#include <string>
//#include <vector>
//#include <sstream>
//#include <set>
//#include <iostream>
//#include <unordered_map>
//
//using namespace std;
//
//vector<int> solution(vector<string> id_list, vector<string> report, int k) {
//    unordered_map<string, set<string>> reportedUser;
//    unordered_map<string, int> reportCnt;
//
//    int size = id_list.size();
//
//    for (int i = 0; i < size; i++)
//    {
//        reportCnt[id_list[i]] = 0;
//    }
//
//    for (string& s : report)
//    {
//        stringstream ss(s);
//        string from = "";
//        string to = "";
//        ss >> from >> to;
//        reportedUser[to].insert(from);
//    }
//
//    vector<int> answer;
//    for (auto& s : reportedUser)
//    {
//        // �Ű� ���� ���� k �̻��̸�
//        if (s.second.size() >= k)
//        {
//            // �Ű��� ����鿡�� ������ ������.
//            for (auto& m : s.second)
//            {
//                ++reportCnt[m];
//            }
//        }
//    }
//
//    for (auto& i : id_list)
//    {
//        answer.push_back(reportCnt[i]);
//    }
//
//    return answer;
//}
//
//int main()
//{
//    solution({ "con", "ryan" }, { "ryan con", "ryan con", "ryan con", "ryan con" }, 3);
//}