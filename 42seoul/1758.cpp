#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[100001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N, greater<int>());
	long long answer = 0;
	for (int i = 0; i < N; i++)
	{
		if (arr[i] - i > 0)
			answer += arr[i] - i;
	}
	cout << answer << '\n';
	return 0;
}