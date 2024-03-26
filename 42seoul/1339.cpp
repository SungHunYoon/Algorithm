#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int N;
string str[10];
int alpha[26];
int alpha_cnt[26];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> str[i];
		for (int j = str[i].size() - 1; j >= 0; j--)
		{
			alpha_cnt[str[i][j] - 'A'] += pow(10, str[i].size() - 1 - j);
			//cout << str[i][j] - 'A' << '\n';
		}
	}
	// for (int i = 0; i < 26; i++)
	// 	cout << alpha_cnt[i] << ' ';
	// cout << '\n';
	sort(alpha_cnt, alpha_cnt + 26, greater<int>());
	int num = 9;
	int answer = 0;
	for (int i = 0; i < 10; i++)
		answer += alpha_cnt[i] * num--;
	cout << answer << '\n';
	return 0;
}