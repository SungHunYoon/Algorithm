#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[1000001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);
	int answer = 0;
	for (int j = N - 1; j >= 2; j--)
	{
		if (arr[j - 2] + arr[j - 1] > arr[j])
		{
			answer = arr[j - 2] + arr[j - 1] + arr[j];
			break;
		}
	}
	cout << (answer == 0 ? -1 : answer) << '\n';
	return 0;
}