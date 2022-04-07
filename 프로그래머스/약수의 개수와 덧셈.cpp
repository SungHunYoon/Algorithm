#include <string>
#include <vector>
#include <cmath>

using namespace std;

int primeNumber(int number)
{
    int cnt = 0;
    
	for (int i = 1; i <= number; i++)
    {
		if (number % i == 0)
		{
			cnt++;
			//if (i != number / i) temp.push_back(number / i);
		}
    }
    
    return cnt;
}

int solution(int left, int right) {
    int answer = 0;
    
    for(int i = left; i <= right; i++)
    {
        int temp = primeNumber(i);
        
        if(temp % 2 == 0)
        {
            answer += i;
        }
        else
        {
            answer -= i;
        }
    }
    
    return answer;
}