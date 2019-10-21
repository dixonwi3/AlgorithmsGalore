# Description
# A set of documents describe how to build a faster-than-light communications system. The only problem is that when a message is sent, its binary representation is encoded and must be decrypted on the other side. The binary string (B ) is of length N. This string is written down K times, shifted respectively by 0, 1, ..., K - 1 bits.

# For example, if B = 1001010 and K = 4 it would appear as:

# 1001010   
#  1001010  
#   1001010 
#   1001010
# Next, calculate XOR in every column and write it down. This number representing the encoded message is call S. For example, XOR-ing the numbers in the above example results in:

# 1110100110
# Both the encoded message (S ) and the value K are sent to the recipient.

# You must implement a decoding algorithm that will take S and K and reproduce the original bitstring B (in the above case, you would output '1001010').

# Input Format

# The first line contains two integers, N and K.
# The second line contains the received string S of length N + K - 1, consisting of ones and zeros.
# Constraints

# 1 ≤ N,K ≤ 106
# Output Format

# The decoded message of length N, consisting of ones and zeros.

n, k = input().split()
n = int(n)
k = int(k)
l = input()
solution = [0] * n
solution[0] = int(l[0])
p = 0
s = int(l[0])
for i in range(1, n):
    if (i < k):
        p += s
    else:
        p += int(s) - int(solution[i-k])
    s = (p + int(l[i]))%2
    solution[i] = s
print(*solution, sep="")


