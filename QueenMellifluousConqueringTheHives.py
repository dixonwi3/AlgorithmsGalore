# Description
# Queen Mellifluous has found a neighboring planet with a series of hives around its equator. You must help her determine which hive to initiate the invasion from such that she will be able to sweep around the planet and have enough warriors to win each battle.

# She knows how many warriors she will gain for winning each hive and how many warriors she will need to then expend to claim the next hive. She can conquor the first hive from orbit (without expending warriors)-- can you identify which hive she must begin the invasion with in order to have enough troops to defeat each of the others as she reaches them?

# Input Format

# The first line will contain the number of hives on the planet(N).
# The next N lines will each contain a pair of integers, indicating the number of warriors that the queen will gain if she wins (or chooses as her starting point) that hive and how many warriors she needs to defeat next hive.

# Constraints

# 1 ≤ N ≤ 105
# 1 ≤ warriors gained, warriors needed ≤ 109
# We guarantee that there is a solution.
# Output Format

#  A single value indicating the lowest position of a hive where she can start her attacks.

n = int(input())
first = 0
warriors = 0
for i in range(n):
    temp = input().split()
    gain, lose = int(temp[0]), int(temp[1])
    if (gain + warriors) - lose >= 0:
        warriors = gain + warriors - lose
    else:
        first = i + 1
        warriors = 0
print(first)
