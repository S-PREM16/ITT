# Read English subscription data
n = int(input())
english_set = set(map(int, input().split()))

# Read French subscription data
m = int(input())
french_set = set(map(int, input().split()))

# Calculate the union of both sets
# The | operator or .union() removes duplicates automatically
total_students = english_set.union(french_set)

# Print the number of unique students
print(len(total_students))
