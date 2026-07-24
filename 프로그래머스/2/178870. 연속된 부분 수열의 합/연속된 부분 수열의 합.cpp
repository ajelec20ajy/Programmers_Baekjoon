#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    int left = 0;
    int right = 0;
    vector<int> answer(2, 0);
    int min_len = sequence.size() + 1;
    int sum = 0;
    for(int right = 0; right < sequence.size(); right++){
        sum+=sequence[right];
        
        while(sum > k && left <= right){
            sum -= sequence[left];
            left++;
        }
        
        if(sum == k){
            if(min_len > right-left+1){
                min_len = right-left+1;
                answer[0] = left;
                answer[1] = right;
            }
        }
    }
    return answer;
}