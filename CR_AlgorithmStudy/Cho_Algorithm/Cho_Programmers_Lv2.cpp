// ÃÖ´ñ°ª°ú ÃÖ¼Ú°ª
// https://school.programmers.co.kr/learn/courses/30/lessons/12939

#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> SplitString(string& s)
{
    istringstream iss(s);
    string token;
    vector<int> tokens;

    while (iss >> token)
    {
        tokens.push_back(stoi(token));
    }

    return tokens;
}

string solution(string s) {
    vector<int> v = SplitString(s);

    sort(v.begin(), v.end());

    int minValue = v[0];
    int maxValue = v[v.size() - 1];

    string answer = "";
    answer = to_string(minValue) + ' ' + to_string(maxValue);

    return answer;
}

int main()
{
    string s = "1 2 3 4";
    cout << solution(s);
}