#include <algorithm>
#include <cstdio>


int main()
{
	int n = 0, v, m;
	int vec[10000] = {5, 4, 3, 2, 1};

	while(scanf("%d", &v) != EOF)
	{
		vec[n++] = v;
		m = n / 2;
		std::nth_element(vec, vec + m, vec + n);
		if(n % 2) printf("%d\n", vec[m]);
		else
		{
			v = vec[m--];
			std::nth_element(vec, vec + m, vec + n);
			v += vec[m];
			printf("%d\n", v / 2);
		}
	}
	return 0;
}

