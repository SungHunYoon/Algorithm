#include <iostream>

using namespace std;

int N;
int A[4];
int dp[61][61][61];
int T[6][3] = {
	{9, 3, 1},
	{9, 1, 3},
	{1, 9, 3},
	{3, 9, 1},
	{1, 3, 9},
	{3, 1, 9}
};

int recursive(int a, int b, int c) {
	if (a == 0 && b == 0 && c == 0)
		return 0;
	if (dp[a][b][c])
		return dp[a][b][c];
	int minValue = 1e9;
	for (int i = 0; i < 6; i++) {
		int nA = a - T[i][0] < 0 ? 0 : a - T[i][0];
		int nB = b - T[i][1] < 0 ? 0 : b - T[i][1];
		int nC = c - T[i][2] < 0 ? 0 : c - T[i][2];
		minValue = min(minValue, recursive(nA, nB, nC));
	}
	dp[a][b][c] = minValue + 1;
	return dp[a][b][c];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> A[i];
	cout << recursive(A[1], A[2], A[3]) << '\n';
	return 0;
}
