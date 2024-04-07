#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int N;
int arr[100001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	N *= 2;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);
	int answer = INT_MAX;
	for (int i = 0; i < N / 2; i++)
		answer = min(answer, arr[i] + arr[N - i - 1]);
	cout << answer << '\n';
	return 0;
}