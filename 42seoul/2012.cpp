#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[500001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);
	long long answer = 0;
	for (int i = 0; i < N; i++)
		answer += abs(i + 1 - arr[i]);
	cout << answer << '\n';
	return 0;
}