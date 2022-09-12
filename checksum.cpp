#include <iostream>
#include <climits>

#ifndef MARMOSET_TESTING
int main();
#endif

unsigned int add_checksum(unsigned int n);
unsigned int add_checksum(unsigned int n){
    int data(n);
	int result{0};
	int digit{0};
	int checksum{0};

	if (n>99999999){
		return UINT_MAX;
	} else {
		while (n>0){
			int remainder{0};
				if ( digit%2 == 0){
				remainder = (n%10)*2;
					if (remainder>9){
					remainder = remainder - 9;
					} else {
					remainder = remainder;
					}
				} else {
				remainder = n%10;
				}
			digit += 1;
			checksum = checksum + remainder;
			n /= 10;
		}
		checksum = (checksum*9)%10;
    	result = data*10 + checksum;
    
		return result;
	}
}
void add_checksum(unsigned int array[], std::size_t capacity);
void add_checksum(unsigned int *array, std::size_t capacity){
    for (int k{0}; k<capacity; k++){
        array[k]=add_checksum(array[k]);
    }
    return;
}

bool verify_checksum(unsigned int n);
bool verify_checksum(unsigned int n){
	if ((n <= 999999999) && ((n%10) == ((add_checksum(n/10))%10))){
		return true;
	}else{
		return false;
	}
}
unsigned int remove_checksum(unsigned int n);
unsigned int remove_checksum(unsigned int n){
	if (verify_checksum(n)){
		return n/10;
	}else{
		return UINT_MAX;
	}
}
void remove_checksum(unsigned int array[], std::size_t capacity);
void remove_checksum(unsigned int array[], std::size_t capacity){
	for (int k{0}; k<capacity; k++ ){
		array[k]=remove_checksum(array[k]);
	}
	return;
}



#ifndef MARMOSET_TESTING
int main() {
	unsigned int value_to_protect{21352411};
	unsigned int protected_value = add_checksum(value_to_protect);
	std::cout << "The value " << value_to_protect
		<< " with the checksum added is " << protected_value
		<< "." << std::endl;
	
	if (verify_checksum(protected_value))
	{
		std::cout << "The checksum is valid." << std::endl;
	}
	else   {
		std::cout << "The checksum is invalid." << std::endl;
	} 
	const std::size_t QTY_VALUES {3};
	unsigned int value_series[QTY_VALUES] {20201122, 20209913, 20224012};
	
	add_checksum(value_series, QTY_VALUES);
	
	std::cout << "Series with checksums added: ";
	for (std::size_t series_index {0};
		series_index < QTY_VALUES; series_index++)
	{
		std::cout << value_series[series_index] << " ";
	}

    std::cout << std::endl;
    return 0;
}
#endif