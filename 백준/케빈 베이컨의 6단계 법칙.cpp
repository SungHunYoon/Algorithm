#include <iostream>
#include <vector>

using namespace std;

void floydwashall(int **arr, int n)
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

    int n, m;
    cin >> n >> m;
    //vector<vector<int>> arr(n + 1, vector<int>(m + 1, 1000000000));
    //int arr[n + 1][m + 1] = { 1000000000, };
    int **arr;
    arr = (int **)malloc(sizeof(int *) * (n + 1));
    for (int i = 0; i < n + 1; i++)
    {
        arr[i] = (int *)malloc(sizeof(int) * (m + 1));
        for (int j = 0; j < n + 1; j++)
            arr[i][j] = 1000000000;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }
    for (int i = 1; i <= n; i++)
        arr[i][i] = 0;
    floydwashall(arr, n);
    int min = 1000000000;
    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        for (int j = 1; j <= n; j++)
        {
            if (i != j)
                sum += arr[i][j];
        }
        if (min > sum)
        {
            min = sum;
            answer = i;
        }
    }
    cout << answer << '\n';
    return (0);
}