#include <iostream> 
double max( double x, double y );

double max( double x, double y ) {
 if ( x >= y ) {
 return x;
 } else {
 return y;
 }
	}
int main() {
	std::cout << max (3 ,5 ) << std::endl;
}