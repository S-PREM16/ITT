from itertools import product
K, M = map(int, input().split())
lists = []
for _ in range(K):
    elements = map(int, input().split()[1:])
    lists.append([x**2 for x in elements])
max_val = 0
for combination in product(*lists):
    current_sum = sum(combination) % M
    if current_sum > max_val:
        max_val = current_sum

print(max_val)
