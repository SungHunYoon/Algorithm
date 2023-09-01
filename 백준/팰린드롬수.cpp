#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str;
    while (cin >> str)
    {
        if (str == "0")
            return (0);
        int i;
        for (i = 0; i < str.length() / 2; i++)
        {
            if (str[i] != str[str.length() - 1 - i])
                break;
        }
        if (i == str.length() / 2)
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return (0);
}