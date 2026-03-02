#include <stdio.h>
#include <stdint.h>
#include <string.h>
#define LEN_INPUT 10

int main(void) {
    char s1[LEN_INPUT];
    scanf("%s", s1);
    uint8_t len = strlen(s1);
    for(uint8_t i = 0; i < len; i++){
        if(s1[i] < 0x61) s1[i] = s1[i] + 0x20;
        else if(s1[i] > 0x60) s1[i] = s1[i] - 0x20;
    }
    for(uint8_t i = 0; i< len;i++){
        printf("%c", s1[i]);
    }
    return 0;
}
