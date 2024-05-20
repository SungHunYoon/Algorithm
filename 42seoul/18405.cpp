#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, K, S, X, Y;
int A[201][201];
queue<pair<int, int>> q[1001];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> A[i][j];
            if (A[i][j] != 0)
                q[A[i][j]].push({i, j});
        }
    }
    cin >> S >> X >> Y;
    while (S--)
    {
        for (int i = 1; i <= K; i++)
        {
            int len = q[i].size();
            for (int j = 0; j < len; j++)
            {
                auto t = q[i].front(); q[i].pop();
                for (int k = 0; k < 4; k++)
                {
                    int nx = t.second + dx[k];
                    int ny = t.first + dy[k];
                    
                    if (0 <= nx && nx < N && 0 <= ny && ny < N && A[ny][nx] == 0)
                    {
                        A[ny][nx] = i;
                        q[i].push({ny, nx});
                    }
                }
            }
        }
    }
    cout << A[X - 1][Y - 1] << '\n';
    return 0;
}