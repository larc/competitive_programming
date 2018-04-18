// Bracket Sequence

#include <cstdio>
#include <stack>

#define N 10001

char line[N];

bool correct_bracket()
{
	std::stack<char> s;

	char * c = line;
	while(*c != '\0')
	{
		if(*c == '(' || *c == '[')
			s.push(*c);
		else if(s.empty()) return 0;
		else if(*c == ')' && s.top() != '(') return 0;
		else if(*c == ']' && s.top() != '[') return 0;
		else s.pop();
		c++;
	}

	return s.empty();
}

int main()
{
	#ifdef JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	#endif

	int n;

	scanf("%d", &n);
	while(n--)
	{
		scanf("%s", line);
		if(correct_bracket()) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}

