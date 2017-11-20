import time
import random
numofnbrs = int(input("Enter a number: "))
numbers = []
for i in range(numofnbrs):
	numbers += [random.randint(0, 999999)]

print("Make %d random numbers" %numofnbrs)

ts = time.time()
newnbrs = sorted(numbers)
ts = time.time() - ts
print("Built-In", numofnbrs, "elapsed time =", ts)

def findminIdx (nbrs, start):
	minval = nbrs[start]
	minidx = start 
	for i in range(start + 1, len(nbrs)):
		if (minval > nbrs[i]):
			minval = nbrs[i]
			minidx = i
	return minidx

ts = time.time()
for curPos in range(len(numbers)):
	minidx = findminIdx(numbers, curPos);
	numbers[curPos], numbers[minidx] = numbers[minidx], numbers[curPos]
ts = time.time() - ts
print("Manual", numofnbrs, "elapsed time =", ts)


