#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int arr[1000001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	vector<int> answer;
	answer.push_back(arr[0]);
	for (int i = 1; i < N; i++)
	{
		if (answer.back() < arr[i])
			answer.push_back(arr[i]);
		else
		{
			auto it = lower_bound(answer.begin(), answer.end(), arr[i]);
			*it = arr[i];
		}
	}
	cout << answer.size() << '\n';
	return 0;
}