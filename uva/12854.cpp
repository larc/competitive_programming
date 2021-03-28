// 12854 - Automated Checking Machine

#include <iostream>

using namespace std;

bool a[5];
bool b[5];

inline char compatible()
{
	for(int i = 0; i < 5; ++i)
		if(!(a[i] ^ b[i]))
			return 'N';

	return 'Y';
}

int main()
{
	while(cin>>a[0])
	{
		for(int i = 1; i < 5; ++i)
			cin >> a[i];
		for(int i = 0; i < 5; ++i)
			cin >> b[i];

		cout << compatible() <<endl;
	}

	return 0;
}
