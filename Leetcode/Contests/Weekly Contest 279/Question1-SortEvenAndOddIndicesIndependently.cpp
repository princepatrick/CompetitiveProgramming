/*
	Status in the contest: Solved on own 
	Approach:
		The digits at even indices need to be sorted in non-decreasing order
		The digits at odd indices need to be sorted in non-increasing order
		We use two lists - evenNums, and oddNums 
		We append the indices at specific index in the two vectors based on the lists and indices

*/

class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> evenNums;
        vector<int> oddNums;

        for( int i=0 ; i<nums.size() ; i++ ){
            int num = nums[i];
            if( i % 2 == 0 ){
                evenNums.push_back( num );
            } else {
                oddNums.push_back( num );
            }
        }

        sort( evenNums.begin(), evenNums.end() );
        sort( oddNums.begin(), oddNums.end(), greater<int>() );
        int a = 0 , b = 0;

        for( int i=0 ; i<nums.size() ; i++ ){
            if( i % 2 == 0 ){
                nums[i] = evenNums[a];
                a++;
            } else {
                nums[i] = oddNums[b];
                b++;
            }
        }

        return nums;
    }
};