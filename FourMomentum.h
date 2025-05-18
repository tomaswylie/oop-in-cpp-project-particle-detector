// FourMomentum.h

// Header file of the FourMomentum object

// Student ID: 10831050, last updated: 18/04/25

#ifndef FOURMOMENTUM_H
#define FOURMOMENTUM_H

#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<stdexcept>
#include<cmath>

class FourMomentum
{
protected:
  double E;
  double px;
  double py;
  double pz;

public:

  // Default constructor
  FourMomentum();

  // Parameterised constructor
  FourMomentum(double E_in, double px_in, double py_in, double pz_in);

  // Detstructor
  ~FourMomentum();

  // Overloaded addition operator to take addition of four-momenta
  FourMomentum operator+(const FourMomentum& v) const noexcept;

  // Overloaded subtraction operator to take subtraction of four-momenta
  FourMomentum operator-(const FourMomentum& v) const;

  // Overloaded multiplication operator to take the inner product of two four-momenta
  double operator*(const FourMomentum& v) const;

  // Overloaded division operator to take scalar division of four-momenta objects
  FourMomentum operator/(const double a) const;

  // Overloaded multiplication operator to support right side scalar multiplication
  FourMomentum operator*(const double a) const;

  // Overloaded multiplication operator as a friend of the class to support left side scalar multiplication
  friend FourMomentum operator*(const double a, const FourMomentum& v);

  // Overloading the ostream operator "<<" as a friend of the class
  friend std::ostream& operator<<(std::ostream& os, const FourMomentum& mom);

  // Overloaded the array index operator to get four momentum components 
  double operator[](const size_t i) const;

  // Getters for each component of Four Momentum
  double get_E() const;
  double get_px() const;
  double get_py() const;
  double get_pz()
};

#endif