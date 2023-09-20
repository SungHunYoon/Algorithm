#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
int arr[100001];
bool exist[1000001];
bool table[1000001];
int cnt[1000001];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        exist[arr[i]] = true;
    }

    for (int i = 2; i <= 1000000; i++)
    {
        //if (table[i])
        //    continue;
        for (int j = i * 2; j <= 1000000; j += i)
        {
            table[j] = true;
            if (exist[i] && exist[j])
            {
                cnt[i]++;
                cnt[j]--;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
            cout << n << ' ';
        else
        {
            if (exist[1])
                cout << cnt[arr[i]] - 1 << ' ';
            else
                cout << cnt[arr[i]] << ' ';
        }
    }
    cout << '\n';
    return (0);
}