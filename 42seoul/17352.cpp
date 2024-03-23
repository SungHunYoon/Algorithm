#include <iostream>
#include <set>

using namespace std;

int N;
int parent[300001];

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
	
	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++)
		parent[i] = i;
	for (int i = 0; i < N - 2; i++)
	{
		int a, b;
		cin >> a >> b;
		if (find(a) != find(b))
			make_union(a, b);
	}
	set<int> answer;
	for (int i = 1; i <= N; i++)
	{
		parent[i] = find(i);
		answer.insert(parent[i]);
	}
	for (auto it = answer.begin(); it != answer.end(); it++)
		cout << *it << ' ';
	cout << '\n';
	 
	return 0;
}