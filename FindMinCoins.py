# Dynamic programming problem that finds the minimum number of coins needed to make the amount of cents passed in. Assumes that 
# a 1 cent coin is always provided in set of coins. Set of coins is on first line in the function

def min_coins_dp(cents):
    coins = [25, 10, 1]
    coins_dp = [0] * (cents + 1)
    coins_dp[1] = 1
    for i in range(2, cents+1):
        for coin in coins:
            if (coin == i):
                coins_dp[i] = 1
                break
            if not (i % coin):
                temp = i // coin
            if (coins_dp[i] != 0):
                coins_dp[i] = min(coins_dp[i],coins_dp[i-coin] + 1, temp)
            else:
                if (coin < i):
                    coins_dp[i] = coins_dp[i-coin] + 1
    return coins_dp[-1]
print(min_coins_dp(89))
