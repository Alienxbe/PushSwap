import random

l = [n for n in range(500)]
random.shuffle(l)

for n in l:
	print(n, end=' ')