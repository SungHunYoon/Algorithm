#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int n, m;
char arr[601][601];
bool visit[601][601];
int nx[4] = {1, -1, 0, 0};
int ny[4] = {0, 0, 1, -1};

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 'I')
            {
                visit[i][j] = true;
                q.push({j, i});
            }
        }
    }
    int answer = 0;
    while (!q.empty())
    {
        pair<int, int> x = q.front();
        q.pop();
        if (arr[x.second][x.first] == 'P')
            answer++;
        else if (arr[x.second][x.first] != 'X')
        {
            for (int i = 0; i < 4; i++)
            {
                int dx, dy;
                dx = x.first + nx[i];
                dy = x.second + ny[i];
                if (0 <= dx && dx < m && 0 <= dy && dy < n)
                {
                    if (!visit[dy][dx])
                    {
                        visit[dy][dx] = true;
                        q.push({dx, dy});
                    }
                }
            }
        }
    }
    if (answer == 0)
        cout << "TT\n";
    else
        cout << answer << '\n';
    return (0);
}