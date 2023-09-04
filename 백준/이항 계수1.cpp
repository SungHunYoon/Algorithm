#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;

    int tmp = 1;
    for (int i = n; i > n - k; i--)
        tmp *= i;
    int tmp2 = 1;
    for (int i = 1; i <= k; i++)
        tmp2 *= i;
    cout << tmp / tmp2 << '\n';
    return (0);
}