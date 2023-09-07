#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int d[1001];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    d[1] = 1;
    d[2] = 3;
    for (int i = 3; i <= n; i++)
        d[i] = (d[i - 1] + d[i - 2] + d[i - 2]) % 10007;
    cout << d[n] << '\n';
    return (0);
}