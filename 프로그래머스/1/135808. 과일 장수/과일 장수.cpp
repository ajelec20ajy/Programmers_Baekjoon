#include <bits/stdc++.h>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    vector<int> my = score;
    sort(my.begin(), my.end(), [](int a, int b){
       return a < b; 
    });
    
    int throwing = my.size() % m;
    for(int i = 0; i < throwing; i++){
        my.erase(my.begin());
    }
    
    for(int i = 0; i < my.size() / m; i++){
        answer += my[i*m]*m;
    }
    
    return answer;
}