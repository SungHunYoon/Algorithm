#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
int arr[100001];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int sum = 0;
    int e = n - 1;
    pair<int, pair<int, int>> answer;
    answer.first = 2000000001;
    for (int i = 0; i < e; i++)
    {
        while (e > i)
        {
            sum = arr[i] + arr[e];
            if (abs(answer.first) > abs(sum))
            {
                answer.first = sum;
                answer.second.first = i;
                answer.second.second = e;
            }
            if (sum < 0)
                break;
            else
                e--;
        }
    }
    cout << arr[answer.second.first] << ' ' << arr[answer.second.second] << '\n';
    return (0);
}