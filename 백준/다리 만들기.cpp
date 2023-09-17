#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n;
int arr[101][101];
vector<pair<int, int>> island[251];
bool visit[101][101];
int nx[4] = {1, -1, 0, 0};
int ny[4] = {0, 0, 1, -1};

void dfs(int index, int x, int y)
{
    if (x < 0 || y < 0 || x >= n || y >= n)
        return;
    else if (visit[y][x])
        return;
    else if (arr[y][x] != 1)
    {
        visit[y][x] = true;
        island[index].push_back({x, y});
        return;
    }
    visit[y][x] = true;
    dfs(index, x + 1, y);
    dfs(index, x - 1, y);
    dfs(index, x, y + 1);
    dfs(index, x, y - 1);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
  
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    int idx = 1;
    int answer = 1000000000;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visit[i][j] && arr[i][j] == 1)
            {
                dfs(idx, j, i);
                bool tmp[101][101];
                for (int k = 0; k < n; k++)
                    for (int l = 0; l < n; l++)
                        tmp[k][l] = visit[k][l];
                queue<pair<int, int>> q;
                for (int k = 0; k < island[idx].size(); k++)
                {
                    visit[island[idx][k].second][island[idx][k].first] = false;
                    q.push(island[idx][k]);
                }
                int cnt = 0;
                int flag = 0;
                while (!q.empty())
                {
                    int len = q.size();
                    for (int l = 0; l < len; l++)
                    {
                        pair<int, int> x = q.front();
                        q.pop();
                        if (arr[x.second][x.first] == 1)
                        {
                            answer = min(answer, cnt);
                            flag = 1;
                            break;
                        }
                        for (int k = 0; k < 4; k++)
                        {
                            int dx, dy;
                            dx = x.first + nx[k];
                            dy = x.second + ny[k];
                            if (0 <= dx && dx < n && 0 <= dy && dy < n)
                            {
                                if (!tmp[dy][dx])
                                {
                                    tmp[dy][dx] = true;
                                    q.push({dx, dy});
                                }
                            }
                        }
                    }
                    if (flag == 1)
                        break;
                    cnt++;
                }
                idx++;
            }
        }
    }
    cout << answer << '\n';
    return (0);
}