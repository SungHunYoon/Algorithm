#include <iostream>
#include <algorithm>

using namespace std;

int N;
pair<int, int> arr[1001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i].second >> arr[i].first;
	sort(arr, arr + N);
	int hour = 0;
	int answer = 1e9;
	for (int i = 0; i < N; i++)
	{
		hour += arr[i].second;
		answer = min(answer, arr[i].first - hour);
	}
	if (answer <= 0)
		cout << "-1\n";
	else
		cout << answer << '\n';
	return 0;
}
