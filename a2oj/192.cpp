#include <cstdio>

int main()
{
	int n_cases, y1, m1, y2, m2;

	scanf("%d", &n_cases);
	while(n_cases--)
	{
		scanf("%d %d", &y1, &m1);
		scanf("%d %d", &y2, &m2);

		m1 += m2;
		y1 += y2 + (m1 > 12);

		printf("%d %d\n", y1, m1 <= 12 ? m1 : m1 - 12);
	}

	return 0;
}

