#include <iostream>
#include <stack>
#include <string>

using namespace std;

string S;

int recursive(int *index, int mul)
{
	int ret = 0;

	for (; *index < S.size(); (*index)++)
	{
		if (S[*index] == '(')
		{
			(*index)++;
			ret += recursive(index, S[*index - 2] - '0');
			ret--;
		}
		else if (S[*index] == ')')
			break;
		else
			ret++;
	}
	ret *= mul;
	//cout << ret << '\n';
	return ret;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> S;
	int index = 0;
	cout << recursive(&index, 1) << '\n';
	return 0;
}