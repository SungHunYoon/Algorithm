#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find(vector<int> arr, int n, int find)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == find)
            return (i);
    }
    return (-1);
}

int main(void)
{
    int n;
    vector<int> arr;

    cin >> n;
    arr.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        int m;

        if (i + 5 <= n)
            m = 5;
        else
            m = n - i;

        vector<int> temp (m, 0);

        for (int j = 0; j < m; j++)
            temp[j] = arr[i] + j;

        int cnt = 0;

        for (int j = 0; j < m; j++)
        {
            if (find(temp, m, arr[i + j]) >= 0)
                cnt++;
        }
        if (cnt > max)
            max = cnt;
    }
    if (5 - max > 0)
        cout << 5 - max << endl;
    else
        cout << 0 << endl;
    return (0);
}