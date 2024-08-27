import random

l = [n for n in range(100)]
random.shuffle(l)

for n in l:
	print(n, end=' ')