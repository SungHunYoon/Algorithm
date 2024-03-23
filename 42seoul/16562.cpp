#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int N, M, K;
int arr[10001];
int parent[10001];
map<int, int> m;

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

	if (arr[a] < arr[b])
		parent[b] = a;
	else
		parent[a] = b;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
		parent[i] = i;
	}
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		if (find(a) != find(b))
			make_union(a, b);
	}
	for (int i = 1; i <= N; i++)
	{
		parent[i] = find(parent[i]);
		//cout << parent[i] << '\n';
	}
	for (int i = 1; i <= N; i++)
	{
		if (m.find(parent[i]) == m.end())
			m.insert({parent[i], arr[parent[i]]});
		//cout << "parent : " << parent[i] << '\n';
	}
	int answer = 0;
	for (auto it = m.begin(); it != m.end(); it++)
	{
		//cout << (*it).first << " " << (*it).second << '\n';
		answer += (*it).second;
	}
	if (answer > K)
		cout << "Oh no\n";
	else
		cout << answer << '\n';
	return 0;
}