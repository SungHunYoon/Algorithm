#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int T, N;
pair<int, int> start;
pair<int, int> dest;
vector<pair<int, int> > arr[131073];
vector<bool> visit[131073];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		for (int j = 0; j < 131073; j++)
		{
			arr[j].clear();
			visit[j].clear();
		}
		cin >> N;
		cin >> start.first >> start.second;
		int standard = 65536 + start.first + start.second;
		int distance;
		for (int j = 0; j < N + 1; j++)
		{
			cin >> dest.first >> dest.second;
			distance = dest.first - start.first + dest.second - start.second;
			//cout << "standard : " << standard << " distance : " << distance << '\n';
			arr[standard + distance].push_back({dest.first, dest.second});
			visit[standard + distance].push_back(false);
		}
		queue<pair<pair<int, int>, int> > q;
		q.push({start, standard});
		bool flag = false;
		while (!q.empty())
		{
			auto p = q.front().first;
			int d = q.front().second;
			q.pop();

			if (p.first == dest.first && p.second == dest.second)
			{
				flag = true;
				break;
			}
			for (int j = -1000; j <= 1000; j++)
			{
				if (d + j >= 0 && d + j <= 131072)
				{
					for (int k = 0; k < arr[d + j].size(); k++)
					{
						int tmp = abs(arr[d + j][k].first - p.first) + abs(arr[d + j][k].second - p.second);
						if (tmp <= 1000 && !visit[d + j][k])
						{
							visit[d + j][k] = true;
							q.push({arr[d + j][k], d + j});
						}
					}
				}
			}

		}
		if (flag)
			cout << "happy\n";
		else
			cout << "sad\n";
	}

	return 0;
}