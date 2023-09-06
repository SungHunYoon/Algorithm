#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;
    int arr[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
#if 0
    int d[n + 1];
    if (n <= 2)
        cout << arr[n] << '\n';
    else
    {
        int total = 0;
        for (int i = 1; i <= n; i++)
            total += arr[i];
        d[1] = arr[1];
        d[2] = arr[2];
        d[3] = arr[3];
        for (int i = 4; i <= n - 1; i++)
            d[i] = min(d[i - 2], d[i - 3]) + arr[i];
        cout << total - min(d[n - 1], d[n - 2]) << '\n';
    }
#else
    int d[n + 1][3];
    d[1][1] = arr[1];
    d[1][2] = 0;
    d[2][1] = arr[2];
    d[2][2] = arr[1] + arr[2];
    for (int i = 3; i <= n; i++)
    {
        d[i][1] = max(d[i - 2][1], d[i - 2][2]) + arr[i];
        d[i][2] = d[i - 1][1] + arr[i]; 
    }
    cout << max(d[n][1], d[n][2]) << '\n';
#endif
    return (0);
}