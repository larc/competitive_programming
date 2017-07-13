#include <iostream>
#include <string>

using namespace std;

inline bool is_letter(char & c)
{
	if(c >= 'A' && c <= 'Z')
	{
		c -= 'A' - 'a';
		return true;
	}
	return c >= 'a' && c <= 'z';
}

int main()
{
	bool p;
	string str; 
	while(getline(cin, str) && str != "DONE")
	{
		p = true;
		
		for(int i = 0, j = str.size() - 1; i < j; )
		{
			if(is_letter(str[i]) && is_letter(str[j]))
			{
				if(str[i] != str[j])
				{
					p = false;
					break;
				}
				else
				{
					i++; j--;
				}
			}
			else
			{
				if(!is_letter(str[i])) i++;
				if(!is_letter(str[j])) j--;
			}
		}

		if(p) cout << "You won't be eaten!" << endl;
		else cout << "Uh oh.." << endl;
	}

	return 0;
}

