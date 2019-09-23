#include <cstdio>
#include <algorithm>

int x[6], y[6];

bool cover(const int & i)
{
	if(x[i] <= x[0] && y[i] <= y[0] &&
		x[i + 1] >= x[1] && y[i + 1] >= y[1])
	{
		printf("NO\n");
		return true;
	}
	
	if(x[i] <= x[0] && y[i] <= y[0] && y[i + 1] >= y[1])
		x[0] = std::max(x[0], x[i + 1]);
	else if(x[i] <= x[0] && y[i] <= y[0] && y[i + 1] >= y[0])
		y[0] = std::max(y[0], y[i + 1]);
	else if(y[i] <= y[0] && x[i + 1] >= x[1] && y[i + 1] >= y[1])
		x[1] = std::min(x[1], x[i]);
	else if(x[i] <= x[0] && x[i + 1] >= x[1] && y[i + 1] >= y[1])
		y[1] = std::min(y[1], y[i]);

	return false;
}

int main()
{
	for(int i = 0; i < 6; i++)
		scanf("%d %d", x + i, y + i);
	
	if(cover(2)) return 0;
	if(cover(4)) return 0;
	
	printf("YES\n");

	return 0;
}

