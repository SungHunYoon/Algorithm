#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int r, c;
int arr[1002][1002];
bool visit[1002][1002];
pair<int, int> s;
vector<pair<int, int>> f;

int nx[4] = {1, -1, 0, 0};
int ny[4] = {0, 0, 1, -1};

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> r >> c;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            char c;
            cin >> c;
            if (c == '#')
                arr[i][j] = 1;
            else if (c == 'J')
            {
                arr[i][j] = 0;
                s = {j, i};
            }
            else if (c == 'F')
            {
                arr[i][j] = 2;
                f.push_back({j, i});
            }
            else
                arr[i][j] = 0;
        }
    }

    int answer = 1000000000;
    queue<pair<int, pair<int, int>>> q;
    for (int i = 0; i < f.size(); i++)
    {
        visit[f[i].second][f[i].first] = true;
        q.push({1, f[i]});
    }
    visit[s.second][s.first] = true;
    q.push({0, s});
    int cnt = 0;
    int flag = 0;
    while (!q.empty())
    {
        int len = q.size();
        for (int i = 0; i < len; i++)
        {
            int kind = q.front().first;
            pair<int, int> x = q.front().second;
            q.pop();
            if (x.first < 1 || x.second < 1 || x.first > c || x.second > r)
            {
                if (kind == 0)
                {
                    answer = min(answer, cnt);
                    flag = 1;
                    break;
                }
                else
                    continue;
            }
            for (int j = 0; j < 4; j++)
            {
                int dx, dy;
                dx = x.first + nx[j];
                dy = x.second + ny[j];
                if (!visit[dy][dx] && arr[dy][dx] == 0)
                {
                    visit[dy][dx] = true;
                    q.push({kind, {dx, dy}});
                }
            }
        }
        if (flag == 1)
            break;
        cnt++;
    }
    if (answer == 1000000000)
        cout << "-1\n";
    else
        cout << answer << '\n';
    return (0);
}