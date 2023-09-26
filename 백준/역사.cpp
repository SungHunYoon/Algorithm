#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, s;
int arr[401][401];

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
            if (i != j)
                arr[i][j] = 1000000000;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[a][b] = 1;
    }
    floydwashall();
    /*
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    */
    cin >> s;
    for (int i = 0; i < s; i++)
    {
        int a, b;
        cin >> a >> b;
        if (arr[a][b] == 1000000000 && arr[b][a] == 1000000000)
            cout << "0\n";
        else if (arr[a][b] != 1000000000)
            cout << "-1\n";
        else if (arr[b][a] != 1000000000)
            cout << "1\n";
    }
    return (0);
}