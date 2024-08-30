import random
import sys
import subprocess

# python3 tester.py <size> <number of test> <above warning>

def	generate_random_list(n: int):
	l = [str(n) for n in range(n)]
	random.shuffle(l)
	return " ".join(l)

def get_op_count(n: int):
	arg = generate_random_list(n)
	p = subprocess.run(['./push_swap', arg], capture_output=True, text=True)
	return len(p.stdout.splitlines())

def	main():
	if (len(sys.argv) != 4 or not sys.argv[1].isdigit() or not sys.argv[2].isdigit()
		or not sys.argv[3].isdigit()):
		return
	total = 0
	above = 0
	minimum = None
	maximum = None
	for i in range(int(sys.argv[2])):
		op = get_op_count(int(sys.argv[1]))
		if (op > int(sys.argv[3])):
			above += 1
		if (minimum is None or op < minimum): minimum = op
		if (maximum is None or op > maximum): maximum = op
		total += op
		print(f"test {i}: {op}\tTotal average: {int(total / (i + 1))}")
	print(f"{above}/{sys.argv[2]} tests where above the given limit ({sys.argv[3]})")
	print(f"Maximum: {maximum}\tMinimum: {minimum}")

main()