// 6133 - Cellphone Typing

#include <iostream>
#include <cstdio>
#include <string>
#include <map>

#define N 100000

using namespace std;

string words[N];

struct parent
{
	map<char, parent> sons;
	bool end;

	parent(): end(0) {}
};

parent tree[26];

void insert(const string & word)
{
	parent * p = &tree[word[0] - 'a'];
	for(int i = 1; i < word.size(); i++)
		p = &p->sons[word[i]];
	
	p->end = 1;
}

int keystrokes(const string & word)
{
	int c = 1;
	
	parent * p = &tree[word[0] - 'a'];
	for(int i = 1; i < word.size(); i++)
	{
		c += p->sons.size() > 1 || p->end;
		p = &p->sons[word[i]];
	}

	return c;
}

int main()
{
	int n, c;
	while(cin >> n)
	{
		for(int i = 0; i < n; i++)
		{
			cin >> words[i];
			insert(words[i]);
		}
		
		c = 0;
		for(int i = 0; i < n; i++)
			c += keystrokes(words[i]);

		printf("%.2f\n", (float) c / n);
		
		for(int i = 0; i < 26; i++)
		{
			tree[i].sons.clear();
			tree[i].end = 0;
		}
	}

	return 0;
}

