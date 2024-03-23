#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, K;
bool visit[2][500001];
queue<pair<int, int>> q;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> K;
	int cnt = 0;
	q.push({N, K});
	visit[cnt][N] = true;
	while (!q.empty())
	{
		int len = q.size();
		for (int i = 0; i < len; i++)
		{
			auto p = q.front();
			q.pop();

			// cout << "t : " << p.first << " K : " << p.second << '\n';

			if (p.second > 500000)
			{
				cout << "-1\n";
				return 0;
			}
			else if (p.first == p.second || visit[cnt % 2][p.second])
			{
				cout << cnt << '\n';
				return 0;
			}

			int pos = p.first * 2;
			if (0 <= pos && pos <= 500001 && !visit[(cnt + 1) % 2][pos])
			{
				visit[(cnt + 1) % 2][pos] = true;
				q.push({pos, p.second + cnt + 1});
			}
			pos = p.first + 1;
			if (0 <= pos && pos <= 500001 && !visit[(cnt + 1) % 2][pos])
			{
				visit[(cnt + 1) % 2][pos] = true;
				q.push({pos, p.second + cnt + 1});
			}
			pos = p.first - 1;
			if (0 <= pos && pos <= 500001 && !visit[(cnt + 1) % 2][pos])
			{
				visit[(cnt + 1) % 2][pos] = true;
				q.push({pos, p.second + cnt + 1});
			}
		}
		cnt++;
	}
	return 0;
}