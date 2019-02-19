# 763 - Fibinary Numbers

import sys

fib = [None] * 103
fib[0] = 0
fib[1] = 1
for i in range(101):
	fib[i + 2] = fib[i] + fib[i + 1]

while True:

	n = 0;

	r = input()
	for i in range(len(r)):
		if r[i] == '1':
			n += fib[len(r) - i + 1]
	
	r = input()
	for i in range(len(r)):
		if r[i] == '1':
			n += fib[len(r) - i + 1]

	r = ''
	for i in reversed(range(2, 103)):
		if n >= fib[i]:
			r += '1'
			n -= fib[i]
		elif r != '':
			r += '0'
	
	if r == '':
		r = '0'

	print(r)

	try:
		input()
		print('')
	except:
		break

