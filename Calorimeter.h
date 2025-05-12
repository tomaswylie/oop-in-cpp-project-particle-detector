// Calorimeter.h

// Header file of the Calorimeter detector

// Student ID: 10831050, last updated: 30/04/25

#ifndef CALORIMETER_H
#define CALORIMETER_H

#include "SubDetector.h"

class Calorimeter: public SubDetector
{
protected:
  int number_of_crystals;

public:

  // Default constructor
  Calorimeter();

  // Parameterised constructor
  Calorimeter(std::string material_in, int number_of_crystals_in);

  // Destructor
  ~Calorimeter();

  // Overrides the print_data function for calorimeter
  void print_detector() const;


};

#endif