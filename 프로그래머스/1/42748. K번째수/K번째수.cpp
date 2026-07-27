#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> ans;
    
    for(vector<int> a : commands){
        vector<int> arr;
        for(int i = a[0]-1; i <= a[1]-1; i++){
            arr.push_back(array[i]);
        }
        sort(arr.begin(), arr.end());
        ans.push_back(arr[a[2]-1]);
    }
    
    return ans;
}