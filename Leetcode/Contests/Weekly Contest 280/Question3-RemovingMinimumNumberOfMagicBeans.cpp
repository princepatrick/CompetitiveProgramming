/*
	Status in the contest: Upsolved
	Approach:
	The approach is to sort the array
	We find the total sum of elements in the array in the right side of the pointer
	sum = Sum of all elements to the right from the current pointer
	offset = sum of all the lower elements to the left of the traversing pointer
	offsetCount = a count of all the elements to the left including current element that has the same value
	
	Then we travese from left to right -
		At each element - that is the lowest of the element we have remaining in the array
		The previous lower elements are added to the offset, if the previous element is same, then we use a offsetCount to keep track of the elements with the same value as they need not be addded to the offset that is dedicatedly for the lower value elements in the left side of hte traversing pointer
		The sum is removed from each traversing element as we only maintain to the right side of the pointer
		

*/

class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort( beans.begin(), beans.end() );

        long long sum = 0, offset = 0, offsetCnt = 1;

        for( int i=0 ; i<beans.size() ; i++ ){
            sum += (long long) beans[i];
        }

        long long ans = 1e14;

        for( int i=0 ; i<beans.size() ; i++ ){
            long long val = (beans.size() - i) * (long long) beans[i];
            long long locAns = sum - val + offset;

            if( locAns < ans ){
                ans = locAns;
            }

            if( i < beans.size() - 1 && beans[i+1] > beans[i] ){
                offset += (long long) beans[i] * offsetCnt;
                offsetCnt = 1;
            } else if( i < beans.size() - 1 ){
                offsetCnt++;
            } 

            sum -= beans[i];
        }

        return ans;
    
    }
};