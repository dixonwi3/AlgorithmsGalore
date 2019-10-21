# Description
# Of all of their discoveries, Oganesson Dynamics is most excited by their new warp engines. The problem is that they go through the quadlithium crystals that power them much too quickly. Can you help figure out how to get the crystals to last for as long as possible?

# Warp engines apply one of K different frequencies to a crystal to extract power from it for an hour, after which the crystal breaks into smaller crystals (some of which may be used again!). Each frequency i is associated with a fracture value Fi  indicating the size of the crystals that this one will break into when used.

# Frequency i can only be used if S (the size of the crystal) is greater than Fi and can be evenly divided by Fi . The crystal then breaks into P/Fi  crystals each of which is size is size Fi .

# Since each application of a frequency to a crystal can power the engine for an hour, what is the LONGEST amount of time (in hours) that the ship can fly given a single starting crystal of size N ?

# Input Format

# The first line contains an integer, T, denoting the number of tests to be performed. The subsequent T pairs of lines describe each test in the following format:

# The first line contains two space-separated integers describing the respective values of S (the size of the initial crystal) and K (the number of available frequencies).
# The second line contains K space-separated integers describing the values of F0 through FK-1.
# Constraints

# 1 ≤ T ≤ 10
# 1 ≤ S ≤ 1012
# 1 ≤ K ≤ 1000
# 1 ≤ Fi  ≤ 1012
# Output Format

# For each test, determine the maximum number of hours that the ship can be powered given the starting crystal; output this value on its own line.

def getMax(s, freqs, i, ans, sp):
	if (s == freqs[0]):
		return 0
	else:
	    ma = 0
	    f = False
	    for j in range(len(freqs)):
		    if s % freqs[j] == 0 and s != freqs[j]:
		        f = True
		        if ans[freqs[j]] != 0:
		            res = ans[freqs[j]]
		        else:
		            res = getMax(freqs[j], freqs, j, ans, (s//freqs[j]) * sp)
		        if res > ma:
		            ma = res
	if f:
	    ans[s] = ma + sp
	    return ans[s]
	return 0

test_cases = int(input())
freqs = []
for t in range(test_cases):
	c_size, splits = map(int,input().strip().split())
	freqs = list(map(int, input().split()))
	freqs.sort()
	ans = {}
	for f in freqs:
	    ans[f] = 0
	print(getMax(c_size, freqs, 0, ans, 1))

	
