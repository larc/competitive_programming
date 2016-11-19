#include <iostream>
#include <string>

#define INF 1E100

using namespace std;

int main()
{
	int n, p, i, r, ip;
	double d, cp, maxcp, mind;
	string s, rs, ps;
	ip = 0;
	cin>>n>>p;
	while(n && p)
	{
		ip++;
		getline(cin, s);
		for(i = 0; i < n; i++)
			getline(cin, s);
		maxcp = 0;
		mind = INF;
		while(p--)
		{
			getline(cin, ps);
			cin>>d>>r;
			getline(cin, s);
			cp = r;
			while(r--)
				getline(cin, s);
			cp /= n;
			if(cp > maxcp)
			{
				maxcp = cp;
				rs = ps;
				mind = d;
			}
			else if(cp == maxcp && d < mind)
			{
				rs = ps;
				mind = d;
			}
				
		}
		cout<<"RFP #"<<ip<<endl;
		cout<<rs<<endl;
		cin>>n>>p;
		if(n && p) cout<<endl;
	}
	return 0;
}
