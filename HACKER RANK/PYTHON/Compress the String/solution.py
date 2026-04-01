from itertools import groupby
s = input()
res = []
for k, g in groupby(s):
    res.append((len(list(g)), int(k)))

print(*(res))
