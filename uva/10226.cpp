#include <iostream>
#include <map>
#include <string>
#include <cstdio>

using namespace std;

int main()
{
	int n, t;
	string s;
	cin>>n;
	getline(cin, s);
	getline(cin, s);
	while(n--)
	{
		t = 0;
		map<string, int> sp;
		while(getline(cin, s) && s != "")
		{
			sp[s]++;
			t++;
		}
		map<string, int>::iterator i = sp.begin();
		for(; i != sp.end(); i++)
		{
			cout<<i->first;
			printf(" %.4lf\n", i->second*100.0f/t);
		}
		if(n)
			printf("\n");
	}
	return 0;
}
