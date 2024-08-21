#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

int N, M;
int O[2];
int A[21];
bool visit[1001][21][21];
int d1[] = {1, -1, 0, 0};
int d2[] = {0, 0, 1, -1};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> O[0] >> O[1] >> M;
    for (int i = 0; i < M; i++)
        cin >> A[i];
    queue<tuple<int, int, int>> q;
    q.push({O[0], O[1], 0});
    visit[0][O[0]][O[1]] = true;
    int answer = 0;
    while (!q.empty()) {
        int len = q.size();
        for (int i = 0; i < len; i++) {
            auto [p1, p2, cnt] = q.front(); q.pop();
            while (p1 == A[cnt] || p2 == A[cnt]) {
                cnt++;
                if (cnt == M) {
                    cout << answer << '\n';
                    return 0;
                }
            }
            for (int j = 0; j < 4; j++) {
                int n1 = p1 + d1[j];
                int n2 = p2 + d2[j];
                if (1 > n1 || n1 > N || 1 > n2 || n2 > N) continue;
                if (visit[cnt][n1][n2]) continue;
                visit[cnt][n1][n2] = true;
                q.push({n1, n2, cnt});
            }
        }
        answer++;
    }
    return 0;
}