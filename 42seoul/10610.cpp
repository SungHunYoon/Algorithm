#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string N;
int arr[100001];

int cmp(int a, int b)
{
    return a > b;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N.size(); i++)
        arr[i] = N[i] - '0';
    sort(arr, arr + N.size(), cmp);
    int mod = 0;
    string answer;
    for (int i = 0; i < N.size(); i++)
    {
        mod = ((mod * 10) + arr[i]) % 30;
        answer.append(1, arr[i] + '0');
    }
    cout << (mod == 0 ? answer : "-1") << '\n';
    return 0;
}