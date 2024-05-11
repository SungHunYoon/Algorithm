#include <iostream>

using namespace std;

int N;
char arr[102][102];
int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> arr[i][j];
	if (N <= 2)
	{
		cout << "0\n";
		return 0;
	}
	int answer = (N - 2) * (N - 2);
	for (int i = 2; i <= N - 1; i++)
	{
		for (int j = 2; j <= N - 1; j++)
		{
			if (i == 2 || i == N - 1 || j == 2 || j == N - 1)
			{
				bool flag = false;
				for (int k = 0; k < 8; k++)
				{
					int nx = j + dx[k];
					int ny = i + dy[k];
					
					if (arr[ny][nx] != '#' && arr[ny][nx] - '0' <= 0)
					{
						flag = true;
						break;
					}
				}
				if (flag)
				{
					answer--;
					continue;
				}
				for (int k = 0; k < 8; k++)
				{
					int nx = j + dx[k];
					int ny = i + dy[k];

					if (arr[ny][nx] != '#')
						arr[ny][nx]--;
				}
			}
		}
	}
	cout << answer << '\n';
	return 0;
}
