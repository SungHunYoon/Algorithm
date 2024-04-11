#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
pair<int, int> arr[100001];
int trace[100001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i].first >> arr[i].second;
	sort(arr, arr + N);
	vector<int> answer;
	answer.push_back(arr[0].second);
	for (int i = 1; i < N; i++)
	{
		if (answer.back() < arr[i].second)
		{
			trace[i] = answer.size();
			answer.push_back(arr[i].second);
		}
		else
		{
			auto it = lower_bound(answer.begin(), answer.end(), arr[i].second);
			*it = arr[i].second;
			trace[i] = distance(answer.begin(), it);
		}
	}
	// for (int i = 0; i < answer.size(); i++)
	// 	cout << answer[i] << ' ';
	// cout << '\n';
	// for (int i = 0; i < N; i++)
	// 	cout << trace[i] << ' ';
	// cout << '\n';
	vector<int> p;
	int idx = answer.size() - 1;
	for (int i = N - 1; i >= 0; i--)
	{
		if (trace[i] == idx)
			idx--;
		else
			p.push_back(arr[i].first);
	}
	cout << p.size() << '\n';
	for (auto it = p.rbegin(); it != p.rend(); it++)
		cout << *it << '\n';
	return 0;
}