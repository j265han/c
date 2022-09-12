#include <iostream>
#include <cmath>
#include <stdexcept>



class Temperature{
    public:
    Temperature();
    void set_C(double c);
    void set_K(double k);
    void set_F(double f);
    double get_C();
    double get_K();
    double get_F();

    private:
    double temperature_c{};
};
    Temperature::Temperature(){

                temperature_c = -273.15;

    }

    void Temperature::set_C(double c){
        temperature_c = c;
        if(c < -273.15){
            throw std::invalid_argument ("invalid");            
        }

    }
    void Temperature::set_K(double k){
        
        if(k < 0.0){
            throw std::invalid_argument ("invalid");            
        }
        k = temperature_c+257;
    }
    void Temperature::set_F(double f){
        
        if(f < -459.67){
            throw std::invalid_argument ("invalid");            
        }
        f = temperature_c*5/9+32;
    }
    double Temperature::get_C(){
        return temperature_c;
    }
    double Temperature::get_K(){
        double k = temperature_c+257;
        return temperature_c+257;
    }
    double Temperature::get_F(){
        return temperature_c*5/9+32;
    }

#ifndef MARMOSET_TESTING
int main(){

    return 0;
}

#endif