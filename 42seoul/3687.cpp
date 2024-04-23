#include <iostream>
#include <algorithm>

using namespace std;

int T, N;
pair<int, int> number[10] = { {8, 7}, {0, 6}, {6, 6}, {9, 6}, {2, 5}, {3, 5}, {5, 5}, {4, 4}, {7, 3}, {1, 2} };
string dp[101];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	dp[2] = "1"; dp[3] = "7"; dp[4] = "4"; dp[5] = "2"; dp[6] = "6"; dp[7] = "8";
	for (int i = 8; i <= 100; i++)
	{
		string s;
		for (int j = 0; j <= i; j++)
		{
			if (dp[i - j].empty() || dp[j].empty())
				continue;
			string t = dp[i - j] + dp[j];
			if (s.empty() || s.size() > t.size())
				s = t;
			else if (s.size() == t.size())
				s = min(s, t);
		}
		for (int j = 0; j < s.size(); j++)
		{
			if (j != 0 && s[j] == '6')
				s[j] = '0';
		}
		dp[i] = s;
	}
	for (int i = 0; i < T; i++)
	{
		string answer;
		int tmp;
		cin >> N;
		
		cout << dp[N] << ' ';
		tmp = N;
		answer.clear();
		while (tmp > 0)
		{
			for (int j = 9; j >= 0; j--)
			{
				if (tmp - number[j].second == 0 || tmp - number[j].second > 1)
				{
					if (number[j].first == 0 && tmp - number[j].second == 0)
						continue;
					tmp -= number[j].second;
					answer = to_string(number[j].first) + answer;
					break;
				}
			}
		}
		cout << answer << '\n';
	}
	return 0;
}
