/*
	Status in the contest: not Solved on own - upsolved with https://leetcode.com/contest/weekly-contest-281/problems/count-array-pairs-divisible-by-k/description/
	Test case:
		arr = [ 1, 2, 3, 4, 5, 6 ]
		ind = [ 0, 1, 2, 3, 4, 5 ]
		k = 12
		Find: Number of product of pairs that is divisible by k
		Ans: (1, 5), (2, 3), (3, 5)
	Approach:
		Important note: GCD(a,b) is simply the multiplication of prime factors of numbers a and b
		using this principle: 
			To find number of product pairs between numbers a and b that is divisible by k
				CONDITION: GCD( a, k) * GCD( b, k) % k == 0
				We maintain a unordered_map [gcd_val, freq] with the gcd value and their frequency
					Whenever we find a pair (a, b) that meets the condition CONDITION, then we increment the answer by "freq"
*/



class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {

        long long pairs = 0;

        unordered_map<long long, long long> m;

        for( long long i = 0 ; i<nums.size() ; i++ ){
            
            long long curr_gcd = gcd(nums[i], k);

            for( auto& [ exist_gcd, freq ] : m ){
                if( (curr_gcd * exist_gcd) % k == 0 ){
                    pairs += freq;
                }
                
            }

            m[curr_gcd] += 1;
            
        }


        return pairs;
        
    }
};