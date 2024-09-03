# 2705 - Keep It Covered

from sys import stdin, stdout
import sys

N = 21
M = N * N * 2

G = [[] for i in range(M)]
visited = [0 for i in range(M)]
match = [-1 for i in range(M)]


def augmenting_path(u) -> bool:
	if visited[u]:
		return 0
	visited[u] = 1

	for v in G[u]:
		if match[v] == -1 or augmenting_path(match[v]):
			match[v] = u
			match[u] = v
			return 1

	return 0

def main() -> int:
	r, c = stdin.readline().split()
	r = int(r)
	c = int(c)

	cell = stdin.readlines()

	'''
	for i in range(r):
		for j in range(c):
			print(cell[i][j], end="")
		print("");
	'''

	pos = lambda i, j : (i * c + j) << 1

	def add_edge(u, i, j):
		if i < 0 or i >= r or j < 0 or j >= c:
			return
		v = pos(i, j)
		G[u].append(v)
		if cell[i][j] == 'o':
			return
		G[u].append(v + 1)


	n = 0
	for i in range(r):
		for j in range(c):
			n += 2 if cell[i][j] != 'o' else 1;
			if (i + j) & 1:
				u = pos(i, j)
				add_edge(u, i - 1, j)
				add_edge(u, i + 1, j)
				add_edge(u, i, j - 1)
				add_edge(u, i, j + 1)

				if cell[i][j] != 'o':
					u += 1;
					add_edge(u, i - 1, j)
					add_edge(u, i + 1, j)
					add_edge(u, i, j - 1)
					add_edge(u, i, j + 1)

	if n & 1:
		print("N")
	else:
		mcbm = 0
		for i in range(r):
			for j in range(c):
				if (i + j) & 1:
					u = pos(i, j)

					for k in range(M):
						visited[k] = 0

					mcbm += augmenting_path(u)

					if cell[i][j] != 'o':
						for k in range(M):
							visited[k] = 0

						mcbm += augmenting_path(u)

		n >>= 1;
		print("Y") if mcbm == n else print("N")

	return 0

if __name__ == "__main__":
	sys.exit(main())

