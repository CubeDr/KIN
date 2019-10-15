n = int(input('몇 명인지 입력하시오 : '))

total = {}

for x in range(0, n):
    namex = input("이름을 입력하시오 : ")
    scorex = input("평점을 입력하시오 : ")

    # 이미 해당 성적이 있으면
    if scorex in total.keys():
        # 다른 학생일 경우에만 추가
        if namex not in total[scorex]:
            # 이미 있는 리스트에 입력받은 이름을 더해줌
            total[scorex].append(namex)
    # 해당 성적이 없으면 무조건 추가
    else:
        # 이름의 리스트로 초기화
        total[scorex] = [namex]

# 성적 역순 정렬
grades = list(reversed(sorted(total.keys())))

want = int(input("몇 등이 궁금한지 입력하시오 : "))

# 원하는 등수의 사람들 모두 출력
for name in total[grades[want-1]]:
    print(name)
