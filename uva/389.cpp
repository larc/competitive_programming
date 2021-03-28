// 389 - Basically Speaking

#include <cstdio>

char digit(const int & i)
{
	if(i < 10) return i + '0';
	return i - 10 + 'A';
}

int value(const char & c)
{
	if('0' <= c && c <= '9')
		return c - '0';
	return c - 'A' + 10;
}

int to_base_10(char * str, const int & b)
{
	int n = 0;
	while(*str)
	{
		n *= b;
		n += value(*str);
		str++;
	}

	return n;
}

char num[8];
int from_base_10(int n, const int & b)
{
	num[7] = 0;

	if(!n)
	{
		num[6] = '0';
		return 6;
	}

	int i = 7;
	while(n)
	{
		if(!i) return -1;

		num[--i] = digit(n % b);
		n /= b;
	}

	return i;
}

int main()
{
	int b_in, b_out, n, i;

	while(scanf("%s %d %d", num, &b_in, &b_out) != EOF)
	{
		n = to_base_10(num, b_in);
		i = from_base_10(n, b_out);
		printf("%7s\n", i < 0 ? "ERROR" : num + i);
	}

	return 0;
}

