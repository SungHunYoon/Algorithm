#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

long long a, b, c;

long long power(long long cnt)
{
    if (cnt == 1)
        return (a % c);
    else if (cnt == 2)
        return (((a % c) * (a % c)) % c);
    
    long long tmp = power(cnt / 2);
    if (cnt % 2 == 1)
        return (((tmp * tmp % c) * a) % c);
    else
        return (tmp * tmp % c);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> a >> b >> c;
    /*
    for (int i = 0; i < b; i++)
        a = a * a % c;
    cout << a << '\n';
    */
    cout << power(b) << '\n';
    return (0);
}