# 가로 길이가 2이고 세로의 길이가 1인 직사각형모양의 타일이 있습니다.
# 이 직사각형 타일을 이용하여 세로의 길이가 2이고 가로의 길이가 n인 바닥을 가득 채우려고 합니다.
# 타일을 채울 때는 다음과 같이 2가지 방법이 있습니다.
#
# 타일을 가로로 배치 하는 경우
# 타일을 세로로 배치 하는 경우
# 예를들어서 n이 7인 직사각형은 다음과 같이 채울 수 있습니다.
#
# Imgur
#
# 직사각형의 가로의 길이 n이 매개변수로 주어질 때, 이 직사각형을 채우는 방법의 수를 return 하는 solution 함수를 완성해주세요.
#
# 제한사항
# 가로의 길이 n은 60,000이하의 자연수 입니다.
# 경우의 수가 많아 질 수 있으므로, 경우의 수를 1,000,000,007으로 나눈 나머지를 return해주세요.
# 입출력 예
# n	result
# 4	5
# 입출력 예 설명
# 입출력 예 #1
# 다음과 같이 5가지 방법이 있다.
#
# Imgur
#
# Imgur
#
# Imgur
#
# Imgur
#
# Imgur

# 처음엔 완전탐색으로 접근, DFS로 구현했으나 시간초과
# 구글링하니, Dynamic Programming 으로 접근하여 점화식을 세워 품..
# 더 연습이 필요

n = 60000

dp = list()

for i in range(n):
    dp.append(0)

dp[0] = 1
dp[1] = 2

for i in range(2, n):
    dp[i] = (dp[i-2] + dp[i-1]) % 1000000007

print(dp[n-1])

# visited = list()
#
# for i in range(2):
#     tmp = list()
#     for j in range(n):
#         tmp.append(False)
#     visited.append(tmp)
# #print(visited)
#
#
# def dfs(result, visited):
#
#     for i in visited:
#         print(i)
#     print('-------------')
#
#     flag = True
#     for i in range(len(visited)):
#         for j in range(len(visited[0])):
#             if not visited[i][j]:
#                 flag = False
#                 break
#         if not flag:
#             break
#
#     if flag:
#         result += 1
#         return result
#
#     if 0 < i + 1 < len(visited) and not visited[i][j] and not visited[i+1][j]:
#         visited[i][j] = True
#         visited[i+1][j] = True
#         result = dfs(result, visited)
#
#         visited[i][j] = False
#         visited[i+1][j] = False
#     if 0 < j + 1 < len(visited[0]) and not visited[i][j] and not visited[i][j+1]:
#         visited[i][j] = True
#         visited[i][j+1] = True
#         result = dfs(result, visited)
#         visited[i][j] = False
#         visited[i][j+1] = False
#
#     return result
#
#
# print(dfs(0, visited))
