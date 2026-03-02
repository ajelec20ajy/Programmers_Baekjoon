#include <stdio.h>
#define LEN_INPUT 11
#include <string.h>
#include <stdint.h>
int main(void) {
    char s1[LEN_INPUT];
    int a;
    scanf("%s %d", s1, &a);
    
    uint8_t len = strlen(s1);
    for(int i = 0; i < a; i++){
        for(int j =0; j < len; j++){
            printf("%c", s1[j]);
        }
    }
    
    return 0;
}