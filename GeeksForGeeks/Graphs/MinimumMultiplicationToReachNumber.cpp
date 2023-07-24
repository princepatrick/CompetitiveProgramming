//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        queue<pair<int, int>> q;
        vector<int> value(100000, 1e9);
        q.push({0, start});
        value[start] = 0;
        
        if( start == end ) return 0;
        
        while( !q.empty() ){
            int numSteps = q.front().first;
            int number = q.front().second;
            q.pop();
            
            for( int i=0 ; i<arr.size() ; i++ ){
                int newNumber = (number * arr[i]);
                newNumber = newNumber % 100000;
                if( newNumber == end ) return numSteps + 1;
                if( numSteps + 1 < value[newNumber]  ){
                    value[newNumber] = numSteps + 1;
                    q.push({numSteps+1, newNumber});
                }
            }
        }
        
        
        return -1;
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends