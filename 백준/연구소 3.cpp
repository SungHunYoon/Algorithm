#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
int arr[51][51];
vector<pair<int, int>> virus;
int zero;
int answer;

int nx[4] = {1, -1, 0, 0};
int ny[4] = {0, 0, 1, -1};

void bfs(vector<pair<int, int>> &comb)
{
    queue<pair<int, int>> q;
    bool visit[51][51] = { false, };
    for (int j = 0; j < comb.size(); j++)
    {
        q.push(comb[j]);
        visit[comb[j].second][comb[j].first] = true;
    }
    int cnt = 0;
    int zCnt = 0;
    while (!q.empty())
    {
        int len = q.size();
        for (int j = 0; j < len; j++)
        {
            pair<int, int> x = q.front();
            q.pop();
            for (int k = 0; k < 4; k++)
            {
                int dx, dy;
                dx = x.first + nx[k];
                dy = x.second + ny[k];
                if (0 <= dx && dx < n && 0 <= dy && dy < n)
                {
                    if (!visit[dy][dx] && arr[dy][dx] != 1)
                    {
                        if (arr[dy][dx] == 0)
                            zCnt++;
                        visit[dy][dx] = true;
                        q.push({dx, dy});
                    }
                }
            }
        }
        cnt++;
        if (zero == zCnt)
            answer = min(answer, cnt);
    }
}

void nCr(vector<pair<int, int>> t, int idx, int r)
{
    if (t.size() >= r)
    {
        bfs(t);
        return;
    }
    else if (virus.size() <= idx)
        return;
    nCr(t, idx + 1, r);
    t.push_back(virus[idx]);
    nCr(t, idx + 1, r);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 2)
                virus.push_back({j, i});
            else if (arr[i][j] == 0)
                zero++;
        }
    }
    answer = 1000000000;
    vector<pair<int, int>> t;
    nCr(t, 0, m);
    if (answer == 1000000000)
        cout << "-1\n";
    else
        cout << answer << '\n';
    return (0);
}