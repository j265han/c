	#include <iostream>
#include <string>
int get_value_no_less_than( std::string text, int lower_bound ) {
 while ( true ) {
 int value{};
 std::cout << text;
 std::cin >> value;
 if ( value >= lower_bound ) {
 return value;
 }
 }
}




int main() {
 int n{ get_value_no_less_than( "Enter a positive integer: ", 1 ) };
 std::cout << "The user entered " << n << std::endl;
 n = get_value_no_less_than( "Enter a non-negative integer: ", 0 );
 std::cout << "The user entered " << n << std::endl;
 n = get_value_no_less_than(
 "Enter an integer greater than 100: ", 101 );
 std::cout << "The user entered " << n << std::endl;
 return 0;
}
