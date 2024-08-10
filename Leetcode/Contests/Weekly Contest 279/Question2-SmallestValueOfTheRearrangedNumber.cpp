/*
	Status in the contest: Solved on own 
	Approach:
	There are two scenarios:
		Positive Number: 
			There should be no trailing 0s
			The numbers  0 0 0 3 2 1 0 2
			The number is stored in vector and sort it
			Valid Number 1 0 0 0 0 2 2 3
			We need to find the smallest number
		Negative Number:
			Num = - (Negative Number)
			We need to find the greatest number
			The numbers  0 0 0 3 2 1 0 2
			The number is stored in vector and sort it decreasing order
			Valid Number 3 2 2 1 0 0 0 0
			
*/

class Solution {
public:
    long long findMinNum( long long num ){
        vector<long long> nums;

        while( num > 0 ){
            long long dig = num % 10;
            nums.push_back(dig);
            num = num / 10;
        }

        sort( nums.begin(), nums.end() );

        int i = 0;

        while( i < nums.size() && nums[i] == 0 ){
            if( nums[i] == 0 ) i++;
        }

        if( i > 0 ){
            long long temp = nums[i];
            nums[i] = nums[0];
            nums[0] = temp;
        }

        long long number = 0;

        for( int i=0 ; i<nums.size() ; i++ ){
            long long dig = nums[i];
            number = (number * 10) + dig;
        }
        
        return number;

    }

    long long findMaxNum( long long num ){
        
        
        num = -num;

        vector<long long> nums;

        int cntZero = 0;

        while( num > 0 ){
            long long dig = num % 10;
            if( dig == 0 ) cntZero++;
            nums.push_back(dig);
            num = num / 10;
        }

        sort( nums.begin(), nums.end(), greater<int>() );

        long long number = 0;

        for( int i=0 ; i<nums.size() ; i++ ){
            long long dig = nums[i];
            number = (number * 10) + dig;
        }

        return (-number);

    }

    long long smallestNumber(long long num) {
        
        if( num == 0 ){
            return 0;
        } else if( num > 0 ){
            return findMinNum( num );
        } else {
            return findMaxNum( num );
        }

        return 0;
        
    }
};