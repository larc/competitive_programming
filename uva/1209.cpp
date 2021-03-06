#include <string>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

inline int maxmin(string p)
{
	int i, m = 1000;
	for(i = 0; i < p.size() - 1; ++i)
		m = min(m, abs(p[i] - p[i+1]));
	return m;
}
int main()
{
	string w, s, r;
	int c;
	int max, aux;
	while(cin>>s)
	{
		max = 0;
		w = s;
		c = 11;
		do
		{
		}
		while(--c > 0 && prev_permutation(w.begin(), w.end()));
		c = 1;
		do
		{
			aux = maxmin(w);
			if(aux > max)
			{
				r = w;
				max = aux;
			}
		}
		while(next_permutation(w.begin(), w.end()) && ++c <= 21);
		cout<<r<<max<<endl;
	}
	return 0;
}
