#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer(2,0);
    // first cond : lower length(min)
    // second cond : lower first index
    
    int start = 0;
    int end = 0;
    int sum = sequence[start];
    int min_len = sequence.size();
    int min_index = end;
    
    
    while(start <= (sequence.size()-1)){
        if(sum < k){
            if(end == sequence.size() - 1) break;
            end++;
            sum+=sequence[end];
        }
        else if(sum == k){
            if(min_len > (end-start)){
                    answer[0] = start;
                    answer[1] = end;
                    min_len = end-start;
                    min_index = start;
            }
            else if(min_len == (end-start)){
                if(min_index >= start){
                    answer[0] = start;
                    answer[1] = end;
                    min_len = end-start;
                    min_index = start;
                }
            }
            
            sum-=sequence[start];
            start++;
        }
        else{
            sum-=sequence[start];
            start++;
        }
    }
    
    return answer;
}