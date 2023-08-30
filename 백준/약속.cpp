#include <iostream>
#include <vector>

using namespace std;

void floydwashall(vector<vector<int>> &arr, int n)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (arr[i][k] + arr[k][j] < arr[i][j])
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

    int n;
    cin >> n;
    vector<vector<int>> arr (n, vector<int>(n, 1000000000));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char c;
            cin >> c;
            if (j == i)
                arr[i][j] = 0;
            else
            {
                if (c == 'Y')
                    arr[i][j] = 1;
            }
        }
    }
    floydwashall(arr, n);
    /*
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    */
    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            else if (arr[i][j] <= 2)
                cnt++;
        }
        if (cnt > answer)
            answer = cnt;
    }
    cout << answer << '\n';
    return (0);
}