// 11879 - Multiple of 17

#include <cstdio>
#include <cstring>
#include <string>

bool mult_17(char * num, int n)
{
	if(n < 4) return !(std::stoi(num) % 17);

	char s = (num[--n] - '0') * 5;
	char d, r = 0;

	for(int i = n - 1; i >= 0; i--)
	{
		if(!s && !r) break;

		d = (s % 10) + r;
		num[i] -= '0';

		if(num[i] < d)
		{
			num[i] += 10;
			r = 1;
		}
		else r = 0;

		num[i] -= d - '0';
		s /= 10;
	}

	d = num[0] == '0';
	num[n] = 0;
	return mult_17(num + d, n - d);
}

bool mult_17(char * num)
{
	int m = 0;
	for(int i = 0; num[i]; ++i)
	{
		m = m * 10 + num[i] - '0';
		m %= 17;
	}

	return !m;
}

int main()
{
	char num[102];

	while(scanf("%s", num), num[0] - '0')
		printf("%d\n", mult_17(num));

	return 0;
}

