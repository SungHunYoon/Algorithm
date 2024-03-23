#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string a;
string b;
int dp[4001][4001];
int answer;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> a >> b;
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < b.size(); j++)
		{
			if (a[i] == b[j])
			{
				dp[i + 1][j + 1] = dp[i][j] + 1;
				answer = max(answer, dp[i + 1][j + 1]);
			}
		}
	}
	cout << answer << '\n';
	return 0;
}

//   A B C D E
// A 1 0 0 0 0
// C 0 0 1 0 0
// D 0 0 0 2 0
// E 0 0 0 0 3
// B 0 1 0 0 0