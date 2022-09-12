#include <iostream>
#include <cmath>

double geometric( double a, double r, int n ) {
 if ( n < 0 ) {
 return 0.0;
 } else {
 return a*(1.0 - std::pow( r, n + 1 ))/(1.0 - r);
 }
}
int main();
double arithmetic( double a, double d, int n );

int main() {
 std::cout << geometric( 7.8, 1.1, 4 ) << " = 47.61978" << std::endl;
 std::cout << geometric( 5.3, -1.5, 5 ) << " = -22.028125"
 << std::endl;

 std::cout << geometric( 2.4, 9.5, 0 ) << " = 2.4" << std::endl;
 std::cout << geometric( 2.4, 9.5, -1 ) << " = 0" << std::endl;
 return 0;
}