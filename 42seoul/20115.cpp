#include <iostream>
#include <algorithm>

using namespace std;

int N;
double arr[100001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0 ; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);
	for (int i = 0; i < N - 1; i++)
		arr[N - 1] += arr[i] / 2;
	cout << arr[N - 1] << '\n';
	return 0;
}