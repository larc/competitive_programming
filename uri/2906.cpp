// 2906 - Database of Clients

#include <cstdio>
#include <string>
#include <set>

#define N 101

int main()
{
	char email[N], user[N];
	int n, s, i;

	std::set<std::string> db;

	scanf("%d", &n);
	while(n--)
	{
		scanf("%s", email);

		i = s = 0;
		while(email[i] != '@')
		{
			if(email[i] == '+') break;
			if(email[i] != '.')
				user[s++] = email[i];

			i++;
		}
		
		while(email[i] != '@') i++;

		while(email[i]) user[s++] = email[i++];
		
		user[s] = 0;
		db.insert(user);
	}

	printf("%lu\n", db.size());

	return 0;
}

