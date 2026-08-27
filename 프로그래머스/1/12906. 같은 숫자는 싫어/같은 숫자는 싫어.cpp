#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    int arr_len = arr.size();
    stack<int> st;
    for(int i = 0; i < arr_len; i++){
        int tmp = arr[i];
        if(!st.empty()){
            if(st.top() == tmp) continue;
            else st.push(tmp);
        }
        else{
            st.push(tmp);
        }
    }
    
    int st_size = st.size();
    cout << "st_size = " << st_size << endl;
    vector<int> ans(st_size);
    int i = st_size - 1;
    while(!st.empty()){
        ans[i] = st.top();
        st.pop();
        i--;
    }
    
    return ans;
}