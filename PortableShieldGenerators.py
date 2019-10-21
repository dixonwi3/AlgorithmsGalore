# Description
# Portable shield generators can keep ships, buildings, and even people safe from harm. Oganesson Dynamics Inc. has a blueprint that will produce a device with a long series of aegis cells that can be individually turned on to produce a shield. Each cell has an individual contribution to shield strength. The total shield strength is the sum of these individual contributions.

# There's a problem though! The cells get very warm when activated, and if you turn on two neighboring ones at the same time, they will overheat. What is the maximum total shield strength possible?

# Given a series of N aegis cells where cell i, in order, has a shield strength of Si , determine the maximum total shield strength that can be generated.

# HINT: an interactive webpage that will step you through a similar problem can be found at: http://www.cse.msu.edu/~ofria/cse431/DP/

# Input Format

# The first line provides N, the number of aegis cells in the row.
# The second line has N values, separated by spaces, indicating the individual contributions to total shield strength (S0 through SN-1 ).
# Constraints

# 1 ≤ N ≤ 106
# 1 ≤ Si ≤ 1010
# Output Format

# A single value indicating the maximum total shield strength possible.

n = int(input())
cells = input().split()

best_score = [0] * n
for i, c in enumerate(cells):
    if (i == 0):
        best_score[i] = int(c)
    elif (i == 1):
        best_score[i] = max(int(cells[i]), int(cells[i-1]))
    else:
        if((int(c) + best_score[i-2]) > best_score[i-1]):
            best_score[i] = int(c) + best_score[i-2]
        else:
            best_score[i] = best_score[i-1]

print(best_score[-1])
