#include <bits/stdc++.h>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    
    vector<string> my = strings;
    
    sort(my.begin(), my.end(), [n](string a, string b){
        if(a[n] != b[n]) return a[n] < b[n]; // 오름차순이져
        return a < b;
    });
    
    answer = my;
    
    return answer;
}