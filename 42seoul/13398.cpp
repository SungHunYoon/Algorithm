#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int N;
int A[100001];
int dp[3][100001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	dp[0][0] = dp[1][0] = A[0];
	dp[2][0] = *min_element(A, A + N);
	for (int i = 1; i < N; i++) {
		dp[0][i] = A[i];
		dp[1][i] = max(dp[0][i - 1], dp[1][i - 1]) + A[i];
		dp[2][i] = max(dp[0][i - 1], max(dp[1][i - 1], dp[2][i - 1] + A[i]));
	}
	int answer = INT_MIN;
	for (int i = 0; i < N; i++) {
		int tmp = max(dp[0][i], max(dp[1][i], dp[2][i]));
		answer = max(answer, tmp);
	}
	cout << answer << '\n';
	return 0;
}