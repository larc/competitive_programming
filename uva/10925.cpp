// 10925 - Krakovia

#include <cstdio>
#include <cstring>
#include <algorithm>

struct big_int
{
	char num[32] = {};

	char & operator [] (const int i)
	{
		return num[i];
	}

	char operator [] (const int i) const
	{
		return num[i];
	}

	char * str()
	{
		char * p = num;
		while(*p == '0') ++p;

		if(!(*p))
		{
			num[1] = 0;
			p = num;
		}

		return p;
	}

	big_int & operator += (const big_int & add)
	{
		int r = 0;
		int i = 0;
		for(; num[i] || add[i]; ++i)
		{
			char & a = num[i];
			const char b = add[i];

			a = (a ? (a - '0') : 0) + (b ? (b - '0') : 0) + r;
			r = a / 10;
			a = a % 10 + '0';
		}

		num[i] = r ? r + '0' : 0;

		return *this;
	}

	big_int operator / (const int n)
	{
		int r = 0;
		big_int ans;

		for(int i = 0; num[i]; ++i)
		{
			r = r * 10 + (num[i] - '0');
			ans[i] = r / n + '0';
			r = r % n;
		}

		return ans;
	}

	void zero()
	{
		memset(num, 0, sizeof(num));
	}

	void reverse()
	{
		int a = 0;
		int b = 0;

		while(num[b]) ++b;

		while(a < --b)
		{
			std::swap(num[a], num[b]);
			++a;
		}
	}
};

int main()
{
	int N, F;
	big_int A, V;

	int n_case = 0;
	while(scanf("%d %d", &N, &F) && N && F)
	{
		A.zero();
		while(N--)
		{
			V.zero();
			scanf("%s", V.num);
			V.reverse();
			A += V;
		}

		A.reverse();
		V = A / F;
		printf("Bill #%d costs %s: each friend should pay %s\n\n", ++n_case, A.str(), V.str());
	}

	return 0;
}

