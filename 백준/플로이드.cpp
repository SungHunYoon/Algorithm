#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int arr[101][101];

void floydwashall()
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (arr[i][j] > arr[i][k] + arr[k][j])
                    arr[i][j] = arr[i][k] + arr[k][j];
            }
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                arr[i][j] = 0;
            else
                arr[i][j] = 1000000000;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int s, e, t;
        cin >> s >> e >> t;
        if (arr[s][e] > t)
            arr[s][e] = t;
    }
    floydwashall();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (arr[i][j] == 1000000)
                cout << "0 ";
            else
                cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    return (0);
}