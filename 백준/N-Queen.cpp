#include <iostream>
#include <vector>

using namespace std;

int check_queens(vector<int> &arr, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        if (arr[i] == arr[r] || r - i == c - arr[i] || r - arr[i] == i - c)
            return (0);
    }
    return (1);
}

int recursive(vector<int> &arr, int n, int row)
{
    if (row == n)
        return (1);
    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        arr[row] = i;
        if (check_queens(arr, row, i) == 1)
            ret += recursive(arr, n, row + 1);
    }
    return (ret);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr (n, 0);
    cout << recursive(arr, n, 0) << '\n';
    return (0);
}