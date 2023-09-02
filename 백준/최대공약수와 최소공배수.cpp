#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
    int m;

    while ((m = a % b) > 0)
    {
        a = b;
        b = m;
    }
    return (b);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a, b;
    cin >> a >> b;

    int g = gcd(a,b);
    cout << g << '\n';
    cout << a * b / g << '\n';
    return (0);
}