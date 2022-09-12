#include <iostream>

int main (){
double running_average(0.0);
double running_sum{0.0};
 int count{0};

 while ( true ) {
 double value{};
 std::cout << "Enter a number: ";
 std::cin >> value;
 running_sum += value;
 ++count;
 std::cout << (running_sum/count) << std::endl;
 if ( value == 0.0 ) {
 return running_sum/count;
 }
 }
}