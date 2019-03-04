// 11821 - High-Precision Number

#include <cstdio>
#include <cstring>

#define N 33

void reverse(char * str, const int & n)
{
	char c;
	for(int i = 0; i < (n >> 1); i++)
	{
		c = str[i];
		str[i] = str[n - i - 1];
		str[n - i - 1] = c;
	}
}

struct decimal_t
{
	char integer[N], decimal[N];
	int decpt;
	bool neg;

	void zero()
	{
		memset(integer, 0, sizeof(integer));
		memset(decimal, 0, sizeof(decimal));

		decpt = 1;
		neg = 0;
	}

	void init(const char * digits)
	{
		zero();

		neg = decpt = digits[0] == '-';
		while(digits[decpt] && digits[decpt] != '.') decpt++;
		
		memcpy(integer, digits + neg, decpt - neg);
		if(decpt + 1 < N)
			memcpy(decimal, digits + decpt + 1, N - decpt - 1);

		decpt -= neg;
		reverse(integer, decpt);

		for(int i = 0; i < decpt; i++)
			integer[i] -= '0';
		for(int i = 0; decimal[i]; i++)
			decimal[i] -= '0';
	}

	void print()
	{
		int i = N - 1;
		while(i >= 0 && !decimal[i]) i--;
		while(i >= 0) decimal[i--] += '0';

		reverse(integer, decpt);
		for(i = 0; i < decpt; i++)
			integer[i] += '0';
		
		if(decpt == 1 && !decimal[0] && integer[0] == '0')
		{
			printf("0\n");
			return;
		}

		if(neg) printf("-%s", integer);
		else printf("%s", integer);

		if(decimal[0]) printf(".%s\n", decimal);
		else putchar('\n');
	}

	void add(const decimal_t & in)
	{
		char a = 0;
		for(int i = N - 1; i >= 0; i--)
		{
			a += decimal[i] + in.decimal[i];
			decimal[i] = a % 10;
			a /= 10;
		}
		
		decpt = decpt < in.decpt ? in.decpt : decpt;
		for(int i = 0; i < decpt; i++)
		{
			a += integer[i] + in.integer[i];
			integer[i] = a % 10;
			a /= 10;
		}

		if(a) integer[decpt++] = a;
	}

	void subtract(const decimal_t & in)
	{
		bool m = is_less(in);

		if(m) neg = in.neg;

		char x, y, a = 0;
		for(int i = N - 1; i >= 0; i--)
		{
			// x - y
			if(m) { x = in.decimal[i]; y = decimal[i]; }
			else { x = decimal[i]; y = in.decimal[i]; }

			x -= a;
			a = x < y;

			if(a) x += 10;
			decimal[i] = x - y;
		}
		
		if(m) decpt = in.decpt;
		for(int i = 0; i < decpt; i++)
		{
			// x - y
			if(m) { x = in.integer[i]; y = integer[i]; }
			else { x = integer[i]; y = in.integer[i]; }

			x -= a;
			a = x < y;

			if(a) x += 10;
			integer[i] = x - y;
		}

		while(decpt > 1 && !integer[decpt - 1]) decpt--;
	}

	bool is_less(const decimal_t & in)
	{
		if(decpt != in.decpt) return decpt < in.decpt;
		
		for(int i = decpt - 1; i >= 0; i--)
			if(integer[i] != in.integer[i])
				return integer[i] < in.integer[i];

		for(int i = 0; i < N; i++)
			if(decimal[i] != in.decimal[i])
				return decimal[i] < in.decimal[i];

		return 0;
	}
};

int main()
{
	decimal_t sum, num;
	char digits[N];
	int n;

	scanf("%d", &n);
	while(n--)
	{
		sum.zero();
		
		memset(digits, 0, sizeof(digits));
		while(scanf("%s", digits) && !(!digits[1] && digits[0] == '0'))
		{
			num.init(digits);
			
			if(num.neg == sum.neg)
				sum.add(num);
			else sum.subtract(num);
			
			memset(digits, 0, sizeof(digits));
		}

		sum.print();
	}

	return 0;
}

