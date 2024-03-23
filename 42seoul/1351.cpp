#include <iostream>
#include <map>

using namespace std;

long long N, P, Q;
map<long long, long long> dp;

long long recursive(long long n)
{
	if (dp.find(n) != dp.end())
		return dp[n];
	dp[n] = recursive(n / P) + recursive(n / Q);
	return dp[n];
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> P >> Q;
	dp[0] = 1;
	recursive(N);
	// for (auto it = dp.begin(); it != dp.end(); it++)
	// 	cout << (*it).first << " " << (*it).second << '\n';
	cout << dp[N] << '\n'; 

	return 0;
}