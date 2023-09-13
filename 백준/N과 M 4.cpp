#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int n, m;

void recursive(vector<int> &arr, int index)
{
    if (index == m)
    {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (index != 0 && arr[index - 1] > i)
            continue;
        arr[index] = i;
        recursive(arr, index + 1);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    vector<int> arr (n + 1, 0);
    recursive(arr, 0);
    return (0);
}