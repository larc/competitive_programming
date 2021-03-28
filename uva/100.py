import sys

N = 1000000
C = [0] * N

def cycle(n):
	if(n == 1):
		return 1
	if(n >= N):
		if(n % 2):
			return 1 + cycle(3 * n + 1)
		else:
			return 1 + cycle(n / 2)

	if(C[int(n)] == 0):
		if(n % 2):
			C[int(n)] = 1 + cycle(3 * n + 1)
		else:
			C[int(n)] = 1 + cycle(n / 2)

	return C[int(n)]

def max_cycle(i, j):
	m = 0
	while(i <= j):
		c = cycle(i)
		if(c > m):
			m = c
		i += 1
	return m

for line in sys.stdin:
	a,b = line.split()
	a = int(a)
	b = int(b)
	if(a < b):
		c = max_cycle(a, b)
	else:
		c = max_cycle(b, a)

	print(a, b, c)

