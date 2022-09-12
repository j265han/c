#include <iostream>

int main() {
  double x{0.0};

  std::cout << "Enter value of x: ";
  std::cin >> x;

  // This local variable should hold the result of stair( x )
  int stair_result{};

  // TASK: write code that calculates an integer value
  // corresponding to the value of the function stair( x ) here

  if ( x >= 0) {
	for ( int k{1}; k <= 9999; ++k ) { 
	  if ( k < k+1 ) { 
	  stair_result = x; }
		}
	  } else { for ( int k{-999999}; k <= 0; ++k ) { 
		  if ( k <= x) {( stair_result = k ) ;
	}
	  }
	  }

  std::cout << "The value of stair(x) is: " << stair_result << std::endl;

 return 0;
}