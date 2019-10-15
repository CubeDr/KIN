n = int(input("몇명? "))

# 입찰 가격과 우선순위를 저장하는 리스트
tries = []

for i in range(n):
    price = int(input(str(i + 1) + "번째 입찰: "))
    # (입찰가, 우선순위) 튜플을 저장
    tries.append((price, n - i))

# 내림차순으로 정렬하여 1. 입찰가 2. 우선순위 순으로 정렬
tries.sort(reverse=True)
# 가장 앞에 있는 사람이 입찰 성공
win = tries[0]

print(str(n-win[1]+1) + "번째 입찰자가 " + str(win[0]) + "원으로 입찰 성공")
