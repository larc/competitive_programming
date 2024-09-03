#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

#define MAX 100001


int B, L, D, S[MAX];
bool vis_lib[MAX] = {};

struct library_t
{
	int N, T, M;
	int value;
	int * books = nullptr;

	~library_t()
	{
		if(books) delete [] books;
	}

	const int operator[](const int i)
	{
		return books[i];
	}

	void update(const int t)
	{
		int n = 0;
		for(int i = 0; i < N; ++i)
			if(S[books[i]]) books[n++] = books[i];

		N = n;

		// update val
		n = std::min(N, (D - (T + t)) * M);

		value = (n + M - 1) / M;
	}

} libraries[MAX];


int select_lib(const int t)
{
	int l = -1;
	int max = 0;
	for(int i = 0; i < L; ++i)
	{
		if(vis_lib[i]) continue;

		library_t & lib = libraries[i];
		lib.update(t);

		if(max < lib.value)
		{
			max = lib.value;
			l = i;
		}
	}

	return l;
}

int main()
{
	std::vector<int> signup;
	signup.reserve(MAX);

	int id, time = 0;

	scanf("%d %d %d", &B, &L, &D);

	for(int i = 0; i < B; ++i)
		scanf("%d", S + i);

	for(int i = 0; i < L; ++i)
	{
		library_t & lib = libraries[i];

		scanf("%d %d %d", &lib.N, &lib.T, &lib.M);

		lib.books = new int[lib.N];

		for(int j = 0; j < lib.N; ++j)
			scanf("%d", lib.books + j);

		std::sort(lib.books, lib.books + lib.N, [&](const int i, const int j)
												{
													return S[i] > S[j];
												});
	}

	while(true)
	{
		id = select_lib(time);
		if(id < 0) break;

		vis_lib[id] = true;
		signup.push_back(id);

		library_t & lib = libraries[id];

		time += lib.T;

		for(int j = 0; j < lib.N; ++j)
			S[lib[j]] = 0;
	}

	printf("%lu\n", signup.size());
	for(int & i: signup)
	{
		library_t & lib = libraries[i];

		printf("%d %d\n", i, lib.N);
		for(int j = 0; j < lib.N; ++j)
			printf("%d ", lib[j]);
		putchar('\n');
	}

	return 0;
}

