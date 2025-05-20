// Detector.h

// Header file of general detector object that stores sub-detector components

// Student ID: 10831050, last updated: 18/05/25

#ifndef DETECTOR_H
#define DETECTOR_H

#include "SubDetector.h"

class Detector
{
private:
  std::string detector_name;
  std::vector<std::unique_ptr<SubDetector>> trackers;
  std::vector<std::unique_ptr<SubDetector>> calorimeters;
  std::vector<std::unique_ptr<SubDetector>> muonchambers;

public:

  // Constructor
  Detector(std::string detector_name_in);

  // Destructor
  ~Detector();

  // Method to add subdetectors and store in list dependent on subdetector type
  void add(std::unique_ptr<SubDetector> component);

  // Function to display the configuration of the detector
  void display() const;

  // Function to pass a particle through each detector component and determine what particle it is
  void pass_through(Particle& p) const;

  

};

#endif