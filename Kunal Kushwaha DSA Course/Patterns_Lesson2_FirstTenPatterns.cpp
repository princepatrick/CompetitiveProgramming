#include<bits/stdc++.h>

void pattern1(int n){

    for( int i=0 ; i<n ; i++ ){
        for( int j=0 ; j<n; j++){
            std::cout<<"*";
        }
        std::cout<<std::endl;
    }

}

void pattern2( int n ){
    
    for( int i=0 ; i<n; i++ ){
        for( int j=0 ; j<n ; j++ ){
            if( j<=i ){
                std::cout<<"*";
            }
        }
        std::cout<<std::endl;
    }
}

int main(){
    int n;
    std::cout<<"Enter the size for which you want the pattern to be printed"<<std::endl;
    std::cin>>n;

    std::cout<<"Pattern 1"<<std::endl;
    pattern1(n);

    std::cout<<"Pattern 2"<<std::endl;
    pattern2(n);
}
