/*
	Status in the contest: Solved on own 
	Approach:
		If n1 == n2:
			return 0 //As n1 = n1 - n2 or n2 = n2 - n1 is 0 
		If n1 > n2:
			then n1 = n1 - n2 and find how many ops needed
		If n2 > n1:
			then n2 = n2 - n1 and find how many ops needed

*/

class Solution {
public:
    int findNumOps( int n1, int n2 ){
        if( n1 == n2 ){
            return 1;
        }

        if( n1 > n2 ){
            return 1 + findNumOps( n1-n2, n2 );
        }

        return 1 + findNumOps( n1, n2-n1 );
    }
    int countOperations(int num1, int num2) {
        if( num1 == 0 || num2 == 0 ) return 0;
        
        return findNumOps( num1, num2 );
    }
};