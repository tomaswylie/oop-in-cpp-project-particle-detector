// Tracker.h

// Header file of the Tracker detector

// Student ID: 10831050, last updated: 30/04/25

#ifndef TRACKER_H
#define TRACKER_H

#include "SubDetector.h"

class Tracker: public SubDetector
{
protected:
  int number_of_layers;

public:

  // Default constructor
  Tracker();

  // Parameterised constructor
  Tracker(std::string material_in, int number_of_layers_in);

  // Destructor
  ~Tracker();

  // Overrides the print_detector function for tracker
  void print_detector() const;

  // Getter for detector type
  std::string get_detector_type() const;

  // Getter for material type
  std::string get_material() const;

  // Overrides the detected function for tracker
  double detected(Particle& p)

};

#endif