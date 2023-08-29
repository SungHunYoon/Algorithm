#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    int m;
    vector<vector<char>> arr;
    
    cin >> n;
    cin >> m;
    arr.assign(n, vector<char>(m, '0'));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int size = min(n - i, m - i);
            for (int k = 0; k < size; k++)
            {
                if (arr[i][j] == arr[i][j + k] && arr[i][j] == arr[i + k][j] && arr[i][j] == arr[i + k][j + k])
                {
                    int sqaure = pow(k + 1, 2);
                    if (sqaure > answer)
                        answer = sqaure;
                }
            }
        }
    }
    cout << answer << '\n';
    return (0);
}