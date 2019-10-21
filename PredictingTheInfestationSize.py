# Description
# The Indrassi Carnivorous Katydid (ICK for short) is an insect species whose colonies grow by one member an hour until they meet their growth goal; then everyone but the queen flies away, the colony size reduces to one, and they start over. In the first round the colony grows to size K. In the next round they will keep growing to 2K. Then 4K, then 8K, and so on, doubling their goal each time.

# Specifically, if we track a colony hour-by-hour where k=3, we would see colony sizes of:

# Hour 1: 1
# Hour 2: 2
# Hour 3: 3 (Goal met, two fly away!)
# Hour 4: 1
# Hour 5: 2
# Hour 6: 3
# Hour 7: 4
# Hour 8: 5
# Hour 9: 6 (Goal met, five fly away!)
# Hour 10: 1
# Hour 11: 2
# ...

# The next goal will be met at hour 21 with 12 individuals; then at hour 22, the colony will be back to only 1.

# Given that Millenium will arrive at hour H, can you warn him what colony size he will be facing?

# Input Format

# Two values, K (the starting growth goal) and H (the time, in hours, until Millinium will arrive at the planet).

# Constraints

# K ≤ 1000
# H ≤ 1012
# Output Format

# A single value indicating the colony size at hour H.

max_size, hours = input().split()
max_size = int(max_size)
hours = int(hours)
resets = 0
size = 0
while(size < hours):
    size += (max_size * 2**resets)
    resets += 1
count = hours
for i in range(resets - 1):
    count -= (max_size * 2**i)
print(count)
