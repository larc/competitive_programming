#include <cstdio>
#include <algorithm>

int main()
{
	int a, b, c;
	while(scanf("%d %d %d", &a, &b, &c) && a)
	{
		if(c < a) std::swap(c, a);
		if(c < b) std::swap(c, b);
		printf("%s\n", a * a + b * b == c * c ? "right" : "wrong");
	}

	return 0;
}

