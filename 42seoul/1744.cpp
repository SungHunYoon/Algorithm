#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[51];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	int minus = 0;
	int plus = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		if (arr[i] <= 0)
			minus++;
		else
			plus++;
	}
	sort(arr, arr + N);
	int answer = 0;
	int i;
	int cnt = minus / 2;
	for (i = 0; i < cnt; i++)
		answer += arr[i * 2] * arr[i * 2 + 1];
	if (minus % 2)
		answer += arr[i * 2];
	//cout << answer << '\n';
	cnt = plus / 2;
	for (i = 0; i < cnt; i++)
		answer += max(arr[(N - 1) - (i * 2)] * arr[(N - 1) - (i * 2) - 1], arr[(N - 1) - (i * 2)] + arr[(N - 1) - (i * 2) - 1]);
	if (plus % 2)
		answer += arr[(N - 1) - (i * 2)];
	cout << answer << '\n';
	return 0;
}