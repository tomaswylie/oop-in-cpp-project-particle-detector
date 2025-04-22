// Tracker.h

// Header file of the Tracker detector

// Student ID: 10831050, last updated: 22/04/25

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

};

#endif