#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void recursive(vector<vector<int>> &arr, int y, int x)
{
    if (x < 0 || x >= arr[0].size())
        return;
    else if (y < 0 || y >= arr.size())
        return;
    else if (arr[y][x] == 0)
        return;
    arr[y][x] = 0;
    recursive(arr, y - 1, x);
    recursive(arr, y + 1, x);
    recursive(arr, y, x - 1);
    recursive(arr, y, x + 1);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    for (int l = 0; l < t; l++)
    {
        int m, n, k;
        cin >> m >> n >> k;
        vector<vector<int>> arr (n, vector<int>(m, 0));
        for (int i = 0; i < k; i++)
        {
            int x, y;
            cin >> x >> y;
            arr[y][x] = 1;
        }
        int answer = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (arr[i][j] == 1)
                {
                    answer++;
                    recursive(arr, i, j);
                }
            }
        }
        cout << answer << '\n';
    }
    return (0);
}