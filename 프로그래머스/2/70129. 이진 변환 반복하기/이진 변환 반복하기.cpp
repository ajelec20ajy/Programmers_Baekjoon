#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string toBinary(int n) {
    if (n == 0) return "0";
    
    string binary = "";
    while (n > 0) {
        binary += to_string(n % 2); // 2로 나눈 나머지(0 또는 1)를 추가
        n /= 2;                     // 2로 나눔
    }
    
    reverse(binary.begin(), binary.end()); // 거꾸로 뒤집기
    return binary;
}

vector<int> solution(string s) {
    vector<int> answer;
    string my = s;
    int cnt2 = 0;
    int cnt = 0; // 0제거 카운트
    while(my != "1"){
    
    // 0 제거하기
    for(int i = 0; i < my.length();){
        char c = my[i];
        if(c == '0'){
            cnt++;
            my.erase(i, 1);
        }
        else{
            i++;
        }
    }
    
    //이진변환
    int len = my.length();
    
    my = toBinary(len);
    cnt2++;
    }
    return {cnt2, cnt};
}