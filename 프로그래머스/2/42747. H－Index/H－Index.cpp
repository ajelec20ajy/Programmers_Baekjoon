#include <bits/stdc++.h>

using namespace std;

bool possible(vector<int>& v, int h){
    int cnt_h = 0;
    for(int i = 0; i < v.size(); i++){
        if(v[i]>=h){
            cnt_h = v.size()-i;
            break;
        }
    }
    if(cnt_h >= h) return true;
    return false;
}

int solution(vector<int> citations) {
    // cond 1 : over h papers were cited over h
    // cond 2 : rest papers were cited under h
    
    vector<int> v = citations;
    sort(v.begin(), v.end());
    int min = 1;
    int max = v.size();
    int ans=0;
    while(min<=max){
        int mid=min+(max-min)/2;
        
        if(possible(v, mid)){
            min = mid+1;
            ans = mid;
        }
        else{
            max = mid-1;
        }
    }
    
    return ans;
}