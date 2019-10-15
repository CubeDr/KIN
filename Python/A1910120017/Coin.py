K = int(input())
C = int(input())

for c in range(C):
    m, n = map(int, input().split())
    if (m <= n and n > m+(K-m+1)/2) or (m > n and m > n + (K-n)/2 + 1):
        print(0)
    else:
        print(1)
