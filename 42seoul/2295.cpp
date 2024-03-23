#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int arr[1001];
vector<int> sum;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	for (int i = 0; i < N - 1; i++)
		for (int j = i; j < N; j++)
			sum.push_back(arr[i] + arr[j]);
	sort(arr, arr + N);
	sort(sum.begin(), sum.end());

	for (int i = N - 1; i >= 1; i--)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			int tmp = arr[i] - arr[j];
			if (binary_search(sum.begin(), sum.end(), tmp))
			{
				cout << arr[i] << '\n';
				return 0;
			}
		}
	}
	return 0;
}
