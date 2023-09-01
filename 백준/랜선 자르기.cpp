#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int k, n;
    cin >> k >> n;
    vector<int> arr;
    for (int i = 0; i < k; i++)
    {
        int len;
        cin >> len;
        arr.push_back(len);
    }

    long long start = 1;
    long long end = 2147483647;
    long long mid;
    while (start <= end)
    {
        mid = (start + end) / 2;
        long long cnt = 0;
        for (int i = 0; i < k; i++)
            cnt += arr[i] / mid;
        if (cnt >= n)
            start = mid + 1;
        else
            end = mid - 1;
    }
    cout << start << '\n';
    return (0);
}