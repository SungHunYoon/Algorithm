#include <iostream>

using namespace std;

int N;
int arr[101];
int answer;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	for (int i = 0; i < N - 1; i++)
	{
		if (arr[i] >= arr[i + 1])
		{
			answer += arr[i] - arr[i + 1] + 1;
			arr[i] = arr[i + 1] - 1;
			for (int j = i; j > 0; j--)
			{
				if (arr[j] > arr[j - 1])
					break;
				answer += arr[j - 1] - arr[j] + 1;
				arr[j - 1] = arr[j] - 1;
			}
			//cout << answer << '\n';
		}
	}
	// for (int i = 0; i < N; i++)
	// 	cout << arr[i] << ' ';
	// cout << '\n';
	cout << answer << '\n';
	return 0;
}