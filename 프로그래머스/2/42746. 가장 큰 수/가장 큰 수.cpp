#include <bits/stdc++.h>

using namespace std;
bool compare(const string& a, const string& b){
    // return이 true면, a를 b앞으로 오게 정렬한다.
    return a+b>b+a;
}
string solution(vector<int> numbers) {
    vector<string> my;
    for(int i : numbers){
        my.push_back(to_string(i));
    }
    
    sort(my.begin(), my.end(), compare);
    
    if(my[0]=="0") return "0";
    string ans;
    for(string i : my){
        ans += i;
    }
    return ans;
}