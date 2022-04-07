#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    
    int i = 0;
    while(i < absolutes.size())
    {
        int temp = 0;
        
        if(signs[i])
        {
            temp = absolutes[i];
        }
        else
        {
            temp = -1 * absolutes[i];
        }
        
        answer += temp;
        i++;
    }
    
    return answer;
}