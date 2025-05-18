// SubDetector.h

// Interface of the SubDetector abstract base class

// Student ID: 10831050, last updated: 21/04/25

#ifndef SUBDETECTOR_H
#define SUBDETECTOR_H

#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<stdexcept>
#include<cmath>

#include "Particle.h"

class SubDetector
{
protected:
  std::string detector_type;
  std::string material;

  // Protected parameterised constructor only accessible by derived classes
  SubDetector(std::string detector_type_in, std::string material_in) :
    detector_type{detector_type_in}, material{material_in}
  {};

public:

  // Virtual destructor
  virtual ~SubDetector() = default;

  // Pure virtual print function
  virtual void print_detector() const = 0;

  // Pure virtual getters
  virtual std::string get_detector_type() const = 0;
  virtual std::string get_material() const = 0;

  // Pure virtual detected function that a double for the energy detected by the detector.
  virtual double detected(Particle& p) = 0;
};


#endif
