# Description
# ATOM labs has a regular inflow of priceless relics, some thought to have mystical powers. Dr. Malcolm Niacal is very interested in getting his hands on some of these relics and wants to keep track of how many are being studied in each lab location... just in case he wants to procure them for himself.

# Input Format

# The first line contains a single value N, indicating the number of relics being sent to labs to be studied.

# The next N lines each contain the ID number of the research lab that each relic was sent to. Note that ID numbers may not be consecutive and can be large values.

# Constraints

# 1 ≤ N ≤ 106
# 0 ≤ lab ID ≤ 1012
# 1 ≤ number of unique lab IDs ≤ 1000
# Output Format

# Print the ID number of the lab that has the most relics. If two labs have the same number of relics, just print the one with the lowest ID.

import statistics
from statistics import mode

n = int(input())
l = []

for _ in range(n):
    lab = int(input())
    l.append(lab)
    
print(mode(l))

# using mode idea came from: 
# https://www.geeksforgeeks.org/python-find-most-frequent-element-in-a-list/
