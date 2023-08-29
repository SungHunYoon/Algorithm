#include <iostream>
#include <vector>
#include <string>

using namespace std;

int isPossible(string str)
{
    string tmp = "";
    int len = str.length();

    for (int i = 0; i < len; i++)
        tmp += str[len - 1 - i];
    if (tmp == str)
        return (1);
    else
        return (0);
}

string reverse(string str)
{
    string rev = "";

    for (int i = str.length() - 1; i >= 0; i--)
        rev += str[i];
    return (rev);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str;
    cin >> str;

    int index = 0;
    for (int i = 0; i < str.length(); i++)
    {
        string front = str.substr(str.length() - 1 - i);
        string back = reverse(front);

        if (front == back)
            index = str.length() - 1 - i;
    }
    cout << str.length() + index << '\n';

    return (0);
}