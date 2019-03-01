// 713 - Adding Reversed Numbers

#include <cstdio>
#include <cstring>

#define N 202

int main()
{
	int n, i;
	char A[N], B[N], C[N], a;

	scanf("%d", &n);
	while(n--)
	{
		memset(A, 0, sizeof(A));
		memset(B, 0, sizeof(B));

		scanf("%s %s", A, B);
		
		a = 0;
		for(i = 0; A[i] || B[i]; i++)
		{
			a += A[i] ? A[i] - '0' : 0;
			a += B[i] ? B[i] - '0' : 0;

			C[i] = a % 10 + '0';

			a /= 10;
		}
	
		C[i++] = a ? a + '0' : 0;
		C[i] = 0;

		for(i = 0; C[i] == '0'; i++);
		
		printf("%s\n", C + i);
	}

	return 0;
}

