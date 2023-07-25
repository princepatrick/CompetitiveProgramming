class Solution {
public:
    int dijkstra( int src, vector<pair<int, int>> adj[], int n, int threshold ){
        vector<int> distance(n, 1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        distance[src] = 0;

        while( !pq.empty() ){
            int node = pq.top().second;
            int parentDist = pq.top().first;
            pq.pop();

            for( auto adjNode : adj[node] ){
                int adjacentNode = adjNode.first;
                int adjDist = adjNode.second;

                if( parentDist + adjDist < distance[adjacentNode] ){
                    distance[adjacentNode] = parentDist + adjDist;
                    pq.push({distance[adjacentNode], adjacentNode});
                }
            }
        }

        int count = 0;
        for( int i=0 ; i<n ; i++ ){
            if( distance[i] <= threshold && i != src ){
                count++;
            }
        }

        return count;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<pair<int, int>> adj[n];
 
        for( int i=0 ; i<edges.size() ; i++ ){
            int src = edges[i][0];
            int dest = edges[i][1];
            int wt = edges[i][2];
            adj[src].push_back(make_pair(dest, wt));
            adj[dest].push_back(make_pair(src, wt));
        }

        int mini = INT_MAX;
        int result = 0;
        for( int i=0 ; i<n ; i++ ){
            int findCitiesUnderThreshold = dijkstra( i, adj, n, distanceThreshold );
            cout<<findCitiesUnderThreshold<<endl;
            if( findCitiesUnderThreshold < mini ){
                mini = findCitiesUnderThreshold;
                result = i;
            } else if( findCitiesUnderThreshold == mini ){
                result = i;
            }
        }

        return result;

    }
};