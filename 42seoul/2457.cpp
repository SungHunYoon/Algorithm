#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N;
pair<int, int> arr[100001];
int S = 98;
int E = 382;

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

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int sM, sD, eM, eD;
		cin >> sM >> sD >> eM >> eD;
		arr[i].first = sM * 32 + sD;
		arr[i].second = eM * 32 + eD;
	}
	sort(arr, arr + N, cmp);
	priority_queue<pair<int, int>> pq;
	int maxIndex = -1;
	int maxValue = -1;
	for (int i = 0; i < N; i++)
	{
		if (arr[i].first < S)
		{
			if (pq.empty())
				pq.push(arr[i]);
			else if (pq.top().second < arr[i].second)
			{
				pq.pop();
				pq.push(arr[i]);
			}
		}
		else
		{
			if (pq.empty() || pq.top().second > E)
				break;
			else if (pq.top().second >= arr[i].first)
			{
				if (pq.top().second < arr[i].second && maxValue < arr[i].second)
				{
					maxValue = arr[i].second;
					maxIndex = i;
				}
			}
			else if (maxIndex != -1)
			{
				pq.push(arr[maxIndex]);
				maxIndex = -1;
				maxValue = -1;
				if (pq.top().second >= arr[i].first && pq.top().second < arr[i].second && maxValue < arr[i].second)
				{
					maxValue = arr[i].second;
					maxIndex = i;
				}
			}
		}
		//cout << pq.top().first << " " << pq.top().second << '\n';
	}
	if (!pq.empty() && pq.top().second <= E && maxIndex != -1)
		pq.push(arr[maxIndex]);
	if (pq.empty() || pq.top().second <= E)
		cout << "0\n";
	else
		cout << pq.size() << '\n';
	return 0;
}

// 2 15 3 23
// 2 28 4 25
// 4 12 6 5
// 5 2 5 31
// 6 3 6 15
// 6 15 9 3
// 6 15 9 27
// 7 14 9 1
// 9 14 12 24
// 10 5 12 31
