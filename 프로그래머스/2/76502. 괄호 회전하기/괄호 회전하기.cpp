#include <bits/stdc++.h>
using namespace std;

bool isright(queue<char> qu){
    stack<char> st;
    
    int s = qu.size();
    for(int i = 0; i < s; i++){
        char c= qu.front();
        qu.pop();
        switch(c){
            case '{':
                st.push('{');
                break;
            case '}':
                if(!st.empty() && st.top() == '{') st.pop();
                else{
                    return false;
                }
                break;
            case '[':
                st.push('[');
                break;
            case ']':
                if(!st.empty() && st.top() == '[') st.pop();
                else{
                    return false;
                }
                break;
            case '(':
                st.push('(');
                break;
            case ')':
                if(!st.empty() && st.top() == '(') st.pop();
                else{
                    return false;
                }
                break;
            default:
                break;
            
        }
    }
    if(st.empty()) return true;
    return false;
}

int solution(string s) {
    int answer = 0;
    
    queue<char> q;
    
    for(char c : s){
        q.push(c);
    }
    
    int len = s.length();
    for(int i = 0; i < len; i++){
        char c = q.front();
        q.pop();
        q.push(c);
        if(isright(q)) answer++;
    }
    
    return answer;
}