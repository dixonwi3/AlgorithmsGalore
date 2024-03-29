# Description
# Extinction is a complex card game involving betting. In the final phase of the game, each round players must bet the amount of money that the poorest player has remaining. When someone is out of money, they drop out of the game. Play continues until only one player remains.

# Dr. Xenovian plays in an Extinction tournament. Assuming she starts the final phase of the game with the most money and wins every round, can you track how many of her opponents will remain each round?

# Suppose Dr. Xenovian has six opponents with the following amounts of money left (in thousands of dollars):

# 5 4 4 2 2 8

# Then, in the first round, should would bet $2,000, which will bankrupt two of the players. For the next round, four opponents are left with the following amounts of money:

# 3 2 2 _ _ 6

# The above step is repeated until no opponents are left.

# Input Format

# The first line contains a single integer N indicating the number of opponents.

# The next line contains N integers: a0 , a1 , ..., aN-1  separated by spaces, where a represents the amount of money that the i th player has.

# Constraints

# 1 ≤ N ≤ 1000
# 1 ≤ ai ≤ 1000
# Output Format

# For each pass, print the number of opponents that remain.

players = int(input())
scores = input().split()
for i in range(0, len(scores)):
    scores[i] = int(scores[i])
#print(scores)
print(players)
while(players > 0):
    bet = 1000000000
    # find bet
    for score in scores:
        if score < bet and score > 0:
            bet = score

    for i in range(len(scores)):
        if (scores[i] > 0):
            scores[i] = scores[i] - bet
        if (scores[i] <= 0 and scores[i] != -99):
            scores[i] = -99
            players = players - 1
    if players != 0:
        print(players)
