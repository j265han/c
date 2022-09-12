#include <iostream>

double max( double x, double y, double z );
// Function definition
double max( double x, double y, double z ) {
 if ( (x >= y) && (x >= z) ) {
 return x;
 } else if ( y >= z ) {
 return y;
 } else {
 return z;
 }
}
int main() {
	std::cout << max ( 5, 7, 8 ) << std::endl;
}