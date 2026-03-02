#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main(void) {
    printf("!@#$%^&*(");
    printf("%c%c%c%c%c%c%c%c", 0x5c, 0x27, 0x22, 0x3c, 0x3e, 0x3f, 0x3a, 0x3b);
    
    return 0;
}