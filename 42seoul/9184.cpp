#include <iostream>

using namespace std;

int A, B, C;
int dp[21][21][21];

int recursive(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;
	else if (a > 20 || b > 20 || c > 20)
	{
		if (dp[20][20][20] == 0)
			dp[20][20][20] = recursive(20, 20, 20);
		return dp[20][20][20];
	}
	else if (dp[a][b][c] != 0)
		return dp[a][b][c];

	if (a < b && b < c)
		dp[a][b][c] = recursive(a, b, c - 1) + recursive(a, b - 1, c - 1) - recursive(a, b - 1, c);
	else
		dp[a][b][c] = recursive(a - 1, b, c) + recursive(a - 1, b - 1, c) + recursive(a - 1, b, c - 1) - recursive(a - 1, b - 1, c - 1);
	return dp[a][b][c];
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (cin >> A >> B >> C)
	{
		if (A == -1 && B == -1 && C == -1)
			break;
		cout << "w(" << A << ", " << B << ", " << C << ") = " << recursive(A, B, C) << "\n";
	}

	return 0;
}