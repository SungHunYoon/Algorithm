#include <iostream>

using namespace std;

double nCr(int n, int r)
{
    double ret = 1;

    if (n == r)
        return (1);

    for (int i = 0; i < r; i++)
        ret *= n - i;
    int factorial = 1;
    for (int i = 2; i <= r; i++)
        factorial *= i;
    return (ret / factorial);
}

int main(void)
{
    int n;
    int m;
    int k;

    cin >> n;
    cin >> m;
    cin >> k;

    double answer = 0;
    for (int i = k; i < m; i++)
        answer += nCr(m, i) * nCr(n - m, m - i) / nCr(n, m);
    answer += 1 / nCr(n, m);
    cout.precision(16);
    cout << answer << endl;
    return (0);
}