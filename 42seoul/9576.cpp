#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

int T, N, M;
int parent[1001];
pair<int, int> arr[1001];

int find(int index)
{
	if (index == parent[index])
		return index;
	parent[index] = find(parent[index]);
	return parent[index];
}

void make_union(int a, int b)
{
	a = find(a);
	b = find(b);

	if (a == b)
		return;
	if (a > b)
		parent[a] = b;
	else
		parent[b] = a;
}

bool cmp(pair<int, int> &a, pair<int, int> &b)
{
	if (a.first == b.first)
		return a.second > b.second;
	return a.first > b.first;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N >> M;
		for (int j = 1; j <= N; j++)
			parent[j] = j;
		for (int j = 0; j < M; j++)
			cin >> arr[j].first >> arr[j].second;
		sort(arr, arr + M, cmp);
		int answer = 0;
		for (int j = 0; j < M; j++)
		{
			//cout << find(parent[arr[j].second]) << '\n';
			if (find(parent[arr[j].second]) < arr[j].first)
				continue;
			make_union(find(parent[arr[j].second]), find(parent[arr[j].second]) - 1);
			answer++;
		}
		cout << answer << '\n';
	}
	return 0;
}