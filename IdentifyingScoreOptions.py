# Description
# Dr. Xenovian is playing a game where there are two possible moves each turn, one that earns a player x points and the other earns the player y points. The winner is the player closest to a given target score after n moves.

# Given x, y, and n, can you calculate the set of all possible scores at the end of the game?

# Input Format

# The first line contains an integer T indicating the number of test cases.

# The next T lines each describe a test case with three integers: x, y, and n.

# Constraints

# 1 ≤ T ≤ 10
# 1 ≤ x, y, n ≤ 1000
# Output Format

# Space-separated list of numbers which are the possible total scores in increasing order.
test_cases = int(input())
x_scores = []
y_scores = []
soln = []
for i in range(test_cases):
    x_scores.clear()
    y_scores.clear()
    soln.clear()
    xyn_input = input().split()
    xy_arr = [int(xyn_input[0]), int(xyn_input[1])]
    moves = int(xyn_input[2])
    for j in reversed(range(moves+1)):
        x_scores.append(xy_arr[0] * j)
    for k in range(moves+1):
        y_scores.append(xy_arr[1] * k)
    for h in range(moves+1):
        soln.append(x_scores[h] + y_scores[h])
    
    soln = list(dict.fromkeys(soln))
    soln.sort()
    print(*soln, sep=" ")
