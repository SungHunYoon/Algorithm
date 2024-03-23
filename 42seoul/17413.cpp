#include <iostream>
#include <string>
#include <queue>

using namespace std;

string s;
char a;
bool flag;
queue<string> q;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	while ((a = cin.get()))
	{
		if (a == '\n' || (!flag && a == ' ') || a == '>' || a == '<')
		{
			if (a == '<')
				flag = true;
			if (a == '>')
			{
				s.append(1, a);
				flag = false;
			}
			if (!s.empty())
			{
				q.push(s);
				s.clear();
			}
			if (a == '\n')
				break;
		}
		if ((flag) || (!flag && a != ' ' && a != '>'))
			s.append(1, a);
	}
	
	flag = false;
	while (!q.empty())
	{
		s = q.front();
		if (s[0] == '<')
		{
			cout << s;
			flag = false;
		}
		else
		{
			if (flag)
				cout << " ";
			for (std::string::reverse_iterator it = s.rbegin(); it != s.rend(); it++)
				cout << *it;
			flag = true;
		}
		q.pop();
	}
	cout << endl;

	return 0;
}