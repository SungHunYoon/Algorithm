#include <iostream>
#include <cstring>
#include <climits>
#include <algorithm>

using namespace std;

int N;
bool arr[21][21];
bool check[21][21];
int answer = INT_MAX;

void changeCol(int idx)
{
	for (int i = 0; i < N; i++)
		arr[i][idx] = !arr[i][idx];
}

void changeRow(int idx)
{
	for (int i = 0; i < N; i++)
		check[idx][i] = !check[idx][i];
}

bool checkRow(int idx)
{
	int cnt = 0;
	for (int i = 0; i < N; i++)
		if (check[idx][i])
			cnt++;
	if (cnt >= (N + 1) / 2)
		return true;
	return false;
}

int checkBack()
{
	memcpy(check, arr, sizeof(check));
	for (int i = 0; i < N; i++)
	{
		if (checkRow(i))
			changeRow(i);
	}

	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (check[i][j])
				cnt++;
		}
	}
	return cnt;
}

void recursive(int x, int y)
{
	if (x >= N)
	{
		answer = min(answer, checkBack());
		return;
	}
	recursive(x + 1, y);
	changeCol(x);
	recursive(x + 1, y);
	changeCol(x);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			char tmp;
			cin >> tmp;
			if (tmp == 'T')
				arr[i][j] = true;
		}
	}
	recursive(0, 0);
	cout << answer << '\n';
	return 0;
}
