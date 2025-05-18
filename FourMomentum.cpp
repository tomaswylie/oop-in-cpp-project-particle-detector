// FourMomentum.cpp

// Implementation of the FourMomentum object

// Student ID: 10831050, last updated: 18/04/25

#include "FourMomentum.h"

// Default constructor
FourMomentum::FourMomentum() :
  E{0}, px{0}, py{0}, pz{0}
{};

// Parameterised constructor
FourMomentum::FourMomentum(double E_in, double px_in, double py_in, double pz_in) :
  E{E_in}, px{px_in}, py{py_in}, pz{pz_in}
{
  if(E_in<0){throw std::invalid_argument("Energy cannot be negative.");}
};

// Destructor
FourMomentum::~FourMomentum(){};

// Overloaded addition operator to take addition of four-momenta
FourMomentum FourMomentum::operator+(const FourMomentum& v) const noexcept
{
  return FourMomentum(E+v.E,px+v.px,py+v.py,pz+v.pz);
}

// Overloaded subtraction operator to take subtraction of four-momenta
FourMomentum FourMomentum::operator-(const FourMomentum& v) const
{
  return FourMomentum(E-v.E,px-v.px,py-v.py,pz-v.pz);
}

// Overloaded division operator to take scalar division of four-momenta objects
FourMomentum FourMomentum::operator/(const double a) const
{
  if(a==0)
  {
    throw std::invalid_argument("Cannot divide by 0.");
  }
  else
  {
    return FourMomentum(E/a,px/a,py/a,pz/a);
  }
}

// Overloaded multiplication operator to take the inner product of two four-momenta
double FourMomentum::operator*(const FourMomentum& v) const
{
  double inner_product{(E*v.E)-(px*v.px)-(py*v.py)-(pz*v.pz)};
  return inner_product;
}

// Overloaded multiplication operator to support right side scalar multiplication
FourMomentum FourMomentum::operator*(const double a) const
{
  return FourMomentum(E*a,px*a,py*a,pz*a);
}

// Overloaded multiplication operator as a friend of the class to support left side scalar multiplication
FourMomentum operator*(const double a, const FourMomentum& v)
{
  return FourMomentum(a*v.E,a*v.px,a*v.py,a*v.pz);
}

// Overloaded ostream operator
std::ostream& operator<<(std::ostream& os, const FourMomentum& mom)
{
  os<<"("<<mom.E<<", "<<mom.px<<", "<<mom.py<<", "<<mom.pz<<")";
  return os;
}

// Overloaded array index selection operator []
double FourMomentum::operator[](const size_t i) const
{
  if(i==0)
  {
    return E;
  }
  else if(i==1)
  {
    return px;
  }
  else if(i==2)
  {
    return py;
  }
  else if(i==3)
  {
    return pz;
  }
  else
  {
    std::invalid_argument("Invalid index used.");
  }
}