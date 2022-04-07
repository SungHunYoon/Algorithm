#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    
    sort(lottos.begin(), lottos.end());
    sort(win_nums.begin(), win_nums.end());
    
    int cnt = 0;
    int zero = 0;
    for(int i = 0; i < lottos.size(); i++)
    {
        if(lottos[i] != 0)
        {
            for(int j = 0; j < win_nums.size(); j++)
            {
                if(lottos[i] == win_nums[j])
                {
                    cnt += 1;
                }
            }
        }
        else
        {
            zero += 1;
        }
    }
    
    answer.push_back(6 - (zero + cnt) < 5 ? 7-(zero + cnt) : 6);
    answer.push_back(6 - cnt < 5 ? 7 - cnt : 6);
    
    return answer;
}