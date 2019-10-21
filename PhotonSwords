# Description
# The individual engineers at Oganesson Dynamics are most excited about the photon swords that they've discovered. Now they want to see just how hot they can make those swords without melting the handles.

# Each sword has N buttons, each of which increases the heat by a fixed (integer) amount, to a limit of K (also an integer), beyond which the handle will melt. Given the amount of heat each button produces (B0 through BN-1), determine the maximum heat possible for the sword.

# For example, if there were two buttons that put out 9 and 12 units of heat respectively, and the sword could handle a maximum of 31 units, you would be able to produce a maximum of 30 units by pressing the first button twice and the second button once. Any more presses and the device would melt. If there were also a button for 1 unit, you would be able to maximize the heat to a perfect 31.

# Input Format

# The first line contains T, the number of test cases.
# Each test comprises two lines:
# The first line contains two integers, N and K, representing the number of buttons and maximum heat, respectively.
# The second line consists of space separated integers, B0 through BN-1, representing the heat output of each button.
# Constraints

# 1 ≤ T ≤ 10
# 1 ≤ N, K ≤ 2000
# 1 ≤ Bi ≤ 2000
# Output Format

# Output T lines, the maximum heat that can be produced for each test case which is as near as possible including, but not exceeding, the heat limit ( K ).

imm = False
test_cases = int(input())
for test in range(test_cases):
    num_but, mheat = map(int, input().split())
    buttons = list(map(int, input().split()))
    buttons.sort()
    ans = 0
    imm = False
    pb = []
    for b in buttons:
        if not (mheat % b):
            print(mheat)
            imm = True
            break
        if b > mheat:
            continue
        pb.append(b)
    if imm:
        imm = False
        continue
    check = [0] * (mheat + 1)
    check[0] = 1
    for i in range(1, mheat + 1):
        for p in pb:
            if (i - p) >= 0 and check[i-p] == 1:
                check[i] = 1
                break
    for k in reversed(range(mheat+1)):
        if(check[k] == 1):
            print(k)
            break
        
