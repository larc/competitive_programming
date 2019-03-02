# 10814 - Simplifying Fractions

def gcd(a, b):
	if b == 0:
		return a
	else:
		return gcd(b, a % b)


n = int(input())

while n > 0:
	n -= 1

	line = input().split()
	
	a = int(line[0])
	b = int(line[2])
	d = gcd(a, b)

	print('%d / %d' %( a // d, b // d))
