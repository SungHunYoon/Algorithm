#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int m, n;
    cin >> m >> n;
    bool table[1000001] = { false, };

    for (int i = 2; i <= 1000000; i++)
    {
        if (table[i] == true)
            continue;
        for (int j = i * 2; j <= 1000000; j += i)
            table[j] = true;
    }
    for (int i = m; i <= n; i++)
    {
        if (table[i] == false)
            cout << i << '\n';
    }
    return (0);
}