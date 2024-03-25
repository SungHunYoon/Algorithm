#include <iostream>
#include <string>

using namespace std;

string S;
string answer;

bool checkA(int idx)
{
	if (idx + 3 >= S.size())
		return false;
	for (int i = idx; i < idx + 4; i++)
		if (S[i] != 'X')
			return false;
	return true;
}

bool checkB(int idx)
{
	if (idx + 1 >= S.size())
		return false;
	for (int i = idx; i < idx + 2; i++)
		if (S[i] != 'X')
			return false;
	return true;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> S;
	answer = S;
	for (int i = 0; i < S.size(); i++)
	{
		if (answer[i] == '.' || answer[i] == 'A' || answer[i] == 'B')
			continue;
		if (checkA(i))
		{
			for (int j = i; j < i + 4; j++)
				answer[j] = 'A';
		}
		else if (checkB(i))
		{
			for (int j = i; j < i + 2; j++)
				answer[j] = 'B';
		}
		else
		{
			cout << "-1\n";
			return 0;
		}
	}
	cout << answer << '\n';
	return 0;
}