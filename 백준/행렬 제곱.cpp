#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
long long b;
int arr[6][6];

vector<vector<int>> power(long long b)
{
    vector<vector<int>> a(n, vector<int>(n, 0));
    if (b == 1)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                a[i][j] = arr[i][j];
        return (a);
    }
    else if (b == 2)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                long long sum = 0;
                for (int k = 0; k < n; k++)
                     sum += arr[i][k] * arr[k][j];
                a[i][j] = sum % 1000;
            }
        }
        return (a);
    }
    vector<vector<int>> tmp = power(b / 2);
    if (b % 2 == 0)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                long long sum = 0;
                for (int k = 0; k < n; k++)
                    sum += tmp[i][k] * tmp[k][j];
                a[i][j] = sum % 1000;
            }
        }
    }
    else
    {
        vector<vector<int>> tmp2(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                long long sum = 0;
                for (int k = 0; k < n; k++)
                    sum += tmp[i][k] * tmp[k][j];
                tmp2[i][j] = sum % 1000;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                long long sum = 0;
                for (int k = 0; k < n; k++)
                    sum += tmp2[i][k] * arr[k][j];
                a[i][j] = sum % 1000;
            }
        }
    }
    return (a);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> b;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    vector<vector<int>> answer = power(b);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << answer[i][j] << ' ';
        cout << '\n';
    }
    return (0);
}