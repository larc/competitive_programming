#include <string>
#include <iostream>
#include <cstring>

#define N 1050

using namespace std;

bool no_primes[N];

void init_primes()
{
	memset(no_primes, 0, sizeof(no_primes));
	for(int j, i = 2; i < N; ++i)
		if(!no_primes[i])
			for(j = i + i; j < N; j += i)
				no_primes[j] = 1;
}

int main()
{
	init_primes();
	string word;
	int sum;
	while(cin>>word)
	{
		sum = 0;
		for(int i = 0; i < word.size(); ++i)
			sum += word[i] >= 'a' && word[i] <= 'z'? word[i] - 'a' + 1 : word[i] - 'A' + 27;
		if(!no_primes[sum]) cout<<"It is a prime word."<<endl;
		else cout<<"It is not a prime word."<<endl;
	}
	return 0;
}
