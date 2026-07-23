#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    string a = s;
    int len = a.length();
    stack<int> st;
    for(int i = 0; i < len; i++){
        char c = a[i];
        if(c == '('){
            st.push(1);
        }
        else if(c == ')'){
            if(st.size() == 0) return false;
            else{
                st.pop();
            }
        }
    }
    if(st.size() == 0) return true;
    else return false;
}