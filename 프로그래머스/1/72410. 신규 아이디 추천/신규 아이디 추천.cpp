#include <bits/stdc++.h>

using namespace std;

string solution(string new_id) {
    string answer = "";
    int len = new_id.size();
    for(int c : new_id){
        if(isalpha(c)){
            c = tolower(c);
        }
        answer+=c;
    }
    string answer2 = "";
    for(char c : answer){
        if((isalpha(c)) || (isdigit(c)) || (c == '-') || (c == '_') || (c == '.')){
            answer2 += c;
        }
    }
    cout << "answer2 = " << answer2 << endl;
    
    string answer3 = "";
    int len2 = answer2.length();
    for(int i = 0; i < len2; i++){
        if(!i){
            answer3+=answer2[i];
            continue;
        }
        if(answer2[i-1] == '.' && answer2[i] == '.'){
            continue;
        }
        answer3+=answer2[i];
    }
    cout << "answer3 = " << answer3 << endl;
    string answer4 = "";
    int len3 = answer3.size();
    for(int i = 0; i < len3; i++){
        if(i == 0 || i == (len3-1)){
            if(answer3[i] == '.'){
                continue;
            }
        }
        answer4+=answer3[i];
    }
    cout << "answer4 = " << answer4 << endl;
    if(!answer4.size()){
        answer4 += 'a';
    }
    cout << "answer5 = " << answer4 << endl;
    string answer5 = "";
    int iterations = (answer4.size() < 15) ? answer4.size() : 15;
    for(int i = 0; i < iterations; i++){
        if(i == 14 && answer4[i] == '.') continue;
        answer5 += answer4[i];
    }
    cout << "answer6 = " << answer5 << endl;
    while(answer5.size() <= 2){
        answer5 += answer5[answer5.size()-1];
    }
    cout << "answer7 = " << answer5 << endl;
    
    return answer5;
}