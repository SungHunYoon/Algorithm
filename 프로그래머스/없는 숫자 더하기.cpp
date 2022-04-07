#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    bool bNumbers[10] = {0};
    
    for(int i = 0; i < numbers.size(); i++)
    {
        bNumbers[numbers[i]] = true;
    }
    
    for(int i = 0; i < 10; i++)
    {
        if(!bNumbers[i])
        {
            answer += i;
        }
    }
    
    return answer;
}