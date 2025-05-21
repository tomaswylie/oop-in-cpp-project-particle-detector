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
  Electron(int ID_in, bool is_antiparticle = false);

  // Parameterised constructor
  Electron(int ID_in, const std::vector<double> momentum_in, bool is_antiparticle = false);

  // Destructor
  ~Electron();

  // Overrided print_particle function
  void print_particle() const;

};

#endif