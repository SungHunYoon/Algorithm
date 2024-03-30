#include <iostream>
#include <algorithm>

using namespace std;

int N, M, J;
int arr[21];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> J;
	for (int i = 0; i < J; i++)
		cin >> arr[i];
	int idx = 1;
	int answer = 0;
	for (int i = 0; i < J; i++)
	{
		if (idx <= arr[i] && arr[i] <= idx + M - 1)
			continue;
		if (arr[i] > idx)
		{
			answer += arr[i] - M + 1 - idx;
			idx = arr[i] - M + 1;
		}
		else
		{
			answer += idx - arr[i];
			idx = arr[i];
		}
		// cout << answer << " " << idx << '\n';
	}
	cout << answer << '\n';
	return 0;
}