#include <iostream>
#include <algorithm>

using namespace std;

int N, A, B;
long long d[251];
long long dp[501][501];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A >> B;
        d[i] = A; d[i + 1] = B;
    }
    for (int i = 0; i <= N; i++)
        fill(dp[i], dp[i] + N + 1, 3e9);
    for (int i = 1; i <= N; i++)
        dp[i][i] = 0;
    for (int i = 1; i < N; i++)
        for (int j = 1; j < N - i + 1; j++)
            for (int k = j; k < i + j; k++)
                dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + (d[j- 1] * d[k] * d[i + j]));
    cout << dp[1][N] << '\n';
    return 0;
}