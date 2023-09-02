#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long a, b, v;
    cin >> a >> b >> v;

    double answer = (double)(v - b) / (a - b);
    cout << (int)ceil(answer) << '\n';
    return (0);
}