#include<iostream>
#include<vector>
using namespace std;

vector<int> subarraySum(vector<int>arr, int n, long long s) {
        // Your code here
        vector<int> result;
        int k=0;
        long long int sum = 0;
        
        for( int i=0 ; i<n ; i++ ){
            sum += arr[i];
            
            while( sum>s ){
                sum -= arr[k];
                k++;
            }
            
            if( sum == s && k<=i ){
                result.push_back(k+1);
                result.push_back(i+1);
                return result;
            }
            
        }
        
        result.push_back(-1);
        return result;
        
        
}

int main(){
    int n;
    long long s;

    // cin>>n>>s;
    // vector<int> arr;
    // cout<<n<<" "<<s;

    cout<<"Hello Prince"<<endl;

    // for( int i=0 ; i<n ; i++ ){
    //     cout<<"The index is "+i;
    //     cin>>arr[i];
    // }

    // vector<int> result = subarraySum(arr, n, s);

    // for( int i=0 ; i<result.size() ; i++ ){
    //     cout<<result[i]<<" ";
    // }
    cout<<endl;
}

