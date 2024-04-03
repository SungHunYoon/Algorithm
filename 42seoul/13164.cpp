#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int arr[300001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	for (int i = 0; i < N - 1; i++)
		arr[i] = arr[i + 1] - arr[i];
	sort(arr, arr + N - 1);
	long long answer = 0;
	for (int i = 0; i < N - 1 - (K - 1); i++)
		answer += arr[i];
	cout << answer << '\n';
	return 0;
}

// 5 3
// 1 3 5 6 10
//  2 2 1 4

// 5 2
// 1 2 3 4 10
//  1 1 1 6