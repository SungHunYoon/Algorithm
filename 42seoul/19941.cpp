#include <iostream>

using namespace std;

int N, K;
char arr[20001];
bool eat[20001];

bool checkEat(int idx)
{
	for (int i = idx - K; i <= idx + K && i <= N; i++)
	{
		if (i < 1)
			continue;
		if (!eat[i])
		{
			eat[i] = true;
			return true;
		}
	}
	return false;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
		if (arr[i] == 'P')
			eat[i] = true;
	}
	int answer = 0;
	for (int i = 1; i <= N; i++)
	{
		if (arr[i] == 'P' && checkEat(i))
			answer++;
		//cout << answer << ' ';
	}
	//cout << '\n';
	cout << answer << '\n';
	return 0;
}