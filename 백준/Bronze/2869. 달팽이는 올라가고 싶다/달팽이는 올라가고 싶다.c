int main() {
	
	long long int A, B, V;
	scanf("%lld %lld %lld", &A, &B, &V);

	long long day = (V - A) / (A - B);

	if (day == 0 && V > A) day = 1;

	if (day*(A-B) < (V-A)) day++;
	
	printf("%lld", day + 1);

	return 0;
}