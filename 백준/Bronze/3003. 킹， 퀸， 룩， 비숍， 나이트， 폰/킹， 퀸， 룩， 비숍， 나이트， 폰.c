int main() {
    int rule[6] = { 1,1,2,2,2,8 };
    int state[6];

    for (int i = 0; i < 6; i++) {
        scanf("%d", &state[i]);
    }
    for (int i = 0; i < 6; i++) {
        printf("%d ", rule[i] - state[i]);
    }
    return 0;
}