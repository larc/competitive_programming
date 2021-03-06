// 7. NASSA's Robot

#include <string>
#include <iostream>

using namespace std;

int main()
{
	string singals;
	size_t T;
	int min[2], max[2];
	cin>>T;
	while(T--)
	{
		cin>>singals;
		min[0] = min[1] = max[0] = max[1] = 0;
		for(size_t  i = 0; i < singals.size(); ++i)
			switch(singals[i])
			{
				case 'D': min[1]--; max[1]--; break;
				case 'L': min[0]--; max[0]--; break;
				case 'U': min[1]++; max[1]++; break;
				case 'R': min[0]++; max[0]++; break;
				case '?': min[0]--; min[1]--; max[0]++; max[1]++; break;
			}

		cout<<min[0]<<" "<<min[1]<<" "<<max[0]<<" "<<max[1]<<endl;
	}
	return 0;
}
