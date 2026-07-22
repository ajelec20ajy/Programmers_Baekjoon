#include <bits/stdc++.h>

using namespace std;

string solution(string new_id) {
    string answer = "";
    int len = new_id.length();
    // step1 : 대문자 -> 소문자
    for(int i = 0; i<len; i++){
        char c = new_id[i];
        if(c >= 'A' && c <= 'Z')
        new_id[i] = tolower(c);
    }
    // step2: -,_,.제외 특수문자 제거(빼기, 밑줄, 마침표)
    len = new_id.length();
    string temp;
    for(int i = 0; i<len; i++){
        char c = new_id[i];
        if((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || c == '-' || c == '_' || c == '.') {
            temp.push_back(c);
        }
    }
    new_id = temp;
    // step 3: 중복되는 .을 하나의 .로 변경 -> 내 앞에가 .면 삭제하면될듯
    len = new_id.length();
    char prev_c = new_id[0];
    for(int i = 1; i < len;){
            if(new_id[i] == '.' && prev_c == '.'){
                new_id.erase(i,1);
                len = new_id.length();
            }
            else{
                prev_c = new_id[i];
                i++;
            }
    }
    
    // step4 : 맨 앞이나 맨 뒤가 마침표면 그거 제거
    len = new_id.length();
   if(!new_id.empty() && new_id[0] == '.'){
        new_id.erase(0, 1);
    }
    if(!new_id.empty() && new_id.back() == '.'){
        new_id.pop_back();
    }
                     
    // step5: 문자열이 엠티면 a대입
    len = new_id.length();
    if(len == 0){
        new_id.insert(0,1,'a');
        // new_id.push_back('a');
        // 문자열이면 append..
    }
    
    // step 6: 길이가 16이상이면, 첫 15개 문자만 냅두고 다 제거. 근데 끝 문자가 '.'이 되어버리면 그것도 제거
    len = new_id.length();
    if(len >= 16){
        new_id.erase(15, len - 15);
    }
    len = new_id.length();
    if(new_id.back() == '.'){
        new_id.erase(len-1, 1);
    }
                     
                     
   // step 7
    len = new_id.length();
    if(len <= 2){
        char c = new_id[len-1];
        while(len < 3){
            new_id.push_back(c);
            len = new_id.length();
        }
    }
    return new_id;
}