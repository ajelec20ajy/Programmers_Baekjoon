int main() {

    int n, m;
    scanf("%d %d", &n, &m);
    getchar();

    int** num1 = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        num1[i] = (int*)malloc(sizeof(int) * m);
    }

    int** num2 = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        num2[i] = (int*)malloc(sizeof(int) * m);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &num1[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &num2[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", num1[i][j] + num2[i][j]);
        }
        printf("\n");
    }
    

    return 0;
}