// 24. Arabic and English

#include <string>
#include <iostream>

using namespace std;

int main()
{
	size_t T, N, i;
	string w[100];
	cin>>T;
	size_t p;
	while(T--)
	{
		cin>>N;
		p = N;
		for(i = 0; i < N; i++)
		{
			cin>>w[i];
			if(w[i][0] != '#')
				p = i;
		}
		for(i = p + 1; i < N; i++)
			cout<<w[i]<<" ";
		if(p && p < N)
			cout<<w[p]<<" ";
		else
			if(!p) cout<<w[p]<<endl;
		if(p)
		{
			p--;
			for(i = 0; i < p; i++)
				cout<<w[i]<<" ";
			cout<<w[i]<<endl;
		}
	}
	return 0;
}
