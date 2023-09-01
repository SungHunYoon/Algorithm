#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find(int *arr, int num, int left, int right)
{
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == num)
            return (1);
        else if (arr[mid] > num)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return (0);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int num;
        cin >> num;
        cout << find(arr, num, 0, n - 1) << '\n';
    }
    return (0);
}