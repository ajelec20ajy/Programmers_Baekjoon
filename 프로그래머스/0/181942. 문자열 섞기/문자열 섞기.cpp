#include <string>
#include <vector>

using namespace std;

string solution(string str1, string str2) {
    string ans;
    int len = str1.length();
    len = 2*str1.length();
    for(int i = 0; i < len; i++){
        if(i%2==0) ans.push_back(str1[i/2]);
        else ans.push_back(str2[i/2]);
    }
    return ans;
}