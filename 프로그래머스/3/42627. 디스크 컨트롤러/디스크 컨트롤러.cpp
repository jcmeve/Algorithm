#include <string>
#include <vector>
#include <queue>
using namespace std;



struct my_comp {

    bool operator()(vector<int>& a, vector<int>& b) {
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] == b[i]) {
                continue;
            }
            return a[i] > b[i];
        }
        return false;
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int jobs_size = jobs.size();
    greater<vector<int>> a;
    priority_queue<vector<int>, vector<vector<int>>, my_comp> q; // proctime, enqueue time, procnumber=
    int curr_time = 0;
    for (;jobs.size() || q.size();) {


        for (int i = 0; i < jobs.size(); ++i) {
            if (jobs[i][0] <= curr_time) {
                q.push({ jobs[i][1], jobs[i][0], i});
                jobs.erase(jobs.begin() + i);
                --i;
            }
        }

        if (!q.empty()) {
            curr_time += q.top()[0];
            answer += (curr_time - q.top()[1]);
            q.pop();
        }
        else
           ++curr_time;
    }

    return answer/jobs_size;
}