#include <cstdio>
#include <string>
#include <algorithm>
#include <unordered_map>

struct combination
{
	int num[5];

	int & operator[](const int & i)
	{
		return num[i];
	}

	std::string to_string()
	{
		std::sort(num, num + 5);

		std::string str = "";
		for(const int & n: num)
			str += std::to_string(n);

		return str;
	}
};

int main()
{
	int max, s, n;
	combination courses;

	while(scanf("%d", &n) != EOF)
	{
		std::unordered_map<std::string, int> popularity;

		max = 1;
		while(n--)
		{
			for(int i = 0; i < 5; ++i)
				scanf("%d", &courses[i]);

			s = ++popularity[courses.to_string()];
			if(s > max) max = s;
		}

		s = 0;
		for(auto & p: popularity)
			if(p.second == max) s += max;

		printf("%d\n", s);
	}

	return 0;
}

