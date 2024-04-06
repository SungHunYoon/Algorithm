#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N;
string arr1, arr2;

void putSwitch(string &tmp, int idx)
{
	if (idx - 1 >= 0)
		tmp[idx - 1] = tmp[idx - 1] == '0' ? '1' : '0';
	tmp[idx] = tmp[idx] == '0' ? '1' : '0';
	if (idx + 1 < N)
		tmp[idx + 1] = tmp[idx + 1] == '0' ? '1' : '0';
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> arr1 >> arr2;
	string tmp = arr1;
	int answer1 = 1;
	int answer2 = 0;
	putSwitch(tmp, 0);
	for (int i = 1; i < N; i++)
	{
		if (tmp[i - 1] != arr2[i - 1])
		{
			putSwitch(tmp, i);
			answer1++;
		}
		if (arr1[i - 1] != arr2[i - 1])
		{
			putSwitch(arr1, i);
			answer2++;
		}
	}

	if (arr1 == arr2 && tmp == arr2)
		cout << min(answer1, answer2) << '\n';
	else if (arr1 == arr2)
		cout << answer2 << '\n';
	else if (tmp == arr2)
		cout << answer1 << '\n';
	else
		cout << "-1\n";
	return 0;
}

// 1 1 1 0 0 0 0 0
// 1 1 0 1 1 0 0 0
