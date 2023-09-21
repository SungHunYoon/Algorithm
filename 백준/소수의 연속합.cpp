#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
bool table[4000001];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    table[1] = true;
    for (int i = 2; i < 4000001; i++)
    {
        if (table[i])
            continue;
        for (int j = i * 2; j < 4000001; j += i)
            table[j] = true;
    }
    int e = 1;
    int sum = 0;
    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        while (!table[i] && sum < n && e <= n)
        {
            if (!table[e])
                sum += e;
            e++;
        }
        if (!table[i])
        {
            if (sum == n)
                answer++;
            sum -= i;
        }
    }
    cout << answer << '\n';
    return (0);
}