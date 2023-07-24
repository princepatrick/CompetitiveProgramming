//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        int row = heights.size();
        int col = heights[0].size();
        vector<vector<int>> distance(row, vector<int>(col, 1e9));
        
        queue<pair<int, pair<int, int>>> q;
        
        q.push({0, {0, 0}});
        int delRow[] = { -1, 0, 1, 0};
        int delCol[] = { 0, 1, 0, -1};
        distance[0][0] = 0;
        
        while( !q.empty() ){
            int diff = q.front().first;
            int cr = q.front().second.first;
            int cc = q.front().second.second;
            q.pop();
            
            for( int i=0 ; i<4 ; i++ ){
                int adjRow = cr + delRow[i];
                int adjCol = cc + delCol[i];
                
                if( adjRow>=0 && adjRow < row && adjCol >= 0 && adjCol < col &&
                    max(abs( heights[cr][cc] - heights[adjRow][adjCol] ), diff) < distance[adjRow][adjCol]){
                        distance[adjRow][adjCol] = max(abs( heights[cr][cc] - heights[adjRow][adjCol] ), diff);
                        //distance[adjRow][adjCol] = abs( heights[cr][cc] - heights[adjRow][adjCol] );
                        q.push({max(distance[adjRow][adjCol], diff), {adjRow, adjCol}});
                    }
            }
            
        }
        
        if( distance[row-1][col-1] == 1e9 ) return -1;
        return distance[row-1][col-1];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends