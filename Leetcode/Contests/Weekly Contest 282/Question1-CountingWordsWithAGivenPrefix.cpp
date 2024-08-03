/*
	Status in the contest: Solved on own - referred some syntax for trie in GFG
	Approach:
	The problem could be solved in brute force or simpler approach but felt to attempt Trie as it was optimal.
	The trie implementation was straightforward implementation of the problem
	The "prefix" is added into the Trie
	Each word is iterated in the Trie to check if the prefix exists in the word 
		If it exists we increase the counter
	Return the counter

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