#include <bits/stdc++.h>
using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second > b.second; // 내림차순 : 앞(a)가 크면 내림차
}

int solution(vector<int> priorities, int location) {
    vector<pair<int,int>> my_p(priorities.size());
    vector<int> my_pp = priorities;
    int len = my_pp.size();
    for(int i = 0; i <len; i++){
        my_p[i].first = i;
        my_p[i].second = my_pp[i];
    } // 자 이제 이 first, 즉 인덱스(로케이션) 정보까지 비교해서 판정하면 될듯
    queue<pair<int,int>> q;
    for(int i = 0; i<len; i++){
        q.push({my_p[i].first, my_p[i].second});
    }
    sort(my_p.begin(), my_p.end(), compare);
    int seq = 1;
    while(!q.empty()){
        if(q.front().second == my_p[0].second){
            if(q.front().first == location){
                return seq;
            }
            q.pop();
            my_p.erase(my_p.begin());
            seq++;
        }
        else{
            q.push(q.front());
            q.pop();
        }
    }
    
   
}