#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    queue<int> q_p;
    queue<int> q_s;
    for(int i = 0; i < progresses.size(); i++){
        q_p.push(progresses[i]);
        q_s.push(speeds[i]);
    }

    vector<int> answer;

    while(!q_p.empty()){
        int current_size = q_p.size();
        for(int i = 0; i < current_size; i++){
            int p = q_p.front(); q_p.pop();
            int s = q_s.front(); q_s.pop();
            q_p.push(p + s); // 진도 업데이트해서 뒤로 보냄
            q_s.push(s);     // 속도 그대로 뒤로 보냄
        }

        int cnt = 0;
        while(!q_p.empty() && q_p.front() >= 100) {
            q_p.pop();
            q_s.pop();
            cnt++;
        }

        if(cnt > 0) {
            answer.push_back(cnt);
        }
    }
    return answer;
}