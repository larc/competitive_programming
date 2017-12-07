#include <cstdio>
#include <string>

#define N 100001

using namespace std;

const string fzero = "What are you doing at the end of the world? Are you busy? Will you save us?";
const string fia = "What are you doing while sending \"";
const string fib = "\"? Are you busy? Will you send \"";
const string fic = "\"?";

unsigned long long fsize[N];

void init_fsize()
{
	fsize[0] = fzero.size();
	for(int i = 1; i < N; i++)
		fsize[i] = fia.size() + fsize[i - 1] + fib.size() + fsize[i - 1] + fic.size();	
}

char query(int n, unsigned long long k)
{
	if(!n) return fzero[k];
	
	if(k < fia.size()) return fia[k];
	
	k -= fia.size();
	if(k < fsize[n - 1]) return query(n - 1, k);

	k -= fsize[n - 1];
	if(k < fib.size()) return fib[k];

	k -= fib.size();
	if(k < fsize[n - 1]) return query(n - 1, k);

	k -= fsize[n - 1];
	return fic[k];
}

int main()
{
	init_fsize();

	int q, n;
	unsigned long long k;

	scanf("%d", &q);
	while(q--)
	{
		scanf("%d %llu", &n, &k);
		if(fsize[n] < k) putchar('.');
		else putchar(query(n, k - 1));
	}
	putchar('\n');

	return 0;
}

