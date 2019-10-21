# Description
# Oganesson Dynamics have blueprints for a carbon sequestration station that will pull carbon out of the atmosphere until it has been reduced to a target level.

# Every day a station can pull a configurable number of units of carbon out of the atmosphere. Unfortunately, the amount removed must always be set to a power of two. So, it could pull 1, 2, 4, 8, 16, or 32 units in a day (or more!), but NOT exactly 5 or 20 units.

# Given a starting number of units (N) and a goal number (G), can you figure out the fewest number of days it would take to reach the target?

# Input Format

# The first line will contain a value T indicating the number of planets (the number of test cases).
# The next T lines will each contain two integers N, indicating a number of units of carbon in the atmosphere, and G, the goal number of units for when the station is finished.
# Constraints

# 1 ≤ T ≤ 200,000
# 1 ≤ G ≤ N ≤ 264 - 1
# Output Format

# N lines, each indicating the number of days it would take to reduce the carbon of a given planet down to the target level.

import math

def count_bits(n): 
    count = 0
    while (n): 
        if (n[0] == '1'):
        	count+=1
        n = n[1:]
    return count
    
tests = int(input())
for _ in range(tests):
	n, g = map(int, input().split())
	s = "{0:b}".format(n-g)
	print(count_bits(s))
