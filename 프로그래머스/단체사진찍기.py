# 입력은 조건의 개수를 나타내는 정수 n과 n개의 원소로 구성된 문자열 배열 data로 주어진다. data의 원소는 각 프렌즈가 원하는 조건이 N~F=0과
# 같은 형태의 문자열로 구성되어 있다. 제한조건은 아래와 같다.

# 1 <= n <= 100
# data의 원소는 다섯 글자로 구성된 문자열이다. 각 원소의 조건은 다음과 같다.
# 첫 번째 글자와 세 번째 글자는 다음 8개 중 하나이다. {A, C, F, J, M, N, R, T}
# 각각 어피치, 콘, 프로도, 제이지, 무지, 네오, 라이언, 튜브를 의미한다. 첫 번째 글자는 조건을 제시한 프렌즈, 세 번째 글자는 상대방이다.
# 첫 번째 글자와 세 번째 글자는 항상 다르다.
# 두 번째 글자는 항상 ~이다.
# 네 번째 글자는 다음 3개 중 하나이다. {=, <, >} 각각 같음, 미만, 초과를 의미한다.
# 다섯 번째 글자는 0 이상 6 이하의 정수의 문자형이며, 조건에 제시되는 간격을 의미한다. 이때 간격은 두 프렌즈 사이에 있는 다른 프렌즈의 수이다.

# 2	["N~F=0", "R~T>2"]	3648
# 2	["M~C<2", "C~M>1"]	0

visit = list()
answer = 0
lookup = ['A', 'C', 'F', 'J', 'M', 'N', 'R', 'T']


def check(names, data):
    for i in data:
        pos1 = names.find(i[0])
        pos2 = names.find(i[2])
        op = i[3]
        num = int(i[4])

        cal = pos1 - pos2

        if op == '=':
            if not (abs(cal) == num + 1):
                return False

        elif op == '>':
            if not (abs(cal) > num + 1):
                return False

        elif op == '<':
            if not (abs(cal) < num + 1):
                return False

    return True


def dfs(names, data):
    global answer
    if len(names) == 8:
        if check(names, data) is True:
            answer += 1
        return

    for i in range(0, 8):
        if not visit[i] is True:
            visit[i] = True
            name = names + lookup[i]
            dfs(name, data)
            visit[i] = False


code = ["N~F=0", "R~T>2"]

visit.append(False)
visit.append(False)
visit.append(False)
visit.append(False)
visit.append(False)
visit.append(False)
visit.append(False)
visit.append(False)

dfs("", code)

print(answer)
