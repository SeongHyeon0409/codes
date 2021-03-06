import sys
import re
fname = input("Enter data file name: ")
try:
	fH = open(fname)
except FileNotFoundError as e:
	print("No such file: " + fname)
	sys.exit()
	

wordcount = {}
for line in fH:
	words = re.split('[^a-zA-Z]', line)
	
	for word in words:
		if word in wordcount:
			wordcount[word] += 1
		else:
			wordcount[word] = 1

#wordcount[word]=wordcont.get(word,0)+1
fH.close()
for word in wordcount:
	print(word, ":", wordcount[word])

