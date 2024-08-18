#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
using id = pair<int, int>;

int N, C;
double M, P;
id A[5001];
int dp[10001];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> N >> M) {
        if (N == 0)
            break;
        for (int i = 1; i <= N; i++) {
            cin >> C >> P;
            A[i] = {C, P * 100 + 0.5};
        }
        int iM = M * 100 + 0.5;
        fill(dp + 1, dp + iM + 1, 0);
        for (int i = 1; i <= N; i++)
            for (int j = A[i].second; j <= iM; j++)
                dp[j] = max(dp[j], A[i].first + dp[j - A[i].second]);
        cout << dp[iM] << '\n';
    }

    return 0;
}