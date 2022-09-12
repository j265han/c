#include <iostream>

int main() 
{
    double a {150000.0};
    double b {1/1055.0};
    double c {1/3.966};
    double d {1/860.4};
    double e {1/1.162};
    std::cout << " There are " << a << " Joules of energy. " << std::endl;
    double kWh {a * b * c * d};
    std::cout << " There are " << kWh << " kWh of energy. " << std::endl;
    double kcal {a * b * c};
    std::cout << " There are " << kcal << " kcal of energy. " << std::endl;
    double BTU {a * b};
    std::cout << " There are " << BTU << " BTU of energy. " << std::endl;
    double kg_TNT {a * b * c * d * e};
    std::cout << " There are " << kg_TNT << " kg-TNT of energy. " << std::endl;
    return 0;
}