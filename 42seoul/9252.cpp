#include <iostream>
#include <string>
#include <stack>
#include <cstring>
#include <algorithm>

using namespace std;

string a;
string b;

int dp[1001][1001];
pair<int, int> trace[1001][1001];
int maxValue;
pair<int, int> maxIndex;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> a >> b;
	memset(trace, -1, sizeof(trace));
	maxIndex = {-1, -1};
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < b.size(); j++)
		{
			if (a[i] == b[j])
			{
				dp[i + 1][j + 1] = dp[i][j] + 1;
				trace[i + 1][j + 1] = {i, j};
				if (maxValue < dp[i + 1][j + 1])
				{
					maxValue = dp[i + 1][j + 1];
					maxIndex = trace[i + 1][j + 1];
				}
			}
			else
			{
				if (dp[i][j + 1] > dp[i + 1][j])
				{
					dp[i + 1][j + 1] = dp[i][j + 1];
					trace[i + 1][j + 1] = trace[i][j + 1];
				}
				else
				{
					dp[i + 1][j + 1] = dp[i + 1][j];
					trace[i + 1][j + 1] = trace[i + 1][j];
				}
			}
		}
	}
	// for (int i = 1; i <= a.size(); i++)
	// {
	// 	for (int j = 1; j <= b.size(); j++)
	// 		cout << dp[i][j] << ' ';
	// 	cout << '\n';
	// 	for (int j = 1; j <= b.size(); j++)
	// 		cout << "{" << trace[i][j].first << ',' << trace[i][j].second << "} ";
	// 	cout << '\n';
	// }
	stack<char> stk;
	while (maxIndex.first != -1 && maxIndex.second != -1)
	{
		stk.push(a[maxIndex.first]);
		maxIndex = trace[maxIndex.first][maxIndex.second];
	}
	cout << stk.size() << '\n';
	while (!stk.empty())
	{
		cout << stk.top();
		stk.pop();
	}
	cout << '\n';
	return 0;
}

//   A C A Y K P
// C 0 1 1 1 1 1
// A 1 1 2 2 2 2
// P 1 1 2 2 2 3
// C 1 2 2 2 2 3
// A 1 2 3 3 3 3
// K 1 2 3 3 4 4
