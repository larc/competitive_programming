// 481 - What Goes Up
:wqi:wqiiii:wqi
#include <cstdio>
#include <cstring>

#define N 100000

int seq[N];
int lis[N];
int parent[N];

void print_lis(const int & i)
{
	if(i < 0) return;

	print_lis(parent[i]);
	printf("%d\n", seq[i]);
}

int main()
{	
	int n = 0;
	while(scanf("%d", seq + n++) != EOF);
	n--;
	
	memset(parent, -1, sizeof(parent));

	lis[0] = 1;
	int k = 0;
	for(int i = 1; i < n; i++)
	{
		lis[i] = 1;
		for(int j = i - 1; j >= 0; j--)
		{
			if(seq[j] < seq[i] && lis[j] + 1 > lis[i])
			{
				lis[i] = lis[j] + 1;
				parent[i] = j;
			}
		}

		if(lis[i] >= lis[k]) k = i;
	}

	printf("%d\n", lis[k]);
	printf("-\n");
	print_lis(k);

	return 0;
}

