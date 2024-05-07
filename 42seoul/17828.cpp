#include <iostream>
#include <string>

using namespace std;

int N, X;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> X;
	if (N > X || X / 26 > N)
	{
		cout << "!\n";
		return 0;
	}
	string answer;
	for (int i = 0; i < N; i++)
		answer.append(1, 'A');
	int idx = N - 1;
	while (X > 0 && idx >= 0)
	{
		for (int i = 26; i > 0; i--)
		{
			if (X - i - idx >= 0)
			{
				X -= i;
				answer[idx--] = 'A' + i - 1;
				break;
			}
		}
	} 
	if (X == 0 && idx == -1)
		cout << answer << '\n';
	else
		cout << "!\n";
	return 0;
}