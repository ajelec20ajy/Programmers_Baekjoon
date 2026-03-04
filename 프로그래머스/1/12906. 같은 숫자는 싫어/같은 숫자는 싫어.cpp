#include <vector>
#include <iostream>
#include <stack>
using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int temp;
    stack<int> s;
    temp = arr[0];
    s.push(temp);
    for(int i = 1; i<arr.size(); i++){
        if(temp != arr[i]){
            temp = arr[i];
            s.push(temp);   
        }
    }
    
    vector<int> temparr;
    while(!s.empty()){
        temparr.push_back(s.top());
        s.pop();
    }
    
    for(int i = temparr.size()-1; i>=0; i--){
        answer.push_back(temparr[i]);
    }
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}