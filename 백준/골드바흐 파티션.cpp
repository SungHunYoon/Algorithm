#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    bool table[1000001] = { false, };
    table[1] = true;
    for (int i = 2; i < 1000001; i++)
    {
        if (table[i] == true)
            continue;
        for (int j = i * 2; j < 1000001; j += i)
            table[j] = true;
    }
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        int cnt = 0;
        bool tmp[n + 1] = { false, };
        for (int i = 2; i < n; i++)
        {
            if (table[i])
                continue;
            if (!table[n - i] && !tmp[n - i])
            {
                tmp[i] = true;
                tmp[n - i] = true;
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
    return (0);
}