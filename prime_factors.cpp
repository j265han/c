#include <iostream>

int main() {
int n{};
std::cout << " Prime Factors Program "<< std::endl; 
std::cout << " Enter number to be factored : " << std::endl;
std:: cin >> n;
int factor{2};
 while ( n > 1 ) {
 while ( n%factor == 0 ) {
  std::cout << factor << " " ;
 n /= factor ; 
 }
 ++factor;
 }
	
return 0;
}
