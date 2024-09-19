// 1063 - Rails Again... Tracing Movements

#include <cstdio>
#include <stack>
#include <string>


int main()
{
	int n;
	char c;
	std::string a, b, r;

	while(scanf("%d", &n), n)
	{
		a = "";
		for(int i = 0; i < n; ++i)
		{
			scanf(" %c", &c);
			a += c;
		}

		b = "";
		for(int i = 0; i < n; ++i)
		{
			scanf(" %c", &c);
			b += c;
		}

		std::stack<char> s;

		n = 0;
		r = "";
		for(char c: b)
		{
			while(s.empty() || s.top() != c)
			{
				if(!a[n]) break;
				s.push(a[n]);
				r += "I";
				++n;
			}

			if(s.empty() || s.top() != c)
			{
				r += " Impossible";
				break;
			}

			s.pop();
			r += "R";
		}

		printf("%s\n", r.c_str());
	}

	return 0;
}

