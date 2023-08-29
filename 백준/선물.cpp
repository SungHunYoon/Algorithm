#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    unsigned long long n, l, w, h;
    cin >> n >> l >> w >> h;

    double start, end, mid;
    start = 0;
    end = 1000000000;
    for (int i = 0; i < 10000; i++)
    {
        mid = (start + end) / 2;
        if (n > (long long)(l / mid) * (long long)(w / mid) * (long long)(h / mid))
            end = mid;
        else
            start = mid;
    }
    cout.precision(10);
    cout << mid << '\n';
    return (0);
}