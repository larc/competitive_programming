#include <cstdio>

int big_mod(const int b, const int p, const int m)
{
	if(!p) return 1;
	if(p % 2) return (b * big_mod((b * b) % m, p >> 1, m)) % m;
	return big_mod((b * b) % m, p >> 1, m);
}

int main()
{
	int b, p, m;
	while(scanf("%d %d %d", &b, &p, &m) != EOF)
		printf("%d\n", big_mod(b % m, p, m));
	return 0;
}

