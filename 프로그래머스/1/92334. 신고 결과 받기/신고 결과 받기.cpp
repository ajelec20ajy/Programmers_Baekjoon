#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    
    // report에서 일단 신고자랑 범인을 구분해야겠다.
    // 근데.... id별로 신고한 사람들을 어케 정리하지?
    // unorderd_map<string, vector<string>> m; 
    
    set<string> s(report.begin(), report.end());
    vector<string> v(s.begin(), s.end());
    
    int v_len = v.size();
    unordered_map<string,vector<string>> m;
    for(int i = 0; i < v_len; i++){
        string tmp = v[i];
        int index = tmp.find(" ");
        string a = tmp.substr(0, index);
        string b = tmp.substr(index+1);
        m[a].push_back(b);
    }
    
    unordered_map<string,int> m2; // ID별 신고받은 횟수
    for(int i = 0; i < v_len; i++){
        string tmp = v[i];
        int index = tmp.find(" ");
        string a = tmp.substr(0, index-1);
        string b = tmp.substr(index+1);
        m2[b]++;
    }
    /* 흠 여기까진 잘 되시구용
    for(auto& [str, i] : m2){
        cout << "ID: " << str << ", COUNT = " << i << endl;
    }
    */
    
    unordered_map<string,int> m3;
    for(auto& [s, n] : m2){
        if(n >= k){
            for(auto& [st, vec] : m){
                for(string str : vec){
                    if(str == s){
                        m3[st]++;
                    }
                    
                }
            }
        }
    }
    /*
    for(auto& [str, num] : m3){
        cout << str << "은 " << num << endl;
    }
    */
    
    vector<int> answer;
    for(string s : id_list){
        answer.push_back(m3[s]);
    }
    
    return answer;
}