#include <iostream>
#include <algorithm>

using namespace std;

int arr[6];
bool plate[6][6];

bool isEmpty()
{
	for (int i = 0; i < 6; i++)
	{
		if (arr[i] != 0)
			return false;
	}
	return true;
}

bool checkPlate(int x, int y, int idx)
{
	if (y + idx >= 6 || x + idx >= 6)
		return false;
	for (int i = y; i <= y + idx; i++)
	{
		for (int j = x; j <= x + idx; j++)
		{
			if (plate[i][j] == true)
				return false;
		}
	}
	for (int i = y; i <= y + idx; i++)
		for (int j = x; j <= x + idx; j++)
			plate[i][j] = true;
	return true;
}

bool fillPlate(int idx)
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (checkPlate(j, i, idx))
				return true;
		}
	}
	return false;
}

void recursive(int idx)
{
	if (idx < 0)
		return;
	if (arr[idx] > 0 && fillPlate(idx))
	{
		arr[idx]--;
		recursive(idx);
	}
	else
		recursive(idx - 1);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0; i < 6; i++)
		cin >> arr[i];
	int answer = 0;
	while (!isEmpty())
	{
		for (int i = 0; i < 6; i++)
			for (int j = 0; j < 6; j++)
				plate[i][j] = false;
		recursive(5);
		answer++;
	}
	cout << answer << '\n';
	return 0;
}
