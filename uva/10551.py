# 10551 - Basic Remains

import sys

def to_base_10(n, b):

	r, p = 0, 1
	while n != 0:
		r += (n % 10) * p
		p *= b
		n //= 10

	return r

def to_base(n, b):
	
	r = ''
	while n >= b:
		r = chr(ord('0') + n % b) + r
		n //= b

	return chr(ord('0') + n) + r

for line in sys.stdin:
	linput = list(map(int, line.split()))
	if linput[0] == 0:
		break;
	
	b, p, m = linput

	if b == 10:
		print(p % m)
	else:
		p = to_base_10(p, b)
		m = to_base_10(m, b)
		print(to_base(p % m, b))

