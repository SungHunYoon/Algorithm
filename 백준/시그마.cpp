#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MOD 1000000007

int m;
long long n, s;

long long power(long long num, long long p)
{
    if (p == 1)
        return (num % MOD);
    else if (p == 2)
        return (num * num % MOD);
    long long ret = power(num, p / 2);
    if (p % 2 == 0)
        ret = ret * ret % MOD;
    else
        ret = ((ret * ret % MOD) * num) % MOD;
    return (ret);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> m >> n >> s;
    long long answer = 0;
    for (int i = 0; i < m; i++)
    {
        answer += (s * power(n, MOD - 2));
        answer %= MOD;
    }
    cout << answer << '\n';
    return (0);
}