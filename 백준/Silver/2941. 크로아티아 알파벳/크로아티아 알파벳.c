#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char s[1000001];

int main() {

    char s[101];
    int cnt = 0;

    gets(s);

    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == 'c' && s[i + 1] == '=') cnt = cnt;
        else if (s[i] == 'c' && s[i + 1] == '-') cnt = cnt;
        else if ((s[i] == 'd' && s[i + 1] == 'z' && s[i+2] == '=') || (s[i-1] == 'd' && s[i] == 'z' && s[i+1] == '=')) cnt = cnt;
        else if (s[i] == 'd' && s[i + 1] == '-') cnt = cnt;
        else if (s[i] == 'l' && s[i + 1] == 'j') cnt = cnt;
        else if (s[i] == 'n' && s[i + 1] == 'j') cnt = cnt;
        else if (s[i] == 's' && s[i + 1] == '=') cnt = cnt;
        else if (s[i] == 'z' && s[i + 1] == '=') cnt = cnt;
        else cnt++;

    }

    printf("%d", cnt);

    return 0;
}
