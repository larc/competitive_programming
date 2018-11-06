// 11350 - Stern-Brocot Tree

#include <cstdio>

struct frac_t
{
	unsigned long long a, b;
	
	frac_t & operator += (const frac_t & f)
	{
		a += f.a; b += f.b;
		return *this;
	}
};

int main()
{
	char str[91];
	frac_t C[2], R;
	int n, dir;

	scanf("%d", &n);
	while(n--)
	{
		R = {1, 1};
		C[0] = {0, 1};
		C[1] = {1, 0};

		scanf("%s", str);
		for(int i = 0; str[i]; i++)
		{
			dir = str[i] == 'R';
			C[!dir] = R;
			R += C[dir];
		}

		printf("%llu/%llu\n", R.a, R.b);
	}
	
	return 0;
}

