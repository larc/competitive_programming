#include <cstdio>
#include <cmath>

int perfect_number(const int & n)
{
	if(n == 1) return 0;

	int sq = sqrt(n);
	if(sq == 1) return 0;

	int sum = 1;
	for(int i = 2; i < sq; i++)
		if(!(n % i)) sum += i + n / i; 
	
	if(sq * sq == n) sum += sq;
	else if(!(n % sq)) sum += sq + n / sq;
	
	if(sum == n) return 2;
	return sum > n;
}

int main()
{
	const char * out[] = {"DEFICIENT", "ABUNDANT", "PERFECT"};

	int n;
	printf("PERFECTION OUTPUT\n");
	while(scanf("%d", &n) && n)
		printf("%5d  %s\n", n, out[perfect_number(n)]);
	printf("END OF OUTPUT\n");
	return 0;
}

