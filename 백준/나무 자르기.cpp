#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int arr[1000001];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    long long left = 0;
    long long right = arr[n - 1];
    long long mid;
    int answer = 2000000000;
    while (left <= right)
    {
        mid = (left + right) / 2;
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] - mid > 0)
                sum += arr[i] - mid;
        }
        if (sum == m)
        {
            answer = mid;
            break;
        }
        else if (sum > m)
        {
            if (answer > mid)
                answer = mid;
            left = mid + 1;
        }
        else
            right = mid - 1;
    }
    cout << answer << '\n';
    return (0);
}