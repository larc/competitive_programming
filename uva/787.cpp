// 787 - Maximum Sub-sequence Product

#include <cstdio>
#include <cstring>

#define N 100

struct big_int_t
{
	char num[500];
	int n;

	big_int_t()
	{
		memset(num, 0, sizeof(num));
		n = 0;
	}

	big_int_t & operator = (int x)
	{
		n = 0;
		while(x)
		{
			num[n++] = x % 10;
			x /= 10;
		}

		return *this;
	}

	big_int_t & operator *= (int x)
	{
		big_int_t prod;

		char r, c, p;
		int i, j, k;

		i = 0;
		while(x)
		{
			p = x % 10;
			x /= 10;

			c = 0;
			for(j = 0; j < n; ++j)
			{
				k = j + i;
				if(prod.n <= k) prod.n++;

				r = prod.num[k] + p * num[j] + c;
				prod.num[k] = r % 10;
				
				c = r / 10;
			}

			if(c) prod.num[prod.n++] = c;
			
			i++;
		}
		
		return *this = prod;
	}

	bool operator > (const big_int_t & x)
	{
		bool a = is_negative();
		bool b = x.is_negative();

		if(a && !b) return 0;
		if(!a && b) return 1;

		if(n != x.n)
		{
			if(a) return n < x.n;
			return n > x.n;
		}

		int i = n;
		
		while(i--)
		{
			if(num[i] != x.num[i])
				return a ? num[i] < x.num[i] : num[i] > x.num[i];
		}

		return 0;
	}

	bool is_negative() const
	{
		int c = n;
		while(c--)
			if(num[c] < 0) return 1;

		return 0;
	}

	void print()
	{
		if(!n)
		{
			printf("0\n");
			return;
		}

		int c = n;
		if(is_negative())
		{
			putchar('-');
			while(c--) putchar(-num[c] + '0');
		}
		else
			while(c--) putchar(num[c] + '0');
		

		putchar('\n');
	}
};

int main()
{
	big_int_t aux, pos, neg, max;
	int num;
		
	while(scanf("%d", &num) != EOF)
	{
		max = num;
		pos = neg = 1;

		do
		{
			pos *= num;
			neg *= num;
				
			if(pos.is_negative() && !neg.is_negative())
			{
				aux = pos;
				pos = neg;
				neg = aux;
			}
			
			if(pos > max)
				max = pos;
			
			if(pos.is_negative())
				pos = 1;
			
			if(!num)
			{
				pos = 1;
				neg = 1;
			}
		}
		while(scanf("%d", &num), num != -999999);
		
		max.print();
	}

	return 0;
}

