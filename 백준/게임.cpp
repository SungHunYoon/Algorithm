#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long x;
    long long y;

    cin >> x >> y;
    
    if (x == y)
        cout << -1 << '\n';
    else
    {
        long long before = (y * 100) / x;
        long long after = 0;
        
        if (before == 99)
            cout << -1 << '\n';
        else
        {
            /*
            int answer = 0;
            while (before >= after)
            {
                answer++;
                after = ((y + answer) * 100) / (x + answer);
            }
            */

            long long start = 0;
            long long end = 1000000000;
            long long mid = 0;
            while (start != end)
            {
                mid = (start + end) / 2;
                after = ((y + mid) * 100) / (x + mid);
                if (before < after)
                    end = mid;
                else
                    start = mid + 1;
            }
            cout << start << '\n';
        }
    }
    return (0);
}