#include <bits/stdc++.h>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    
    // 자 그라모 callings.length()만큼 재정렬이 필요하겠군요?
    // map에서 재정렬이 어케 되는거였죠?
    unordered_map<string, int> m;
    int players_len = players.size();
    for(int i = 0; i < players_len; i++){
        string s = players[i];
        m[s] = i;
    }
    answer = players;
    int callings_len = callings.size();
    for(int i = 0; i < callings_len; i++){
        int tmp = m[callings[i]]; // 지금 호명하는 사람의 등수 접근
        string tmp_s = answer[tmp-1]; // 그 앞 등수의 사람
        swap(answer[tmp], answer[tmp-1]); // 앞 사람과 벡터 위치 교환
        m[callings[i]] = m[callings[i]] - 1; // 호명했던 사람 value - 1
        m[tmp_s] = m[tmp_s] + 1; // 그 앞사람 등수 value + 1
    }
    
    return answer;
}