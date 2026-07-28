#include <bits/stdc++.h>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> m;
    for(int i = 0; i < participant.size(); i++){
        m[participant[i]]+=1;
    }
    for(int i = 0; i < completion.size(); i++){
        m[completion[i]] -= 1;
    }
    for(auto x : participant){
        if(m[x] > 0){
            answer = x;
        }
    }
    
    return answer;
}