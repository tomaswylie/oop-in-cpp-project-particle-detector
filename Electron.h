// Electron.h

// Interface of the Electron object

// Student ID: 10831050, last updated: 18/05/25

#ifndef ELECTRON_H
#define ELECTRON_H

#include "Particle.h"

class Electron: public Particle
{
protected:


public:

  // Default constuctor
  Electron(bool is_antiparticle = false);

  // Parameterised constructor
  Electron(std::vector<double> momentum_in, bool is_antiparticle = false);

  // Destructor
  ~Electron();
  
};

#endif