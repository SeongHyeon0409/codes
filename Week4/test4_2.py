data = input("Enter list of numbers: ")
numbers = data.split()
numbers = [int(i) for i in numbers]


def findmin (nbrs):
	minval = nbrs[0]
	for val in nbrs:
		if (minval > val):
			minval = val
	return minval

sortedlist = []
tempnbrs = numbers[:]
for i in range(len(numbers)):
	minval = findmin(tempnbrs);
	sortedlist += [minval]
	tempnbrs.remove(minval)

print("Manual:", sortedlist)
print("Built-In", sorted(numbers))

def findminIdx (nbrs, start):
	minval = nbrs[start]
	minidx = start 
	for i in range(start + 1, len(nbrs)):
		if (minval > nbrs[i]):
			minval = nbrs[i]
			minidx = i
	return minidx

for curPos in range(len(numbers)):
	minidx = findminIdx(numbers, curPos);
#	temp = numbers[minidx]
#	numbers[minidx] = numbers[curPos]
#	numbers[curPos] = temp
	numbers[curPos], numbers[minidx] = numbers[minidx], numbers[curPos]

print("Manual2:", numbers)


scoredb = [ {'Name':'Lee', 'Score':30},
    {'Name':'Kim', 'Score':40},
	{'Name':'Park', 'Score':50},
	{'Name':'Choi', 'Score':90} ]

print("Sort:", sorted(scoredb, key=lambda person: person['Score']))
print("Sort:", sorted(scoredb, key=lambda person: person['Score'], reverse=True))

