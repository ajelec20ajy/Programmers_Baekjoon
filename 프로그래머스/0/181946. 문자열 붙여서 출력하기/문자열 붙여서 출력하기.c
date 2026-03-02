#include <stdio.h>
#define LEN_INPUT1 11
#define LEN_INPUT2 11
#include <string.h>
int main(void) {
    char s1[LEN_INPUT1];
    char s2[LEN_INPUT2];
    scanf("%s %s", s1, s2);
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    
    for(int i = 0; i < len1; i++){
        printf("%c", s1[i]);
    }
        for(int i = 0; i < len2; i++){
        printf("%c", s2[i]);
    }
    return 0;
}