// 11423 - Cache Simulator

#include <cstdio>
#include <deque>
#include <vector>

#define N 30

struct fenwick_tree
{
	std::vector<int> bit;

	fenwick_tree()
	{
		bit.resize(10000001);
	}

	void add(unsigned int i, const int & v)
	{
		while(i < bit.size())
		{
			bit[i] += v;
			i += i & -i;
		}
	}

	int rsq(unsigned int i)
	{
		int s = 0;
		while(i)
		{
			s += bit[i];
			i -= i & -i;
		}
		return s;
	}

	int rsq(const int & a, const int & b)
	{
		return rsq(b) - rsq(a - 1);
	}
};

int main()
{
	fenwick_tree timeline;
	int cache[N];
	int n_misses[N] = {};
	std::vector<unsigned int> last_time(1 << 24);
	int time = 0;

	int n_caches, b, y, n;

	scanf("%d", &n_caches);
	for(int i = 0; i < n_caches; ++i)
		scanf("%d", cache + i);

	auto update_cache = [&](const int & a)
	{
		if(last_time[a])
		{
			int count = timeline.rsq(last_time[a], time);
			for(int i = 0; i < n_caches; ++i)
				if(count > cache[i])
					++n_misses[i];

			timeline.add(last_time[a], -1);
		}
		else
		{
			for(int i = 0; i < N; ++i)
				++n_misses[i];
		}

		last_time[a] = ++time;
		timeline.add(time, 1);
	};

	char str[8];
	while(scanf("%s", str), str[0] != 'E')
	{
		switch(str[0])
		{
			case 'S':
				printf("%d", n_misses[0]);
				n_misses[0] = 0;
				for(int i = 1; i < n_caches; ++i)
				{
					printf(" %d", n_misses[i]);
					n_misses[i] = 0;
				}
				printf("\n");
				break;
			case 'A':
				scanf("%d", &b);
				update_cache(b);
				break;
			case 'R':
				scanf("%d %d %d", &b, &y, &n);
				for(int k = 0; k < n; ++k)
					update_cache(b + y * k);
				break;
		}
	}

	return 0;
}

