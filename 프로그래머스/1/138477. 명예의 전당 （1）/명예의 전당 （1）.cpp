#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    int len = score.size();
    for(int i = 0; i < len; i++){
        if(pq.empty()){
            pq.push(score[i]);
            answer.push_back(score[i]);
            continue;
        }
        else{
            if(pq.size() < k){
                pq.push(score[i]);
                answer.push_back(pq.top());
            }
            else{
                pq.push(score[i]);
                while(pq.size() > k){
                    pq.pop();
                }
                answer.push_back(pq.top());
            }
        }
    }
    
    return answer;
}