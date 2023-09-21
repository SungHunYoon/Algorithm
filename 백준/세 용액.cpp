#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
int arr[5001];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);

    long long sum = 0;
    long long sumValue = 3000000003;
    int answer[3];
    for (int j = 0; j < n; j++)
    {
        int e = n - 1;
        for (int i = j + 1; i < e; i++)
        {
            while (e > i)
            {
                sum = arr[j] + arr[i] + arr[e];
                if (abs(sumValue) > abs(sum))
                {
                    sumValue = sum;
                    answer[0] = arr[j];
                    answer[1] = arr[i];
                    answer[2] = arr[e];
                }
                if (sum > 0)
                    e--;
                else
                    break;
            }
        }
    }
    cout << answer[0] << ' ' << answer[1] << ' ' << answer[2] << '\n';
    return (0);
}