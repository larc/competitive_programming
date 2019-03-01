# 10523 - Very Easy !!!

import sys

for line in sys.stdin:
	n, a = map(int, line.split())
	if a == 1:
		print(n * (n + 1) // 2)
	else:
		print((a - (n + 1) * a ** (n + 1) + n * a ** (n + 2) ) // (1 - a) ** 2)

