// 신고 결과 받기
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
//        // 신고 당한 수가 k 이상이면
//        if (s.second.size() >= k)
//        {
//            // 신고한 사람들에게 메일을 보낸다.
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