// 1284 - Cellphone Typing

#include <cstdio>
#include <cstring>

#define N 100000
#define M 1000026

using namespace std;

char words[N][81];

struct trie
{
	trie * sons[26];
	int size;
	bool end;

	void reset()
	{
		memset(sons, 0, sizeof(sons));
		size = 0;
		end = 0;
	}
};

trie tree[M];
int s;

void insert(char * word)
{
	trie * p = &tree[*word++ - 'a'];
	while(*word != '\0')
	{
		trie *& q = p->sons[*word++ - 'a'];
		if(!q)
		{
			q = &tree[s++];
			q->reset();

			p->size++;
		}

		p = q;
	}

	p->end = 1;
}

int keystrokes(char * word)
{
	int c = 1;

	trie * p = &tree[*word++ - 'a'];
	while(*word != '\0')
	{
		c += p->size > 1 || p->end;
		p = p->sons[*word++ - 'a'];
	}

	return c;
}

int main()
{
	int n, c;
	while(scanf("%d", &n) != EOF)
	{
		memset(tree, 0, sizeof(trie) * 26);
		s = 26;

		for(int i = 0; i < n; ++i)
		{
			scanf("%s", words[i]);
			insert(words[i]);
		}

		c = 0;
		for(int i = 0; i < n; ++i)
			c += keystrokes(words[i]);

		printf("%.2f\n", (float) c / n);

	}

	return 0;
}

