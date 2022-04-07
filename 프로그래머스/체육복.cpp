#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
	for( vector<int>::iterator lost_it = lost.begin(); lost_it < lost.end(); )
	{
		int lost_num = *lost_it;
		int isErase = 0;
		for( vector<int>::iterator reserve_it = reserve.begin(); reserve_it < reserve.end(); )
		{
			int reserve_num = *reserve_it;
			if( lost_num == reserve_num )
			{
				isErase = 1;
				lost_it = lost.erase( lost_it );
				reserve_it = reserve.erase( reserve_it );

                
            }
			else
			{
				reserve_it++;
			}
		}
		
		if( isErase == 1 )
		{
			isErase = 0;
		}
		else
		{
			lost_it++;
		}
	}
	
    answer = n - lost.size();
    
    return answer;
}