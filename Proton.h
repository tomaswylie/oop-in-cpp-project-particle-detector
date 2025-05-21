// Proton.h

// Interface of the Proton object

// Student ID: 10831050, last updated: 21/05/25

#ifndef PROTON_H
#define PROTON_H

#include "Particle.h"

class Proton: public Particle
{
protected:


public:

  // Default constuctor
  Proton(int ID_in, bool is_antiparticle = false);

  // Parameterised constructor
  Proton(int ID_in, const std::vector<double> momentum_in, bool is_antiparticle = false);

  // Destructor
  ~Proton();

  // Overrided print_particle function
  void print_particle() const;

};

#endif