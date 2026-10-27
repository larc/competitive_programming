#include <cstdio>
#include <vector>

void candies(std::vector<int> & R, const int sum, const int target, int n)
{
	if(sum == target)
	{
		for(int r: R)
			printf("%d ", r);
		printf("\n");
		return;
	}

	do
	{
		if(n + sum > target)
			continue;

		R.push_back(n);
		candies(R, sum + n, target, n);
		R.pop_back();
	}
	while(--n);
}

int main()
{
	int n;
	std::vector<int> R;
	R.reserve(176);
	
	scanf("%d", &n);
	candies(R, 0, n, n);

	return 0;
}

