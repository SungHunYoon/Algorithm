#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int t;
int truth[51];
int p[51];
int party[51][51];
int arr[51][51];

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

    cin >> t;
    for (int i = 0; i < t; i++)
        cin >> truth[i];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            arr[i][j] = 1000000000;

    for (int i = 0; i < m; i++)
    {
        cin >> p[i];
        for (int j = 0; j < p[i]; j++)
            cin >> party[i][j];
        for (int j = 0; j < p[i]; j++)
        {
            for (int k = j; k < p[i]; k++)
            {
                arr[party[i][j]][party[i][k]] = 1;
                arr[party[i][k]][party[i][j]] = 1;
            }
        }
    }
    floydwashall();
    int answer = 0;
    for (int i = 0; i < m; i++)
    {
        int j;
        for (j = 0; j < p[i]; j++)
        {
            int k;
            for (k = 0; k < t; k++)
            {
                if (arr[party[i][j]][truth[k]] != 1000000000)
                    break;
            }
            if (k != t)
                break;
        }
        if (j == p[i])
            answer++;
    }
    cout << answer << '\n';
    return (0);
}