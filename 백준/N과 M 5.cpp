#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int a[9];
int v[9];

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
        if (!v[i])
        {
            v[i] = true;
            arr[index] = a[i];
            recursive(arr, index + 1);
            v[i] = false;
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    vector<int> arr (n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    recursive(arr, 0);
    return (0);
}