#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int F, S, G, U, D;
queue<int> q;
bool visit[1000001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> F >> S >> G >> U >> D;
	visit[S] = true;
	q.push(S);
	int answer = 0;
	bool flag = false;
	while (!q.empty())
	{
		int len = q.size();
		for (int i = 0; i < len; i++)
		{
			int t = q.front(); q.pop();
			if (t == G)
			{
				cout << answer << '\n';
				return 0;
			}
			if (t + U <= F && !visit[t + U])
			{
				visit[t + U] = true;
				q.push(t + U);
			}
			if (t - D >= 1 && !visit[t - D])
			{
				visit[t - D] = true;
				q.push(t - D);
			}
		}
		answer++;
	}
	cout << "use the stairs\n";
	return 0;
}