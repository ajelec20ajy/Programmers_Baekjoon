#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int len = s.size();
    int cnt = 0;
    for(int i = 0; i < len; i++){
        if(s[i] == ' '){
            answer.push_back(' ');
            cnt = 0;
            continue;
        }
        if(cnt%2 == 0){
            answer+=toupper(s[i]);
            cnt++;
            continue;
        }
        answer+=tolower(s[i]);
        cnt++;
    }
    return answer;
}