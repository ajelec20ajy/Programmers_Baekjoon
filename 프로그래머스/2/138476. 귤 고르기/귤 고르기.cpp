#include <bits/stdc++.h>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    vector<int> my = tangerine;
    vector<int> m2;
    unordered_map<int, int> h;
    
    for(int i : my){
        h[i]++;
    }
    
    for(auto i : h){
        m2.push_back(i.second);
        //cout << "key : " << i.first << ", value : " << i.second << endl;
    }
    
    sort(m2.begin(), m2.end(), [](int a, int b){return a>b;});
    int sum = 0;
    int i = 0;
    while(sum <= k){
        if(sum + m2[i] >= k){
            answer++;
            break;
        }
        if(sum + m2[i] < k){
            sum += m2[i];
            answer++;
            i++;
        }
    }
    
    return answer;
}