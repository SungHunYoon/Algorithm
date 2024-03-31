#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
int crain[51];
int box[10001];
bool visit[10001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> crain[i];
		pq.push({0, crain[i]});
	}
	cin >> M;
	for (int i = 0; i < M; i++)
		cin >> box[i];
	sort(box, box + M);
	int answer = 0;
	while (!pq.empty())
	{
		auto p = pq.top(); pq.pop();
		
		for (int i = M - 1; i >= 0; i--)
		{
			if (p.second >= box[i] && !visit[i])
			{
				pq.push({p.first + 1, p.second});
				visit[i] = true;
				answer = max(answer, p.first + 1);
				break;
			}
		}
	}
	for (int i = 0; i < M; i++)
	{
		if (!visit[i])
		{
			cout << "-1\n";
			return 0;
		}
	}
	cout << answer << '\n';
	return 0;
}