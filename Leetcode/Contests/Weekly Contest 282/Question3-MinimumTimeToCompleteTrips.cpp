/*
	Status in the contest: Did not solve - used the solution to upsolve the question
	Approach:
		The original intuition, I had was that linearly moving through all the scores and calculating the possibility, once you find the 1st value that meets the criteria - we return as the answer
		The original intution fails since - number of possible numbers - 10^7, number of terms - 10^5
		
		The alternate intution from the solutions :
			You are trying from numbers - 1, 2, 3, 4.... in a sorted order
			As we can see the order is sorted in nature, as a result we can actually try binary search instead of linearly search the number
			The approach is to use a limit of i = 1 and j = 1e14, and try till i < j, and run the binary search
				the general idea if let's say time = ans satisfies the equation then all [ans+1], [ans+2], etc also satisfies the equation
				and let's say time = ans does not satisfies the condition, then time = ans - 1, ans - 2 etc also do not satisfies the equation

*/

struct TrieNode{
    TrieNode* childNode[26];

    bool isWordEnd;

    TrieNode(){
        isWordEnd = false;

        for( int i=0 ; i<26 ; i++ ){
            childNode[i] = nullptr;
        }
    }
};

class Solution {
public:
    
    TrieNode* root;

    void insert( string word, TrieNode* root ){

        TrieNode* node = root;

        for( int i=0 ; i<word.length() ; i++ ){
            char ch = word[i];

            if( node->childNode[ch-'a'] == nullptr ){
                TrieNode* newNode = new TrieNode();

                node->childNode[ch-'a'] = newNode;
            }

            node = node->childNode[ch-'a'];
        }

        node->isWordEnd = true;

    }

    bool search( string word, TrieNode* root ){

        TrieNode* node = root;

        for( int i=0 ; i<word.length() ; i++ ){
            char ch = word[i];

            // cout<<"Checking for character "<<ch<<endl;

            // for( int i=0 ; i<26 ; i++ ){
            //     cout<<node->childNode[i]<<" ";
            // }

            // cout<<endl;

            if( node->childNode[ch-'a'] == nullptr ){
                return false;
            } else {
                node = node->childNode[ch-'a'];
            }

            if( node->isWordEnd ){ 
                // cout<<word<<endl;
                return true;
            }
        }

        // cout<<word<<endl;
        return node->isWordEnd;
    }

    int prefixCount(vector<string>& words, string pref) {

        root = new TrieNode();

        insert( pref, root );

        int count = 0;

        for( int i=0 ; i<words.size() ; i++ ){
            string word = words[i];

            if( search(word, root) ){
                count++;
            }
        }

        return count;
        
    }
};