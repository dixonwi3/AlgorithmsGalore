/*
Description
Dr. Xenovian has developed a fantastic new computer game, but it requires a new type of multi-core computer that she designed. The cores in this computer must come in multiples of 12 AND they must be arranged on the motherboard in a perfect square.

Atfter talking to each customer, Dr. Xenovian determines the minimum number of cores they need ( x ) and the maximum number of cores they can afford ( y ). Given this range in the number of cores possible, she then needs to calculate how many of these values are divisible by 12 (d ), how many are perfect squares ( s ), and how many values have both qualities ( b ).

Write a program to perform these calculations.

Input Format

The first line contains C, the number of customers she needs to perform calculations for. C ranges then follow, each on a new line.

Each test contains two space-separated integers denoting the MIN( x ) and the MAX( y ) number of cores, inclusive.

Constraints

1 ≤ C ≤ 100
1 ≤ x ≤ y ≤ 109
Output Format

With each customer result on a new line, print out d, s, and b (where d is the number of values divisible by 12, s is the number of perfect squares, and b is the number of values that meet both criteria).
*/
import math
def countDivisibles(minimum, maximum, M): 
    if (minimum % M == 0): 
        return (int(maximum / M) - int(minimum / M)) + 1
    return (int(maximum / M) - int(minimum / M))

test_cases = int(input())
for _ in range(test_cases):
    both = 0
    inp = input().split()
    mini = int(inp[0])
    maxi = int(inp[1])
    squares = math.floor(math.sqrt(maxi)) - math.ceil(math.sqrt(mini)) + 1
    mults = countDivisibles(mini, maxi, 12)
    if (mini == maxi and squares == 1 and mults == 1):
        print("1 1 1")
        continue
    # loop from bottom perfect square to top perfect square
    # check if the perf squares are divisible by 12.
    for i in range(math.ceil(math.sqrt(mini)), math.floor(math.sqrt(maxi)) + 1):
        if i**2 % 12 == 0:
            both += 1
    print(str(mults) + " " + str(squares) + " " + str(both))
        
