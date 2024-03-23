#include <iostream>
#include <queue>
#include <set>
#include <climits>

using namespace std;

int N;
vector<int> arr[51];
set<int> answer;
int answer_cnt;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	int a, b;
	while (cin >> a >> b)
	{
		if (a == -1 && b == -1)
			break;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	answer_cnt = INT_MAX;
	for (int i = 1; i <= N; i++)
	{
		queue<int> q;
		bool visit[51];
		fill(visit, visit + 51, false);
		visit[i] = true;
		for (int j = 0; j < arr[i].size(); j++)
		{
			q.push(arr[i][j]);
			visit[arr[i][j]] = true;
		}
		int cnt = 0;
		while (!q.empty())
		{
			int len = q.size();
			for (int j = 0; j < len; j++)
			{
				int t = q.front();
				q.pop();

				for (int k = 0; k < arr[t].size(); k++)
				{
					if (!visit[arr[t][k]])
					{
						visit[arr[t][k]] = true;
						q.push(arr[t][k]);
					}
				}
			}
			cnt++;
		}
		if (answer_cnt > cnt)
		{
			answer.clear();
			answer.insert(i);
			answer_cnt = cnt;
		}
		else if (answer_cnt == cnt)
			answer.insert(i);
		//cout << "test : " << answer_cnt << " " << cnt << '\n';
	}
	cout << answer_cnt << ' ' << answer.size() << '\n';
	for (auto it = answer.begin(); it != answer.end(); it++)
		cout << *it << ' ';
	cout << '\n';
	return 0;
}