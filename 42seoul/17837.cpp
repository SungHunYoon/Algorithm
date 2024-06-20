#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
using player = tuple<int, int, int>;

int N, K, X, Y, Z;
int A[13][13];
player P[10];
vector<player *> M[13][13];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> A[i][j];
	for (int i = 0; i < K; i++)
	{
		cin >> X >> Y >> Z;
		get<0>(P[i]) = X;
		get<1>(P[i]) = Y;
		get<2>(P[i]) = Z;
		M[X][Y].push_back(&P[i]);
	}
	for (int i = 1; i <= 1000; i++)
	{
		for (int j = 0; j < K; j++)
		{
			int x = get<0>(P[j]);
			int y = get<1>(P[j]);
			int z = get<2>(P[j]);
			int nx = x + dx[z - 1];
			int ny = y + dy[z - 1];
			if (0 >= nx || nx > N || 0 >= ny || ny > N || A[nx][ny] == 2)
			{
				if (z <= 2)
				{
					if (++z >= 3)
						z = 1;
				}
				else
				{
					if (++z >= 5)
						z = 3;
				}
				get<2>(P[j]) = z;
				nx = x + dx[z - 1];
				ny = y + dy[z - 1];
				if (0 >= nx || nx > N || 0 >= ny || ny > N || A[nx][ny] == 2)
					continue;
			}
			auto it = find(M[x][y].begin(), M[x][y].end(), &P[j]);
			if (A[nx][ny] == 1)
				reverse(it, M[x][y].end());
			for (auto it2 = it; it2 != M[x][y].end(); it2++)
			{
				get<0>(*(*it2)) = nx;
				get<1>(*(*it2)) = ny;
				M[nx][ny].push_back(*it2);
			}
			M[x][y].erase(it, M[x][y].end());
			if (M[nx][ny].size() >= 4)
			{
				cout << i << '\n';
				return 0;
			}
		}
	}
	cout << "-1\n";
	return 0;
}