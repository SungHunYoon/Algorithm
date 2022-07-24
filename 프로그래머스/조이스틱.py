# 조이스틱으로 알파벳 이름을 완성하세요. 맨 처음엔 A로만 이루어져 있습니다.
# ex) 완성해야 하는 이름이 세 글자면 AAA, 네 글자면 AAAA
#
# 조이스틱을 각 방향으로 움직이면 아래와 같습니다.
#
# ▲ - 다음 알파벳
# ▼ - 이전 알파벳 (A에서 아래쪽으로 이동하면 Z로)
# ◀ - 커서를 왼쪽으로 이동 (첫 번째 위치에서 왼쪽으로 이동하면 마지막 문자에 커서)
# ▶ - 커서를 오른쪽으로 이동 (마지막 위치에서 오른쪽으로 이동하면 첫 번째 문자에 커서)
# 예를 들어 아래의 방법으로 "JAZ"를 만들 수 있습니다.
#
# - 첫 번째 위치에서 조이스틱을 위로 9번 조작하여 J를 완성합니다.
# - 조이스틱을 왼쪽으로 1번 조작하여 커서를 마지막 문자 위치로 이동시킵니다.
# - 마지막 위치에서 조이스틱을 아래로 1번 조작하여 Z를 완성합니다.
# 따라서 11번 이동시켜 "JAZ"를 만들 수 있고, 이때가 최소 이동입니다.
# 만들고자 하는 이름 name이 매개변수로 주어질 때, 이름에 대해 조이스틱 조작 횟수의 최솟값을 return 하도록 solution 함수를 만드세요.
#
# 제한 사항
# name은 알파벳 대문자로만 이루어져 있습니다.
# name의 길이는 1 이상 20 이하입니다.
# 입출력 예
# name	return
# "JEROEN"	56
# "JAN"	23
# 출처
#
# ※ 공지 - 2019년 2월 28일 테스트케이스가 추가되었습니다.
# ※ 공지 - 2022년 1월 14일 지문 수정 및 테스트케이스가 추가되었습니다. 이로 인해 이전에 통과하던 코드가 더 이상 통과하지 않을 수 있습니다.

# 그리디 알고리즘으로 구현했으나 이 문제의 경우에는 그리디 문제에 적합하지 않음
# 아래 문제의 경우 그리디로 풀면 11이고, 완전탐색한 경우 10임
# 이 문제에서는 완전 탐색으로 풀어야 정답을 풀 수 있음
name = "ABABAAAAABA"

check_name = list()

for i in name:
    check_name.append('A')

#print(check_name)

current_pos = 0

answer = 0

def dfs(target, name, check_name, current_pos):
    complete = True
    for i in range(len(name)):
        if not name[i] == check_name[i]:
            complete = False
            break

    if complete:
        return target

    pos = current_pos

    right = -1
    left = -1

    for i in range(len(name)):
        if name[i] != check_name[i]:
            check_right = i - pos if pos <= i else i + len(name) - pos
            check_left = len(name) - i + pos if pos < i else pos - i
            if right == -1 or check_right < right:
                right = check_right

            if left == -1 or check_left < left:
                left = check_left

    left_answer = target + left
    left_pos = pos - left
    left_name = check_name.copy()

    if left_pos < 0:
        left_pos += len(name)

    if ord('Z') - ord(name[left_pos]) > ord(name[left_pos]) - ord('A'):
        left_answer += ord(name[left_pos]) - ord('A')
        left_name[left_pos] = chr(ord('A') + ord(name[left_pos]) - ord('A'))
    else:
        left_answer += ord('Z') - ord(name[left_pos]) + 1
        # print(chr(ord('Z') - (ord('Z') - ord(name[pos]))))
        # print(check_name[pos])
        left_name[left_pos] = chr(ord('Z') - (ord('Z') - ord(name[left_pos])))

    #print(left_name)

    left_ret = dfs(left_answer, name, left_name, left_pos)

    right_answer = target + right
    right_pos = pos + right
    right_name = check_name.copy()

    if right_pos >= len(name):
        right_pos -= len(name)

    if ord('Z') - ord(name[right_pos]) > ord(name[right_pos]) - ord('A'):
        right_answer += ord(name[right_pos]) - ord('A')
        right_name[right_pos] = chr(ord('A') + ord(name[right_pos]) - ord('A'))
    else:
        right_answer += ord('Z') - ord(name[right_pos]) + 1
        # print(chr(ord('Z') - (ord('Z') - ord(name[pos]))))
        # print(check_name[pos])
        right_name[right_pos] = chr(ord('Z') - (ord('Z') - ord(name[right_pos])))

    #print(right_name)

    right_ret = dfs(right_answer, name, right_name, right_pos)

    if left_ret > right_ret:
        target = right_ret
    else:
        target = left_ret

    return target


# while True:
#     complete = True
#     for i in range(len(name)):
#         if not name[i] == check_name[i]:
#             complete = False
#             break
#
#     if complete:
#         break
#
#     pos = current_pos
#
#     right = -1
#     left = -1
#
#     for i in range(len(name)):
#         if name[i] != check_name[i]:
#             check_right = i - pos if pos <= i else i + len(name) - pos
#             check_left = len(name) - i + pos if pos < i else pos - i
#             if right == -1 or check_right < right:
#                 right = check_right
#
#             if left == -1 or check_left < left:
#                 left = check_left
#
#     if right > left:
#         answer += left
#         pos -= left
#     else:
#         answer += right
#         pos += right
#
#     if pos >= len(name):
#         pos -= len(name)
#     elif pos < 0:
#         pos += len(name)
#
#     if ord('Z') - ord(name[pos]) > ord(name[pos]) - ord('A'):
#         answer += ord(name[pos]) - ord('A')
#         check_name[pos] = chr(ord('A') + ord(name[pos]) - ord('A'))
#     else:
#         answer += ord('Z') - ord(name[pos]) + 1
#         #print(chr(ord('Z') - (ord('Z') - ord(name[pos]))))
#         #print(check_name[pos])
#         check_name[pos] = chr(ord('Z') - (ord('Z') - ord(name[pos])))
#     #print(answer)
#
#     current_pos = pos

print(dfs(answer, name, check_name, 0))
#print(check_name)

#for i in range(len(name)):
#    if 'Z' - name[i] >