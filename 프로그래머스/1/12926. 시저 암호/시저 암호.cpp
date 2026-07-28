#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for(int i = 0; i < s.size(); i++){
        char c = s[i];
        if(c == ' '){
            answer+=' ';
            continue;
        }
        if(c >= 'A' && c <= 'Z'){
            int tmp = c - 'A';
            c = (tmp+n) % 26 + 'A';
            answer+=c;
            continue;
        }
        int tmp = c - 'a';
        c = (tmp+n) % 26 + 'a';
        
        answer+=c;
    }
    
    return answer;
}