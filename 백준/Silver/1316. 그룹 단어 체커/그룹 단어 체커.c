#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char s[1000001];

int main() {

    int N; scanf("%d", &N); // 시행횟수
    getchar();
    int test; // 그룹단어인지 테스트해야됨
    int cnt = 0; // 그룹단어의 갯수
    char word[101]; // 워드죠
   

    for (int i = 0; i < N; i++) {
        test = 1;
        gets(word); 
        int used[26] = { 0 }; // 주어진 단어에서 사용된 알파벳들의 주소를 저장하는 것
        used[word[0] - 'a'] = 1; // word의 첫 글자의 알파벳을 사용되었음으로 저장. j for문이 j=1부터 시작하게 하기위한 초기지정.
        int len = strlen(word);
        for (int j = 1; j < len; j++) {
  
            if (word[j] == word[j - 1]) continue; //word가 알파벳이 연속될떄는 그냥 컨티뉴
            else { //word가 불연속점을 만나면 그 알파벳이 이전에 있던 알파벳인지 본다. 이전에 있던 알파벳이면 그룹단어 탈락
                if (used[word[j] -'a'] == 0) { //word[j]의 알파벳이 기존에 사용되지 않았다. 그룹단어이다.
                     used[word[j]-'a'] = 1;
                }
                else if (used[word[j] - 'a'] == 1) {
                    used[word[j] - 'a'] = 1;
                    test = 0;
                } // 그룹단어 탈락. 이미 존재하는 알파벳이 다시 등장함.
            }
        }
       if (test) cnt++;

    }

    printf("%d", cnt);
    return 0;
}

//연속인지를 따져가며 word를 검사하다, 새로운 알파벳을 만났을 때 그것이 기존에 있던 알파벳인지(그룹x) 아닌지(그룹o)? 