#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
pair<int, int> arr[100001];

bool cmp(pair<int, int> &a, pair<int, int> &b)
{
	if (a.first == b.first)
		return a.second > b.second;
	return a.first < b.first;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> arr[i].second >> arr[i].first;
	sort(arr, arr + N, cmp);
	pair<int, int> tmp = {0, 0};
	int answer = 2147483647;
	bool flag = false;
	for (int i = 0; i < N; i++)
	{
		if (i != 0 && arr[i - 1].first == arr[i].first)
		{
			if (tmp.second < M)
				tmp.first += arr[i].first;
		}
		else
			tmp.first = arr[i].first;
		tmp.second += arr[i].second;
		if (tmp.second >= M)
		{
			answer = min(answer, tmp.first);
			flag = true;
		}
	}
	if (!flag)
		cout << "-1\n";
	else
		cout << answer << '\n';
	return 0;
}