#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int T, N;
int dt[5] = {60, 10, -10, 1, -1};
bool visit[121];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		vector<int> arr(5, 0);
		queue<pair<int, vector<int>>> q;
		fill(visit, visit + 121, false);
		arr[0] = N / 60;
		vector<int> answer = arr;
		N %= 60;
		q.push({0, arr});
		while (!q.empty())
		{
			int len = q.size();
			bool flag = false;
			for (int k = 0; k < len; k++)
			{
				auto p = q.front(); q.pop();
				if (p.first == N)
				{
					answer = p.second;
					flag = true;
				}
				visit[p.first] = true;
				for (int j = 0; j < 5; j++)
				{
					int nt = p.first + dt[j];
					if (0 <= nt && nt <= N + 61 && !visit[nt])
					{
						p.second[j] += 1;
						q.push({nt, p.second});
						p.second[j] -= 1;
					}
				}
			}
			if (flag)
				break;
		}
		for (int j = 0; j < 5; j++)
			cout << answer[j] << ' ';
		cout << '\n';
	}
	return 0;
}