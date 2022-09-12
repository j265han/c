#include <iostream>

#ifndef MARMOSET_TESTING
int main();

#endif
std::size_t partition( double array[], std::size_t cap, double val);
std::size_t partition( double array[], std::size_t cap, double val){
    if (val < array[0]){
        return 0;
    } else if(val > array[cap - 1]){
        return cap;
    } else {
        int count {};
        for (int i{}; i < cap; i++){
            if (array[i] < val){
                count++;
            }
        }
        return count;
    }
}

#ifndef MARMOSET_TESTING
int main(){
    const std::size_t CAP{5};
    double array[CAP]{1.0, 4.8, 7.0, 8.2, 9.1};
    std::cout <<  partition(array,CAP,5.0) << std::endl;
    //val = 5.0, function should return 1, for index 1
    std::cout << partition(array,CAP,0.2) << std::endl;
    //val = 0.2, function should return 0
    std::cout << partition(array,CAP,10.4) << std::endl;
    //val = 10.4, function should return 5
    return 0;
}
#endif