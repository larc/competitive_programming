// 7646 - Candle Box

#include <cstdio>

int candles_rita(const int & RT, const int & D)
{
	int eR, eT = 3, cR, cT;
	do
	{
		eR = eT + D;
		cR = ((4 + eR) * (eR - 3)) >> 1;
		cT = ((3 + eT) * (eT - 2)) >> 1;

		eT++;
	}
	while(cR + cT != RT);

	return cR;
}

int main()
{
	int R, T, D;

	while(scanf("%d %d %d", &D, &R, &T) != EOF)
		printf("%d\n", R - candles_rita(R + T, D));
	return 0;
}

