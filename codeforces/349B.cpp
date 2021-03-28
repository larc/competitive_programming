#include <cstdio>

int main()
{
	int v, d, first;
	int num[10], min;

	scanf("%d", &v);

	min = 0;
	num[0] = 1000000;
	for(int i = 1; i < 10; ++i)
	{
		scanf("%d", num + i);
		if(num[i] <= num[min]) min = i;
	}

	if(v < num[min])
	{
		printf("-1\n");
		return 0;
	}

	d = v / num[min];
	v %= num[min];

	first = 0;
	while(d && v && !first)
	{
		for(int i = 1; i < 10; ++i)
		{
			if(v + num[min] >= num[i])
				first = i;
		}

		if(first)
		{
			d--;
			putchar(first + '0');
			v = v + num[min] - num[first];
			first = 0;
		}
		else first = 1;
	}

	while(d--) putchar(min + '0');
	putchar('\n');

	return 0;
}

