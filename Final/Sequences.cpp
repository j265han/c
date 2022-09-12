#include "InfiniteSequence.hpp" // This imports the parent class 
#include <iostream>
#include <cmath>
#ifndef MARMOSET_TESTING
int main();
#endif
// Derived class declarations here
class InfiniteSequence
{
protected : // These member variables are inherited by derived classes
    double * values;
    std::size_t qty_relevant_values;
public :
    InfiniteSequence();
    ~InfiniteSequence();
    // Not implemented in the parent class
    double operator [] (unsigned int idx) const;
};
InfiniteSequence::InfiniteSequence()
{
    // values holds a dynamically allocated array
    values = nullptr;
    qty_relevant_values = 0;
}
InfiniteSequence::~InfiniteSequence()
{
    if (values != nullptr)
    {
        delete [] values;
        values = nullptr;
    }
}


class EventuallyZeroInfSeq 
{
    protected:


    public :
        EventuallyZeroInfSeq::EventuallyZeroInfSeq();
        double EventuallyZeroInfSeq::operator [] (unsigned int idx) const;
};

class PeriodicInfSeq
{
    protected:


    public :
        PeriodicInfSeq::PeriodicInfSeq();
        double PeriodicInfSeq::operator [] (unsigned int idx) const;
};

class GeometricInfSeq
{
    protected:


    public :
        GeometricInfSeq::GeometricInfSeq();
        double GeometricInfSeq::operator [] (unsigned int idx) const;
};

EventuallyZeroInfSeq::EventuallyZeroInfSeq(){

}
        double EventuallyZeroInfSeq::operator [] (unsigned int idx) const{
return idx;
        }
PeriodicInfSeq::PeriodicInfSeq(){

}
        double PeriodicInfSeq::operator [] (unsigned int idx) const{
return idx;
        }
        GeometricInfSeq::GeometricInfSeq(){
            
        }
        double GeometricInfSeq::operator [] (unsigned int idx) const{
return idx;
        }

#ifndef MARMOSET_TESTING
int main()
{
  double arr[5] ={1,2,3,4,5};
  EventuallyZeroInfSeq zseq{arr,5};
  std::cout<<zseq[1]<<std::endl;
  std::cout<<zseq[7]<<std::endl;
  PeriodicInfSeq pseq{arr,5};
  std::cout<<pseq[1]<<std::endl;
  std::cout<<pseq[7]<<std::endl;
  GeometricInfSeq gseq{5,3};
  std::cout<<gseq[0]<<std::endl;
  std::cout<<gseq[5]<<std::endl;
  return 0;
}
#endif
// Derived class member function definitions here
