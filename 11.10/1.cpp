#include <iostream>
#ifndef MARMOSET_TESTING
int main();
#endif

int * merge_arrays (int * & data_1, std::size_t data_1_size,int * & data_2, std::size_t data_2_size);

#ifndef MARMOSET_TESTING
int main(){
    int *data_1 = new int[5]{1, 2, 3, 5, 6};
    int *data_2 = new int[5]{1, 2, 3, 5, 6};
    std::size_t data_2_size{5};
    std::size_t data_1_size{5};
    int *new_array = merge_arrays(data_1,data_1_size, data_2, data_2_size);
    return 0;
}
#endif

int * merge_arrays (int * & data_1, std::size_t data_1_size,int * & data_2, std::size_t data_2_size){
        // int capacity2{};
        // while (capacity2 <= data_2_size){
        //     capacity2++;
        // }
        int *temp_array = new int[data_2_size+data_1_size]{};
        for(int i{}; i < data_2_size+data_1_size+data_2_size+data_1_size-1; i=i+2){
            if (data_1[i] < data_2[i]){
                temp_array[i]=data_1[i];
                temp_array[i+1]=data_2[i];
            } else {
                temp_array[i]=data_2[i];
                temp_array[i+1]=data_1[i];
            }
        }

}