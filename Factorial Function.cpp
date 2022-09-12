#include <iostream>

int factorial( int n );

int factorial( int n ) {
 if ( n < 0 ) {
 return 0;
 } else {
 int result{1};
 for ( int k{2}; k <= n; ++k ) {
 result *= k;
 }
 return result;
 }
}
int binomial( int n, int k ) {
 return factorial( n )/factorial( k )/factorial( n - k );
}

int main() {
 std::cout << factorial( -1 ) << std::endl;
 std::cout << factorial( 6 ) << std::endl;
 std::cout << factorial( 7 ) << std::endl;
 return 0;
}
