#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int N, X, Y, D, G;
int A[101][101];

void dfs(int g, deque<pair<int, int>> &dq)
{
	if (g < 0)
		return;
	deque<pair<int, int>> t = dq;
	int prevX = t[0].second, prevY = t[0].first;
	int diffX = 0, diffY = 0;
	for (int i = 1; i < t.size(); i++)
	{
		diffY = abs(prevY- t[i].first);
		diffX = abs(prevX - t[i].second);
		
		if (prevY < t[i].first)
			diffY *= -1;
		if (prevX > t[i].second)
			diffX *= -1;

		prevX = t[i].second;
		prevY = t[i].first;

		int x = dq[0].second + diffY;
		int y = dq[0].first + diffX;

		dq.push_front({y, x});
		A[y][x] = 1;
	}
	dfs(g - 1, dq);
}


int countAnswer()
{
	int answer = 0;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (A[i][j] && A[i + 1][j] && A[i][j + 1] && A[i + 1][j + 1])
				answer++;
		}
	}
	return answer;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> X >> Y >> D >> G;
		deque<pair<int, int>> dq;
		dq.push_front({Y, X});
		A[Y][X] = 1;
		if (D == 0)
			X += 1;
		else if (D == 1)
			Y -= 1;
		else if (D == 2)
			X -= 1;
		else
			Y += 1;
		dq.push_front({Y, X});
		A[Y][X] = 1;
		dfs(G - 1, dq);
	}
	cout << countAnswer() << '\n';
	return 0;
}