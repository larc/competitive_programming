// 11286 - Conformity

#include <cstdio>
#include <algorithm>
#include <map>

struct combination
{
	int course[5];

	const int & operator[](const int & i) const
	{
		return course[i];
	}

	int & operator[](const int & i)
	{
		return course[i];
	}

	void sort()
	{
		std::sort(course, course + 5);
	}
};

bool operator < (const combination & a, const combination & b)
{
	for(int i = 0; i < 5; ++i)
		if(a[i] != b[i]) return a[i] < b[i];

	return 0;
}

int main()
{
	int max, s, n;
	combination courses;

	while(scanf("%d", &n), n)
	{
		std::map<combination, int> popularity;

		max = 1;
		while(n--)
		{
			for(int i = 0; i < 5; ++i)
				scanf("%d", &courses[i]);

			courses.sort();
			s = ++popularity[courses];
			if(s > max) max = s;
		}

		s = 0;
		for(auto & p: popularity)
			if(p.second == max) s += max;

		printf("%d\n", s);
	}

	return 0;
}

