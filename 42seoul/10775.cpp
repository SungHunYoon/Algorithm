#include <iostream>
#include <set>

using namespace std;

int G, P;
int gate[100001];
int arr[100001];
set<int> s;

int find(int index)
{
	if (index == gate[index])
		return index;
	gate[index] = find(gate[index]);
	return gate[index];
}

void make_union(int a, int b)
{
	a = find(a);
	b = find(b);

	if (a == b)
		return;
	if (a > b)
		gate[a] = b;
	else
		gate[b] = a;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> G >> P;
	for (int i = 1; i <= G; i++)
		gate[i] = i;
	for (int i = 0; i < P; i++)
		cin >> arr[i];
	for (int i = 0; i < P; i++)
	{
		if (find(gate[arr[i]]) == 0)
			break;
		s.insert(find(gate[arr[i]]));
		make_union(find(gate[arr[i]]), find(gate[arr[i]]) - 1);
	}
	cout << s.size() << '\n';
	return 0;
}
