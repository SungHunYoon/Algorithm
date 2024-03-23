#include <iostream>
#include <map>

using namespace std;

long long N, P, Q, X, Y;
map<long long, long long> dp;

long long recursive(long long n)
{
	if (n <= 0)
		return 1;
	if (dp.find(n) != dp.end())
		return dp[n];

	dp[n] = recursive((n / P) - X) + recursive((n / Q) - Y);
	return dp[n];
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> P >> Q >> X >> Y;
	dp[0] = 1;
	cout << recursive(N) << '\n';
	return 0;
}