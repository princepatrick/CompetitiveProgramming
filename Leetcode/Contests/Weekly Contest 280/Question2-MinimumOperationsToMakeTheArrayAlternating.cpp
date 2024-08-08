/*
	Status in the contest: Solved on own 
	Approach:
	The approach is simple - create a frequency map for the odd and even digits
	Idea is - the minimum alteration for a digit 'x' in odd digit places are 
			the number of digits other than 'x' in the odd digit places - sum of other digits - number of 'x' in odd places
			Find highest occurring digit in even place other than 'x' lets say 'y' and find the number of total occurrence of all digits - 'y' in even places
	
	We use map<int, int> to store frequency maps
	We use a priority queue to find the highest frequency element in the even digit places
*/

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        map<int, int> mOdd;
        map<int, int> mEven;

        if( nums.size() <= 1 ) return 0;

        for( int i=0 ; i<nums.size() ; i++ ){
            int num = nums[i];

            if( i%2 == 0 ){
                if( mEven.find(num) == mEven.end() ){
                    mEven.insert({num, 1});
                } else {
                    auto itr = mEven.find(num);
                    itr->second = itr->second + 1;
                }
            } else {
                if( mOdd.find(num) == mOdd.end() ){
                    mOdd.insert({num, 1});
                } else {
                    auto itr = mOdd.find(num);
                    itr->second = itr->second + 1;
                }
            }
        }

        int sz = nums.size();
        int oddPlaces = sz / 2;
        int evenPlaces = (sz / 2) + ( sz % 2 );

        priority_queue< pair<int, int>, vector<pair<int, int>> > pqEven;

        for( auto itr = mEven.begin() ; itr != mEven.end() ; itr++ ){
            pair<int, int> p = make_pair( itr->second, itr->first );
            pqEven.push(p);
        }

        int ans = 10000000;

        for( auto itr = mOdd.begin() ; itr != mOdd.end() ; itr++ ){
            int num = itr->first;
            int freq = itr->second;

            int oddChange = 10000000, evenChange = 10000000;

            oddChange =  oddPlaces - freq ;

            queue<pair<int, int>> q;

            while( !pqEven.empty() ){
                pair<int, int> topEle = pqEven.top();
                pqEven.pop();
                q.push(topEle);
                if( topEle.second != num ){
                    evenChange = evenPlaces - topEle.first;
                    ans = min( ans, oddChange + evenChange );
                    break;
                }
            }

            while( !q.empty() ){
                pair<int, int> p = q.front();
                q.pop();
                pqEven.push(p);
            }
            
            
        }

        if( ans >= 10000000  ){
            return oddPlaces;
        }

        return ans;

    }
};