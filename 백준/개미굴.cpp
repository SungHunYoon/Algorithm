#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef struct s_trie
{
    struct s_trie *c[27];
    bool isFinished;
} t_trie;

int n;
t_trie *trie;

void trie_insert(t_trie *t, char *str)
{
    if (*str == '\0')
    {
        t->isFinished = true;
        return;
    }
    int index = *str == ' ' ? 0 : *str - 'A' + 1;
    if (t->c[index] == NULL)
    {
        t->c[index] = (t_trie *)malloc(sizeof(t_trie));
        for (int i = 0; i < 27; i++)
            t->c[index]->c[i] = NULL;
        t->c[index]->isFinished = false;
    }
    trie_insert(t->c[index], str + 1);
}

void trie_travle(t_trie *t, int index, string str)
{
    if (t->isFinished)
    {
        for (int j = 0; j < index; j++)
            cout << "--";
        cout << str << '\n';
        cout << str.size() << '\n';
    }
    for (int i = 0; i < 27; i++)
    {
        if (t->c[i] != NULL)
        {
            if (i == 0)
            {
                if (!t->isFinished)
                {
                    for (int j = 0; j < index; j++)
                        cout << "--";
                    cout << str << '\n';
                }
                string tmp = "";
                trie_travle(t->c[i], index + 1, tmp);
            }
            else
            {
                str.push_back('A' + i - 1);
                trie_travle(t->c[i], index, str);
                str.pop_back();
            }
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    trie = (t_trie *)malloc(sizeof(t_trie));
    for (int i = 0; i < 27; i++)
        trie->c[i] = NULL;
    trie->isFinished = false;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        char str[16 * k] = { 0, };
        cin.ignore();
        cin.getline(str, 16 * k);
        trie_insert(trie, str);
    }
    string s;
    trie_travle(trie, 0, s);
    return (0);
}