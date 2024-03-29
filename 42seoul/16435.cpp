#include <iostream>
#include <algorithm>

using namespace std;

int N, L;
int arr[1001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> L;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);
	for (int i = 0; i < N; i++)
	{
		if (L < arr[i])
			break;
		L++;
	}
	cout << L << '\n';
	return 0;
}