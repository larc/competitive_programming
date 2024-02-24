// Postfix Notation

#include <cstdio>
#include <stack>

bool is_digit(const char c)
{
	return c >= '0' && c <= '9';
}

int main()
{
	#ifdef JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	#endif

	int n, a, b;
	char c;
	std::stack<int> s;

	scanf("%d", &n);
	while(n--)
	{
		scanf(" %c", &c);
		if(is_digit(c)) s.push(c - '0');
		else
		{
			b = s.top(); s.pop();
			a = s.top(); s.pop();

			if(c == '*') s.push(a * b);
			else if(c == '+') s.push(a + b);
			else s.push(a - b);
		}
	}

	printf("%d\n", s.top());

	return 0;
}

