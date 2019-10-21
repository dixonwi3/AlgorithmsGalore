# Description
# The ICKs (Indrassi Carnivorous Katydid) have gotten out of control and Millennium Jackson wants to wipe them all out. He realizes that the best way to do this is to get colonies wiped out as fast as possible. Given a series of jobs, how can he get each job done as quickly as possible?

# You will be provided with a list of job requests, with the time each request arrives and how long the job will take to complete. Every time Millennium finishes a job, he should start on the SHORTEST one that he knows about. The completion time of a job is measured from the time the request comes in to the time Millennium has completed the job. You must output the AVERAGE completion time (rounded down to the nearest integer) that Millennium took to complete all jobs.

# For example, assume three job requests come in at time 0, time 1, and time 2, and they will take Millennium 3, 9, and 6 hours respectively. Millennium will start on the first job at time zero, taking 3 hours to finish it. At time 3 he'll start on the third job (since it's the shortest one) and finish it at time 9 (3+6). Since this job came in at time 2, he would have taken 7 hours to complete it (9-2). Finally at time 9 he start on the second job, finishing it at time 18, for a total of 17 hours spent on it (18-1).

# Given that the completion times for the three jobs were 3 hours, 7 hours, and 17 hours, he would have spend an average of (3+7+17)/3 = 9 hours per job, which is what you would output.

# Input Format

# The first line provides the value N, the total number of job request coming in.
# The next N lines each have two values: the time the job arrives (Ti) and how long the job will take (Li)
# Note that the job list may be unsorted.

# Constraints

# 1 ≤ N ≤ 105
# 0 ≤ Ti ≤ 109
# 1 ≤ Li ≤ 109
# Output Format

# Display the integer part of the minimum average time that the job took.

import heapq
import sys

n = int(input())
jobs = []
current_time = 0
total_time = 0
minimum_t = sys.maxsize

for i in range(n):
    temp = input().split()
    t = int(temp[0])
    h = int(temp[1])
    if t < minimum_t:
        minimum_t = t
    jobs.append((h, t))

jobs.sort()
current_time = minimum_t

while jobs:
    found_job = False
    for job in jobs:
        if job[1] <= current_time:
            found_job = True
            current_job = job
            jobs.remove(job)
            break
    if found_job:
        current_time += job[0]
        total_time += current_time - job[1]
    else:
        current_time += 1
    
print(total_time // n)

