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

void pattern3( int n ){

    for( int i=0 ; i<n ; i++ ){
        for( int j=0 ; j<n ; j++ ){
            if( i<=j ){
                std::cout<<"*";
            }
        }
        std::cout<<std::endl;
    }

}

void pattern4( int n ){

    for( int i=0 ; i<n ; i++ ){
        for( int j=0 ; j<n; j++ ){
            if( j<= i ){
                std::cout<<j+1;
            }
        }

        std::cout<<std::endl;
    }

}

void pattern5( int n ){

    for( int i=0 ; i<2*n-1 ; i++ ){
        int ind = i >= n ? 2*n-2-i : i+1;

        for( int j=0 ; j<n ; j++ ){
            while( ind>0 ){
                std::cout<<"*";
                ind--;
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

    std::cout<<"Pattern 3"<<std::endl;
    pattern3(n);

    std::cout<<"Pattern 4"<<std::endl;
    pattern4(n);

    std::cout<<"Pattern 5"<<std::endl;
    pattern5(n);

}
