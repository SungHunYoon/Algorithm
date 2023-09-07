#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int t;
int n;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        long long d[101] = { 0, };
        d[1] = 1;
        d[2] = 1;
        d[3] = 1;
        for (int j = 4; j <= n; j++)
            d[j] = d[j - 2] + d[j - 3];
        cout << d[n] << '\n';
    }
    return (0);
}