class Disjointset{
    vector<int> parent, size;
    
    public:
        Disjointset( int n ){
            parent.resize(n+1);
            size.resize(n+1, 0);
            
            for( int i=0 ; i<n ; i++ ){
                parent[i] = i;
            }
        }
        
        int findUltParent( int node ){
            if( node == parent[node] ){
                return node;
            }
            
            return parent[node] = findUltParent(parent[node]);
        }
        
        int unionBySize( int u, int v ){
            int ultU = findUltParent(u);
            int ultV = findUltParent(v);
            
            if( ultU == ultV ){
                return 1;
            }
            
            if( size[ultU] < size[ultV] ){
                parent[ultU] = ultV;
                size[ultV] += size[ultU];
            } else {
                parent[ultV] = ultU;
                size[ultU] += size[ultV];
            }

            return 0;
        }
        
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& edge) {
        int m = edge.size();
        //if( n - m > 1 ) return -1;
        
        Disjointset ds(n);
        int extra = 0;
        for( int i=0 ; i<edge.size() ; i++ ){
            int src = edge[i][0];
            int dest = edge[i][1];
            
            extra += ds.unionBySize(src, dest);
        }
        
        int count = 0;
        
        for( int i=0 ; i<n ; i++ ){
            if( ds.findUltParent(i) == i ){
                count++;
            }
        }

        cout<<extra<<" "<<count<<endl;
        
        if( extra >= count-1 ) return count-1;
        return -1;
    }
};