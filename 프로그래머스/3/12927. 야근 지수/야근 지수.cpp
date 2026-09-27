#include <bits/stdc++.h>

using namespace std;

long long solution(int n, vector<int> works){
    priority_queue<int> pq;
    for(int i : works){
        pq.push(i);
    }
    
    for(int i = 0 ; i < n; i++){
        int f = pq.top();
        if(f>0){
            f = f - 1;
            pq.push(f);
        }
        else{
            pq.push(f);
        }
        pq.pop();
    }
    
    long long ans = 0;
    while(!pq.empty()){
        long long tmp = pq.top();
        ans += (tmp*tmp);
        pq.pop();
    }
    
    return ans;
}
/*
long long solution(int n, vector<int> works) {
    vector<int> my = works;
    for(int i = 0; i < n; i++){
        int max = *max_element(my.begin(), my.end());
        for(int j = 0; j < my.size(); j++){
            if(max == my[j]) {if(my[j] > 0) {my[j]--; break;}}
        }
        // cout << "MAX : " << max << endl;
    }
    long long ans = 0;
    for(int i : my){
        long long tmp = i;
        // cout << "tmp : " << tmp << ", i : " << i << endl;
        ans += (tmp*tmp);
        // cout << "ANS : " << ans << endl;
    }
    return ans;
}
*/