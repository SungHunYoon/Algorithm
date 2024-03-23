#include <iostream>

using namespace std;

int parent[1000001];
int T, N, K, M;

int find(int index)
{
	if (parent[index] == index)
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
		parent[b] = a;
	else
		parent[a] = b;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		for (int j = 1; j <= N; j++)
			parent[j] = j;
		cin >> K;
		int a, b;
		for (int j = 0; j < K; j++)
		{
			cin >> a >> b;
			make_union(a, b);
		}
		cin >> M;
		cout << "Scenario " << i + 1 << ":\n";
		for (int j = 0; j < M; j++)
		{
			cin >> a >> b;
			if (find(a) == find(b))
				cout << "1\n";
			else
				cout << "0\n";
		}
		cout << '\n';
	}

	return 0;
}