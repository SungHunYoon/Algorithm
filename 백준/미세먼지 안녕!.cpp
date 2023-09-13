#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int r, c, t;
int arr[51][51];
pair<int, int> topC;
pair<int, int> botC;

int nx[4] = {1, -1, 0, 0};
int ny[4] = {0, 0, 1, -1};

int dust()
{
    int check[51][51] = { 0, };
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (arr[i][j] > 0)
            {
                int cnt = 0;
                for (int k = 0; k < 4; k++)
                {
                    int dx, dy;
                    dx = j + nx[k];
                    dy = i + ny[k];
                    if (0 <= dx && dx < c && 0 <= dy && dy < r)
                    {
                        if (arr[dy][dx] != -1)
                        {
                            check[dy][dx] += arr[i][j] / 5;
                            cnt++;
                        }
                    }
                }
                check[i][j] += arr[i][j] - (arr[i][j] / 5) * cnt;
            }
            else if (arr[i][j] == -1)
                check[i][j] = arr[i][j];
        }
    }

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            arr[i][j] = check[i][j];
}

int airclean()
{
    int cur;
    int prv;
    for (int i = topC.first + 1; i < c; i++)
    {
        cur = arr[topC.second][i];
        if (i != topC.first + 1)
            arr[topC.second][i] = prv;
        else
            arr[topC.second][i] = 0;
        prv = cur;
    }
    for (int i = topC.second - 1; i >= 0; i--)
    {
        cur = arr[i][c - 1];
        arr[i][c - 1] = prv;
        prv = cur;
    }
    for (int i = c - 2; i >= topC.first; i--)
    {
        cur = arr[0][i];
        arr[0][i] = prv;
        prv = cur;
    }
    for (int i = 1; i < topC.second; i++)
    {
        cur = arr[i][topC.first];
        arr[i][topC.first] = prv;
        prv = cur;
    }

    for (int i = botC.first + 1; i < c; i++)
    {
        cur = arr[botC.second][i];
        if (i != botC.first + 1)
            arr[botC.second][i] = prv;
        else
            arr[botC.second][i] = 0;
        prv = cur;
    }
    for (int i = botC.second + 1; i < r; i++)
    {
        cur = arr[i][c - 1];
        arr[i][c - 1] = prv;
        prv = cur;
    }
    for (int i = c - 2; i >= botC.first; i--)
    {
        cur = arr[r - 1][i];
        arr[r - 1][i] = prv;
        prv = cur;
    }
    for (int i = r - 2; i > botC.second; i--)
    {
        cur = arr[i][botC.first];
        arr[i][botC.first] = prv;
        prv = cur;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> r >> c >> t;
    int cnt = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == -1)
            {
                if (cnt == 0)
                    topC = {j, i};
                else
                    botC = {j, i};
                cnt++;
            }
        }
    }
    for (int i = 0; i < t; i++)
    {
        dust();
        airclean();
    }
    int answer = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (arr[i][j] > 0)
                answer += arr[i][j];
        }
    }
    cout << answer << '\n';
    return (0);
}