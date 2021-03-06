// 136 - Ugly Numbers

#include <cstdio>

int ugly_1500()
{
	int ugly[1500];

	int i, j, k;
	i = j = k = 0;

	ugly[0] = 1;
	for(int n = 1; n < 1500; ++n)
	{
		while(ugly[i] * 2 <= ugly[n - 1]) i++;
		while(ugly[j] * 3 <= ugly[n - 1]) j++;
		while(ugly[k] * 5 <= ugly[n - 1]) k++;

		ugly[n] = ugly[i] * 2;
		if(ugly[j] * 3 < ugly[n]) ugly[n] = ugly[j] * 3;
		if(ugly[k] * 5 < ugly[n]) ugly[n] = ugly[k] * 5;
	}

	return ugly[1499];
}

int main()
{
	printf("The 1500'th ugly number is %d.\n", ugly_1500());

	return 0;
}

