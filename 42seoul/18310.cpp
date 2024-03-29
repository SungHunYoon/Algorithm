#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int N;
int arr[200001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);
	cout << (N % 2 == 0 ? arr[N / 2 - 1] : arr[N / 2]) << '\n';
	return 0;
}

// 1 5 10 100000
// 0 4 9 99999
// 4 0 5 99995 = 100004
// 9 5 0 99990 = 100004
// 99999 99995 99990 0