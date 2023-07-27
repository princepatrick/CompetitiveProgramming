class Disjointset{
    public:
        vector<int> parent, size;

        Disjointset( int sz ){
            parent.resize(sz+1);
            size.resize(sz+1, 0);

            for( int i=0 ; i<sz ; i++ ){
                parent[i] = i;
            }
        }

        int findUltParent( int u ){
            if( u == parent[u] ){
                return u;
            }

            return parent[u] = findUltParent( parent[u] );
        }

        void unionBySize( int u, int v){
            int ultParU = findUltParent(u);
            int ultParV = findUltParent(v);

            if( ultParU == ultParV ){
                return;
            }

            if( size[ultParU] < size[ultParV] ){
                parent[ultParU] = ultParV;
                size[ultParV] += size[ultParU];
            } else {
                parent[ultParV] = ultParU;
                size[ultParU] += size[ultParV];
            }
        }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string, int> m;

        int accsz = accounts.size();

        vector<string> names(accsz);
        vector<vector<string>> emails(accsz), ans;
        Disjointset ds(accsz);

        for( int i=0 ; i<accsz ; i++ ){
            names[i] = accounts[i][0];
            for( int j=1 ; j<accounts[i].size() ; j++ ){
                string email = accounts[i][j];

                if( m.find(email) == m.end() ){
                    m.insert({email, i});
                } else {
                    int par = ds.findUltParent(m.find(email)->second);
                    int parI = ds.findUltParent(i);
                    if( parI != par ){
                        ds.unionBySize(par, parI);
                    }
                }
            }
        }

        for( auto mElem = m.begin() ; mElem != m.end() ; mElem++ ){
            int ultPar = ds.findUltParent(mElem->second);
            string email = mElem->first;
            emails[ultPar].push_back(email);
        }

        for( int i=0 ; i<accsz ; i++ ){
            sort(emails[i].begin(), emails[i].end());
        }

        for( int i=0 ; i<accsz ; i++ ){
            vector<string> temp;
            cout<<emails[i].size()<<endl;
            if( emails[i].size() > 0 ){
                temp.push_back(names[i]);
                temp.insert(temp.end(), emails[i].begin(), emails[i].end()); 
                ans.push_back(temp);
            }
        }

        return ans;
    }
};