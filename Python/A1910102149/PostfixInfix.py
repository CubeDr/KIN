errors = [
    "유효하지 않은 연산자입니다.",      # 0
    "0으로 나눌 수 없습니다.",          # 1
    "올바르지 않은 식입니다."           # 2
]


def calc(op, n1, n2):
    if op == "+":
        return n1 + n2
    if op == "-":
        return n1 - n2
    if op == "*":
        return n1 * n2
    if op == "/":
        if n2 == 0:
            raise Exception(1)
        return n1 / n2
    raise Exception(0)


# 1. 후위표기법 수식 계산
def calc_postfix(statement):
    stack = []

    for e in statement:
        if e.isdigit():
            stack.append(e)
        else:
            if len(stack) < 2:
                raise Exception(2)

            a = float(stack.pop())
            b = float(stack.pop())
            new = calc(e, b, a)
            stack.append(new)

    if len(stack) != 1:
        raise Exception(2)

    return float(stack[0])


rank = {
    "(": 0,
    "+": 1,
    "-": 2,
    "*": 3,
    "/": 4
}


# 2. 중위표기 -> 후위표기
def infix_to_postfix(statement):
    stack = []
    result = ""

    for e in statement:
        if e.isdigit():
            result += e
        elif e == ")":
            while stack and stack[-1] != "(":
                result += stack.pop()
            if not stack:
                raise Exception(2)
            stack.pop()
        else:
            while stack and rank[stack[-1]] > rank[e]:
                result += stack.pop()
            stack.append(e)

    while stack:
        result += stack.pop()

    return result


if __name__ == '__main__':
    try:
        statement = input()
        postfix = infix_to_postfix(statement)
        print(postfix)
        result = calc_postfix(postfix)
        print(result)
    except Exception as e:
        print(errors[e.args[0]])
