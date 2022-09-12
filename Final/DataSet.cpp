#include <iostream>
#include <cmath>
#include <stdexcept>
#ifndef MARMOSET_TESTING
int main();

#endif
class DataSet
{
    protected:
        double sum_of_values;
        double sum_of_squares;
        int qty_values;

    public :
       DataSet() ;
       void add_data_element(double element);
       double mean() const;
       double std_dev() const;
};



DataSet::DataSet(){
    sum_of_values=0.0;
    sum_of_squares=0.0;
    qty_values=0;
}



void DataSet::add_data_element(double element){
    sum_of_values= sum_of_values+element;
    sum_of_squares= element*element+sum_of_squares;
    qty_values++;
}

double DataSet::mean() const{
    if (qty_values == 0){
        throw std::logic_error("No values have been entered yet.");
    } else {
        return sum_of_values/qty_values;
    }
}



double DataSet::std_dev() const{
    if (qty_values == 0){
        throw std::logic_error("No values have been entered yet.");
    } else {
        double mean_value = sum_of_values/qty_values;
        double mean_value_sqr = mean_value*mean_value;
        return pow(sum_of_squares/qty_values- mean_value_sqr,0.5);
    }
}








