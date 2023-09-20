#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
int arr[15][15];
pair<int, int> red;
pair<int, int> blue;
pair<int, int> out;

int move(pair<int, int> &color, int dir)
{
    if (dir == 0)
    {
        for (int i = color.first - 1; i >= 0; i--)
        {
            if (arr[color.second][i] == 1)
            {
                color.first = i + 1;
                return (0);
            }
            else if (arr[color.second][i] == 2)
            {
                color.first = i - 1;
                return (1);
            }
        }
    }
    else if (dir == 1)
    {
        for (int i = color.first + 1; i < m; i++)
        {
            if (arr[color.second][i] == 1)
            {
                color.first = i - 1;
                return (0);
            }
            else if (arr[color.second][i] == 2)
            {
                color.first = i + 1;
                return (1);
            }
        }
    }
    else if (dir == 2)
    {
        for (int i = color.second + 1; i < n; i++)
        {
            if (arr[i][color.first] == 1)
            {
                color.second = i - 1;
                return (0);
            }
            else if (arr[i][color.first] == 2)
            {
                color.second = i + 1;
                return (1);
            }
        }
    }
    else
    {
        for (int i = color.second - 1; i >= 0; i--)
        {
            if (arr[i][color.first] == 1)
            {
                color.second = i + 1;
                return (0);
            }
            else if (arr[i][color.first] == 2)
            {
                color.second = i - 1;
                return (1);
            }
        }
    }
    return (0);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            if (c == '#')
                arr[i][j] = 1;
            else if (c == 'B')
                blue = {j, i};
            else if (c == 'R')
                red = {j, i};
            else if (c == 'O')
            {
                arr[i][j] = 2;
                out = {j, i};
            }
        }
    }

    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push({red, blue});
    int cnt = 0;
    while (!q.empty())
    {
        int len = q.size();
        for (int i = 0; i < len; i++)
        {
            pair<int, int> r = q.front().first;
            pair<int, int> b = q.front().second;
            q.pop();

            pair<int, int> nextR, nextB;
            int sFlag[4] = { 0, 0, 0, 0 };
            int fFlag[4] = { 0, 0, 0, 0 };
            int org = 0;

            arr[r.second][r.first] = 1;
            arr[b.second][b.first] = 1;
            nextR = r;
            nextB = b;
            // Left
            if (r.first > b.first)
            {
                if (move(nextB, 0) == 1)
                    fFlag[0] = 1;
                arr[b.second][b.first] = 0;
                org = arr[nextB.second][nextB.first];
                arr[nextB.second][nextB.first] = 1;
                if (move(nextR, 0) == 1)
                    sFlag[0] = 1;
                if (org == 0)
                    arr[nextB.second][nextB.first] = 0;
            }
            else
            {
                if (move(nextR, 0) == 1)
                    sFlag[0] = 1;
                arr[r.second][r.first] = 0;
                org = arr[nextR.second][nextR.first];
                arr[nextR.second][nextR.first] = 1;
                if (move(nextB, 0) == 1)
                    fFlag[0] = 1;
                if (org == 0)
                    arr[nextR.second][nextR.first] = 0;
            }
            if (fFlag[0] == 1)
                sFlag[0] = 0;
            else
                q.push({nextR, nextB});

            arr[r.second][r.first] = 1;
            arr[b.second][b.first] = 1;
            nextR = r;
            nextB = b;
            // Right
            if (r.first < b.first)
            {
                if (move(nextB, 1) == 1)
                    fFlag[1] = 1;
                arr[b.second][b.first] = 0;
                org = arr[nextB.second][nextB.first];
                arr[nextB.second][nextB.first] = 1;
                if (move(nextR, 1) == 1)
                    sFlag[1] = 1;
                if (org == 0)
                    arr[nextB.second][nextB.first] = 0;
            }
            else
            {
                if (move(nextR, 1) == 1)
                    sFlag[1] = 1;
                arr[r.second][r.first] = 0;
                org = arr[nextR.second][nextR.first];
                arr[nextR.second][nextR.first] = 1;
                if (move(nextB, 1) == 1)
                    fFlag[1] = 1;
                if (org == 0)
                    arr[nextR.second][nextR.first] = 0;
            }
            if (fFlag[1] == 1)
                sFlag[1] = 0;
            else
                q.push({nextR, nextB});

            arr[r.second][r.first] = 1;
            arr[b.second][b.first] = 1;
            nextR = r;
            nextB = b;
            // Bottom
            if (r.second < b.second)
            {
                if (move(nextB, 2) == 1)
                    fFlag[2] = 1;
                arr[b.second][b.first] = 0;
                org = arr[nextB.second][nextB.first];
                arr[nextB.second][nextB.first] = 1;
                if (move(nextR, 2) == 1)
                    sFlag[2] = 1;
                if (org == 0)
                    arr[nextB.second][nextB.first] = 0;
            }
            else
            {
                if (move(nextR, 2) == 1)
                    sFlag[2] = 1;
                arr[r.second][r.first] = 0;
                org = arr[nextR.second][nextR.first];
                arr[nextR.second][nextR.first] = 1;
                if (move(nextB, 2) == 1)
                    fFlag[2] = 1;
                if (org == 0)
                    arr[nextR.second][nextR.first] = 0;
            }
            if (fFlag[2] == 1)
                sFlag[2] = 0;
            else
                q.push({nextR, nextB});

            arr[r.second][r.first] = 1;
            arr[b.second][b.first] = 1;
            nextR = r;
            nextB = b;
            // Top
            if (r.second > b.second)
            {
                if (move(nextB, 3) == 1)
                    fFlag[3] = 1;
                arr[b.second][b.first] = 0;
                org = arr[nextB.second][nextB.first];
                arr[nextB.second][nextB.first] = 1;
                if (move(nextR, 3) == 1)
                    sFlag[3] = 1;
                if (org == 0)
                    arr[nextB.second][nextB.first] = 0;
            }
            else
            {
                if (move(nextR, 3) == 1)
                    sFlag[3] = 1;
                arr[r.second][r.first] = 0;
                org = arr[nextR.second][nextR.first];
                arr[nextR.second][nextR.first] = 1;
                if (move(nextB, 3) == 1)
                    fFlag[3] = 1;
                if (org == 0)
                    arr[nextR.second][nextR.first] = 0;
            }
            if (fFlag[3] == 1)
                sFlag[3] = 0;
            else
                q.push({nextR, nextB});

            arr[r.second][r.first] = 0;
            arr[b.second][b.first] = 0;

            if (sFlag[0] == 1 || sFlag[1] == 1 || sFlag[2] == 1 || sFlag[3] == 1)
            {
                cout << cnt + 1 << '\n';
                return (0);
            }
        }
        cnt++;
        if (cnt >= 10)
        {
            cout << "-1\n";
            return (0);
        }
        
    }
    cout << "-1\n";
    return (0);
}