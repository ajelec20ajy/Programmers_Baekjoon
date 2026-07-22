#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = s;
    bool flag = true; //flag가 true면 공백 전 첫 문자이다
    
    for(int i = 0; i <answer.length(); i++){
        char c = answer[i];
        if(c == ' ') {
            flag = true;
            continue;
        }
        if(flag){
            flag = 0;
            if(c >= '0' && c <= '9'){
                continue;
            }
            else{
                c = toupper(c);
                answer[i] = c;
            }
        }
        else{
            if(c < 'a' || c >'z' || !(c > '0' && c < '9')){
                c = tolower(c);
                answer[i] = c;
            }
        }
    }
    
    return answer;
}