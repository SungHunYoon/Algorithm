#include <iostream>
#include <deque>

using namespace std;

int N;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		deque<char> answer;
		int cursor = 0;
		for (int j = 0; j < str.length(); j++)
		{
			if (str[j] == '<')
			{
				if (cursor > 0)
					cursor--;
			}
			else if (str[j] == '>')
			{
				if (cursor < answer.size())
					cursor++;
			}
			else if (str[j] == '-')
			{
				if (cursor > 0)
				{
					cursor--;
					answer.erase(answer.begin() + cursor);
				}
			}
			else
			{
				answer.insert(answer.begin() + cursor, str[j]);
				cursor++;
			}
		}
		for (int j = 0; j < answer.size(); j++)
			cout << answer[j];
		cout << '\n';
	}

	return 0;
}