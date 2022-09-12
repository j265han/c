#include <iostream>


int falling_factorial( int n, int k ) {
 if ( k < 0 ) {
 return 0;
 } else {
 int result{1};
 for ( int i{n}; i >= n - k + 1; --i ) {
 result *= i;
 }
 return result;
 }
}
int factorial( int n ) {
 return falling_factorial( n, n );
}
int main();
int factorial( int n );
int falling_factorial( int n, int k );

int main() {
 std::cout << falling_factorial( 7, 0 ) << " = 1" << std::endl;
 std::cout << falling_factorial( 7, 1 ) << " = 5" << std::endl;
 std::cout << falling_factorial( 7, 2 ) << " = 20" << std::endl;
 std::cout << falling_factorial( 7, 3 ) << " = 60" << std::endl;
 std::cout << falling_factorial( 7, 4 ) << " = 120" << std::endl;
 std::cout << falling_factorial( 7, 5 ) << " = 120" << std::endl;
 std::cout << falling_factorial( 7, 6 ) << " = 0" << std::endl;
 return 0;
}
