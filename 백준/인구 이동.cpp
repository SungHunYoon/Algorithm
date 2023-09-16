#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n, L, R;
int arr[51][51];

int nx[4] = {1, -1, 0, 0};
int ny[4] = {0, 0, 1, -1};

int cnt;
int sum;
void recursive(vector<pair<int, int>> &m, int visit[][51], int x, int y, int p, int idx)
{
    if (x < 0 || y < 0 || x >= n || y >= n)
        return;
    else if (visit[y][x])
        return;
    else if (p != -1 && !(L <= abs(arr[y][x] - p) && abs(arr[y][x] - p) <= R))
        return;
    visit[y][x] = idx;
    cnt++;
    sum += arr[y][x];
    m.push_back({x, y});
    recursive(m, visit, x + 1, y, arr[y][x], idx);
    recursive(m, visit, x - 1, y, arr[y][x], idx);
    recursive(m, visit, x, y + 1, arr[y][x], idx);
    recursive(m, visit, x, y - 1, arr[y][x], idx);
}

int move()
{
    int change = 0;
    int idx = 1;
    int visit[51][51] = { 0, };
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visit[i][j])
            {
                sum = 0;
                cnt = 0;
                vector<pair<int, int>> m;
                recursive(m, visit, j, i, -1, idx);
                int val = sum / cnt;
                if (m.size() > 1)
                {
                    for (int k = 0; k < m.size(); k++)
                    {
                        change = 1;
                        arr[m[k].second][m[k].first] = val;
                    }
                }
                idx++;
            }
        }
    }
    return (change);
} 

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
  
    cin >> n >> L >> R;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    int answer = 0;
    while (move() != 0)
        answer++;
    cout << answer << '\n';
    return (0);
}