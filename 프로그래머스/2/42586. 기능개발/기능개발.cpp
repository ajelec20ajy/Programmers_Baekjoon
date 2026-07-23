#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    // 큐를 써볼까요?
    queue<int> q;
    vector<int> ans;
    vector<int> my_speeds = speeds;
    for(int n : progresses){
        q.push(n);
    }
    while(!q.empty()){
        for(int i = 0; i<q.size(); i++){
            int tmp = q.front();
            tmp += my_speeds[i];
            q.push(tmp);
            q.pop();
        }
        int cnt = 0;
        while(q.empty()? 0 : q.front() >= 100){
            q.pop();
            my_speeds.erase(my_speeds.begin());
            cnt++;
        }
        if(cnt){
            ans.push_back(cnt);
        }
    }
    return ans;
}