#include <cstdio>

int comp(char a, char b)
{
	if('A' <= a && a <= 'Z') a = a - 'A' + 'a';
	if('A' <= b && b <= 'Z') b = b - 'A' + 'a';
	return a < b ? -1 : (a == b ? 0 : 1);
}

int str_comp(char * a, char * b)
{
	int r;
	while(*a != '\0')
	{
		r = comp(*a, *b);
		if(r != 0) return r;

		a++, b++;
	}

	return 0;
}

int main()
{
	char str_a[101];
	char str_b[101];

	scanf("%s", str_a);
	scanf("%s", str_b);

	printf("%d\n", str_comp(str_a, str_b));

	return 0;
}

