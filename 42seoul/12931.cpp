#include <iostream>

using namespace std;

int N;
int B[51];

bool checkAllZero()
{
	for (int i = 0; i < N; i++)
	{
		if (B[i] != 0)
			return false;
	}
	return true;
}

int Odd()
{
	int ret = 0;
	for (int i = 0; i < N; i++)
	{
		if (B[i] % 2 == 1)
		{
			B[i]--;
			ret++;
		}
	}
	return ret;
}

void divide()
{
	for (int i = 0; i < N; i++)
		B[i] /= 2;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> B[i];
	int answer = 0;
	while (!checkAllZero())
	{
		answer += Odd();
		if (checkAllZero())
			break;
		divide();
		answer++;
	}
	cout << answer << '\n';
	return 0;
}