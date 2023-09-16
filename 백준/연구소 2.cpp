#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
int arr[51][51];
vector<pair<int, int>> virus;
vector<vector<pair<int, int>>> comb;
int nx[4] = {1, -1, 0, 0};
int ny[4] = {0, 0, 1, -1};

void nCr(vector<pair<int, int>> t, vector<pair<int, int>> virus, int idx, int r)
{
    if (r == t.size())
    {
        comb.push_back(t);
        return;
    }
    else if (idx >= virus.size())
        return;
    nCr(t, virus, idx + 1, r);
    t.push_back(virus[idx]);
    nCr(t, virus, idx + 1, r);
}

int check(bool visit[][51])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visit[i][j] == false)
                return (0);
        }
    }
    return (1);
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
            {
                arr[i][j] = 0;
                virus.push_back({j, i});
            }
        }
    }
    vector<pair<int, int>> t;
    nCr(t, virus, 0, m);

    int answer = 1000000000;
    for (int i = 0; i < comb.size(); i++)
    {
        queue<pair<int, int>> q;
        bool visit[51][51] = { false, };
        for (int j = 0; j < comb[i].size(); j++)
        {
            q.push({comb[i][j].first, comb[i][j].second});
            visit[comb[i][j].second][comb[i][j].first] = true;
        }
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (arr[j][k] == 1)
                    visit[j][k] = true;
            }
        }
        int time = 0;
        while (!q.empty())
        {
            int len = q.size();
            for (int j = 0; j < len; j++)
            {
                pair<int, int> x = q.front();
                q.pop();
                if (arr[x.second][x.first] == 1)
                    continue;
                for (int k = 0; k < 4; k++)
                {
                    int dx, dy;
                    dx = x.first + nx[k];
                    dy = x.second + ny[k];
                    if (0 <= dx && dx < n && 0 <= dy && dy < n)
                    {
                        if (!visit[dy][dx])
                        {
                            visit[dy][dx] = true;
                            q.push({dx, dy});
                        }
                    }
                }
            }
            time++;
        }
        if (check(visit) == 1)
            answer = min(answer, time - 1);
    }
    if (answer == 1000000000)
        cout << "-1\n";
    else
        cout << answer << '\n';
    return (0);
}