int main() {

	char N[31];
	long long int num = 0; 

	long long int ref;
	int B;
	scanf("%s %d", N, &B);
	int len = strlen(N);

	for (int i = 0; i < len; i++) {
		ref = 1;
		for (int j = 0; j < len - i-1; j++) {
			ref = ref * B;
		}
		if (N[i] == '0') continue;
		else if (N[i] > '0' && N[i] <= '9') {
			num += ((N[i] - 48) * ref);
		}
		else if (N[i] >= 'A' && N[i] <= 'Z') {
			num += ((N[i] - 55) * ref);
		}
	}
	printf("%d", num);
}