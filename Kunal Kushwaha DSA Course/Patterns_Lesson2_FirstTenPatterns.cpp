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

void pattern6( int n ){

    for( int i=0 ; i<n ; i++ ){
        int ind = n-1-i;
        while( ind > 0 ){
            std::cout<<" ";
            ind--;
            continue;
        }

        ind = i+1;

        while( ind>0 ){
            std::cout<<"*";
            ind--;
        }
        
        std::cout<<std::endl;
    }

}

void pattern7(int n){

    for( int i=0 ; i<n ; i++ ){
        for( int j=0 ; j<n; j++ ){
            if( j >= i ){
                std::cout<<"*";
            } else {
                std::cout<<" ";
            }
        }
        std::cout<<std::endl;
    }
}

void pattern8( int n ){

    for( int i=0 ; i<n ; i++ ){
        for( int j=0 ; j<2*n-1 ; j++ ){
            if( j >= n-1-i && j <= n-1+i ){
                std::cout<<"*";
            }else{
                std::cout<<" ";
            }
        }
        std::cout<<std::endl;
    }

}

void pattern9( int n ){

    for( int i=0 ; i<n ; i++ ){
        for( int j=0 ; j<2*n-1 ; j++ ){
            if( j >= i && j < 2*n-1-i ){
                std::cout<<"*";
            }else{
                std::cout<<" ";
            }
        }
        std::cout<<std::endl;
    }
}

void pattern10( int n ){
    
    for( int i=0 ; i<n ; i++ ){
        for( int j=0 ; j<2*n-1 ; j++ ){
            if( j>=n-1-i && j<=n-1+i ){
                if( (n%2==1 && i%2 == j%2) || (n%2==0 && i%2 != j%2) )
                    std::cout<<"*";
                else
                std::cout<<" "; 
            } else {
                std::cout<<" ";
            }
        }
        std::cout<<std::endl;
    }
    
}

void pattern11( int n ){

    for( int i=0 ; i<n ; i++ ){
        for( int j=0 ; j<2*n-1 ; j++ ){
            if( j>=i && j<= 2*n-1-i){
                if( ( n%2 != 0 && j%2 == i%2 ) || ( n%2 == 0 && j%2 != i%2 ) )
                    std::cout<<"*";
                else
                    std::cout<<" ";
            }else{
                std::cout<<" ";
            }
        } 
        std::cout<<std::endl;
    }

}

void pattern12( int n ){

    for( int i=0 ; i<2*n ; i++ ){
        for( int j=0 ; j<2*n-1 ; j++ ){
            if( i<n ){
                if( j >= i && j <= 2*n-1-i ){
                    if( (n%2 != 0 && i%2==j%2) || ( n%2 == 0 && i%2 != j%2 ) )
                        std::cout<<"*";
                    else
                        std::cout<<" ";
                } else {
                    std::cout<<" ";
                }
            } else {
                if( j >= 2*n-1-i && j <= i-1 ){
                    if( (n%2 != 0 && i%2!=j%2) || ( n%2 == 0 && i%2 == j%2 ) )
                        std::cout<<"*";
                    else
                        std::cout<<" ";
                } else {
                    std::cout<<" ";
                }
            }
        }
        std::cout<<std::endl;
    }

}

void pattern13( int n ){

    for( int i=0 ; i<n ; i++ ){
        for( int j=0 ; j<2*n-1 ; j++ ){
            if( i== n-1 ){
                std::cout<<"*";
            } else if( j==n-1-i || j==n-1+i ){
                std::cout<<"*";
            }else{
                std::cout<<" ";
            }
        }
        std::cout<<" "<<std::endl;
    }

}

void pattern14( int n ){

    for( int i=0 ; i<n ; i++ ){
        for( int j=0 ; j<2*n-1 ; j++ ){
            if( i== 0 ){
                std::cout<<"*";
            } else if( j==i || j==2*n-2-i ){
                std::cout<<"*";
            } else {
                std::cout<<" ";
            }
        }
        std::cout<<std::endl;
    }

}

void pattern15( int n ){

    for( int i=0 ; i<2*n-1 ; i++ ){
        for( int j=0 ; j<2*n-1 ; j++ ){
            if( i<n ){
                if( j==n-1-i || j==n-1+i ){
                    std::cout<<"*";
                } else {
                    std::cout<<" ";
                }
            } else {
                if( j==i-n+1 || j==3*n-3-i ){
                    std::cout<<"*";
                }else{
                    std::cout<<" ";
                }
            }
        }
        std::cout<<std::endl;
    }

}

void pattern16( int n ){

    for( int i=0 ; i<n ; i++ ){
        int val = 1;
        for( int j=0 ; j<2*n-1 ; j++ ){
            if( j>=n-1-i && j<=n-1+i ){
                if( (n%2!=0 && i%2==j%2) || (n%2==0 && i%2!=j%2) ){
                    std::cout<<val;
                    
                    if( (n%2!=0 && i%2==0) || (n%2==0 && i%2==0))
                        j<n-1 ? val++ : val--;
                    else if(j<n-2){
                        val++;
                    } else if(j>n-1){
                        val--;
                    } 
                } else {
                    std::cout<<" ";
                }
            } else {
                std::cout<<" ";
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

    std::cout<<"Pattern 6"<<std::endl;
    pattern6(n);

    std::cout<<"Pattern 7"<<std::endl;
    pattern7(n);

    std::cout<<"Pattern 8"<<std::endl;
    pattern8(n);

    std::cout<<"Pattern 9"<<std::endl;
    pattern9(n);

    std::cout<<"Pattern 10"<<std::endl;
    pattern10(n);

    std::cout<<"Pattern 11"<<std::endl;
    pattern11(n);

    std::cout<<"Pattern 12"<<std::endl;
    pattern12(n);

    std::cout<<"Pattern 13"<<std::endl;
    pattern13(n);

    std::cout<<"Pattern 14"<<std::endl;
    pattern14(n);

    std::cout<<"Pattern 15"<<std::endl;
    pattern15(n);

    std::cout<<"Pattern 16"<<std::endl;
    pattern16(n);

}
