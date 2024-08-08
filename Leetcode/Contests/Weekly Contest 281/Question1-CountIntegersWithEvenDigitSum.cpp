/*
	Status in the contest: Solved on own 
	Approach:
	I solved in a naive manner
	Iterated through the valid range of values
	Calculated the sum of digits for each and when an even sum appears, I increment the sumDigits variable
	Return the sumDigits

*/

class Solution {
public:
    bool evenSum( int val ){
        int sumDigits = 0;

        while( val > 0 ){
            int dig = val % 10;
            val = val / 10;
            sumDigits += dig;
        }

        return (sumDigits % 2) == 0;
    }
    int countEven(int num) {
        
        int count = 0;

        for( int i=2 ; i<=num ; i++ ){
            if( evenSum( i ) ){
                count++;
            }
        }

        return count;
    }
};