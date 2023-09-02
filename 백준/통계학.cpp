#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

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
    int table[8002] = { 0, };
    double avg = 0;
    int center = arr[n / 2];
    int sum = 0;
    int max = -4001;
    int min = 4001;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        table[arr[i] + 4000]++;
        if (max < arr[i])
            max = arr[i];
        if (min > arr[i])
            min = arr[i];
    }
    avg = round((double)sum / n);
    int p = 0;
    vector<int> preq;
    for (int i = 0; i < 8002; i++)
    {
        if (table[i] >= p)
        {
            if (table[i] > p)
                preq.erase(preq.begin(), preq.begin() + preq.size());
            p = table[i];
            preq.push_back(i - 4000);
        }
    }
    cout << (int)avg << '\n';
    cout << center << '\n';
    if (preq.size() == 1)
        cout << preq[0] << '\n';
    else
        cout << preq[1] << '\n';
    cout << max - min << '\n';
    return (0);
}