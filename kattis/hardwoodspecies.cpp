#include <cstdio>
#include <string>
#include <map>

using namespace std;

int main()
{
	int num;
	char str[22];
	map<string, int> sp;

	num = 0;
	while(fgets(str, sizeof(str), stdin))
	{
		for(int i = 0; str[i]; ++i)
			str[i] = str[i] == '\n' ? 0 : str[i];
		++sp[str];
		++num;
	}

	for(auto it: sp)
		printf("%s %.6lf\n", it.first.c_str(), it.second * 100.0f / num);

	return 0;
}

