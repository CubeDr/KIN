def fiboSum(n, a1=1, a2=0):
    if n == 1:
        return a1 + a2
    return fiboSum(n-1, a2+1, a1+a2)


n = int(input("합을 구할 개수: "))
print(fiboSum(n))
