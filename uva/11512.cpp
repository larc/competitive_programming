// 11512 - GATTACA

#include <cstdio>
#include <cstring>

#define N 1001
#define M 500500

using namespace std;

struct trie
{
	trie * sons[26];
	int count;
	int next;

	void reset()
	{
		memset(sons, 0, sizeof(sons));
		count = 0;
	}
};

trie tree[M];
int s;

char letter[4] = {'A', 'C', 'G', 'T'};
int index(const char & c)
{
	if(c == 'A') return 0;
	if(c == 'C') return 1;
	if(c == 'G') return 2;
	if(c == 'T') return 3;
	return -1;
}

void insert(char * word)
{
	trie * p = &tree[index(*word++)];
	p->count++;

	while(*word != '\0')
	{
		trie *& q = p->sons[index(*word++)];
		if(!q)
		{
			q = &tree[s++];
			q->reset();
		}

		q->count++;
		p = q;
	}
}

int lrs(trie * t)
{
	if(!t || t->count <= 1) return 0;

	int l, m = 0;
	for(int i = 0; i < 4; ++i)
		if((l = lrs(t->sons[i])) > m)
		{
			m = l;
			t->next = i;
		}

	return m + 1;
}

trie * print_lrs(trie * str, int n)
{
	if(!n) return str;

	putchar(letter[str->next]);
	return print_lrs(str->sons[str->next], n - 1);
}

int main()
{
	int n, m, l, k;
	char seq[N];
	char * c;
	trie * str;

	scanf("%d", &n);
	while(n--)
	{
		scanf("%s", seq);
		memset(tree, 0, sizeof(trie) * 4);
		s = 4;

		c = seq;
		while(*c != '\0') insert(c++);

		m = 0;
		for(int i = 0; i < 4; ++i)
			if((l = lrs(&tree[i])) > m)
			{
				m = l;
				k = i;
			}

		if(!m) printf("No repetitions found!\n");
		else
		{
			putchar(letter[k]);
			str = print_lrs(&tree[k], m - 1);
			printf(" %d\n", str->count);
		}
	}

	return 0;
}

