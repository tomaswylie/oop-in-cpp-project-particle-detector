// Neutron.h

// Interface of the Neutron object

// Student ID: 10831050, last updated: 21/05/25

#ifndef NEUTRON_H
#define NEUTRON_H

#include "Particle.h"

class Neutron: public Particle
{
protected:


public:

  // Default constuctor
  Neutron(int ID_in, bool is_antiparticle = false);

  // Parameterised constructor
  Neutron(int ID_in, const std::vector<double> momentum_in, bool is_antiparticle = false);

  // Destructor
  ~Neutron();

  // Overrided print_particle function
  void print_particle() const;

};

#endif