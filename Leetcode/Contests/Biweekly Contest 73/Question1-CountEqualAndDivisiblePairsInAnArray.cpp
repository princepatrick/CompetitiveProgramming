/*
	Status in the contest: Solved on own 
	Approach:
	I solved in a naive manner
	Iterated through all valid pairs and checked the condition - nums[i] == nums[j] and ( i * j ) % k == 0

*/

class Solution {
public:
    int countPairs(vector<int>& nums, int k) {

        // // unordered_map<int ,vector<int>> m;
        // map<int, vector<int>> m

        // for( int i=0 ; i<nums.size() ; i++ ){
        //     if( m.find(nums[i]) == m.end() ){
        //         vector<int> arr;
        //         arr.push_back(i);
        //         m.insert({nums[i], arr});
        //     } else {
        //         auto itr = m.find(nums[i]);
        //         vector<int> arr = itr->second;
        //         arr.push_back(i);
        //         itr->second = arr;
        //     }
        // }

        // for( auto itr = m.begin() ; itr != m.end() ; itr++ ){
        //     vector<int> list = itr->second;
        //     for( int i=0 ;i)
        // }

        int count = 0;

        for( int i=0 ; i<nums.size() ; i++ ){
            for( int j=i+1 ; j<nums.size() ; j++ ){
                if( nums[i] == nums[j] && (( i * j ) % k) == 0 ){
                    count++;
                }
            }
        }

        return count;
                
    }
};