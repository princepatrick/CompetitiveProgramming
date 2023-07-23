//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<pair<int, int>> adj[n+1];
        vector<int> result;
        
        for( int i=0 ; i<m ; i++ ){
            int e1 = edges[i][0];
            int e2 = edges[i][1];
            int wt = edges[i][2];
            adj[e1].push_back(make_pair(e2, wt));
            adj[e2].push_back(make_pair(e1, wt));
        }
        
        vector<int> distance(n+1, 1e9);
        
        distance[1] = 0;
        
        vector<int> parent( n+1, 0);
        
        for( int i=1 ; i<=n ; i++ ){
            parent[i] = i;
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>> > q;
        
        q.push({0, 1});
        
        while( !q.empty() ){
            int weight = q.top().first;
            int node = q.top().second;
            q.pop();
            
            for( auto adjNode : adj[node] ) {
                int dest = adjNode.first;
                int localWeight = adjNode.second;
                
                if( weight + localWeight < distance[dest] ){
                    distance[dest] = weight + localWeight;
                    q.push({distance[dest], dest});
                    parent[dest] = node;
                }
            }
        }
        
        int node = n;
        
        while( parent[node] != node ){
            result.push_back(node);
            node = parent[node];
        }
        
        result.push_back(node);
        
        reverse( result.begin(), result.end());
        
        if( result.size() == 1 && n != 1 ) return {-1};
        
        return result;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends