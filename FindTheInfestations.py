# Description
# Millenium Jackson has a flood of infestation reports coming in, and he needs to decide which ones to deal with first. Can you examine the size of each report and let him know which infestations are the largest?

# Input Format

# The first line has two values N and K. N is the number of reports coming in, and K is the number that Millenium can deal with this month.

# The next N lines indicate the size of each infestation.

# Constraints

# 1 ≤ N ≤ 107
# 1 ≤ K ≤ 1000
# 1 ≤ infestation size ≤ 109
# Output Format

#  K values, indicating the K largest infestations in order (each on a new line).

N, K = input().split()
orders = []
for i in range(int(N)):
    orders.append(int(input()))
orders.sort(reverse = True)
for i in range(int(K)):
    print(orders[i])
