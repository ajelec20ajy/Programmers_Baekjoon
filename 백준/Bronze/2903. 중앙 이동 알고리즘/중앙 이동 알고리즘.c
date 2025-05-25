int main() {
	int n; scanf("%d", &n);
	int x = 1;
	for (int i = 0; i < n; i++) {
		x = x * 2;
	}

	printf("%d", (x + 1) * (x + 1));

	return 0;
}