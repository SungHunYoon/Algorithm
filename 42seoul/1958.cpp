#include <iostream>
#include <algorithm>

using namespace std;

string S[3];
int dp[101][101][101];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> S[0] >> S[1] >> S[2];
	for (int i = 0; i < S[0].size(); i++) {
		for (int j = 0; j < S[1].size(); j++) {
			for (int k = 0; k < S[2].size(); k++) {
				if (S[0][i] == S[1][j] && S[1][j] == S[2][k])
					dp[i + 1][j + 1][k + 1] = dp[i][j][k] + 1;
				else
					dp[i + 1][j + 1][k + 1] = max(dp[i][j + 1][k + 1], max(dp[i + 1][j][k + 1], dp[i + 1][j + 1][k]));
			}
		}
	}
	cout << dp[S[0].size()][S[1].size()][S[2].size()] << '\n';
	return 0;
}