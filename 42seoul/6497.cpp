#include <iostream>
#include <algorithm>

using namespace std;

int M, N;
pair<int, pair<int, int>> A[200001];
int parent[200001];

int find(int idx)
{
	if (idx == parent[idx])
		return idx;
	parent[idx] = find(parent[idx]);
	return parent[idx];
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

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (cin >> M >> N)
	{
		if (M == 0 && N == 0)
			break;
		for (int i = 0; i < M; i++)
			parent[i] = i;
		int sum = 0;
		for (int i = 0; i < N; i++)
		{
			cin >> A[i].second.first >> A[i].second.second >> A[i].first;
			sum += A[i].first;
		}
		sort(A, A + N);
		int answer = 0;
		int cnt = 0;
		for (int i = 0; i < N; i++)
		{
			if (find(A[i].second.first) != find(A[i].second.second))
			{
				make_union(A[i].second.first, A[i].second.second);
				cnt++;
				answer += A[i].first;
				if (cnt == N - 1)
					break;
			}
		}
		cout << sum - answer << '\n';
	}

	return 0;
}
