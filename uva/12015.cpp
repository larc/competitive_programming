#include <string>
#include <cstring>
#include <iostream>

#define N 101
#define W 10

using namespace std;

int main()
{
	int S[N];
	string web, webs[N][W];
	int max, T, c = 0, w, pr;

	cin >> T;
	while(T--)
	{
		memset(S, 0, sizeof(S));
		max = 0;
		w = W;
		while(w--)
		{
			cin >> web >> pr;
			webs[pr][S[pr]++] = web;
			if(pr > max) max = pr;
		}
		
		cout << "Case #" << ++c << ":" << endl;
		for(int i = 0; i < S[max]; ++i)
			cout << webs[max][i] << endl;
		
	}

	return 0;
}

