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

class SubDetector
{
protected:
  std::string detector_type;
  std::string material;

public:

  // Virtual destructor
  virtual ~SubDetector() = default;

  // Pure virtual print function
  virtual void print_detector() = 0;
};


#endif
