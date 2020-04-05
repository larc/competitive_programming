#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

#define MAX 100001


int B, L, D, S[MAX], ids[MAX];
int send[MAX] = {};

struct library_t
{
	int N, T, M;
	int value;
	int * books = nullptr;

	~library_t()
	{
		if(books) delete [] books;
	}

	const int & operator[](const int & i)
	{
		return books[i];
	}

	float ratio()
	{
		return float(T + (N + M - 1) / M) / D;
	}

} libraries[MAX];

struct compare
{
	bool operator()(const int & i, const int & j)
	{
		return libraries[i].ratio() > libraries[j].ratio();
	};
};

int main()
{
	scanf("%d %d %d", &B, &L, &D);

	for(int i = 0; i < B; i++)
		scanf("%d", S + i);

	for(int i = 0; i < L; i++)
	{
		ids[i] = i;
		library_t & lib = libraries[i];

		scanf("%d %d %d", &lib.N, &lib.T, &lib.M);
		
		lib.books = new int[lib.N];
		lib.value = 0;

		for(int j = 0; j < lib.N; j++)
		{
			scanf("%d", lib.books + j);
			lib.value += S[lib[j]] * lib.M;
		}

		std::sort(lib.books, lib.books + lib.N, [&](const int & i, const int & j)
												{
													return S[i] > S[j];
												});
	}

	std::priority_queue<int, std::vector<int>, compare> Q(ids, ids + L);

	std::vector<int> books;
	books.reserve(MAX);
	
	int id, time = 0; bool b;

	L = 0;
	while(!Q.empty())
	{
		id = Q.top(); Q.pop();
		library_t & lib = libraries[id];

		time += lib.T;
		
		books.clear();
		for(int t = 0, i = 0; i < lib.N && t + time < D; i++)
		{
			b = false;
			if(!send[lib[i]])
				b = true;
			else if(send[lib[i]] > t + time)
				b = true;

			if(b)
			{
				books.push_back(lib[i]);
				send[lib[i]] = t + time;
				if(books.size() % lib.M == 0) t++;
			}
		}
		
		if(books.size())
		{
			ids[L++] = id;

			lib.N = books.size();
			memcpy(lib.books, books.data(), lib.N * sizeof(int));
		}
	}

	printf("%d\n", L);
	for(int i = 0; i < L; i++)
	{
		library_t & lib = libraries[ids[i]];

		printf("%d %d\n", ids[i], lib.N);
		for(int j = 0; j < lib.N; j++)
			printf("%d ", lib[j]);
		putchar('\n');
	}

	return 0;
}

