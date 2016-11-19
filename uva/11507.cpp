#include <iostream>
#include <string>

using namespace std;

int main()
{
	int L;
	string d;
	char p, s, c[2];
	c[0] = '-';
	c[1] = '+';
	while(cin>>L && L)
	{
		L--;
		p = 'x';
		s = '+';
		
		while(L--)
		{
			cin>>d;
			if(d[0] == 'N') continue;
			if(p == 'x')
			{
				p = d[1];
				s = s == '+' ? d[0] : c[d[0] == '-'];
			}
			else if(d[1] == p)
			{
				p = 'x';
				s = s == '+' ? c[d[0] == '-'] : d[0];
			}
		}
		cout<<s<<p<<endl;
	}
	return 0;
}
