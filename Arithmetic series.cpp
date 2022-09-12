#include <iostream>

double arithmetic( double a, double d, int n ) {
 if ( n < 0 ) {
 return 0.0;
 } else {
 double sum{0.0};
 for ( int k{0}; k <= n; ++k ) {
 sum += a + k*d;
 }
 return sum;
 }
}

int main();
double arithmetic( double a, double d, int n );
// Function definitions
int main() {
 std::cout << arithmetic( 1.5, 0.8, 6 ) << " = 27.3" << std::endl;
 std::cout << arithmetic( 7.8, -1.2, 10 ) << " = 19.8" << std::endl;
 std::cout << arithmetic( 2.4, 0.0, 10 ) << " = " << (11*2.4)
 << std::endl;
 std::cout << arithmetic( 2.4, 9.5, 0 ) << " = 2.4" << std::endl;
 std::cout << arithmetic( 2.4, 9.5, -1 ) << " = 0" << std::endl;
 return 0;
}