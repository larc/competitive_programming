#include <cstdio>
#include <cstring>
#include <stack>

int main()
{
	const int values[5] = {	0b01010101010101010101010101010101,
							0b00110011001100110011001100110011,
							0b00001111000011110000111100001111,
							0b00000000111111110000000011111111,
							0b00000000000000001111111111111111
							};

	char wff[101];
	int n, m, a, b;
	int vars[256];
	std::stack<int> op;

	while(scanf("%s", wff) != EOF)
	{
		if(wff[0] == '0')
			break;

		memset(vars, -1, sizeof(vars));

		m = 0;
		for(n = 0; wff[n]; ++n)
		{
			int c = wff[n];
			if('a' <= c && c <= 'z' && vars[c] == -1)
				vars[c] = m++;
		}

		for(int j = n - 1; j >= 0; --j)
		{
			int c = wff[j];
			if('a' <= c && c <= 'z')
			{
				op.push(values[vars[c]]);
			}
			else
			{
				a = op.top(); op.pop();
				switch(c)
				{
					case 'K': b = op.top(); op.pop(); op.push(a & b);
						break;
					case 'A': b = op.top(); op.pop(); op.push(a | b);
						break;
					case 'N': op.push(~a);
						break;
					case 'C': b = op.top(); op.pop(); op.push((~a) | b);
						break;
					case 'E': b = op.top(); op.pop(); op.push(~(a ^ b));
						break;
				}
			}
		}

		printf("%s\n", op.top() == -1 ? "tautology" : "not");
		op.pop();
	}

	return 0;
}

