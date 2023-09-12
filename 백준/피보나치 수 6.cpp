#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long n;

void matrix_multiple(long long arr1[2][2], long long arr2[2][2])
{
    long long a = arr1[0][0] * arr2[0][0] + arr1[0][1] * arr2[1][0];
    long long b = arr1[0][0] * arr2[0][1] + arr1[0][1] * arr2[1][1];
    long long c = arr1[1][0] * arr2[0][0] + arr1[1][1] * arr2[1][0];
    long long d = arr1[1][0] * arr2[0][1] + arr1[1][1] * arr2[1][1];

    arr1[0][0] = a % 1000000007;
    arr1[0][1] = b % 1000000007;
    arr1[1][0] = c % 1000000007;
    arr1[1][1] = d % 1000000007;
}

void power(long long arr[2][2], long long num)
{
    if (num == 0 || num == 1)
        return;
    long long m[2][2] = { {1, 1}, {1, 0} };
    power(arr, num / 2);
    matrix_multiple(arr, arr);
    if (num % 2 == 1)
        matrix_multiple(arr, m);
}

long long fibonacci(long long num)
{
    if (num == 0)
        return (0);
    long long arr[2][2] = { {1, 1}, {1, 0} };
    power(arr, num - 1);
    return (arr[0][0]);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    cout << fibonacci(n) << '\n';
    return (0);
}