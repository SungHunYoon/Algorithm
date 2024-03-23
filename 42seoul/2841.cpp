#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, P;
priority_queue<int> pq[7];
int answer;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> P;
	for (int i = 0; i < N; i++)
	{
		int first, second;
		cin >> first >> second;
		if (pq[first].empty())
		{
			pq[first].push(second);
			answer++;
		}
		else
		{
			bool flag = false;
			while (!pq[first].empty())
			{
				if (pq[first].top() < second)
				{
					pq[first].push(second);
					answer++;
					flag = true;
					break;
				}
				else if (pq[first].top() == second)
				{
					flag = true;
					break;
				}
				else
				{
					pq[first].pop();
					answer++;
				}
			}
			if (!flag)
			{
				pq[first].push(second);
				answer++;
			}
		}
	}
	cout << answer << '\n';
	return 0;
}