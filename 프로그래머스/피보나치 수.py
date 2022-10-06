# 피보나치 수는 F(0) = 0, F(1) = 1일 때, 1 이상의 n에 대하여 F(n) = F(n-1) + F(n-2) 가 적용되는 수 입니다.
#
# 예를들어
#
# F(2) = F(0) + F(1) = 0 + 1 = 1
# F(3) = F(1) + F(2) = 1 + 1 = 2
# F(4) = F(2) + F(3) = 1 + 2 = 3
# F(5) = F(3) + F(4) = 2 + 3 = 5
# 와 같이 이어집니다.
#
# 2 이상의 n이 입력되었을 때, n번째 피보나치 수를 1234567으로 나눈 나머지를 리턴하는 함수, solution을 완성해 주세요.
#
# 제한 사항
# n은 2 이상 100,000 이하인 자연수입니다.
# 입출력 예
# n	return
# 3	2
# 5	5
# 입출력 예 설명
# 피보나치수는 0번째부터 0, 1, 1, 2, 3, 5, ... 와 같이 이어집니다.
#
# 문제가 잘 안풀린다면😢
# 힌트가 필요한가요? [코딩테스트 연습 힌트 모음집]으로 오세요! → 클릭


b_list = list()


def fibonachi(n):
    if b_list[n] == -1:
        if n == 0:
            result = 0
        elif n == 1:
            result = 1
        else:
            result = fibonachi(n-1) + fibonachi(n-2)
        b_list[n] = result
    else:
        result = b_list[n]

    return result


def solution(n):
    answer = 0

    for i in range(n + 1):
        b_list.append(-1)

    for i in range(n + 1):
        answer = fibonachi(i)   

    return answer


print(solution(500) % 1234567)
