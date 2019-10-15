a = [12, 14, 22, 15, 25]
b = [42, 21, 25, 54, 21]

s = [max(a[x], b[x]) for x in range(len(a))]

print(s)
