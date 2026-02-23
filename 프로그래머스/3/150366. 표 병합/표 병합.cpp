#include <string>
#include <vector>
#include <sstream>
#include <map>
using namespace std;

vector<string> solution(vector<string> commands) {
    vector<string> answer;
    vector<int> group(50*50,-1);
    vector<string> sheet(50*50);
    map<int, string> groupValue;
    map<int, vector<int>> groupMembers;
    int nextGroup=0;
    for (string cmd : commands) {
        istringstream is(cmd);
        vector<string> tokens;
        string token;
        while (is >> token) {
            tokens.push_back(token);
        }
        if (tokens[0].compare("UPDATE") == 0) {
            if (tokens.size() == 4) {//1
                int idx = (stoi(tokens[1]) - 1) * 50 + (stoi(tokens[2]) - 1);
                if (group[idx] == -1) {
                    sheet[idx] = tokens[3];
                }
                else {
                    groupValue[group[idx]] = tokens[3];
                }
            }
            else {//2
                for (string& s : sheet) {
                    if (s == tokens[1]) s = tokens[2];
                }
                for (auto& pair : groupValue) {
                    if (pair.second == tokens[1]) pair.second = tokens[2];
                }
            }
        }
        else if (tokens[0].compare("MERGE") == 0) {//3
            int idx1 = (stoi(tokens[1]) - 1) * 50 + (stoi(tokens[2]) - 1);
            int idx2 = (stoi(tokens[3]) - 1) * 50 + (stoi(tokens[4]) - 1);
            if (idx1 == idx2) continue;
            if (group[idx1] == group[idx2] && group[idx1] != -1)
                continue;
            if (group[idx1] != -1 && group[idx2] != -1) {
                int g1 = group[idx1];
                int g2 = group[idx2];
                for (int i : groupMembers[g2]) {
                    group[i] = g1;
                }
                groupMembers[g1].insert(groupMembers[g1].end(),groupMembers[g2].begin(), groupMembers[g2].end());
                groupMembers[g2].clear();
                if (groupValue[g1].empty()) {
                    groupValue[g1] = groupValue[g2];
                }
            }
            else if (group[idx1] != -1) {
                group[idx2] = group[idx1];
                groupMembers[group[idx1]].push_back(idx2);
                if (groupValue[group[idx1]].empty()) {
                    groupValue[group[idx1]] = sheet[idx2];
                }
            }
            else if (group[idx2] != -1) {
                group[idx1] = group[idx2];
                groupMembers[group[idx2]].push_back(idx1);
                if (!sheet[idx1].empty()) {
                    groupValue[group[idx2]] = sheet[idx1];
                }
            }
            else {
                group[idx1] = nextGroup;
                group[idx2] = nextGroup;
                groupMembers[nextGroup].push_back(idx1);
                groupMembers[nextGroup].push_back(idx2);
                if (sheet[idx1].empty()) {
                    groupValue[nextGroup] = sheet[idx2];
                }
                else {
                    groupValue[nextGroup] = sheet[idx1];
                }
                nextGroup++;
            }
        }
        else if (tokens[0].compare("UNMERGE") == 0) {//4
            int idx = (stoi(tokens[1]) - 1) * 50 + (stoi(tokens[2]) - 1);
            int g = group[idx];
            string s = groupValue[g];
            if (g == -1) continue;
            for (int i : groupMembers[g]) {
                group[i] = -1;
                sheet[i].clear();
            }
            groupMembers[g].clear();
            sheet[idx] = s;
        }
        else if (tokens[0].compare("PRINT") == 0) {//5
            int idx = (stoi(tokens[1]) - 1) * 50 + (stoi(tokens[2]) - 1);
            if (group[idx] != -1) {
                if (groupValue[group[idx]].empty()) {
                    answer.push_back("EMPTY");
                }
                else {
                    answer.push_back(groupValue[group[idx]]);
                }
            }
            else {
                if (sheet[idx].empty()) {
                    answer.push_back("EMPTY");
                }
                else {
                    answer.push_back(sheet[idx]);
                }
            }
        }


    }

    return answer;
}
