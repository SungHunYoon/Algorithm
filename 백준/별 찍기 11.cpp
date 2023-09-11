#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
char arr[3073][6145];

void recursive(int x, int y, int n)
{
    if (n == 3)
    {
        arr[y][x] = '*';
        arr[y + 1][x - 1] = '*';
        arr[y + 1][x + 1] = '*';
        for (int i = x - 2; i <= x + 2; i++)
            arr[y + 2][i] = '*';
        return;
    }
    recursive(x, y, n / 2);
    recursive(x - n / 2, y + n / 2, n / 2);
    recursive(x + n / 2, y + n / 2, n / 2);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 2 * n; j++)
            arr[i][j] = ' ';
    recursive(n - 1, 0, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2 * n; j++)
        {
            cout << arr[i][j];
        }
        cout << '\n';
    }
    return (0);
}