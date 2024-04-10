#include <iostream>
#include <vector>

using namespace std;

int T, N;
int arr[45];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	arr[1] = 1;
	for (int i = 2; i < 45; i++)
		arr[i] = arr[i - 2] + arr[i - 1];
	cin >> T;
	while (T--)
	{
		cin >> N;
		vector<int> answer;
		for (int i = 44; i >= 1; i--)
		{
			if (N - arr[i] >= 0)
			{
				answer.push_back(arr[i]);
				N -= arr[i];
			}
		}
		for (auto it = answer.rbegin(); it != answer.rend(); it++)
			cout << *it << ' ';
		cout << '\n';
	}
	return 0;
}