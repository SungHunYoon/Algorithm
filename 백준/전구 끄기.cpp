#include <iostream>
#include <vector>

using namespace std;

int check(vector<vector<bool>> arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == true)
                return (0);
        }
    }
    return (1);
}

void onoff(vector<vector<bool>> &arr, int n, int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= n)
        return;
    if (arr[y][x] == false)
        arr[y][x] = true;
    else
        arr[y][x] = false;
}

void sw(vector<vector<bool>> &arr, int n, int x , int y)
{
    onoff(arr, n, x, y);
    onoff(arr, n, x - 1, y);
    onoff(arr, n, x + 1, y);
    onoff(arr, n, x, y - 1);
    onoff(arr, n, x, y + 1);
}

int loop(vector<vector<bool>> arr, int n, int cnt)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i - 1][j] == true)
            {
                cnt++;
                sw(arr, n, j, i);
            }
        }
    }
    if (check(arr, n) == 1)
        return (cnt);
    else
        return (-1);
}

int brute_force(vector<vector<bool>> &arr, int n, int x, int cnt)
{
    int ret = -1;
    if (x == n)
    {
        int t = loop(arr, n, cnt);
        if (ret == -1 || (t != -1 && ret > t))
            ret = t;
        return (ret);
    }

    int tmp = brute_force(arr, n, x + 1, cnt);
    if (ret == -1 || (tmp != -1 && ret > tmp))
        ret = tmp;
    sw(arr, n, x, 0);
    tmp = brute_force(arr, n, x + 1, cnt + 1);
    sw(arr, n, x, 0);
    if (ret == -1 || (tmp != -1 && ret > tmp))
        ret = tmp;
    return (ret);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<bool>> arr (n, vector<bool>(n, false));
    for (int i = 0 ; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            if (x == 1)
                arr[i][j] = true;
        }
    }
    cout << brute_force(arr, n, 0, 0) << '\n';
    return (0);
}