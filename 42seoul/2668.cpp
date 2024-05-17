#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> arr[101];
vector<int> answer;

void dfs(vector<int> &v, int dest)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == dest)
		{
			answer.push_back(dest);
			return;
		}
		else
			dfs(arr[v[i]], dest);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int num; cin >> num;
		arr[num].push_back(i);
	}
	for (int i = 1; i <= N; i++)
		dfs(arr[i], i);
	cout << answer.size() << '\n';
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << '\n';
	return 0;
}
