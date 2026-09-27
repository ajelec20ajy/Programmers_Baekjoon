#include <bits/stdc++.h>
using namespace std;

long long lo = 1;
long long hi;

bool possible(int n, long long mid, vector<int> times){
    long long total = 0;
    for(int t : times){
        total += mid/t; //
    }
    //cout << "Now Total : " << total << endl;
    return (total >= n) ? true : false;
}

long long solution(int n, vector<int> times) {
    long long mid;
    hi = (long long)*max_element(times.begin(), times.end())*(long long)n;
    long long answer = hi;
    while(lo <= hi){
        mid = lo + (hi - lo) / 2;
        if(possible(n, mid, times)){
            // time could be shorter
            hi = mid - 1;
            answer = mid;
        }
        else{
            lo = mid + 1;
            // time shoud be longer
        }
        cout << "Now Mid: " << mid << endl;
        cout << "Hi:" << hi<<",lo:"<<lo<<endl;
    }
    
    return answer;
}