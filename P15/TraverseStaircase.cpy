#b797a07e-cf38-4d20-b8ef-60f3f21eeed0

def traverseStairs(height, maxSteps, dictionary):
    if height == 0:
        return 1
    
    if height in dictionary:
        return dictionary[height]
    
    total_ways = 0

    for step in range(1, min(maxSteps, height) + 1):
        total_ways += traverseStairs(height - step, maxSteps, dictionary)

    dictionary[height] = total_ways  # Store the result in the memo
    return total_ways

map = {}

height = int(input())
max = int(input())
traverseStairs(height, max, map)