#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N;
priority_queue<int, vector<int>, greater<int> > q;
vector<pair<int, int> > arr(100001);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i].first >> arr[i].second;
	sort(arr.begin(), arr.begin() + N);
	q.push(arr[0].second);
	for (int i = 1; i < N; i++)
	{
		if (arr[i].first < q.top())
			q.push(arr[i].second);
		else
		{
			q.pop();
			q.push(arr[i].second);
		}
	}
	cout << q.size() << '\n';
	return 0;
}