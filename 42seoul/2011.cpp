#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string str;
int dp[5001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> str;
	if (str[0] == '0')
	{
		cout << "0\n";
		return 0;
	}
	dp[1] = 1;

	// 20114 : 3, 1010 : 1, 111012 : 4
	// 1131212501112122 : 0
	cout << dp[str.size()] << '\n';
	return 0;
}