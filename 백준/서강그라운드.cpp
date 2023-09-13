#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int n, m, r;
int arr[101];
int d[101][101];
int answer[101];

void floydwashall()
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (d[i][j] > d[i][k] + d[k][j])
                    d[i][j] = d[i][k] + d[k][j];
            }
        } 
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> r;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                d[i][j] = 0;
            else
                d[i][j] = 1000000000;
        }
    }
    for (int i = 0; i < r; i++)
    {
        int s, e, dis;
        cin >> s >> e >> dis;
        d[s][e] = dis;
        d[e][s] = dis;
    }
    floydwashall();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (d[i][j] <= m)
                answer[i] += arr[j - 1];
        }
    }
    cout << *max_element(answer + 1, answer + n + 1) << '\n';
    return (0);
}