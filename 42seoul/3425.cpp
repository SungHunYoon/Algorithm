#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <climits>
#include <algorithm>

using namespace std;

stack<int> stk;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	while (1)
	{
		string cmd;
		vector<pair<string, int>> cmds;
		while (getline(cin, cmd))
		{
			if (cmd == "QUIT")
				return 0;
			else if (cmd == "")
			{
				cmds.clear();
				continue;
			}
			else if (cmd == "END")
				break;
			else if (cmd.find("NUM") != std::string::npos)
				cmds.push_back({"NUM", stoi(cmd.substr(cmd.find(" ") + 1))});
			else
				cmds.push_back({cmd, 0});
		}
		// cout << "-------------------\n";
		// for (int i = 0; i < cmds.size(); i++)
		// 	cout << cmds[i].first << " " << cmds[i].second << '\n';
		int N;
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			bool flag = true;
			int num;
			cin >> num;
			stk.push(num);
			for (int j = 0; j < cmds.size(); j++)
			{
				if (cmds[j].first == "NUM")
				{
					if (abs(cmds[j].second) > 1000000000)
					{
						flag = false;
						break;
					}
					stk.push(cmds[j].second);
				}
				else if (cmds[j].first == "POP")
				{
					if (stk.empty())
					{
						flag = false;
						break;
					}
					stk.pop();
				}
				else if (cmds[j].first == "INV")
				{
					if (stk.empty())
					{
						flag = false;
						break;
					}
					int top = stk.top();
					stk.pop();
					top *= -1;
					stk.push(top);
				}
				else if (cmds[j].first == "DUP")
				{
					if (stk.empty())
					{
						flag = false;
						break;
					}
					stk.push(stk.top());
				}
				else if (cmds[j].first == "SWP")
				{
					int tmp1;
					int tmp2;

					if (stk.empty())
					{
						flag = false;
						break;
					}
					tmp1 = stk.top(); stk.pop();
					if (stk.empty())
					{
						flag = false;
						break;
					}
					tmp2 = stk.top(); stk.pop();
					stk.push(tmp1);
					stk.push(tmp2);
				}
				else if (cmds[j].first == "ADD")
				{
					long long tmp1;
					long long tmp2;
					long long tmp3;
					
					if (stk.empty())
					{
						flag = false;
						break;
					}
					tmp1 = stk.top(); stk.pop();
					if (stk.empty())
					{
						flag = false;
						break;
					}
					tmp2 = stk.top(); stk.pop();
					tmp3 = tmp2 + tmp1;
					if (abs(tmp3) > 1000000000)
					{
						flag = false;
						break;
					}
					stk.push(tmp3);
				}
				else if (cmds[j].first == "SUB")
				{
					long long tmp1;
					long long tmp2;
					long long tmp3;

					if (stk.empty())
					{
						flag = false;
						break;
					}
					tmp1 = stk.top(); stk.pop();
					if (stk.empty())
					{
						flag = false;
						break;
					}
					tmp2 = stk.top(); stk.pop();
					tmp3 = tmp2 - tmp1;
					if (abs(tmp3) > 1000000000)
					{
						flag = false;
						break;
					}
					stk.push(tmp3);
				}
				else if (cmds[j].first == "MUL")
				{
					long long tmp1;
					long long tmp2;
					long long tmp3;

					if (stk.empty())
					{
						flag = false;
						break;
					}
					tmp1 = stk.top(); stk.pop();
					if (stk.empty())
					{
						flag = false;
						break;
					}
					tmp2 = stk.top(); stk.pop();
					tmp3 = tmp2 * tmp1;
					if (abs(tmp3) > 1000000000)
					{
						flag = false;
						break;
					}
					stk.push(tmp3);
				}
				else if (cmds[j].first == "DIV")
				{
					long long tmp1;
					long long tmp2;
					long long tmp3;
					int div = 1;

					if (stk.empty())
					{
						flag = false;
						break;
					}
					tmp1 = stk.top(); stk.pop();
					if (stk.empty())
					{
						flag = false;
						break;
					}
					tmp2 = stk.top(); stk.pop();
					if (tmp1 < 0)
						div *= -1;
					if (tmp2 < 0)
						div *= -1;
					if (tmp1 == 0)
					{
						flag = false;
						break;
					}
					tmp3 = (abs(tmp2) / abs(tmp1)) * div;
					if (abs(tmp3) > 1000000000)
					{
						flag = false;
						break;
					}
					stk.push(tmp3);
				}
				else if (cmds[j].first == "MOD")
				{
					long long tmp1;
					long long tmp2;
					long long tmp3;
					int mod = 1;

					if (stk.empty())
					{
						flag = false;
						break;
					}
					tmp1 = stk.top(); stk.pop();
					if (stk.empty())
					{
						flag = false;
						break;
					}
					tmp2 = stk.top(); stk.pop();
					if (tmp2 < 0)
						mod *= -1;
					if (tmp1 == 0)
					{
						flag = false;
						break;
					}
					tmp3 = (abs(tmp2) % abs(tmp1)) * mod;
					if (abs(tmp3) > 1000000000)
					{
						flag = false;
						break;
					}
					stk.push(tmp3);
				}
			}
			if (stk.size() == 1 && flag)
				cout << stk.top() << '\n';
			else
				cout << "ERROR\n";
			while (!stk.empty())
				stk.pop();
		}
		cout << '\n';
	}

	return 0;
}