print('----menu----')
print('메뉴를 선택하세요')
print('1.아메리카노 2.루이보스티 3.카라멜마끼아또')
price = [4000, 5000, 6000]

money = 10000

while True:
    num = int(input())

    if num < 1 or num > 3:
        print('메뉴를 선택하세요')
        continue  # 아래 코드를 실행하지 않고 다시 반복

    # 1 base 를 0 base 로 변경
    num -= 1

    if money < price[num]:
        print('잔액이 부족합니다.')
        print('현재잔액 %d: ' % money)
    else:
        print('총주문금액 %d \n ' % price[num])
        print('카드잔액 %d' % (money-price[num]))
        money = money-price[num]
