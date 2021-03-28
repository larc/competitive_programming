#include <iostream>
#include <string>

using namespace std;

int main()
{
	string sword, tword;
	cin >> sword >> tword;

	bool ok = sword.size() == tword.size();

	if(ok)
	{
		for(int i = 0; i < sword.size(); ++i)
			if(sword[i] != tword[sword.size() - i - 1])
			{
				ok = 0;
				break;
			}
	}

	if(ok) printf("YES\n");
	else printf("NO\n");

	return 0;
}

