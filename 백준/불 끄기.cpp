#include <iostream>
#include <vector>

using namespace std;

int check(vector<vector<char>> arr)
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (arr[i][j] != '#')
                return (0);
        }
    }
    return (1);
}

void onoff(vector<vector<char>> &arr, int x, int y)
{
    if (x < 0 || x >= 10 || y < 0 || y >= 10)
        return;
    if (arr[y][x] == '#')
        arr[y][x] = 'O';
    else
        arr[y][x] = '#';
}

void sw(vector<vector<char>> &arr, int x , int y)
{
    onoff(arr, x, y);
    onoff(arr, x - 1, y);
    onoff(arr, x + 1, y);
    onoff(arr, x, y - 1);
    onoff(arr, x, y + 1);
}

int loop(vector<vector<char>> arr, int cnt)
{
    for (int i = 1; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (arr[i - 1][j] == 'O')
            {
                cnt++;
                sw(arr, j, i);
            }
        }
    }
    if (check(arr) == 1)
        return (cnt);
    else
        return (-1);
}

int brute_force(vector<vector<char>> &arr, int x, int cnt)
{
    int ret = -1;
    if (x == 10)
    {
        int t = loop(arr, cnt);
        if (ret == -1 || (t != -1 && ret > t))
            ret = t;
        return (ret);
    }

    int tmp = brute_force(arr, x + 1, cnt);
    if (ret == -1 || (tmp != -1 && ret > tmp))
        ret = tmp;
    sw(arr, x, 0);
    tmp = brute_force(arr, x + 1, cnt + 1);
    sw(arr, x, 0);
    if (ret == -1 || (tmp != -1 && ret > tmp))
        ret = tmp;
    return (ret);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<vector<char>> arr (10, vector<char>(10, 0));
    for (int i = 0 ; i < 10; i++)
        for (int j = 0; j < 10; j++)
            cin >> arr[i][j];

    cout << brute_force(arr, 0, 0) << '\n';
    return (0);
}