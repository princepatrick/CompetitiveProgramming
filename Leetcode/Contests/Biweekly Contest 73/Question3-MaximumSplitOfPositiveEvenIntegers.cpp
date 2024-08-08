/*
	Status in the contest: Solved the question on own
	Approach:
	The problem could be solved greedily
	Lets say the val is 12 Start with the lowest even number - 2
		Find the remaining val = 12 - 10, 
			If the remaining > the current even val (2) 
				-> append the even val in to result
				-> increment val += 2 -> 4 and repeat
			Else -> append the remaining val into the result array		

*/

class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long> ans;

        if( finalSum % 2 ) return ans;

        long long val = 2;
        
        while( finalSum > 0 ){
            long long rem = finalSum - val;
            if( rem > val ){
                ans.push_back( val );
            } else {
                ans.push_back( finalSum );
                break;
            }
            val += 2;
            finalSum = rem;
        }

        return ans;

    }
};