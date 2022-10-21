## Question : 1 
## Solution : [longest-common-prefix](./longest-common-prefix.py)

# The longest common prefix for N strings of length at most M each is defined as a string K
# Such that every string has K as a prefix.
# You are given the task of finding the longest common prefix for N such strings.

# Constraints:

# 1<=N<=10000

# 1<=M<=100

### Input Description:
# The first line contains a single integer N : the number of strings The next N line contains the N strings - one in each line All strings consists of only lowercase alphabets from ‘a’-’z’

### Output Description:
# Output a single line : the longest common prefix of the N strings . If no longest common prefix exists output “No common prefix exists”

### Sample Input :
# 4 
# abcdjkhkjh 
# ahhjk 
# abcdhjjj
# aa 

# Sample Output :
# a

## Solution 
import re

occurances = int(input())
main = []
flag = False
for i in range(occurances):
    main.append(str(input()))
dec = -1
ref = main[0]

# Searching for the longest common prefix in each word provided
while(len(ref) > 0):
    cc = 0
    for i in main:
        if re.match(ref, i): cc += 1
    if cc == occurances:
        print("The longest common prefix is : ")
        print(ref)
        flag = True
        break
    else:
        ref = ref[:-1]
if flag != True:
    print("No common prefix exists")
    