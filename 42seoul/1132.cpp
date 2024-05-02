#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
using LL = long long;

int N;
pair<LL, int> arr[10];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		arr[str[0] - 'A'].second++;
		LL digit = 1;
		for (int j = str.size() - 1; j >= 0; j--)
		{
			arr[str[j] - 'A'].first += digit;
			digit *= 10;
		}
	}
	sort(arr, arr + 10);
	for (int i = 1; i < 10; i++)
	{
		if (arr[0].second != 0 && arr[i].second == 0)
		{
			arr[i].first = 0;
			break;
		}
	}
	sort(arr, arr + 10);
	// for (int i = 0; i < 10; i++)
	// 	cout << arr[i].first << " " << arr[i].second << '\n';
	LL answer = 0;
	for (int i = 9; i >= 0; i--)
		answer += arr[i].first * i;
	cout << answer << '\n';
	return 0;
}
