#include <iostream>
#include <algorithm>

using namespace std;

int V, E;
pair<int, pair<int, int>> A[159601];
int F[401][401];

void floydwashall()
{
	for (int k = 1; k <= V; k++)
		for (int i = 1; i <= V; i++)
			for (int j = 1; j <= V; j++)
				F[i][j] = min(F[i][j], F[i][k] + F[k][j]);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> V >> E;
	for (int i = 1; i <= V; i++)
	{
		for (int j = 1; j <= V; j++)
		{
			if (i == j)
				F[i][j] = 0;
			else
				F[i][j] = 1e9;
		}
	}
	for (int i = 0; i < E; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		F[a][b] = c;
	}
	floydwashall();
	int answer = 1e9;
	for (int i = 1; i <= V; i++)
	{
		for (int j = 1; j <= V; j++)
		{
			if (i != j && F[i][j] != 1e9 && F[j][i] != 1e9)
				answer = min(answer, F[i][j] + F[j][i]);
		}
	}
	if (answer == 1e9)
		cout << "-1\n";
	else
		cout << answer << '\n';
	return 0;
}