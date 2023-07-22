class Solution {
public:
    void findDfs( string word, int currOperLevel, vector<string>& words, 
        vector<vector<string>>& ans, map<string, int>& m, string beginWord ){
        
        if( word == beginWord ){
            ans.push_back(words);
            return;
        }
        
        for( int i=0 ; i<word.size() ; i++ ){
            string copyWord = word;
            for( char ch='a' ; ch<='z' ; ch++ ){
                copyWord[i] = ch;
                if( m.find( copyWord ) != m.end() ){
                    int operations = m.find(copyWord)->second;
                    if( operations + 1 == currOperLevel ){
                        words.push_back(copyWord);
                        findDfs( copyWord, operations, words, ans, m, beginWord );
                        words.pop_back();
                    }
                }
            }
        }
        
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        queue<pair<string, int>> q;
        map<string, int> m;
        set<string> s;
        
        for( int i=0 ; i<wordList.size() ; i++ ){
            s.insert(wordList[i]);
        }
        
        q.push({beginWord, 1});
        m.insert({beginWord, 1});
        int minOper = INT_MAX;
        
        while( !q.empty() ){
            string currWord = q.front().first;
            int currOper = q.front().second;
            
            if( currWord == endWord )
                minOper = min( minOper, currOper);
                
            q.pop();
            
            for( int i=0 ; i<currWord.size() ; i++ ){
                string copyWord = currWord;
                for( int j=0 ; j<26 ; j++ ){
                    copyWord[i] = (char)( j+ 'a');
                    if( s.find(copyWord) != s.end() ){
                        s.erase(s.find(copyWord));
                        int numOper = currOper + 1;
                        q.push({copyWord, numOper});
                        m.insert({copyWord, numOper});
                    }
                }
            }
            
        }
        
        vector<string> temp;
        temp.push_back(endWord);
        
        findDfs( endWord, minOper, temp, ans, m, beginWord );
        
        for( int i=0 ;i<ans.size() ; i++ ){
            reverse( ans[i].begin(), ans[i].end() );
        }
        
        
        return ans;
    }
};