#include <iostream>

using namespace std;

long long S;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> S;
    long long N = 0;
    long long sum = 0;
    for (long long i = 1; i <= S; i++)
    {
        sum += i;
        if (sum > S)
            break;
        N++;
    }
    cout << N << '\n';
    return 0;
}

// 1 1 2 2 2 3 3 3 3 3 4 4 4 4 4