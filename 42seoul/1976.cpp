#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int parent[201];
int arr[1001];

int find(int a)
{
	if (parent[a] == a)
		return a;
	parent[a] = find(parent[a]);
	return parent[a];
}

void make_union(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b)
		return;
	parent[b] = a;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		parent[i] = i;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int num;
			cin >> num;
			if (num == 1)
				make_union(i + 1, j + 1);
		}
	}
	for (int i = 0; i < M; i++)
		cin >> arr[i];

	int equal = find(parent[arr[0]]);
	for (int i = 1; i < M; i++)
	{
		if (equal != find(parent[arr[i]]))
		{
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	return 0;
}