#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string name;
    cin >> name;

    vector<int> arr (26, 0);
    for (int i = 0; i < name.length(); i++)
        arr[name[i] - 'A']++;
    string front = "";
    string odd = "";
    string back = "";
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] % 2 != 0)
        {
            if (odd.length() == 0)
                odd += 'A' + i;
            else
                break;
        }
        for (int j = 0; j < arr[i] / 2; j++)
            front += 'A' + i;
    }
    for (int i = 25; i >= 0; i--)
    {
        for (int j = 0; j < arr[i] / 2; j++)
            back += 'A' + i;
    }
    string answer = front + odd + back;
    if (answer.length() != name.length())
        cout << "I'm Sorry Hansoo\n";
    else
        cout << answer << "\n";
    return (0);
}