#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int bfs(vector<vector<int>> &arr, pair<int, int> shark, int n)
{
    int cnt = 0;
    int size = 2;
    int eat = 0;
    int time = 0;
    queue<pair<int, pair<int, int>>> q;
    vector<vector<bool>> v(n, vector<bool>(n, false));
    queue<pair<int, pair<int, int>>> tq;
    q.push({cnt, shark});
    arr[shark.first][shark.second] = 0;
    v[shark.first][shark.second] = true;
    while (!q.empty())
    {
        tq.push(q.front());
        q.pop();
        if (q.empty())
        {
            pair<int, int> t = {30, 30};
            while(!tq.empty())
            {
                cnt = tq.front().first;
                pair<int, int> x = tq.front().second;
                tq.pop();
                if (0 < arr[x.first][x.second] && arr[x.first][x.second] < size)
                {
                    if (x.first < t.first)
                    {
                        t.first = x.first;
                        t.second = x.second;
                    }
                    else
                    {
                        if (x.first == t.first && x.second < t.second)
                        {
                            t.first = x.first;
                            t.second = x.second;
                        }
                    }
                }
                else
                {
                    if (x.first - 1 >= 0 && arr[x.first - 1][x.second] <= size && !v[x.first - 1][x.second])
                    {
                        v[x.first - 1][x.second] = true;
                        q.push({cnt + 1, {x.first - 1, x.second}});
                    }
                    if (x.second - 1 >= 0 && arr[x.first][x.second - 1] <= size && !v[x.first][x.second - 1])
                    {
                        v[x.first][x.second - 1] = true;
                        q.push({cnt + 1, {x.first, x.second - 1}});
                    }
                    if (x.first + 1 < n && arr[x.first + 1][x.second] <= size && !v[x.first + 1][x.second])
                    {
                        v[x.first + 1][x.second] = true;
                        q.push({cnt + 1, {x.first + 1, x.second}});
                    }
                    if (x.second + 1 < n && arr[x.first][x.second + 1] <= size && !v[x.first][x.second + 1])
                    {
                        v[x.first][x.second + 1] = true;
                        q.push({cnt + 1, {x.first, x.second + 1}});
                    }
                }
            }
            pair<int, int> x = t;
            if (x.first != 30 && x.second != 30)
            {
                if (0 < arr[x.first][x.second] && arr[x.first][x.second] < size)
                {
                    arr[x.first][x.second] = 0;
                    time = cnt;
                    eat++;
                    if (eat >= size)
                    {
                        eat = 0;
                        size++;
                    }
                    while (!q.empty())
                        q.pop();
                    for (int i = 0; i < n; i++)
                        for (int j = 0; j < n; j++)
                            v[i][j] = false;
                    v[x.first][x.second] = true;

                    if (x.first - 1 >= 0 && arr[x.first - 1][x.second] <= size && !v[x.first - 1][x.second])
                    {
                        v[x.first - 1][x.second] = true;
                        q.push({cnt + 1, {x.first - 1, x.second}});
                    }
                    if (x.second - 1 >= 0 && arr[x.first][x.second - 1] <= size && !v[x.first][x.second - 1])
                    {
                        v[x.first][x.second - 1] = true;
                        q.push({cnt + 1, {x.first, x.second - 1}});
                    }
                    if (x.first + 1 < n && arr[x.first + 1][x.second] <= size && !v[x.first + 1][x.second])
                    {
                        v[x.first + 1][x.second] = true;
                        q.push({cnt + 1, {x.first + 1, x.second}});
                    }
                    if (x.second + 1 < n && arr[x.first][x.second + 1] <= size && !v[x.first][x.second + 1])
                    {
                        v[x.first][x.second + 1] = true;
                        q.push({cnt + 1, {x.first, x.second + 1}});
                    }
                }
            }
        }
    }
    return (time);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n, 0));
    pair<int, int> shark;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 9)
            {
                shark.first = i;
                shark.second = j;
            }
        }
    }
    cout << bfs(arr, shark, n) << '\n';
    return (0);
}