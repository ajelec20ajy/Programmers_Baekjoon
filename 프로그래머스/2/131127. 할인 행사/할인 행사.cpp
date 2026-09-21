#include <bits/stdc++.h>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    // 2. 슬라이딩 윈도우로 하면 되나..?
    // 3. 뭔가 해시로 하고 싶기도 하고
    
    int cnt = discount.size();
    cnt = cnt -  9;
    unordered_map<string, int> h;
    for(int i = 0; i < 10; i++){
        h[discount[i]]++;
    }
    int ans = 0;
    int len_want = want.size();
    for(int i = 0; i < cnt; i++){
        int tmp = 0;
        for(int j = 0; j < len_want; j++){
            if(h[want[j]] == number[j]){
                tmp++;
            }
        }
        if(tmp == len_want){
            ans++;
        }
        h[discount[i]]--;
        if(i+10<discount.size()) h[discount[i+10]]++;
    }
    return ans;
}