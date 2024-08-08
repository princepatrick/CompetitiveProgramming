/*
	Status in the contest: Solved on own 
	Approach:
	The approach is simple - if the num is not divisible by 3, then no possible pairs are possible
	If it is divisible find the number val, and add the pairs val - 1, val , val + 1 in the exact order		

*/

class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        
        vector<long long> ans;

        if( num % 3 != 0 ) return ans;

        long long val = num / 3;

        ans.push_back( val - 1 );
        ans.push_back( val );
        ans.push_back( val + 1 );

        return ans;
    }
};