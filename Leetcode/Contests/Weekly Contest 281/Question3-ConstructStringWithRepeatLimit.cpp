/*
	Status in the contest: Solved the question on own
	Approach:
	I am not sure if this is the optimal approach.
	I collected the frequency of all characters, iterating through the string
	we find the number of characters, whenever we add a character to the result string we decrement a value in the number of characters .
	We run the loop until this number of character variable > 0
	As we need lexicographically largest,
		We iterate from i = 25 to i = 0
		Whenever the freq[i] <= repeatLimit we simply create a string s of lenght freq[i] with the character (char) i + 'a' and append the string sb_type
		When the freq[i] > repeatLimit then we only create a string of lenght repeatLimit with corresponding character.
			Now the character with higher lexicographical value is still not completed so we need to add 1 character with next lexicographical value and continue back to the previous step
		

*/

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        
        vector<int> freq( 26, 0 );
        int numChars = s.length();

        for( int i=0 ; i<s.length() ; i++ ){
            freq[s[i]-'a']++;
        }

        string ans = "";

        while( numChars > 0 ){
            bool greaterValue = false;

            for( int i=25 ; i>=0 ; i-- ){
                int frequency = freq[i];

                if( frequency == 0 ) continue;

                //cout<<frequency<<" "<<repeatLimit<<endl;

                if( greaterValue ){
                    frequency = 1;
                    string s(1, (char) 'a' + i );
                    ans.append( s );
                    freq[i]--;
                    numChars--;
                    break;
                } else if( frequency > repeatLimit ){
                    frequency = repeatLimit;
                    greaterValue = true;
                } 

                if( freq[i] == numChars ){
                    string s(frequency, (char) 'a' + i );
                    ans.append( s );
                    numChars = 0;
                    break;
                }

                freq[i] -= frequency;
                numChars -= frequency;

                string s(frequency, (char) 'a' + i );
                ans.append( s );
            }
        }

        return ans;
    }
};