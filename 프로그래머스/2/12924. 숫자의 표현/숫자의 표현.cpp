#include <bits/stdc++.h>
using namespace std;

int solution(int n) {
    // window + 누적합
    int ans = 0;
    int start = 1;
    int end = 1;
    int sum = start;
    
    while(start <= n){
        if(sum < n){
            end++;
            sum += end;
        }
        else if(sum == n){
            sum -= start;
            start++;
            ans++;
        }
        else{
            sum -= start;
            start++;
        }
    }
    
    return ans;
}