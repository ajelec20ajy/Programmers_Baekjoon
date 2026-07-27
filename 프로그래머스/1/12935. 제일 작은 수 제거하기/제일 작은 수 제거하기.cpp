#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer = arr;
    vector<int> tmp = arr;
    
    sort(tmp.begin(), tmp.end(), [](int a, int b){
        return a < b;
    });
    
    int min = tmp[0];
    
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == min){
            answer.erase(answer.begin() +i);
        }
    }
    if(answer.size() == 0) answer.push_back(-1);
    return answer;
}