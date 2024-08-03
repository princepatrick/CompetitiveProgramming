/*
	Status in the contest: Solved on own - referred some syntax for trie in GFG
	Approach:
		The solution is very simple
		Maintain two frequency counters for string s, and t
		Find the frequency of each character for the strings 
		For each index, find the minimum frequency occurrences and subtract the other occurrences from this min occurrence
		Get the total count of these occurrences and return it

*/

class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> freq1( 26, 0 );

        vector<int> freq2( 26, 0 );

        for( int i=0 ; i<s.length() ; i++ ){
            freq1[s[i] - 'a']++;
        }

        for( int i=0 ; i<t.length() ; i++ ){
            freq2[t[i] - 'a']++;
        }

        int ans = 0;

        for( int i=0 ; i<26 ; i++ ){
            int mini = min( freq1[i] , freq2[i] );
            ans += freq1[i] - mini + freq2[i] - mini;
        }

        return ans;
    }
};