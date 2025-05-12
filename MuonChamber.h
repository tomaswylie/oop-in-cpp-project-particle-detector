// MuonChamber.h

// Header file of the MuonChamber detector

// Student ID: 10831050, last updated: 30/04/25

#ifndef MUONCHAMBER_H
#define MUONCHAMBER_H

#include "SubDetector.h"

class MuonChamber: public SubDetector
{
protected:
  int number_of_drift_tubes;
public:
  
  // Defualt constructor
  MuonChamber();

  // Parameterised constructor
  MuonChamber(std::string material_in, int number_of_drift_tubes_in);

  // Destructor
  ~MuonChamber();

  // Overrided print_detector function
  void print_detector() const;

};

#endif