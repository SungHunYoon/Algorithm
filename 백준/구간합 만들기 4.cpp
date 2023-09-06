#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    int arr[n + 1];
    int d[n + 1];
    d[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        d[i] = d[i - 1] + arr[i];
    }
    for (int k = 0; k < m; k++)
    {
        int i, j;
        cin >> i >> j;
        cout << d[j] - d[i] << '\n';
    }
    return (0);
}