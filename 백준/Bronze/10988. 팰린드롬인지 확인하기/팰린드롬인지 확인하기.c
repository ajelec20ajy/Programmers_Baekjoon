int main() {
    
    char s[101];
    int result = 0;
    gets(s);

    for (int i = 0; i < strlen(s) / 2; i++) {
        if (s[i] == s[strlen(s)-1 - i]) result++;
    }

    if (result == strlen(s) / 2) printf("1"); else printf("0");
    return 0;
}