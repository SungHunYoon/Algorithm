#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[1001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);
	int sum = 1;
	for (int i = 0; i < N; i++)
	{
		//cout << sum << " " << arr[i] << '\n';
		if (sum < arr[i])
			break;
		sum += arr[i];
	}
	cout << sum << '\n';
	return 0;
}
