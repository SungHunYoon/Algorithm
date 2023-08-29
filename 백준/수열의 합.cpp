#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, l;
    cin >> n >> l;

    int i;
    for (i = l; i < 101; i++)
    {
        long long constance = 0;
        for (int j = 0; j < i; j++)
            constance += j;
        if (n - constance < 0)
            continue;
        int a = (n - constance) / i;
        if (a >= 0)
        {
            long long sum = 0;
            for (int j = 0; j < i; j++)
                sum += a + j;
            if (sum % n == 0)
            {
                for (int j = 0; j < i; j++)
                {
                    cout << a + j;
                    if (j + 1 < i)
                        cout << ' ';
                }
                cout << '\n';
                break;
            }
        }
    }
    if (i == 101)
        cout << -1 << '\n';
    return (0);
}