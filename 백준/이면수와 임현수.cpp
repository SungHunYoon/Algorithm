#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int absolute(int number)
{
    int cnt = 0;

    if (number < 4 || number == 5)
        return (0);
    while (number > 0)
    {
        cnt += number % 10;
        number /= 10;
    }
    if (cnt % 2 == 0)
        return (0);
    return (1);
}

int isPrime(int number)
{
    for (int i = 2; i * i <= number; i++)
    {
        if (number % i == 0)
            return (0);
    }
    return (1);
}

int world(int number)
{
    int kind = 0;
    int n = number;
    
    int i = 2;
    while (n > 1)
    {
        int prime = isPrime(i);
        while (n % i == 0)
        {
            if (prime == 1)
            {
                kind++;
                prime = 0;
            }
            n /= i;
        }
        i++;
    }
    if (number == 2 || number == 4 || (isPrime(number) == 0 && kind % 2 == 0))
        return (1);
    return(0);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    if (absolute(n) == 1 && world(n) == 1)
        cout << 4 << '\n';
    else if (absolute(n) == 1)
        cout << 1 << '\n';
    else if (world(n) == 1)
        cout << 2 << '\n';
    else
        cout << 3 << '\n';
    return (0);
}