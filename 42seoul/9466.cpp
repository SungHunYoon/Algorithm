#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, N;
int A[100001];
bool visit[100001];

int dfs(vector<int> &v, int idx)
{
	int ret = 0;
	if (!visit[A[idx - 1]])
	{
		v.push_back(A[idx - 1]);
		visit[A[idx - 1]] = true;
		ret = dfs(v, A[idx - 1]);
	}
	else
	{
		auto f = find(v.begin(), v.end(), A[idx - 1]);
		ret = f - v.begin();
	}
	return ret;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	while (T--)
	{
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> A[i];
		fill(visit, visit + N + 1, false);
		int answer = 0;
		for (int i = 0; i < N; i++)
		{
			vector<int> v;
			if (visit[i + 1])
				continue;
			v.push_back(i + 1);
			visit[i + 1] = true;
			answer += dfs(v, i + 1);
		}
		cout << answer << '\n';
	}
	return 0;
}