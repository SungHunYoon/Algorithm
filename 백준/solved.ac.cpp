#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    
    if (n == 0)
        cout << 0 << '\n';
    else
    {
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        sort(arr, arr + n);
        double p = n * 0.3 / 2;
        int percent = round(p);
        int sum = 0;
        for (int i = percent; i < n - percent; i++)
            sum += arr[i];
        int answer = round(sum / ((double)n - 2 * percent));
        cout << answer << '\n';
    }
    return (0);
}